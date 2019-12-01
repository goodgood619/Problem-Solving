#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string t;
    while(getline(cin,t,'\n')){
        int big=0, small=0,num=0,space=0;
        for(int i=0;i<t.size();i++){
            if(t[i]>='A' && t[i]<='Z') big++;
            else if(t[i]>='a'&& t[i]<='z') small++;
            else if(t[i]>='0' && t[i]<='9') num++;
            else if(t[i]==' ') space++;
        }
        printf("%d %d %d %d\n",small,big,num,space);
    }
    return 0;
}