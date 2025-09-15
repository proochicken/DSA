# Describe:

Một xâu nhị phân độ dài n (n < 10) được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu nhị phân đó ta vẫn nhận được chính nó. Cho số tự nhiên n (n nhập từ bàn phím). Hãy 

viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.  Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.


Ví dụ với n = 4 ta tìm được 4 xâu nhị phân thuận nghịch như dưới đây.


0                      0                      0                      0         

0                      1                      1                      0         

1                      0                      0                      1         

1                      1                      1                      1

Ví dụ

```text
Input

4
```

```text
Output

0 0 0 0
0 1 1 0
1 0 0 1
1 1 1 1
```

# Solution:

```C++
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[100];
bool ok = true;
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
}
void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = false;
    else{
        a[i] = 1;
    }
}
bool check(int a[], int n){
    int l = 1, r = n;
    while(l <= r){
        if(a[l] != a[r]) return false;
        else{
            l++; r--;
        }
    }
    return true;
}
int main(){
    nhap();
    while(ok == true){
        if(check(a, n)){
            for(int i = 1; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        sinh();
    }
}
```
