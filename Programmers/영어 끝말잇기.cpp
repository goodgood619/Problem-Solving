#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int mod = n;
    int cnt=1,turn=0;
    map<string,int> m;
    m[words[0]]++;
    string pre=words[0];
    int ok=0;
    for(int i=1;i<words.size();i++){
        string here=words[i];
        if(m.count(here)!=0 || pre[pre.size()-1]!=here[0]) {
            answer.push_back(++cnt);
            answer.push_back(++turn);
            ok=1;
            break;
        }
        m[here]++;
        pre=here;
        cnt++;
        if(cnt%mod==0) {
            cnt=0;
            turn++;
        }
    }
    if(!ok) answer.push_back(0),answer.push_back(0);
    return answer;
}