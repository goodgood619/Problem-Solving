class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        int pLength = p.length();
        p = makeSortString(p);
        for(int i=0;i<s.length()-pLength+1;i++) {
            String sAnagram = s.substring(i,i+pLength);
            sAnagram = makeSortString(sAnagram);
            if(sAnagram.length() == pLength && sAnagram.equals(p)) {
                ans.add(i);
            }
        }
        return ans;
    }
    private String makeSortString(String s) {
        char c[] = s.toCharArray();
        Arrays.sort(c);
        s = new String(c);
        return s;
    }
}