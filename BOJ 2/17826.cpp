#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };


int main()
{
    int *arr = new int[50];
    for(int i=0 ;i<50;i++){
        scanf("%d",&arr[i]);
    }
    int num,idx=-1;
    scanf("%d",&num);
    for(int i=0 ;i<50;i++){
        if(num == arr[i]){
            idx = i+1;
            break;
        }
    }

    if(idx>=1 && idx<=5) printf("A+");
    else if(idx>=6 && idx<=15) printf("A0");
    else if(idx>=16 && idx<=30) printf("B+");
    else if(idx>=31 && idx<=35) printf("B0");
    else if(idx>=36 &&idx<=45) printf("C+");
    else if(idx>=46 && idx<=48) printf("C0");
    else printf("F");
    return 0;
}