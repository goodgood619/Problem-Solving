#include <cstdio>
#include <algorithm>
int v,a,s,b,n, m,N[51],M[51][51];
int main() {
	// 00 01
	// 10 11
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a);
			M[i][j] = a;
		}
	}
	if (n - m > 0) s = m;
	else s = n;
	// s=min(m,n);	
	//bool check = false; // bool형은 false,true !-> not
	//if (!check) check = true;
	//else check = false;
	for (int k = s-1; k>=0; k--) {
		for (int i = 0; i < n; i++) {		
			for (int j = 0; j < m; j++) {
				if (i+k<n && j+k<m){
					if (M[i][j] == M[i][j + k] && M[i][j] == M[i + k][j] && M[i][j] == M[i + k][j + k]) {
						printf("%d\n", (k + 1)*(k + 1));
						return 0;
					}

				}
			}
		}
	}
	return 0;
}

