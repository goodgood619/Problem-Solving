#include<stdio.h>
int check[27];
int main(void) {
	//EOF-> End Of File
	// ~ -> not , ^ -> not
	// 'A' -> 65
	// 'a' -> 32+65-> 97
	char c;
	while (scanf("%c", &c)!=EOF) {
		// 97-> 1. 98-> 2
		check[c - 'a' + 1]++;
	}
	int Max = 0;
	for (int i = 1; i <= 26; i++) {
		if (Max < check[i]) {
			Max = check[i];
		}
	}
	for (int i = 1; i <= 26; i++) {
		if (Max == check[i]) printf("%c", i + 96);
	}
	return 0;
}