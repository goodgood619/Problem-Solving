#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    while(true) {
        double weight;
        scanf("%lf",&weight);
        if(weight == -1) break;
        printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n",weight,weight*0.167);
    }
    return 0;
}