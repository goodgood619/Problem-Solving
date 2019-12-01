#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin >> s;
        int sum = 0;
        string a;
        if(s == "P=NP"){
            printf("skipped\n");
            continue;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'){
                sum += stoi(a);
                a.clear();
            }
            else {
                a.push_back(s[i]);
            }
        }
        sum += stoi(a);
        printf("%d\n",sum);
    }
    return 0;
}