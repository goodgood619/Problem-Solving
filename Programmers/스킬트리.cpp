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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int no=0;
    for(int i=0;i<skill_trees.size();i++){
        string temp=skill_trees[i];
        int ptr=0;
        no=0;
        vector<int> v;
        while(ptr<skill.size()){
            int ok=0;
        for(int j=0;j<temp.size();j++){
            if(skill[ptr]==temp[j]){
                v.push_back(j);
                ok=1;
                break;
                }
            }
            if(!ok) v.push_back(10000);
            ptr++;
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]){
                no=1;
                break;
            }
        }
        if(!no) answer++;
    }
    
    return answer;
}