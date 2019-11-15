#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>> s;
        int check = 0,idx1 = -1,idx2 = -1;
        for(int i= 0,j = s.size()-1;i<=j;i++,j--){
            if(s[i] != s[j]){
                    idx1 =i, idx2 = j;
                    check = 1;
                    break;
            }
        }
        if(check == 0) printf("0\n");
        else {
            string t = s;
            int no = 0;
            t.erase(t.begin() + idx1);
            for(int i= 0,j = t.size()-1;i<=j;i++,j--){
                if(t[i] != t[j]) {
                    no = 1;
                    break;
                }
            }
            if(!no){
                printf("1\n");
            }
            else {
               int tno = 0;
                string t2 = s;
                t2.erase(t2.begin()+idx2);
                for(int i= 0,j = t2.size()-1;i<=j;i++,j--){
                    if(t2[i] != t2[j]) {
                        tno = 1;
                        break;
                    }
                }
                if(!tno) printf("1\n");
                else printf("2\n");
            }
        }
    }
    return 0;
}