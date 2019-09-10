#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int n, m;
typedef long long ll;
map<int, int> mm;
vector<int> v;
string a, b;
ll r;
#define limit LLONG_MAX
int main(){
	cin >> a >> b;
	scanf("%lld", &r);
	int Min=min(a.size(), b.size());
	if (a == "0" || b == "0") {
		printf("0\n");
	}
	else {
		if (a.size()>=20 || b.size() >= 20) printf("overflow\n");
		else {
			string lt = to_string(limit);
			ll x=0, y=0;
			int check1 = 0, check2 = 0;
			if (a.size() < lt.size()) {
				x = stoll(a);
				check1 = 1;
			}
			if (b.size() < lt.size()) {
				y = stoll(b);
				check2 = 1;
			}
			if (a.size() == lt.size() && !check1){
				bool no1 = false;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] <=lt[i]) {
						continue;
					}
					else {
						no1 = true;
						break;
					}
				}
				if (no1) {
					check1 = 1;
				}
				else {
					x = stoll(a);
				}
			}
			if (b.size() == lt.size() && !check2) {
				bool no2 = false;
				for (int i = 0; i < b.size(); i++) {
					if (b[i] <= lt[i]) {
						continue;
					}
					else {
						no2 = true;
						break;
					}
				}
				if (no2) {
					check2 = 1;
				}
				else {
					y = stoll(b);
				}
			}
			// 둘중에 하나라도 ll 넘어가면 끝
			if (x == 0 && y == 0) printf("overflow\n"); // 둘다 넘어갈때
			else if (x != 0 && y == 0) { // b만 넘어가고 a는 안넘어갈때
				printf("overflow\n");
			}
			else if (x == 0 && y != 0) { // a는 넘어가고 b는 안넘어갈때
				printf("overflow\n");
			}
			else { //둘다 안넘어갈때
				ll mod = r / x;
				if (y > mod) printf("overflow\n");
				else printf("%lld\n", x*y);
			}

		}
	}
	return 0;
}