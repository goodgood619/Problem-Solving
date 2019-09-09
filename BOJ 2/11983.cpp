#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
ll dp[1005][1005];
int n, m,fx,fy,bx,by,fsize,bsize;
typedef pair<ll, ll> P;
P fmove[1005];
P bmove[1005];
#define INF 1000000000000000
ll go(int ff, int bb){
	ll aa = fmove[ff].first - bmove[bb].first;
	ll cc = fmove[ff].second - bmove[bb].second;
	ll dist = aa * aa + cc * cc;
	if (ff== fsize && bb == bsize){
		return dist;
	}
	ll &ret = dp[ff][bb];
	if (ret != -1) return ret;
	if (ff == 0 && bb == 0) dist = 0;
	ret = INF;
	if (ff+1<= fsize){
		ret = min(ret,dist+go(ff + 1, bb));
	}
	if (bb+1 <= bsize){
		ret = min(ret, dist+go(ff, bb + 1));
	}
	if (ff+1 <= fsize && bb+1<= bsize){
		ret = min(ret, dist+go(ff + 1, bb + 1));
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d", &fx, &fy);
	scanf("%d%d", &bx, &by);
	fmove[0].first = fx;
	fmove[0].second = fy;
	for (int i = 1; i <= n; i++){
		char c;
		scanf(" %c", &c);
		if (c == 'N') {
			fy+= 1;
		}
		else if (c == 'S') {
			fy-= 1;
		}
		else if (c == 'W') {
			fx-= 1;
		}
		else if (c == 'E') {
			fx += 1;
		}
		fmove[i].first = fx;
		fmove[i].second = fy;
	}
	bmove[0].first = bx;
	bmove[0].second = by;
	for (int i = 1; i <= m; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'N') {
			by+= 1;
		}
		else if (c == 'S') {
			by-= 1;
		}
		else if (c == 'W') {
			bx-= 1;
		}
		else if (c == 'E') {
			bx+= 1;
		}
		bmove[i].first = bx;
		bmove[i].second = by;
	}
	fsize = n;
	bsize = m;
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0,0));
	return 0;
}