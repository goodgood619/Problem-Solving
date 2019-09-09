#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
typedef pair <int, string> P;
int n;
string temp;
P anspo[20003];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		int length = s.size();
		anspo[i].first = length;
		anspo[i].second=s;
	}

	sort(anspo + 1, anspo + n + 1);
	temp=anspo[1].second;
	cout << temp << endl;
	for (int i = 2; i <= n; i++){
		if (temp==anspo[i].second) continue;
		else {
			cout << anspo[i].second << endl;
			temp=anspo[i].second;
		}
	}
	return 0;
}