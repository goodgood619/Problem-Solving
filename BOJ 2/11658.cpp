#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(vector<vector<int>> &fenwick,int i,int j,int value){
    int temp;
    while(i<=fenwick.size()) {
        temp = j;
        while (temp <= fenwick[i].size()) {
            fenwick[i][temp] += value;
            temp += (temp & -temp);
        }
        i += (i & -i);
    }
}
int query(vector<vector<int>> &fenwick,int i,int j){
    int sum = 0,temp;
    while(i>0) {
        temp = j;
        while (temp > 0) {
            sum += fenwick[i][temp];
            temp -= (temp & -temp);
        }
        i -= (i& -i);
    }
    return sum;
}
int main() {
    vector<vector<int>> arr;
    vector<vector<int>> fenwick;
    int n,m;
    scanf("%d%d",&n,&m);
    fenwick.assign(n+1,vector<int>(n+1,0));
    arr.assign(n+1,vector<int>(n+1,0));

    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %d",&arr[i][j]);
            update(fenwick,i,j,arr[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        int a;
        scanf("%d",&a);
        if(a == 0){
            int x,y,value;
            scanf("%d%d%d",&x,&y,&value);
            int diff = value - arr[x][y];
            arr[x][y] = value;
            update(fenwick,x,y,diff);
        }
        else {
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            printf("%d\n",query(fenwick,x2,y2)-query(fenwick,x1-1,y2)-query(fenwick,x2,y1-1)+query(fenwick,x1-1,y1-1));
        }
    }
    return 0;
}