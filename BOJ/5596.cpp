#include <cstdio>
#include <algorithm>
using namespace std;
int minguk[4];
int manse[4];
int minguksum, mansesum;
int main(){
	for (int i = 0; i < 4; i++) { scanf("%d", &minguk[i]); 
	minguksum += minguk[i];
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &manse[i]);
		mansesum += manse[i];
	}
	if (minguksum >= mansesum) printf("%d\n", minguksum);
	else printf("%d\n", mansesum);
	return 0;
}