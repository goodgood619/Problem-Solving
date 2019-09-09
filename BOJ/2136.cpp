#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int, int> P;
vector<P> check;
int n,l,le,leftmax,rightmax;
vector<P> ans;
int main(){
	scanf("%d%d", &n,&l);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		if (num < 0){
			le++;
			leftmax = max(leftmax, abs(num));
		}
		else{
			rightmax = max(rightmax, l - num);
		}
		check.push_back({ abs(num),i });
	}
	sort(check.begin(), check.end());
	if (leftmax > rightmax) {
		printf("%d %d\n", check[le-1].second, leftmax);
	}
	else {
		printf("%d %d\n", check[le].second,rightmax);
	}
	return 0;
}