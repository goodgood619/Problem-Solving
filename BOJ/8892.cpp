#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		string s[200];
		for (int i = 1; i <= n; i++) {
			char c[200] = {'\0',};
			scanf("%s", c);
			s[i] = c;
		}

		string ans;
		bool real = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				else {
					string temp = s[i];
					bool check = false;
					temp.append(s[j]);
					for (int i = 0,j=temp.size()-1; i < temp.size() / 2; i++,j--) {
						if (temp[i] == temp[j]) continue;
						else { check = true;
						break;
						}
					}
					if (!check){
						ans = temp;
						real = true;
						break;
					}
				}
			}
			if (real)break;
		}
		if (!real) printf("0\n");
		else cout << ans << endl;
	}
	return 0;
}