#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
int a, b;
vector<int> ans;
int main(){
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			ans.push_back(i);
		}
	}

	int sum = 0;
	for (int i = a-1; i <b; i++) {
		sum += ans[i];
	}
	printf("%d\n", sum);
	return 0;
}