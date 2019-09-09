#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int a, b, c, d,p;
// x사 기본요금 a
// y사 기본요금 b
// y사 사용량 c리터이하 기본요금
// c리터 초과의 경우 1리터당 d원
// 총 사용량 p리터
int main(){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&p);
	int a1 = p * a;
	int a2 = 0;
	if (p > c) a2 = b + d * (p - c);
	else a2 = b;
	if (a1 > a2) printf("%d\n", a2);
	else printf("%d\n", a1);
	return 0;
}