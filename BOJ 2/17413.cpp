#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    char s[100001]={'\0',};
    scanf("%[^\n]s",s);
    int length = strlen(s);
    vector<string> word;
    string a;
    for(int i=0;i<length;) {
        if(s[i] == '<') {
            if(!a.empty()) {
                word.push_back(a);
                a.clear();
            }
            int start = i;
            while(s[i]!='>') {
                i++;
            }
            int end = i;
            i++;
        }
        else if(s[i] == ' ') {
            if(!a.empty()) {
                word.push_back(a);
                a.clear();
            }
            i++;
        }
        else {
            a.push_back(s[i]);
            i++;
        }
    }
    if(!a.empty()) {
        word.push_back(a);
        a.clear();
    }
    int j=0;
    for(int i=0;i<length;) {
        if(s[i]=='<') {
            while(s[i]!='>') {
                printf("%c",s[i]);
                i++;
            }
            printf("%c",s[i]);
            i++;
        }
        else if(s[i]==' ') {
            printf(" ");
            i++;
        }
        else {
            int length2 = word[j].size();
            string ss = word[j];
            reverse(ss.begin(),ss.end());
            printf("%s",ss.c_str());
            i+=length2,j++;
        }
    }
    return 0;
}