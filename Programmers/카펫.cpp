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
int ans1, ans2;
vector<int> solution(int brown, int red) {
	vector<int> answer;
    bool ok=false;
	for (int i = 1; i <= sqrt(red); i++){
		if (red%i == 0) {
			int temp = red / i;
			int temp2 = 2 * (temp + i) + 4;
			if (temp2 == brown){
				ok = true;
				ans1 = max(temp+ 2, i + 2);
				ans2 = min(temp+ 2, i + 2);
				break;
			}
		}
		if (ok) break;	
	}
	answer.push_back(ans1);
	answer.push_back(ans2);
	return answer;
}