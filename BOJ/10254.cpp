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
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair < ll,ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
vector<P> v;
map<ll, int> m;
stack<ll> st,en;
ll ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<P> v;
		map<ll, int> m;
		stack<ll> st, en;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			ll x, y;
			scanf("%lld%lld", &x, &y);
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end());
		//graham scan방법으로 0~v.size()-1까지 돌린다(기준은 반시계방향, 시계방향이 나오면 걔를뺀다)
		int ptr = 2;
		st.push(0), st.push(1);
		// 0부터 쭉 진행하기(반시계여야 값을 넣을수 있다-> 즉 ccw값이 양수일때)
		while (ptr < v.size()) {
			ll first = st.top();
			st.pop();
			ll second = st.top();
			st.pop();
			ll ccw1 = ccw(v[second], v[first], v[ptr]);
			if (ccw1 > 0) {
				st.push(second);
				st.push(first);
				st.push(ptr);
				ptr++;
			}
			else {
				st.push(second);
				st.push(first); //원상태로 만들고
				st.pop();
				if (st.size() == 1) {
					st.push(ptr);
					ptr++;
				}
			}
		}
		ptr = v.size() - 3;
		en.push(v.size() - 1);
		en.push(v.size() - 2);
		while (ptr >= 0) {
			ll first = en.top();
			en.pop();
			ll second = en.top();
			en.pop();
			ll ccw1 = ccw(v[second], v[first], v[ptr]);
			if (ccw1 > 0) {
				en.push(second);
				en.push(first);
				en.push(ptr);
				ptr--;
			}
			else {
				en.push(second);
				en.push(first); //원상태로 만들고
				en.pop();
				if (en.size() == 1) {
					en.push(ptr);
					ptr--;
				}
			}
		}
		vector<P> route,route1,route2;
		int first = st.top();
		st.pop();
		int second = st.top();
		route1.push_back({ second,first });
		st.pop();
		while (!st.empty()) { //아래껍질
			int next = st.top();
			route1.push_back({next,second});
			second = next;
			st.pop();
		}
		reverse(route1.begin(), route1.end());
		en.pop();
		while (!en.empty()) { // 윗껍질
			int next = en.top();
			route2.push_back({ next,second });
			second = next;
			en.pop();
		}
		ll Max = 0;
		int idx1 = 0, idx2 = 0;
		reverse(route2.begin(), route2.end());
		for (int i = 0; i < route2.size(); i++) route.push_back(route2[i]);
		for (int i = 0; i < route1.size(); i++) route.push_back(route1[i]);
		ptr = 0; //시작 포인터
		int move = 1;
		// route에는 정점번호 2개가 들어가있다
		while (ptr < route.size()) {
			P first = route[ptr]; //정점들의 집합
			P next = route[move];
			ll x1 = v[first.first].first, y1 = v[first.first].second, x2 = v[first.second].first, y2 = v[first.second].second, x3 = v[next.first].first, y3 = v[next.first].second, x4 = v[next.second].first, y4 = v[next.second].second;
			ll tx1 = x1, ty1 = y1, tx2 = x2, ty2 = y2, tx3 = x3, ty3 = y3, tx4 = x4,ty4=y4;
			x2-=x1,y2 -= y1,x1-=x1,y1-=y1, x4 -= x3, y4 -= y3, x3 -= x3, y3 -= y3;
			ll ccw1 = ccw({ x1,y1 }, { x2,y2 }, {x4,y4});
 			if (ccw1 > 0) { //반시계방향이면 그냥 move를 옮긴다
				move++;
				if (move == route.size()) move = 0;
			}
			else { // 시계가 되면 그때 최대 거리를 체크한다
				ll dist = (tx3 - tx2)*(tx3 -tx2) + (ty3 -ty2)*(ty3 - ty2);
				ll dist3 = (tx1 - tx3)*(tx1 - tx3) + (ty1 - ty3)*(ty1 - ty3);
				ll dist4 = (tx1 - tx4)*(tx1 - tx4) + (ty1 - ty4)*(ty1 - ty4);
				ll dist2 = (tx2 - tx4)*(tx2 - tx4) + (ty2 - ty4)*(ty2 - ty4);
				if (Max < dist3) {
					Max = dist3;
					idx1 = first.first;
					idx2 = next.first;
				}
				if (Max < dist) {
					Max = dist;
					idx1 = first.second;
					idx2 = next.first;
				}
				if (Max < dist4) {
					Max = dist4;
					idx1 = first.first;
					idx2 = next.second;
				}
				if (Max < dist2) {
					Max = dist2;
					idx1 = first.second;
					idx2 = next.second;
				}
				ptr++;
			}
		}
		printf("%lld %lld %lld %lld\n", v[idx1].first, v[idx1].second, v[idx2].first, v[idx2].second);

	}
	return 0;
}