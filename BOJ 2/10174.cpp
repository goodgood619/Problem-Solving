#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        char s[1000]={'\0',};
        scanf(" %[^\n]s",s);
        string temp = s;
        int no=0;
        for(int i=0,j=temp.size()-1;i<=j;i++,j--){
            if(toupper(temp[i])!= toupper(temp[j])) {
                no=1;
                break;
            }
        }
        no?printf("No\n"):printf("Yes\n");
    }
    return 0;
}