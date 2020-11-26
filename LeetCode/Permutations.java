class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        List<Integer> temp = new ArrayList<>();
        go(0,nums.length,visited,nums,temp);
        return ans;
    }
    private void go(int cnt,int depth,boolean[] visited, int[] nums,List<Integer> temp) {
        if(cnt==depth) {
            List<Integer> temp2 = new ArrayList<>(temp);
            ans.add(temp2);
            return;
        }
        for(int i=0;i<nums.length;i++) {
            if(!visited[i]) {
                visited[i]=true;
                temp.add(nums[i]);
                go(cnt+1,depth,visited,nums,temp);
                temp.remove(temp.size()-1);
                visited[i]=false;
            }
        }
    }
}