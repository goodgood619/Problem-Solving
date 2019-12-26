#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int t;
    scanf("%d",&t);
    while(t-- ){
        string s1,s2;
        cin >> s1 >> s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        Int a = stoi(s1), b = stoi(s2);
        a += b;
        s1.clear();
        s1 = to_string(a);
        reverse(s1.begin(),s1.end());
        printf("%d\n",stoi(s1));
    }
    return 0;
}