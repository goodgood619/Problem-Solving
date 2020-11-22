#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	char input[1000001] = { '\0' };
	scanf("%s", input);
	string s = input;
	vector<int> alphaCount = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };
	int curidx = 0, total = 0;
	for (int i = 0; i < s.size(); i += 2) {
		curidx = i;
		if (i + 1 < s.size()) {
			total += alphaCount[s[i] - 'A'];
			total += alphaCount[s[i + 1] - 'A'];
		}
		else {
			total += alphaCount[s[i] - 'A'];
		}
		total %= 10;
	}
	printf("%s\n", total % 2 == 1 ? "I'm a winner!" : "You're the winner?");
	s.clear();
	alphaCount.clear();
	return 0;
}