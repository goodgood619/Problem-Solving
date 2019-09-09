#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int n, m,p;
string temp;
int what[8];
int main(){
	cin >> temp;
	int length = temp.size();
	for (int i = 0; i < length; i++) {
		if (temp[i] == '1' || temp[i] == 'Q' || temp[i] == 'A' || temp[i] == 'Z') {
			what[0]++;
		}
		else if (temp[i] == '2' || temp[i] == 'W' || temp[i] == 'S' || temp[i] == 'X') {
		what[1]++;
		}
		else if (temp[i] == '3' || temp[i] == 'E' || temp[i] == 'D' || temp[i] == 'C') {
			what[2]++;
		}
		else if (temp[i] == '4' || temp[i] == 'R' || temp[i] == 'F' || temp[i] == 'V' || temp[i] == '5' || temp[i] == 'T' || temp[i] == 'G' || temp[i] == 'B') {
			what[3]++;
		}
		else if (temp[i] == '6' || temp[i] == '7' || temp[i] == 'Y' || temp[i] == 'U' || temp[i] == 'H' || temp[i] == 'J' || temp[i] == 'N' || temp[i] == 'M') {
			what[4]++;
		}
		else if (temp[i] == '8' || temp[i] == 'I' || temp[i] == 'K' || temp[i] == ',') {
			what[5] ++;
		}
		else if (temp[i] == '9' || temp[i] == 'O' || temp[i] == 'L' || temp[i] == '.') {
			what[6]++;
		}
		else what[7]++;
	}
	for (int i = 0; i < 8; i++) {
		printf("%d\n", what[i]);
	}
	return 0;
}