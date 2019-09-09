#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		int h, w, n;
		scanf("%d%d%d", &h, &w, &n);
		int cnt = 1;
		bool ok = false;
		for (int j = 1; j <= w; j++){
			for (int i = 1; i <= h; i++) {
				if (cnt == n){
					if (j < 10) {
						printf("%d0%d\n", i, j);
						ok = true;
						break;
					}
					else {
						printf("%d%d\n", i, j);
						ok = true;
						break;
					}
				}
				cnt++;
			}
			if (ok) break;
		}
	}
	return 0;
}