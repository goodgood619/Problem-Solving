#include <cstdio>
#include <algorithm>
using namespace std;
int total = 210;
int n, k;
bool check;
typedef pair <int, char> P;
P quest[100];
int main() {
	scanf("%d", &k);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &quest[i].first, &quest[i].second);
	}
	int sum = 0;
	while (sum<total) {
		for (int i = 0; i < n; i++){
			if (sum >= 210) break;
			if (quest[i].second == 'T') {
				k = (k + 1) %9;
				if (k == 0) k += 1;
				sum += quest[i].first;
				check = true;
			}
			else {
				check = false;
				sum += quest[i].first;
				continue;
			}
		}
	}
	if (check) printf("%d\n", k - 1);
	else printf("%d\n", k);
	return 0;
}