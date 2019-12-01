#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    while(true){
        char c[256]={'\0',};
        scanf(" %[^\n]s",c);
        if(!strcmp(c,"#")) break;
        int sum = 0;
        string s = c;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ') continue;
            else sum +=(i+1)* (s[i]-'A' + 1);
        }
        printf("%d\n",sum);
    }
    return 0;
}