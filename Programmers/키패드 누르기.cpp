#include <string>
#include <vector>

using namespace std;

struct p {
    int dist;
    int px, py;
};
p check(int lx,int px,int ly,int py,int rx,int ry,string hand) {
    int left = abs(lx - px) + abs(ly - py);
    int right = abs(rx - px) + abs(ry - py);
    if (left < right) {
        return p{left,lx,ly};
    }
    else if (left > right) {
        return p{ right,rx,ry };
    }
    else {
        if (hand == "left") return p{ left,lx,ly };
        else return p{ right,rx,ry };
    }
}
string solution(vector<int> numbers, string hand) {
    int lx = 3, ly = 0,rx = 3,ry = 2;
    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        int px = -1, py = -1;
        if (num == 0) {
            px = 3, py = 1;
            p ret = check(lx,px,ly,py,rx,ry,hand);
            if (ret.px == lx && ret.py == ly) {
                lx = px, ly = py;
                answer.push_back('L');
            }
            else {
                rx = px, ry = py;
                answer.push_back('R');
            }
        }
        else if (num == 1 || num == 4 || num == 7) {
            num--;
            px = num / 3, py = num % 3;
            answer.push_back('L');
            lx = px, ly = py;
        }
        else if (num == 3 || num == 6 || num == 9) {
            num--;
            px = num / 3, py = num % 3;
            answer.push_back('R');
            rx = px, ry = py;
        }
        else {
            num--;
            px = num / 3, py = num % 3;
            p ret = check(lx, px, ly, py, rx, ry, hand);
            if (ret.px == lx && ret.py == ly) {
                lx = px, ly = py;
                answer.push_back('L');
            }
            else {
                rx = px, ry = py;
                answer.push_back('R');
            }
        }
    }
    return answer;
}