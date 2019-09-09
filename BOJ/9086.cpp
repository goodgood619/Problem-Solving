
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
		string s;
		cin >> s;
		printf("%c%c\n", s[0], s[s.size() - 1]);
	}
	return 0;
}