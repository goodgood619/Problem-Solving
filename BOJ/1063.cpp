#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int kx, ky, sx, sy, n;
int s1[10000], s2[10000];
int main() {
	scanf("%c%d %c%d %d", &s1[0], &s1[1], &s2[0], &s2[1], &n);
	kx = s1[0] - 65;
	ky = s1[1] - 1;
	sx = s2[0] - 65;
	sy = s2[1] - 1;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int dx = 0, dy = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R')dx++;
			else if (s[i] == 'L')dx--;
			else if (s[i] == 'B')dy--;
			else if (s[i] == 'T')dy++;
		}
		int kix = dx + kx, kiy = dy + ky;
		if (0 <= kix && kix < 8 && 0 <= kiy && kiy < 8) {
			if (sx == kix && sy == kiy) {
				int stx = dx + sx, sty = dy + sy;
				if (0 <= stx && stx < 8 && 0 <= sty && sty < 8) {
					kx = kix;
					ky = kiy;
					sx = stx;
					sy = sty;
				}
			}
			else {
				kx = kix;
				ky = kiy;
			}
		}
	}
	printf("%c", 65 + kx);
	printf("%d\n", ky+1);
	printf("%c", 65 + sx);
	printf("%d", sy+1);

	return 0;
}