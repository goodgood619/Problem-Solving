class Solution {
    public List<List<Integer>> combine(int n, int k) {
        boolean[] visited = new boolean[n];
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> makeAns = new ArrayList<>();
        makeCombinations(0,0,n,k,visited,ans,makeAns);
        return ans;
    }
    private void makeCombinations(int index,int cnt,int n,int k,boolean[] visited,List<List<Integer>> ans,List<Integer> temp) {
        if(cnt==k) {
            List<Integer> putAns =new ArrayList<>(temp);
            ans.add(putAns);
            return;
        }
        for(int i=index;i<n;i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.add(i+1);
                makeCombinations(i+1,cnt+1,n,k,visited,ans,temp);
                temp.remove(temp.size()-1);
                visited[i] = false;
            }
        }
    }
}