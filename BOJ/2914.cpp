#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
double a, b;
int main(){
	scanf("%lf%lf", &a, &b);
	int ahr = (int)a*(b - 1);
	printf("%d\n", ahr + 1);
	return 0;
}