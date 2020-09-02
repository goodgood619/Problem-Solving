import java.util.*;
import java.io.*;
class Solution {
    public static String solution(String s) {
        if(s.isEmpty()) return s;
        StringBuilder answer=new StringBuilder();
        StringBuilder u = new StringBuilder();
        StringBuilder v = new StringBuilder();
        int left =0;
        // 균형잡힌 괄호문자열로 분리: 단순히 갯수만 맞으면 됨
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(c =='(') left++;
            else left--;
            if(left==0) {
                u.append(s, 0, i+1);
                v.append(s.substring(i+1));
                break;
            }
        }
        // u가 올바른 괄호문자열이면 v에 대해 1단계부터 다시 수행해야 하고 u는 붙이고 반환
        if(check(u.toString())) {
            answer = u.append(solution(v.toString()));
        }
        else { //아니면 ( 붙이고 v에대해 1단계 붙이고 )붙이고
            answer.append("(");
            answer.append(solution(v.toString()));
            answer.append(")");
            u.deleteCharAt(0);
            u.deleteCharAt(u.length()-1);// u의 첫번째와 마지막 문자제거 ㅇㅇ
            StringBuilder U =new StringBuilder();
            for(int j=0;j<u.length();j++) {
                char c = u.charAt(j);
                if(c =='(') U.append(')'); // 거꾸로 붙이기
                else U.append('(');
            }
            answer.append(U); // 더해서반환
        }
        return answer.toString();
    }
    public static boolean check(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(c=='(') dq.push(c);
            else {
                if(dq.isEmpty()) return false;
                else dq.pollFirst();
            }
        }
        return dq.isEmpty();
    }
}