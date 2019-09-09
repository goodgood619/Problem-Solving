#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
int t;
string s;
int main(){
	scanf("%d", &t);
	t += 1;
	bool check = false;
	while (t--){
		getline(cin,s);
		int first = 0;
		if (!check) {
			check = true;
			continue;
		}
		printf("god");
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (first == 0) {
					first++;
					continue;
				}
				else {
					continue;
				}
			}
			else{
				if (first == 0) continue;
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}