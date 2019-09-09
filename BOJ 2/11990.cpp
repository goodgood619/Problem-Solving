#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
map<int, int> m;
map<int, int> m2;
vector<int> topseg;
vector<int> downseg;
vector<vector<int>> xx;
vector<vector<int>> yy; 
int h = 1;
int n, p, r, a, b, c, d, all, g = 1, q;
int cnt[100005];
int divx[100005];
int divy[100005];
int Maxx, Maxy;
int Min = 999999999;
void go(const vector<int> &topseg,const vector<int> &downseg,int topleftcnt,int toprightcnt,int downleftcnt,int downrightcnt,int toptotal,int downtotal,int nodenum) {
	int Min1 = topleftcnt + topseg[nodenum];
	int Min2 = toprightcnt + topseg[nodenum];
	int diff1 = abs(Min1 - toprightcnt);
	int diff2 = abs(Min2 - topleftcnt); 
	int downMin1 = downleftcnt + downseg[nodenum];
	int downMin2 = downrightcnt + downseg[nodenum];
	int downdiff1 = abs(downMin1 - downrightcnt);
	int downdiff2 = abs(downMin2 - downleftcnt); 
	int totalMax1 = max(diff1, downdiff1);
	int totalMax2 = max(diff2, downdiff2);
	if (totalMax1 <= totalMax2){
		b = Min1;
		d = toptotal - b;
		a = downMin1;
		c = downtotal - a;
	}
	else{
		d = Min2;
		b = toptotal - d;
		c = downMin2;
		a = downtotal - c;
	}
}
void update(int index, int value, bool check) {
	index += h - 1;
	if (!check) topseg[index] += value;
	else downseg[index] += value;
	while (index > 1) {
		if (!check) {
			index /= 2;
			topseg[index] = topseg[index * 2] + topseg[index * 2 + 1];
		}
		else {
			index /= 2;
			downseg[index] = downseg[index * 2] + downseg[index * 2 + 1];
		}
	}
}
void query(int nodenum, int nodeleft, int noderight, int topleftcnt, int toprightcnt,int downleftcnt,int downrightcnt,int toptotal,int downtotal){
	if (nodeleft == noderight) {
		go(topseg,downseg,topleftcnt,toprightcnt,downleftcnt,downrightcnt,toptotal,downtotal,nodenum);
		return;
	}
	int mid = (nodeleft + noderight) / 2;
	int topgoright = abs(topseg[nodenum * 2] + topleftcnt);
	int topgoleft = abs(topseg[nodenum * 2 + 1] + toprightcnt);
	int downgoright = abs(downseg[nodenum * 2] + downleftcnt);
	int downgoleft = abs(downseg[nodenum * 2 + 1] + downrightcnt);
	int leftMax = max(topgoleft, downgoleft);
	int rightMax = max(topgoright, downgoright);
	if (leftMax > rightMax) {
		query(nodenum * 2 + 1, mid + 1, noderight,topseg[nodenum * 2] + topleftcnt, toprightcnt, downseg[nodenum * 2] + downleftcnt, downrightcnt, d, c);
	}
	else if (leftMax < rightMax) {
		query(nodenum*2,nodeleft,mid,topleftcnt,topseg[nodenum*2+1]+toprightcnt,downleftcnt,downseg[nodenum*2+1]+downrightcnt,d,c);
	}
	else if (leftMax == rightMax) {
		query(nodenum * 2, nodeleft, mid, topleftcnt, topseg[nodenum * 2 + 1] + toprightcnt, downleftcnt, downseg[nodenum * 2 + 1] + downrightcnt, d, c);
	}
}
int main() {
	scanf("%d", &n);
	xx.resize(1000005);
	yy.resize(1000005);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		xx[first].push_back(second);
		m[second + 1]++;
		m2[first + 1]++;
		Maxx = max(Maxx, first);
		Maxy = max(Maxy, second);
	}
	while (h < n) h *= 2;
	topseg.resize(h * 2);
	downseg.resize(h * 2);
	for (int i = 1; i <= Maxx; i++) {
		if (xx[i].size() == 0) continue;
		else sort(xx[i].begin(), xx[i].end());
	}
	for (int i = 1; i <= Maxx; i+=2) {
		if (xx[i].size() == 0) continue;
		else {
			int tempcnt = xx[i].size();
			for (int j = 0; j < xx[i].size(); j++) {
				int next = xx[i][j];
				yy[next + 1].push_back(g);
			}
			update(g, tempcnt, false);
			g++;
		}
	}
	for (int i = 2; i <= Maxy+1; i+=2) {
		if (yy[i].size() == 0) continue;
		else sort(yy[i].begin(), yy[i].end());
	}
	for (int j = 2; j <= Maxy + 1; j += 2) {
		if (m.count(j) == 0) continue;
		else {
			all += m[j];
			cnt[p++] = all;
			divy[q++] = j;
		}
	}

	for (int j = 0; j <p; j++) {
		int ydiv = divy[j];
		for (int i = 0; i < yy[ydiv].size(); i++) {
			int index = yy[ydiv][i];
			update(index, -1, false);
			update(index, 1, true);
		}
		c = cnt[j];
		d = n - cnt[j];
		a = 0;
		b = 0;
		query(1,1,h,0,0,0,0,d,c);
		int temp = max(d, max(c, max(a, b)));
		Min = min(temp, Min);
	}
	printf("%d\n", Min);
	return 0;
}