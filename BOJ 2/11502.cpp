#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <climits>
#include <map>
#include <functional>
#include <set>
#include <list>
#include <math.h>
using namespace std;
typedef long long ll;
int isprime[1005];
void go() {
	for (int i = 2; i <= sqrt(1000); i++){
		if (isprime[i] == 0) continue;
		for (int j = i * i; j <= 1000; j += i) {
			isprime[j] = 0;
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	for (int i = 2; i <= 1000; i++)isprime[i] = i;
	go();
	vector<int> temp;
	for (int i = 2; i <= 1000; i++) {
		if (isprime[i] != 0) temp.push_back(isprime[i]);
		else continue;
	}
	while (t--){
		int n;
		scanf("%d", &n);
		int sum = 0;
		bool ok = false;
		for (int i = 0; i < temp.size(); i++){
			for (int j = i; j < temp.size(); j++){
				for (int k = j; k < temp.size(); k++){
					if (n== temp[i] + temp[j] + temp[k]) {
						ok = true;
						printf("%d %d %d\n", temp[i], temp[j], temp[k]);
						break;
					}
				}
				if (ok) break;
			}
			if (ok) break;
		}
	}
	return 0;
}