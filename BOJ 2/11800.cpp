#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
string same[7] = { "","Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh" };
string notsame[7] = { "","Yakk","Doh","Seh","Ghar","Bang","Sheesh" };
int main(){
	int t;
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a<b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if (a == b){
			printf("Case %d: %s\n", Case,same[a].c_str());
			Case++;
			continue;
		}
		else {
			if (a == 6 && b == 5) {
				printf("Case %d: %s %s\n", Case, "Sheesh", "Beesh");
				Case++;
				continue;
			}
			else {
				printf("Case %d: %s %s\n",Case, notsame[a].c_str(), notsame[b].c_str());
				Case++;
			}
		}
	}
	return 0;
}