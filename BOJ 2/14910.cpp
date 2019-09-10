#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int n;
	int Max = -2000000;
	bool check = false;
	while (scanf("%d", &n) != EOF){
		if (Max<=n) {
			Max = n;
		}
		else {
			check = true;
			break;
		}
	}
	if (check) printf("Bad");
	else printf("Good");
	return 0;
}