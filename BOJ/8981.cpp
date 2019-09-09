#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> arr;
vector<int> ans;
int main(){
	scanf("%d",&n);
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr.push_back(num);
	}
	ans[0] = arr[0];
	int idx = arr[0];
	for (int i = 1; i < n;){
		if (idx > n-1) {
			idx = idx%n;
		}
		if (ans[idx] == 0) {
			ans[idx] = arr[i];
			idx = (idx + arr[i]) % n;
			i++;
		}
		else{
			idx = (idx + 1) % n;
			continue;
		}
	}
	printf("%d\n", n);
	for (int i = 0; i <ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}