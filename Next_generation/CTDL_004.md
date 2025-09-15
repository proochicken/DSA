# Describe:

Cho dãy gồm N số phân biệt AN = {a1, a2, .., aN } và số tự nhiên K (K<=N<=100). Ta gọi một dãy con tăng dần bậc K của dãy số AN là một dãy các số gồm K phần tử trong dãy đó thỏa mãn tính chất tăng dần. Bài toán được đặt ra là in ra màn hình  số các dãy con tăng dần bậc K của dãy số AN. Ví dụ :


Input:  5    3

2    5    15   10    20  

    • Dòng đầu tiên ghi lại hai số N và K tương ứng với số phần tử của dãy số và bậc của dãy con.

    • Dòng kế tiếp : N số của dãy số AN, các số trong dãy không lớn hơn 100. 

thì Output : 7 (số các dãy con tăng dần bậc 3 của dãy số AN)



# Solution:

```C++
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[105], b[105];
bool check = false;
void nhap(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++){
        b[i] = i;
    }
}
void sinh(){
    int i = k;
    while(i >= 1 && b[i] == n - k + i) i--;
    if(i == 0) check = true;
    else{
        b[i]++;
        for(int j = i + 1; j <= k; j++){
            b[j] = b[j-1] + 1;
        }
    }
}
int main(){
    nhap();
    int cnt = 0;
    while(check == false){
        bool ok = true;
        for(int i = 2; i <= k; i++){
            if(a[b[i]] <= a[b[i - 1]]){
                ok = false;
                break;
            }
        }
        if(ok == true){
            cnt++;
        }
        sinh();
    }
    cout << cnt;
}
```
