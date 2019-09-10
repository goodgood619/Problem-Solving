#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int n, m;
string temp;
int main(){
	scanf("%d%d", &n, &m);
	cin >> temp;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int length = s.size();
		int p = temp.size();
		int ptr = 0;
		for (int j = 0; j < length;){
			if (temp[ptr] == s[j])
			{
				ptr++;
				j++;
			}
			else j++;
		}
		if (ptr == p) { printf("true\n");
		}
		else printf("false\n");
	}
	return 0;
}