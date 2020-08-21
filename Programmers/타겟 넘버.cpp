#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
bool visited[25];
int ans,n;
void dfs(int index,int sum,int cnt,int depth){
    if(cnt==depth){
        if(sum==n) ans++;
        return;
    }
    dfs(index+1,sum+v[index],cnt+1,depth);
    dfs(index+1,sum-v[index],cnt+1,depth);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    n=target;
    for(int i=0;i<numbers.size();i++){
        v.push_back(numbers[i]);
    }
    dfs(0,0,0,numbers.size());
    return ans;
}