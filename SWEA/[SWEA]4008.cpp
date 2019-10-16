#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,hab,minu,gob,divide,Max;
int Min = 99999999;
int arr[14];
int cnt = 1;
void go(int index, int hab, int minu, int gob, int divide,int sum) {
	if (index > n + 1) return;
	if (hab==0 && minu==0 && gob==0 && divide==0) {
		Min = min(sum, Min);
		Max = max(Max, sum);
		return;
	}
	if (hab != 0)go(index + 1, hab - 1, minu, gob, divide,sum+arr[index]);
	if (minu != 0)go(index + 1, hab, minu - 1, gob, divide,sum-arr[index]);
	if (gob!= 0)go(index + 1, hab, minu, gob-1, divide,sum*arr[index]);
	if (divide != 0)go(index + 1, hab, minu, gob, divide-1,sum/arr[index]);
}
int main(){
	scanf("%d", &t);
	while (t--) {
		Max = -999999999;
		Min = 999999999;
		scanf("%d", &n);
		scanf("%d%d%d%d", &hab, &minu, &gob, ÷);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]); 
		go(2, hab, minu, gob, divide,arr[1]);
		printf("#%d %d\n",cnt, Max - Min);
		cnt++;
	}
	return 0;
}