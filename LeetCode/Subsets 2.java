class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        int length = nums.length;
        Set<List<Integer>> makeAns =new HashSet<>();
        List<Integer> list =new ArrayList<>();
        boolean[] visited = new boolean[length];
        for(int i=0;i<=length;i++) {
            makeSubSets(0,0,i,nums,makeAns,list,visited);
        }
        Iterator<List<Integer>> iterAns = makeAns.iterator();
        List<List<Integer>> ans = new ArrayList<>();
        while(iterAns.hasNext()) {
            ans.add(iterAns.next());
        }
        return ans;
    }
    private void makeSubSets(int index,int cnt,int depth,int[] nums,Set<List<Integer>> makeAns,List<Integer> list
                            ,boolean[] visited) {
        if(cnt==depth) {
            List<Integer> tempAns = new ArrayList<>(list);
            makeAns.add(tempAns);
            return;
        }
        for(int i=index;i<nums.length;i++) {
            if(!visited[i]) {
                visited[i] = true;
                list.add(nums[i]);
                makeSubSets(i+1,cnt+1,depth,nums,makeAns,list,visited);
                visited[i] = false;
                list.remove(list.size()-1);
            }
        }
    }
}