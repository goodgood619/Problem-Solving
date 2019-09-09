#include <cstdio>
#include <algorithm>
using namespace std;
long long barn[200005];
bool visited[200005];
int n,circlecnt,c;
typedef long long ll;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &barn[i]);
	}
	for (int i = 1; i <= n; i++) {
		barn[i + n] = barn[i];
	}
	c = barn[1];
	int ptr = 1;
	int start = 1;
	while (circlecnt<=2*n) {
		circlecnt++;
		if(c>0) c--;
		ptr++;
		if (ptr > n) ptr = 1;
		if (circlecnt > n) {
			if (c == 0) {
				start = ptr;
				break;
			}
		}
		c = barn[ptr] + c;
	}
	 // i2의 총합: 시그마 (n)*(n+1)*(2n+1)/6;
	long long jump = 0;
	long long total = 0;
	for (int i = start; i <start + n; i++){
		long long cowcnt = barn[i];
		if (cowcnt == 0) continue;
		// 건너뛰어야하는갯수
		int startptr = i;
		long long p = cowcnt;
		jump = 0;
		for (;cowcnt!=0;){
			if(!visited[startptr]){
				visited[startptr] = true;
				startptr++;
				cowcnt--;
			}
			else if (visited[startptr]){
				startptr++;
				jump++;
			}
		}
		long long range = jump - 1 + p;
		long long total1=(range)*(range + 1)*(2 * range + 1) / 6;
		long long total2 = (jump - 1)*(jump)*(2 * jump - 1) / 6;
		total += total1 - total2;
	}
	printf("%lld\n", total);


	return 0;

}