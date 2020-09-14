#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<string> v;
    bool check = false;
    int ans = 0;
    for (auto c : s) {
        if (c == 'q') {
            //v가 비어있는지, 
            v.push_back("q");
        }
        else {
            if (v.empty()) {
                check = true;
                break;
            }
            // 이제 알맞은 위치에 넣어야 하는데, 알맞은 위치가 없다면 그것또한 불가능
            bool ok = false;
            for (int j = 0; j < v.size(); j++) {
                string s = v[j];
                if (c == 'u' && s == "q" || c=='a' && s=="qu" || c=='c' && s=="qua") {
                    v[j].push_back(c);
                    ok = true;
                    break;
                }
                else if (c == 'k' && s == "quac") {
                    v[j].push_back(c);
                    ans = max(ans, (int)v.size());
                    auto it = find(v.begin(), v.end(), v[j]);
                    v.erase(it);
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                check = true;
                break;
            }
        }
    }
    if (!v.empty()) check = true;
    printf("%d\n", check?-1:ans);
    return 0;
}