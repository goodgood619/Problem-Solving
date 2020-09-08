#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.assign(2, 0);
    // 최초에 세팅을 해줘야 한다. 왜냐하면 if(diff>right-left)문장에 걸리지 않고, 맨처음의 구간부터 맨끝까지의 구간이 정답이 될수있기때문
    answer[0] = 1;
    answer[answer.size()-1] = gems.size();
    map<string, int> m;
    for (string s : gems) {
        m[s] += 1;
    }
    int left = 0, right = 0,total = m.size(),diff = gems.size()-1;
    m.clear();
    while (true) {
        // 총갯수가 만약 다 되었다 
        if (m.size() == total) {
            if (diff > right-left) {
                diff = right - left;
                answer[0] = left+1, answer[1] = right;
            }
            // 갯수가 1개면 아예 없애야한다, 그리고 앞칸으로 한칸 이동
            if (m[gems[left]] == 1) {
                m.erase(gems[left]);
                left++;
            }
            // 갯수가 여러개면 하나 지우고 옮긴다
            else {
                m[gems[left]]--;
                left++;
            }
        }
        else if (right == gems.size()) break;
        else {
            // 총갯수가 아직 안됐으니까 right를 늘린다, 그리고 각각 보석의 갯수가 필요하기때문에 map에 더한다
            m[gems[right]]++;
            right++;
        }
    }
    return answer;
}