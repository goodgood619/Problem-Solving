#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int arr[30];
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		string s1, s2;
		cin >> s1 >> s2;
		memset(arr, 0, sizeof(arr));
		int length = s1.size();
		for (int i = 0; i < length; i++) {
			char left = s1[i];
			char right = s2[i];
			if (right >= left) arr[i] = right - left;
			else arr[i] = right + 26 - left;
		}
		printf("Distances:");
		for (int i = 0; i < length; i++) {
			printf(" %d", arr[i]);
		}
		printf("\n");
	}
	return 0;
}