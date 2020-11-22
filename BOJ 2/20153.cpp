#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> inputArray;
	long long answer = 0;
	long long realanswer = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		inputArray.push_back(num);
		answer = answer ^ num;
	}
	realanswer = max(realanswer, answer);
	for (int i = 0; i < inputArray.size(); i++) {
		long long temp = answer;
		temp ^= inputArray[i];
		realanswer = max(realanswer, temp);
	}
	printf("%lld%lld\n", realanswer, realanswer);
	return 0;
}