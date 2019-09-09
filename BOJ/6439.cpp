
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
typedef pair<double, double> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double,double>, pair<double,double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<PPPP> v;
vector<P> v1;
double ccw(P A, P B, P C) {
	double x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
}
bool check(P A, P B, P C, P D) {
	double x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second,x4=D.first,y4=D.second;
	if (x1 == x2 && x2 == x3 && x3 == x4 && x4 == x1) {
		double maxy = max(y1, y2);
		double miny = min(y3, y4);
		if (maxy < miny) return false;
		double maxy2 = max(y3, y4);
		double miny2 = min(y1, y2);
		if (maxy2 < miny2) return false;
	}
	else {
		double maxx = max(x1, x2);
		double minx = min(x3, x4);
		if (maxx < minx) return false;
		double maxx2 = max(x3, x4);
		double minx2 = min(x1, x2);
		if (maxx2 < minx2) return false;
	}
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		double x1, y1, x2, y2, rx1, ry1, rx2, ry2;
		v.clear();
		v1.clear();
		scanf(" %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &rx1, &ry1, &rx2, &ry2);
		if (rx1 < rx2 && ry1 < ry2 || rx1>rx2 && ry1>ry2) {// 직사각형의 최소x좌표,최소 y좌표, 최대 x좌표, 최대 y좌표 인경우
			double rx3 = min(rx1, rx2);
			double ry3 = max(ry1, ry2);
			double rx4 = max(rx1, rx2);
			double ry4 = min(ry1, ry2);
			v1.push_back({ rx1,ry1 }), v1.push_back({ rx2, ry2 }), v1.push_back({ rx3,ry3 }), v1.push_back({ rx4,ry4 });
			v.push_back({ { x1,y1 }, { x2,y2 } });
			v.push_back({ { rx1,ry1 },{ rx3,ry3 } });
			v.push_back({ {rx1,ry1 }, { rx4,ry4 } });
			v.push_back({ { rx2,ry2 },{ rx3,ry3 } });
			v.push_back({ { rx2,ry2 },{ rx4,ry4 } });
		}
		else { // 직사각형의 최소x좌표, 최대y좌표, 최대x좌표, 최소y좌표
			double minx = min(rx1, rx2);
			double miny = min(ry1, ry2);
			double maxx = max(rx1, rx2);
			double maxy = max(ry1, ry2);
			v1.push_back({ rx1,ry1 }), v1.push_back({ rx2, ry2 }), v1.push_back({ minx,miny }), v1.push_back({ maxx,maxy });
			v.push_back({ { x1,y1 },{ x2,y2 } });
			v.push_back({ { rx1,ry1 },{ minx,miny } });
			v.push_back({ { rx1,ry1 },{ maxx,maxy } });
			v.push_back({ { rx2,ry2 },{ minx,miny } });
			v.push_back({ { rx2,ry2 },{ maxx,maxy } });
		}
		int ok = 0;
		for (int i = 1; i < v.size(); i++) {
			PPPP here = v[i];
			double ccw1 = ccw(v[0].first, v[0].second, here.first);
			double ccw2 = ccw(v[0].first, v[0].second, here.second);
			double ccw3 = ccw(here.first, here.second, v[0].first);
			double ccw4 = ccw(here.first, here.second, v[0].second);
			if (ccw1*ccw2 > 0 || ccw3*ccw4 > 0) continue;
			else {
				if (check(v[0].first, v[0].second, here.first, here.second)) {
					ok = 1;
					break;
				}
			}
		}
		sort(v1.begin(), v1.end());
		//안에 들어있느지 확인6
		double maxx = max(x1, x2);
		double minx = min(x1, x2);
		double maxy = max(y1, y2);
		double miny = min(y1, y2);
		if (maxx > v1[0].first && maxx<v1[2].first && maxy>v1[0].second && maxy < v1[3].second && minx>v1[0].first && minx<v1[2].first && miny>v1[0].second && miny<v1[3].second) ok = 1;

		ok == 1 ? printf("T\n") : printf("F\n");
	}

	return 0;

}