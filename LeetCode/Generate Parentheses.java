class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans= new ArrayList<>();
        backtrack(ans,new StringBuilder(),n,n);
        return ans;
    }
    private void backtrack(List<String> ans,StringBuilder sb, int closecnt,int opencnt) {
        if(opencnt!=0) {
            sb.append('(');
            backtrack(ans,sb,closecnt,opencnt-1);
            sb.deleteCharAt(sb.length()-1);
        }
        if(closecnt!=0 && closecnt>opencnt) {
            sb.append(')');
            backtrack(ans,sb,closecnt-1,opencnt);
            sb.deleteCharAt(sb.length()-1);
        }
        if(opencnt==0 && closecnt==0) {
            ans.add(sb.toString());
        }
    }
}