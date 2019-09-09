#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int t;
int wear[50];
map <string,int> m;
int main(){
	scanf("%d", &t);
	while (t--){
		int n;
		m.clear();
		scanf("%d", &n);
		int idx = 0;
		for (int i = 1; i <= n; i++)
		{
			string s1, s2;
			cin >> s1;
			cin >> s2;
			m[s2]++;
		}
		int ans = 1;
		map <string, int>::iterator it;
		for (it = m.begin(); it!=m.end(); it++) {
			ans *= (1 + it->second);
		}
		printf("%d\n",ans-1);
	}
	return 0;
}