#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
using namespace std;
int n;
map<string, int> m;
int main(){
	scanf("%d", &n);
	vector<int> origin;
	vector<int> output;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		m[s] = i;
		origin.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		output.push_back(m[s]);
	}
	int cnt = 0;
	for (int i = 0; i < output.size(); i++) {
		int here = output[i];
		int what = origin[0];
		if (here == what){
			origin.erase(origin.begin());
			continue;
		}
		else {
			for (int j = 0; j < origin.size(); j++) {
				if (here != origin[j]) continue;
				else {
					origin.erase(origin.begin() + j);
					break;
				}
 			}
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}