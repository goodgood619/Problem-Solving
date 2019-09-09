#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int n,leftcow,rightcow;
// 1:가위 2: 바위 3:보(1,3 -> 1이 win,2,3-> 3이 win, 1,2-> 2가 win)
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (first == second) continue;
		else if (first == 1 && second == 3) leftcow++;
		else if (first == 2 && second == 3) rightcow++;
		else if (first == 1 && second == 2) rightcow++;
		else if (first == 3 && second == 1) rightcow++;
		else if (first == 3 && second == 2) leftcow++;
		else if (first == 2 && second == 1) leftcow++;
	}
	printf("%d\n", max(leftcow, rightcow));
	return 0;
}