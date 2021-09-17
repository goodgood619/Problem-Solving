#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n,q;
    scanf("%d",&n);
    vector<int> v,mistake;
    v.assign(n+1,0);
    mistake.assign(n+1,0);
    for(int i=1;i<=n;i++) {
        scanf("%d",&v[i]);
    }

    for(int i=1;i<n;i++) {
        if(v[i+1]-v[i]>=0) {
            mistake[i+1] = mistake[i];
        }
        else {
            mistake[i+1] += mistake[i];
            mistake[i+1]++;
        }
    }


    scanf(" %d",&q);

    for(int i=0;i<q;i++) {
        int start,end;
        scanf(" %d%d",&start,&end);
        printf("%d\n",mistake[end]-mistake[start]);
    }

    return 0;
}
