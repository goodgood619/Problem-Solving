#include <cstdio>
#include <algorithm>
using namespace std;
int total,cnt;
int main(){
	scanf("%d", &total);
	for (int y= 1;y<=total;y++) {
		for (int x= y+2;x<=total;x++) {
			for (int z = 2;z<=total;z += 2) {
				int sum = x + y + z;
				if (sum == total) cnt++;
				else if (sum > total) break;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}