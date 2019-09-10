#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int k;
int isprime[8000005];
vector<int> temp;
void go() {

	for (int i = 2; i <= sqrt(8000000); i++){
		if (isprime[i] == 0) continue;
		for (int j = i*i; j <= 8000000; j += i) {
			isprime[j] = 0;
		}
	}
}
int main(){
	for (int i = 2; i <= 8000000; i++)isprime[i] = i;
	go();
	for (int i = 2; i <= 8000000; i++) {
		if (isprime[i] != 0) temp.push_back(isprime[i]);
		else continue;
	}
	scanf("%d", &k);
	printf("%d\n", temp[k - 1]);
	return 0;
}