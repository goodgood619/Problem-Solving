#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	for (int i = n; i >= 1; i--){
		string s;
		int rest = n - i;
		for (; rest > 0; rest--) printf(" ");
		for (int k = 1; k <= i; k++)s.push_back('*');
		cout << s << endl;
	}
	return 0;
}