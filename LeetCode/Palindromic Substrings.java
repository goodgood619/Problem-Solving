class Solution {
    public int countSubstrings(String s) {
        int ans = 0;
        for(int i=0;i<s.length();i++) {
            for(int j=i;j<s.length();j++) {
                if(checkSubStrings(i,j,s)) ans++;
            }
        }
        return ans;
    }
    private boolean checkSubStrings(int start,int end,String s) {
        boolean check = true;
        for(int i=start,j = end;i<=j;i++,j--) {
            if(s.charAt(i) != s.charAt(j)) {
                check = false;
                break;
            }
        }
        return check;
    }
}