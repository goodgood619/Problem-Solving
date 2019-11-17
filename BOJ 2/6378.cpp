#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};

int main() {
    while(true) {
        string s;
        cin >> s;
        if(s[0]=='0') break;
        int num = 0;
        while(true) {
            for (int i = 0; i < s.size(); i++) {
                num += (s[i] - '0');
            }
            if (num<10) {
                printf("%d\n",num);
                break;
            }
            else {
                s = to_string(num);
                num = 0;
            }
        }
    }
    return 0;
}