class Solution {
    public boolean isValid(String s) {
        Deque<Character> q = new ArrayDeque<>();
        boolean no = false;
        for(int i=0;i<s.length();i++) {
            char c= s.charAt(i);
            if(c=='(' || c=='{' || c=='[') {
                q.add(c);
            }
            else {
                if(q.isEmpty()) {
                    no = true;
                    break;
                }
                char top = q.pollLast();
                if(top=='(' && c==')' || top=='{' && c=='}' || top=='[' && c==']') {
                    continue;
                }
                else {
                    no= true;
                    break;
                }
            }
        }
        
        if(!no && q.isEmpty()) return true;
        return false;
    }
}