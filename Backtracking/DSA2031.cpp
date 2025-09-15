//From <https://code.ptit.edu.vn/student/question/DSA02031> 

#include <bits/stdc++.h>
using namespace std;
char c;
string s;
bool used[128];
bool is_consonant(char x) {
    return x != 'A' && x != 'E';
}
bool valid(const string& str) {
    for (int i = 1; i < str.size() - 1; i++) {
        if ((str[i] == 'A' || str[i] == 'E') && is_consonant(str[i - 1]) && is_consonant(str[i + 1]))
            return false;
    }
    return true;
}
void Try(int i) {
    int len = c - 'A' + 1;
    for (char ch = 'A'; ch <= c; ++ch) {
        if (!used[ch]) {
            used[ch] = true;
            s.push_back(ch);
            if (i == len - 1) {
                if (valid(s)) cout << s << '\n';
            } else {
                Try(i + 1);
            }
            s.pop_back();
            used[ch] = false;
        }
    }
}

int main() {
    cin >> c;
    Try(0);
    return 0;
}
