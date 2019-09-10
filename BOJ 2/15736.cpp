#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
typedef long long ll;
ll n;
typedef pair<int, int> P;
int main(){
	scanf("%lld", &n);
	int cnt = 0;
	for (ll i = 1;i*i<=n;i++){
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}