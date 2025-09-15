//From <https://code.ptit.edu.vn/student/question/DSA02018> 



#include <bits/stdc++.h>
using namespace std;
int a[5];
char ops[] = {'+', '-', '*'};
int nums[5], pick[5];
bool used[5], found;
int calculator(int a, char op, int b){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}
void ql(int i){
    if(found) return;
    if(i == 5){
        for(char o1 : ops){
            for(char o2 : ops){
                for(char o3 : ops){
                    for(char o4 : ops){
                        int res = calculator(pick[0], o1, pick[1]);
                        res = calculator(res, o2, pick[2]);
                        if(abs(res) > 1000) continue;
                        res = calculator(res, o3, pick[3]);
                        if(abs(res) > 1000) continue;
                        res = calculator(res, o4, pick[4]);
                        if(res == 23){
                            found = true;
                            return;
                        }
                    }
                }
            }
        }
        return;
    }
    for(int j = 0; j < 5; j++){
        if(!used[j]){
            used[j] = true;
            pick[i] = nums[j];
            ql(i + 1);
            used[j] = false;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        for(int i = 0; i < 5; i++){
            cin >> nums[i];
        }
        found = false;
        memset(used, false, sizeof(used));
        ql(0);
        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
