#include <stdio.h>

#include <algorithm>

using namespace std;

int n, k, cnt, Cnt;

int x = 1;

int y = 1;

bool flag;

typedef pair <int, int> P;

P spot[4] = { { 1,0 },{ 1,2 },{ 2,2 },{ 2,1 } };

P xy;

void go(int index, int n, int row) {

	if (n<cnt) {

		Cnt = n;

		go(index << 2, n + 1, row / 2);

	}

	for (int i = 1; i <= Cnt; i++)

		index = index >> 2;

	int space = (index)& 3;

	xy = spot[index & 3];

	if (space == 0) {

		int temp = x;

		x = y;

		y = temp;

		flag = true;

		return;

	}

	else if (space == 1) {

		y = y + row;

		flag = true;

		return;

	}

	else if (space == 2) {

		x += row;

		y += row;

		flag = true;

		return;

	}

	else if (space == 3) {

		if (!flag) {

			int temp = xy.second;

			int temp2 = xy.first;

			x = temp2;

			y = temp;

			flag = true;

			return;

		}

		int temp = y;

		int temp2 = x;

		x = (row*2+1)-temp;

		y = (row+1)-temp2;

		//x += row;

		return;

	}

}

int main() {

	scanf("%d%d", &n, &k);

	while (n != 1) {

		n = n / 2;

		if (n != 1)

			cnt++;

	}

	cnt++;

	int row = 1;

	for (int i = 1; i < cnt; i++) row *= 2;

	go(k - 1, 1, row);

	printf("%d %d\n", x, y);

	return 0;

}