#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll dp[40000];
int n,k;
int grade[7][2];
int main() {
	scanf("%d%d", &n, &k);
	vector<int> temp;
	for (int i = 1; i <= n; i++) {
		int what, g;
		scanf("%d%d", &what, &g);
		grade[g][what]++;
	}
	int total = 0;
	int sum = 0;
	for (int i = 1; i <= 2; i++){
		for (int j = 0; j < 2; j++) {
			sum += grade[i][j];
		}
	}
	if (sum%k == 0) {
		total += (sum / k);
	}
	else total = total + (sum / k) + 1;
	temp.push_back(grade[3][0] + grade[4][0]);
	temp.push_back(grade[3][1] + grade[4][1]);
	temp.push_back(grade[5][0] + grade[6][0]);
	temp.push_back(grade[5][1] + grade[6][1]);
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] % k == 0) {
			total += (temp[i] / k);
		}
		else total = total + (temp[i] / k) + 1;
	}
	printf("%d\n", total);
	return 0;
}