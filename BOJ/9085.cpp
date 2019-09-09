#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
using namespace std;
vector<int> temp;
int n;
int arr[100005];
vector<int>dp;
int t;
int main(){
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++){
			int num;
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n",sum);
	}
	return 0;
}