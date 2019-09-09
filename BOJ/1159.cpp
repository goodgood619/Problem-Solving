#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
string player[151];
char c[31];
int n,k;
int cnt[27];
char ans[26];
bool check;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", c);
		player[i] = c;
	}
	for (int i = 0; i < n; i++) {
		char c = player[i][0];
		cnt[c - 97]++;
	}
	for (int i = 0; i <26; i++) {
		if (cnt[i] >= 5){
			ans[k] = i + 97;
			k++;
			check = true;
		}
	}
	if (check) printf("%s\n", ans);
	else printf("PREDAJA\n");
	return 0;
}