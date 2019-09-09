#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int n;
string s;
int main() {
	cin >> s;
	int length = s.size();
	int cnt = 0;
	vector<int> temp;
	int sum = 0;
	for (int i = length - 1; i >= 0; i--){
		if (cnt == 3){
			temp.push_back(sum);
			sum = 0;
			cnt = 0;
			i++;
		}
		else {
			if (i == 0){
				sum += (s[i] - '0')*pow(2, cnt);
				temp.push_back(sum);
			}
			sum += (s[i] - '0')*pow(2, cnt);
			cnt++;
		}
	}
	reverse(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++) {
		printf("%d", temp[i]);
	}
	return 0;
}