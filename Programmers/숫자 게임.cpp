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
priority_queue<int,vector<int>,greater<int>> a,b;
int solution(vector<int> A, vector<int> B) {
    for(int i=0;i<B.size();i++) {
       a.push(A[i]);
        b.push(B[i]);
    }
    int answer=0;
    while(!a.empty() && !b.empty()){
        if(a.top()<b.top()){
            answer++;
            a.pop();
            b.pop();
        }
        else b.pop();
    }
    return answer;
}