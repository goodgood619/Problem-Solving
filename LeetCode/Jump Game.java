class Solution {
    public boolean canJump(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        Deque<Integer> q = new ArrayDeque<>();
        q.add(0);
        visited[0]=true;
        while(!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            int jump = nums[here];
            for(int i=1;i<=jump;i++) {
                int next = here+i;
                if(next>=nums.length) continue;
                if(!visited[next]) {
                    visited[next]=true;
                    q.add(next);
                }
            }
        }
        return visited[nums.length-1];
    }
}