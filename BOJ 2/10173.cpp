#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    while(true){
        char s[81]={'\0',};
        scanf(" %[^\n]s",s);
        if(!strcmp(s,"EOI")) break;
        string t = s;
        int ok = 0;
        for(int i=0;i<t.size()-3;i++){
            if(t[i]=='N' || t[i]=='n'){
                if(t[i+1]=='E' || t[i+1]=='e'){
                    if(t[i+2]=='M' || t[i+2]=='m'){
                        if(t[i+3]=='O' || t[i+3]=='o'){
                            ok = 1;
                        }
                    }
                }
            }
        }
        ok?printf("Found\n"):printf("Missing\n");
    }
    return 0;
}