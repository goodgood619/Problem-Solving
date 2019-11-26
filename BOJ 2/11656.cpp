#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
int main() {
    string s;
    cin >> s;
    vector<string> v;
    for(int i=0 ;i<s.size();i++){
        string temp = s.substr(i,s.size());
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) printf("%s\n",v[i].c_str());
    return 0;
}