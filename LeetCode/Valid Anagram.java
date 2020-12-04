class Solution {
    public boolean isAnagram(String s, String t) {
        int[] cnt = new int[26];
        int[] cnt2 = new int[26];
        for(int i=0;i<s.length();i++) {
            char c= s.charAt(i);
            cnt[c-'a']++;
        }
        for(int i=0;i<t.length();i++) {
            char cc= t.charAt(i);
            cnt2[cc-'a']++;
        }
        for(int i=0;i<26;i++) {
            if(cnt[i]!=cnt2[i]) return false;
        }
        return true;
    }
}