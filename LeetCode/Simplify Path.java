class Solution {
    public String simplifyPath(String path) {
        String[] arr = path.split("/");
        Deque<String> dq = new ArrayDeque<>();
        for(int i=0;i<arr.length;i++) {
            String cur = arr[i];
            if(cur.equals(".") || cur.equals("")) continue;
            else if(cur.equals("..")) {
                if(dq.isEmpty()) continue;
                dq.pollLast();
            }
            else dq.add(cur);
        }
        StringBuilder sb = new StringBuilder();
        if(dq.isEmpty()) return "/";
        while(!dq.isEmpty()) {
            sb.append('/');
            sb.append(dq.pollFirst());
        }
        return sb.toString();
    }
}