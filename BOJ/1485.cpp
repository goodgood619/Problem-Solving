#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int t;
typedef pair <int, int> P;
P arr[5];
int main(){
	scanf("%d", &t);
	while (t--) {
		for (int i = 1; i <= 4; i++) {
			scanf("%d%d", &arr[i].first, &arr[i].second);
		}
		sort(arr+1, arr + 5);
		int a1 = abs(arr[1].first - arr[2].first);
		int b1 = abs(arr[1].second - arr[2].second);
		a1 *= a1;
		b1 *= b1;
		int A1 = sqrt(a1 + b1);
		int a2 = abs(arr[2].first - arr[4].first);
		int b2 = abs(arr[2].second - arr[4].second);
		a2 *= a2;
		b2 *= b2;
		int A2 = sqrt(a2 + b2);
		int a3 = abs(arr[4].first - arr[3].first);
		int b3 = abs(arr[4].second - arr[3].second);
		a3 *= a3;
		b3 *= b3;
		int A3 = sqrt(a3 + b3);
		int a4 = abs(arr[1].first - arr[3].first);
		int b4 = abs(arr[1].second - arr[3].second);
		a4 *= a4;
		b4 *= b4;
		int A4 = sqrt(a4 + b4);

		int a5 = abs(arr[1].first - arr[4].first);
		int b5 = abs(arr[1].second - arr[4].second);
		a5 *= a5;
		b5 *= b5;
		int A5 = sqrt(a5 + b5);

		int a6 = abs(arr[2].first - arr[3].first);
		int b6 = abs(arr[2].second - arr[3].second);
		a6 *= a6;
		b6 *= b6;
		int A6 = sqrt(a6 + b6);
		if (A5==A6 &&A1 == A4 && A1 == A2 && A1 == A3 && A2 == A3 && A2 == A4 && A3 == A4) printf("1\n");
		else printf("0\n");
	}
	return 0;
}