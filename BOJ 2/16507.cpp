#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(vector<vector<int>> &fenwick,int i,int j,int value){
    while(i<fenwick.size()){
        int temp = j;
        while(temp < fenwick[i].size()){
            fenwick[i][temp] += value;
            temp += (temp & -temp);
        }
        i += (i & -i);
    }
}
int query(vector<vector<int>> &fenwick, int i,int j){
    int sum = 0;
    while(i > 0) {
        int temp = j;
        while(temp > 0){
            sum += fenwick[i][temp];
            temp -= (temp & -temp);
        }
        i -= (i & -i);
    }
    return sum;
}
int main() {
    int r,c,q;
    scanf("%d%d%d",&r,&c,&q);
    vector<vector<int>> arr,fenwick;
    arr.assign(r+1,vector<int>(c+1,0));
    fenwick.assign(r+1,vector<int>(c+1,0));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %d",&arr[i][j]);
            update(fenwick,i,j,arr[i][j]);
        }
    }

    for(int i=0;i<q;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int sum = query(fenwick,x2,y2)-query(fenwick,x1-1,y2)-query(fenwick,x2,y1-1)+query(fenwick,x1-1,y1-1);
        printf("%d\n",sum /((x2-x1+1)*(y2-y1+1)));
    }
    return 0;
}