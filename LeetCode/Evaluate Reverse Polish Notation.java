class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();
        for(int i=0;i<tokens.length;i++) {
            String s= tokens[i];
            if(s.charAt(0)>='0' && s.charAt(0)<='9') {
                int num = Integer.parseInt(s);
                stack.add(num);
            }
            else if(s.charAt(0)=='-' && s.length()>1) {
                int num = Integer.parseInt(s);
                stack.add(num);
            }
            else {
                int second = stack.pollLast();
                int first = stack.pollLast();
                if(s.equals("+")) {
                    stack.add(first+second);
                }
                if(s.equals("-")) {
                    stack.add(first-second);
                }
                if(s.equals("*")) {
                    stack.add(first*second);
                }
                if(s.equals("/")) {
                    stack.add(first/second);
                }
            }
        }
        return stack.pollLast();
    }
}