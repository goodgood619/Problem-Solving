#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_V =  50;
vector<int> map[MAX_V+1];
typedef pair<int,int> pii;
int child_cnt[MAX_V+1]={0};
int dfs(int idx  ){
    priority_queue<int> PQ;
    for(int next:map[idx]){
      int num =  dfs(next);
        PQ.push(num);
    }
    int ret =0;
    int size = PQ.size();
    for(int i = 1; i <=size;i++){
        int num = PQ.top();PQ.pop();
        ret = max(ret,i+num);
    }
    return ret;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i =0 ; i < N ; i++){
        int num;
        scanf("%d",&num);
        if(num!=-1){
            map[num].push_back(i);
        }
    }
    printf("%d \n",dfs(0));
}