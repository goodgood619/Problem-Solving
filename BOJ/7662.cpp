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
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		map<int, int> m;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			char c;
			scanf(" %c", &c);
			if (c == 'I'){
				int num;
				scanf("%d", &num);
				m[num]++;
			}
			else if (c == 'D'){
				int num;
				scanf("%d", &num);
				if (m.size() == 0) continue;
				if (num < 0){
					if(m.begin()->second==1)
					m.erase(m.begin());
					else m.begin()->second--;
				}
				else if (num > 0){
					if(m.rbegin()->second==1)
					m.erase(m.rbegin()->first);
					else m.rbegin()->second--;
				}
			}
		}
		if (m.size() == 0) printf("EMPTY\n");
		else printf("%d %d\n", m.rbegin()->first, m.begin()->first);
	}
	return 0;
}