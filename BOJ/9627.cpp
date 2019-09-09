#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
string one[20]= { "","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
string two[10] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
string three[10] = { "","onehundred","twohundred","threehundred","fourhundred","fivehundred","sixhundred","sevenhundred","eighthundred","ninehundred" };
string make[1001] = { "" };
int n,cnt,length,idx;
string what[100];
bool check;
int leng[1001];
void go() {
	for (int i = 1; i <= 19; i++) {
		leng[i]= (one[i].size());
		make[i] = one[i];
	}
	for (int i = 20; i <= 99; i++) {
		if (i % 10 == 0) {
			leng[i]=two[i / 10].size();
			make[i] = two[i / 10];
		}
		else {
			int a = two[i / 10].size();
			int b = one[i % 10].size();
			int c = a + b;
			leng[i] = c;
			make[i] = two[i / 10] + one[i % 10];
		}
	}
	for (int i = 100; i <= 999;i++) {
		if (i % 100 == 0) {
			leng[i] = three[i / 100].size();
			make[i] = three[i / 100];
		}
		else if (i%100>=1 && i%100<=19){
			int a = three[i / 100].size();
			int b = one[i % 100].size();
			int c = a + b;
			leng[i] = c;
			make[i] = three[i / 100] + one[i % 100];
		}
		else if (i % 10 == 0) {
			int a = three[i / 100].size();
			int b = two[i / 10 % 10].size();
			int c = a + b;
			leng[i] = c;
			make[i] = three[i / 100] + two[i / 10 % 10];
		}
		else {
			int a = three[i / 100].size();
			int b = two[i / 10 % 10].size();
			int c = one[i%10].size();
			int d = a + b + c;
			leng[i] = d;
			make[i] = three[i / 100] + two[i / 10 % 10] + one[i % 10];
		}
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> what[i];
		if (what[i] =="$") {
			idx = i;
			continue;
		}
		else {
			length = what[i].size();
			cnt += length;
		}
	}
	go();
	for (int i = 1; i <= 999; i++) {
		if (cnt+ leng[i] == i){
			what[idx] = make[i];
			break;
		}
		else continue;
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << what[i] << endl;
		else cout << what[i] << " ";
	}
	return 0;
}
