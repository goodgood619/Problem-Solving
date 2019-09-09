#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair <int, int> P;
P anspo[1001];
int n;
double limitx=100000000;
double limity = 0;
double ans;
int idx;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d%d", &anspo[i].first, &anspo[i].second); }
	bool check = false;
	for (int i = 1; i < n; i++) {
		double a= anspo[i].first;
		double b = anspo[i].second;
		double c = anspo[i + 1].first;
		double d = anspo[i + 1].second;
		if (b - d == 0) {
			if (c>a) {
				check = true;
				break;
			}
		}
		else {
			double k = (a-c) / (d-b);
			if (k<=limitx && d-b>0 &&a>c) {
				limitx= k;
			}
			else if (k>=limity && b - d>0 && a>c) {
				limity = k;
			}
			else if (k<=limitx && d-b>0 && c>a){
				limitx = k;
			}
			else if (k>=limity && b - d>0 && c>a) {
				limity = k;
			}
			if (limitx < limity) {
				check = true;
				break;
			}
		}
	}

	if (limity>limitx || check) printf("-1\n");
	else {
		for (int i = 1; i <= n; i++) {
			if (anspo[i].second == 0) continue;
			else {
				idx+=anspo[i].second;
			}
		}
		printf("%.11lf\n", idx*limity);
	}
	return 0;
}