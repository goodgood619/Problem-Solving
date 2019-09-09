#include <cstdio>
#include <algorithm>
#include <deque>
#include <string.h>
#include <cstring>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		char s[100003] = { '\0', };
		char temp[20] = { '\0', };
		int n;
		int first;
		bool check = false;
		bool real = false;
		deque <int> dq;
		scanf("%s", s);
		scanf("%d", &n);
		if (n != 0) {
			for (int i = 0; i < n; i++) {
				int num, first;
				if (i == 0) {
					scanf(" [%d", &first);
					dq.push_back(first);
					continue;
				}
				scanf(" ,%d", &num);
				dq.push_back(num);
			}
		}
		scanf("%s", temp);
		int length = strlen(s);
		int rcnt = 0;
		for (int i = 0; i < length; i++) {
			if (s[i] == 'R') rcnt++;
		}
		for (int i = 0; i < length; i++) {
			char c = s[i];
			if (c == 'R'){
				if (dq.empty()) {
					real = true;
					break;
				}
				if (!check) check = true;
				else check = false;
			}
			else if (c == 'D'){
				if (dq.empty()) {
					real = true;
					break;
				}
				if (!check) {
					dq.pop_front();
				}
				else {
					dq.pop_back();

				}
			}
		}
		if (rcnt==length && n==0) printf("[]\n");
		else if (real) printf("error\n");
		else {
			if (!check){
				printf("[");
				int Size = dq.size();
				for (int i = 0; i <Size; i++){
					if (i == Size - 1) {
						printf("%d", dq.front());
						dq.pop_front();
						break;
					}
					printf("%d,", dq.front());
					dq.pop_front();
				}
				printf("]\n");
			}
			else {
				printf("[");
				int Size = dq.size();
				for (int i = 0; i <Size; i++) {
					if (i == Size - 1) {
						printf("%d", dq.back());
						dq.pop_back();
						break;
					}
					printf("%d,", dq.back());
					dq.pop_back();
				}
				printf("]\n");
			}
		}
	}

	return 0;
}
