import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        Deque<Character> stack = new ArrayDeque<>();
        for(int i=0;i<s.length();i++) {
            char value = s.charAt(i);
            if(value == '(') {
                stack.addLast(value);
            }
            else if(value ==')') {
                if(stack.isEmpty()) {
                    return false;
                }
                stack.pollLast();
            }
        }
        if(stack.isEmpty()) return true;
        return false;
    }
}