#include <cstdio>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int arr[500002];
int n;
map <int, int> m;
typedef long long ll;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += arr[i];
	}
	sum /= n;
	printf("%.0lf\n", sum);
	sort(arr + 1, arr + n + 1);
	if (n % 2 == 0) { printf("%d\n", arr[n / 2]);}
	else printf("%d\n", arr[(n / 2) + 1]);
	int Max = 0;
	int what = 0;
	int same = 0;
	for (int i = 1; i <= n; i++) {
		m[arr[i]]++;
		if (Max < m[arr[i]]) {
			Max = m[arr[i]];
			what = arr[i];
		}
	}
	map<int, int>::iterator it;
	for (it=m.begin(); it!=m.end(); it++) {
		if (Max ==it->second) same++;
		else continue;
	}
	if (same >=2){
		bool check = false;
		for (it=m.begin(); it!=m.end(); it++) {
			if (Max ==it->second) {
				if (!check) {
					check = true;
					continue;
				}
				what = it->first;
				break;
			}
			else continue;
		}
	}
	printf("%d\n", what);
	printf("%d\n", arr[n] - arr[1]);
	return 0;
}