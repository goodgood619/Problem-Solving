#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll; 
bool checkConveyerBelt(vector<int> &conveyerVelt,int k) {
	int cnt = 0;
	for (int i = 0; i < conveyerVelt.size(); i++) {
		if (conveyerVelt[i] == 0) cnt++;
	}
	if (cnt >= k) return true;
	else return false;
}
int main() {
	
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> conveyerVelt,robotArray;
	conveyerVelt.assign(2 * n, 0);
	robotArray.assign(n, 0);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &conveyerVelt[i]);
	}
	int cnt = 1;

	while (true) {
		vector<int> tempConveyerVelt,tempRobotArray;
		tempConveyerVelt.push_back(conveyerVelt[2 * n - 1]);
		tempRobotArray = robotArray;
		for (int i = 0; i < 2 * n - 1; i++) {
			tempConveyerVelt.push_back(conveyerVelt[i]);
		}
		// robot도 벨트가 움직임에 따라 한칸씩이동함
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1) {
				tempRobotArray[i] = 0;
			}
			else {
				tempRobotArray[i+1] = tempRobotArray[i];
				if (tempRobotArray[i] == 1) {
					tempRobotArray[i] = 0;
				}
			}
		}

		// 이동(다음칸이 내구도가 있어야하고, 비어있어야하고, 현재칸에 로봇이 있어야함)
		for (int i = n - 1; i >= 0; i--) {
			if (i == n - 1) {
				if (tempRobotArray[i] == 1) {
					tempRobotArray[i] = 0;
				}
			}
			else if (tempConveyerVelt[i + 1] > 0 && tempRobotArray[i+1] == 0 && tempRobotArray[i] ==1) {
				tempRobotArray[i + 1] = 1;
				tempConveyerVelt[i + 1]--;
				tempRobotArray[i] = 0;
			}
		}

		if (tempRobotArray[0] == 0 && tempConveyerVelt[0] > 0) {
			tempRobotArray[0] = 1;
			tempConveyerVelt[0]--;
		}

		if (checkConveyerBelt(tempConveyerVelt,k)) {
			break;
		}
		cnt++;
		conveyerVelt = tempConveyerVelt;
		robotArray = tempRobotArray;

	}
	printf("%d\n", cnt);
	return 0;
}