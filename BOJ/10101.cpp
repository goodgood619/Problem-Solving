#include <stdio.h>
#include <algorithm>
using namespace std;
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	if (a == 60 && b == 60 && c == 60) printf("Equilateral\n");
	else if (a + b + c != 180) printf("Error\n");
	else if (a + b + c == 180 && a != b && b != c && c != a) printf("Scalene\n");
	else printf("Isosceles\n");
	return 0;
}