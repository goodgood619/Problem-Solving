#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int go(int num1,char op1,int num2,char op2,int num3,int option) {
	if (option == 1) {
		if (op1 == '+') num1 += num2;
		if (op1 == '-') num1 -= num2;
		if (op1 == '*') num1 *= num2;
		if (op1 == '/') num1 /= num2;
		if (op2 == '+') num1 += num3;
		if (op2 == '-') num1 -= num3;
		if (op2 == '*') num1 *= num3;
		if (op2 == '/') num1 /= num3;
		return num1;
	}
	else {
		if (op2 == '+') num2 += num3;
		if (op2 == '-') num2 -= num3;
		if (op2 == '*') num2 *= num3;
		if (op2 == '/') num2 /= num3;
		if (op1 == '+') num1 += num2;
		if (op1 == '-') num1 -= num2;
		if (op1 == '*') num1 *= num2;
		if (op1 == '/') num1 /= num2;
		return num1;
	}
}
int main() {
	int num1, num2, num3;
	char op1, op2;
	scanf(" %d %c %d %c %d", &num1, &op1, &num2, &op2, &num3);
	vector<int> v;
	v.push_back(go(num1,op1,num2,op2,num3,1));
	v.push_back(go(num1, op1, num2, op2, num3, 0));
	sort(v.begin(),v.end());
	printf("%d\n%d\n", v[0], v[1]);
	return 0;
}