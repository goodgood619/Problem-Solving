import java.io.*;
import java.util.*;
class Solution {
        public static int solution(String s) {
        int answer = s.length();
        int len = s.length();
        for(int i=1;i<=len/2;++i) {
            StringBuilder sb = new StringBuilder();
            List<String> list =new ArrayList<>();
            for(int j=0;j<len;j+=i) {
                String substr;
                if(j+i<=len) {
                    substr = s.substring(j, j + i);
                }
                else {
                    substr = s.substring(j, len);
                }
                list.add(substr);
            }
            int same = 1;
            String here,next=null;
            for(int j=0;j<list.size()-1;j++) {
                here = list.get(j);
                next = list.get(j+1);
                if(here.equals(next)) {
                    same++;
                }
                else {
                    if(same>1) {
                        sb.append(same);
                        sb.append(here);
                        same = 1;
                    }
                    else sb.append(here);
                }
            }
            if(same>=1) {
                if(same>=2) {
                    sb.append(same);
                }
                sb.append(next);
            }
            int tempLength = sb.length();
            if(answer>tempLength) answer = tempLength;
        }
        return answer;
    }
}