#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string Left[600];
string Right[600];
int n;
int main(){
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		else {
			int p = 0;
			int q = 0;
			int pptr = 1;
			int qptr = 1;
			if (n % 2 == 0) {
				p = n / 2;
				q = n / 2;
			}
			else {
				p = n / 2 + 1;
				q = n - p;
			}
			for (int i = 1; i <= n; i++) {
				if (i <= p){
					string s;
					cin >> s;
					Left[pptr++] = s;
				}
				else {
					string s;
					cin >> s;
					Right[qptr++] = s;
				}
			}
			bool check = false;
			int lok = 1;
			int rok = 1;
			while (1){
				if (lok == pptr && rok == qptr) break;
				if (!check){
					if (lok < pptr){
						cout << Left[lok] << endl;
						lok++;
					}
					check = true;
				}
				else{
					if (rok < qptr) {
						cout << Right[rok] << endl;
						rok++;
					}
					check = false;
				}
			}

		}
	}
	return 0;
}