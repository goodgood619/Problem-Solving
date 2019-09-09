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
		string temp = s;
		int length = s.size();
		bool check = false;
		while (next_permutation(s.begin(),s.end())){
			check = true;
			printf("%s\n", s.c_str());
			break;
		}
		if (!check) printf("%s\n", temp.c_str());
	}
	return 0;
}