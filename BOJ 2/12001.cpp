#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int, int> P;
P x[1005];
map<int, int> m;
map<int, int> m2;
int cnt[1005];
int real[1005];
int realx[1005];
int n,Maxy,Maxx,p=1,q=1,r=1;
int Min = 99999999;
int total,b;
int main(){
	scanf("%d%d", &n,&b);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &x[i].first, &x[i].second);
		m[x[i].second + 1]++;
		m2[x[i].first + 1]++;
		Maxy = max(Maxy, x[i].second);
		Maxx = max(Maxx, x[i].first);
	}
	sort(x + 1, x + n + 1);

	for (int j = 2; j <= Maxy+1; j += 2){
		if (m.count(j)==0) continue;
		else{
			real[p++] = j;
			total += m[j];
			cnt[r++]=total;
		}
	}
	for (int i = 2; i <= Maxx+1; i += 2) {
		if (m2.count(i)==0) continue;
		else realx[q++] = i;
	}

	for (int j = 1; j <r; j++){
		int divy = real[j];
		int c = cnt[j];
		int d = n - cnt[j];
		int a = 0; // 왼쪽아래갯수
		int b = 0; // 왼쪽위의 갯수
		int cur = 1;
		for (int i = 1; i <q && cur<=n; i++){
			int divx = realx[i];
			while (x[cur].first <=divx && x[cur].second <=divy){
				a++;
				c--;
				cur++;
			}
			while (x[cur].first <=divx && x[cur].second >=divy) {
				b++;
				d--;
				cur++;
			}
			int temp = 0;
			temp = max(max(max(max(temp, a),b),c),d);
			Min = min(Min, temp);
		}
	}
	printf("%d\n", Min);
	return 0;
}