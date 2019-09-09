#include <cstdio>
#include <algorithm>
#include <list>
#include <string.h>
using namespace std;
int n;
int main(){
	char c[100005] = { '\0', };
	scanf("%s", c);
	int length = strlen(c);
	scanf("%d", &n);
	list<char> li;
	for (int i = 0; i < length; i++) {
		li.push_back(c[i]);
	}
	list <char>::iterator it= li.end();
	list <char>::iterator it2;
	for (int i = 1; i <= n; i++){
		char w;
		scanf(" %c", &w);
		if (w == 'P') {
			char insert;
			scanf(" %c", &insert);
			li.insert(it, insert);
		}
		else if (w == 'L'){
			if (it == li.begin()) continue;
			it--;
		}
		else if (w == 'D') {
			if (it == li.end()) continue;
			it++;
		}
		else if (w == 'B'){
			if (it != li.begin()){
				//문제에서 실제 커서의 위치가 변동되지는 않으니까, 왼쪽에 있는걸 지우기만 하면 되는 용도 라는것
				it2 = it;
				it2--;
				li.erase(it2);
			}
		}
	}
	list<char>::iterator ans;
	for (ans = li.begin(); ans != li.end(); ans++) {
		printf("%c",*ans);
	}
	return 0;
}