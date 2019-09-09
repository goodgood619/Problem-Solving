#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
int n;
// 가단조 A D E(A-minor)
// 다장조 C F G(c-major)
// 만약 같다면 마지막 나오는갯수로 장조나 단조를 정함
int ga,da;
string s;
int main(){
	cin >> s;
	int length = s.size();
	char last;
	if (s[0] == 'A' || s[0] == 'D' || s[0] == 'E') ga++;
	else if (s[0] == 'C' || s[0] == 'F' || s[0] == 'G') da++;
	for (int i = 1; i < length; i++) {
		if (s[i] == '|') {
			char c = s[i + 1];
			last = c;
			if (c == 'A' || c == 'D' || c == 'E') ga++;
			else if (c == 'C' || c == 'F' || c == 'G') da++;
			i++;
			continue;
		}
		else{
			last = s[i];
			continue;
		}
	}

	if (ga < da) printf("C-major\n");
	else if (ga > da) printf("A-minor\n");
	else {
		if (last == 'A' || last == 'D' || last == 'E') printf("A-minor\n");
		else if (last == 'C' || last == 'F' || last == 'G') printf("C-major\n");
	}
	return 0;
}