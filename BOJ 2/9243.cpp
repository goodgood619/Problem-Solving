#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };

int main()
{
    int n;
    scanf("%d",&n);
    string s1,s2;
    cin>>s1>>s2;
    for(int i =0 ;i<n;i++){
        for(int j=0 ;j<s1.size();j++)
        s1[j]=='1'?s1[j]='0':s1[j]='1';
    }
    s1==s2?printf("Deletion succeeded "):printf("Deletion failed");
    return 0;
}