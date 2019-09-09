#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string s;
string ans[20000];
bool visited[55];
int length, k;
void go(int here, int cnt) {
	if (cnt == 2) {
		int s1index = -1;
		int s2index = -1;
		string s1, s2, s3;
		int ok = 0;
		for (int i = 0; i < length; i++) {
			if (ok == 2) break;
			if (visited[i]) {
				if (s1index == -1) {
					s1index = i;
				}
				else if (s2index == -1) {
					s2index = i;
				}
				ok++;
			}
		}
		for (int i = 0; i < length; i++) {
			if (i <= s1index) {
				s1.push_back(s[i]);
			}
			else if (i <= s2index) {
				s2.push_back(s[i]);
			}
			else s3.push_back(s[i]);
		}
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		reverse(s3.begin(), s3.end());
		s1.append(s2 + s3);
		ans[k++] = s1;
		return;
	}
	for (int i = here; i<length - 1; i++) {
		if (!visited[i]) {
			visited[i] = true;
			go(here + 1, cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> s;
	length = s.size();
	for (int i = 0; i < length - 2; i++) {
		visited[i] = true;
		go(i + 1, 1);
		visited[i] = false;
	}

	sort(ans, ans+k);
	cout << ans[0] << endl;
	return 0;
}