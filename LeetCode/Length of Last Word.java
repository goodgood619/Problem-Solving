class Solution {
    public int lengthOfLastWord(String s) {
        String[] input = s.split(" ");
        if(input.length ==0) return 0;
        return input[input.length-1].length();
    }
}