#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
P anspo[15];
int main(){
	for (int i = 1; i <= 9; i++){
		int num;
		scanf("%d", &num); 
		anspo[i].first = num;
		anspo[i].second = i;
	}
	sort(anspo + 1, anspo + 10);
	printf("%d\n%d\n", anspo[9].first, anspo[9].second);
	return 0;
}