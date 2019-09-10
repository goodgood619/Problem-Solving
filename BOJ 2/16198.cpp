#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<int> v;
int n,Max;
void go(int left, int right, int sum,vector<int> v,bool check){
	if (v.size() == 2){
		Max = max(Max, sum);
		return;
	}
	vector<int> temp;
	temp = v;
	int now;
	for (int i = 1; i < v.size() - 1; i++){
		now = v[i];
		int temp = v[i - 1] * v[i + 1];
		v.erase(v.begin() + i);
		go(left, right, sum + temp, v, true);
		v.insert(v.begin() + i, now);
	}
	return;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {	
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	go(1, n - 2, 0, v, false);
	printf("%d\n", Max);
	return 0;
}