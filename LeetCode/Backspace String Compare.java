class Solution {
    public boolean backspaceCompare(String s, String t) {
        Deque<Character> d1 = new ArrayDeque<>();
        Deque<Character> d2 = new ArrayDeque<>();
        for(int i=0;i<s.length();i++) {
            char c= s.charAt(i);
            if(c=='#') {
                if(s.isEmpty()) {
                    continue;
                }
                d1.pollLast();
            }
            else {
                d1.add(c);
            }
        }
        
        for(int i=0;i<t.length();i++) {
            char c1 = t.charAt(i);
            if(c1 =='#') {
                if(t.isEmpty()) {
                    continue;
                }
                d2.pollLast();
            }
            else {
                d2.add(c1);
            }
        }
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        while(!d1.isEmpty()) {
            sb1.append(d1.pollFirst());
        }
        while(!d2.isEmpty()) {
            sb2.append(d2.pollFirst());
        }
        if(sb1.toString().equals(sb2.toString())) return true;
        return false;
    }
}