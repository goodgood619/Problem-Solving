#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
using namespace std;
typedef long long ll;
int t;
vector<int> arr;
int n, m;
string team[105];
typedef pair<string, int> PP;
typedef pair<string, string> P;
map<string, int> mm;
map<int, string> mm2;
PP teamnumber[10005];
int main(){
	scanf("%d%d", &n, &m);
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		team[i] = s;
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			string ss;
			cin >> ss;
			mm.insert({ss,i});
			teamnumber[cnt].first = ss;
			teamnumber[cnt].second = i;
			cnt++;
		}
	}

	for (int i = 1; i <= m; i++) {
		string name;
		cin >> name;
		int what;
		scanf("%d", &what);
		if (what == 1) {
			map<string, int>::iterator it;
			for (it = mm.begin(); it != mm.end(); it++) {
				if (name == it->first) {
					printf("%s\n", team[it->second].c_str());
					break;
				}
			}
		}
		else {
			int idx = 0;
			for (int i = 1; i <= 100; i++) {
				if (name == team[i]) {
					idx = i;
					break;
				}
			}
			map<string, int>::iterator it;
			vector<string> temp;
			for (it = mm.begin(); it != mm.end(); it++) {
				if (idx == it->second) {
					temp.push_back(it->first);
				}
				else continue;
			}
			sort(temp.begin(), temp.end());
			int length = temp.size();
			for (int i = 0; i < length; i++) {
				printf("%s\n", temp[i].c_str());
			}
		}
	}

	return 0;
}