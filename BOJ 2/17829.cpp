#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
void go(int **board,int n){
    if(n==1){
        printf("%d\n",board[0][0]);
        return;
    }
    int **tempboard = new int*[n];
    for(int i = 0; i<n;i++) tempboard[i] = new int[n];
    int sx =0;
    for(int i = 0 ;i<n;i+=2) {
            int sy=0;
        for(int j = 0;j<n;j+=2){
                vector<int> v;
            for(int p = i;p<i+2;p++){
                for(int k=j;k<j+2;k++){
                    v.push_back(board[p][k]);
                }
            }
            sort(v.begin(),v.end());
            tempboard[sx][sy++] = v[2];
        }
        sx++;
    }
    go(tempboard,n/2);
    for(int i = 0; i<n;i++) delete[] tempboard[i];
    delete[] tempboard;
}
int main() {
	int n;
	scanf("%d",&n);
	int **board = new int*[n];
	for(int i=0;i<n;i++) board[i] = new int[n];
	for(int i=0 ;i<n;i++){
        for(int j =0 ;j<n ;j++){
            scanf(" %d",&board[i][j]);
        }
	}
	go(board,n);
	for(int i = 0; i<n ;i++) delete[] board[i];
	delete[] board;
 	return 0;
}