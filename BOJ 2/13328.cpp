#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <functional>
#include <set>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;

typedef pair<int, int> Pair;

int d, t;

struct mat {
	int m[50][50] = {};
	mat operator*(mat X) {
		mat r;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < d; j++)
				for (int k = 0; k < d; k++)
					r.m[i][j] = (r.m[i][j] + m[i][k] * X.m[k][j]) % 31991;
		return r;
	}
} m1, m2;

int main(void) {
	scanf("%d %d", &d, &t);
	for (int i = 0; i < d; i++) {
		m1.m[i][i] = m2.m[0][i] = 1;
		if (i) m2.m[i][i - 1] = 1;
	}
	while (t) {
		if (t & 1) m1 = m1 * m2;
		m2 = m2 * m2;
		t >>= 1;
	}
	printf("%d\n", m1.m[0][0]);
}