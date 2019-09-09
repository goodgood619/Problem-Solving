#include <cstdio>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;
int n, m,cnt,num;
int arr[55];
deque <int> dq;
int leftgo(deque <int> leftdq){
	int leftcnt = 0;
	while (1){
		if (leftdq.front() != num) {
			leftdq.push_back(leftdq.front());
			leftdq.pop_front();
			leftcnt++;
		}
		else if (leftdq.front() == num) {
			break;
		}
	}
	return leftcnt;
}
int rightgo(deque <int> rightdq) {
	int rightcnt = 0;
	while (1) {
		if (rightdq.front() != num) {
			rightdq.push_front(rightdq.back());
			rightdq.pop_back();
			rightcnt++;
		}
		else if (rightdq.front() == num) {
			break;
		}
	}
	return rightcnt;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 1; i <= m; i++){
		int lefttemp = 0;
		int righttemp = 0;
		scanf("%d",&num);
		if (dq.front() == num){
			dq.pop_front();
			continue;
		}
		else{
			lefttemp=leftgo(dq);
			righttemp=rightgo(dq);
			if (lefttemp > righttemp){
				cnt += righttemp;
				while (1) {
					if (dq.front() != num) {
						dq.push_front(dq.back());
						dq.pop_back();
					}
					else if (dq.front() == num) {
						break;
					}
				}
				dq.pop_front();
			}
			else {
				while (1) {
					if (dq.front() != num) {
						dq.push_back(dq.front());
						dq.pop_front();
					}
					else if (dq.front() == num) {
						break;
					}
				}
				dq.pop_front();
				cnt += lefttemp;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}