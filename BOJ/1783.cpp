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
#define limit LLONG_MAX
int main(){
	// 가로가 m 세로가 n
	scanf("%d%d", &n, &m);
	if (n >= 3 && m >= 7) {
		printf("%d\n", m - 2);
	}
	else if(n==1 || m==1){
		printf("1\n");
	}
	else if(n==2){
		printf("%d\n", min(4, (m + 1) / 2));
	}
	else if (n > 2 && m < 7) {
		printf("%d\n", min(m, 4));
	}
	return 0;
}