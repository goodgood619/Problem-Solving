class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        for(int i=0;i<=nums.length;i++) {
            boolean[] visited = new boolean[nums.length];
            List<Integer> temp = new ArrayList<>();
            go(0,0,i,visited,temp,nums);
        }
        return ans;
    }
    private void go(int here,int cnt,int depth,boolean[] visited,List<Integer> temp,int[] nums) {
        if(cnt==depth){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=here;i<visited.length;i++) {
            if(!visited[i]) {
                visited[i]=true;
                temp.add(nums[i]);
                go(i+1,cnt+1,depth,visited,temp,nums);
                visited[i]=false;
                temp.remove(temp.size()-1);
            }
        }
    }
}