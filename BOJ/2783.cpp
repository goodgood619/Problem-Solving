#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
typedef pair <double, double> P;
P anspo[101];
double ans = 100000000;
int main(){
	scanf("%lf%lf", &anspo[0].first, &anspo[0].second);
	scanf("%d", &n);
	for (int i = 1; i <=n; i++) {
		scanf("%lf%lf", &anspo[i].first, &anspo[i].second);
	}
	sort(anspo, anspo + n+1);

	for (int i = 0; i<=n; i++) {
		double gram = anspo[i].second;
		ans=min(anspo[i].first*1000/anspo[i].second,ans);
	}
	printf("%.2lf\n", ans);
	return 0;
}
