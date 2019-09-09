#include <stdio.h>
#include <algorithm>
using namespace std;
int t,a,b;
int idax, iday;
int idbx, idby;
int idx = 1;
int arr[301][301];
void go(int x, int y) {
	arr[x][y] = idx;
	idx++;
	y++;
	for (int i = 1; idx <=41000;)
	{
		i = 1;
		for (int j =y;j>0; j--) {
			arr[i][j] = idx;
			i++;
			idx++;
		}
		y++;
	}
}
int main() {
	scanf("%d", &t);
	go(1,1);
	while (t--) {
		scanf("%d%d", &a, &b);
		for (int i = 1; i <= 300; i++) {
			for (int j = 1; j <=300; j++)
			{
				if (arr[i][j] == a)
				{
					idax = i;
					iday = j;
					break;
				}
			}
			if (idax == i)
				break;
		}
		for (int i = 1; i <= 300; i++) {
			for (int j = 1; j <=300; j++)
			{
				if (arr[i][j] == b)
				{
					idbx = i;
					idby = j;
					break;
				}
			}
			if (idbx == i)
				break;
		}
		printf("%d\n", arr[idax + idbx][iday + idby]);
		idax = 0;
		iday = 0;
		idbx = 0;
		idby = 0;
	}
	return 0;
}