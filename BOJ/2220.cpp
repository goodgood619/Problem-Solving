#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
typedef long long ll;
vector<int> temp;
void swap(vector<int> &temp,int a,int b){
	int temp2 = temp[a];
	temp[a] = temp[b];
	temp[b] = temp2;
}
int main(){
	int n;
	scanf("%d", &n);
	temp.resize(n + 1);
	temp[1] = 1;
	for (int i = 2; i <= n; i++) {
		temp[i] = i;
		swap(temp, i, i - 1);
		int next = i - 1;
		while (next != 1){
			swap(temp, next, next / 2);
			next /= 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", temp[i]);
	}
	return 0;
}