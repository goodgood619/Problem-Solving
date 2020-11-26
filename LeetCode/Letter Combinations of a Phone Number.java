class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> output = new ArrayList<>();
        Map<String,String> map = new HashMap<>();
        map.put("2","abc");
        map.put("3","def");
        map.put("4","ghi");
        map.put("5","jkl");
        map.put("6","mno");
        map.put("7","pqrs");
        map.put("8","tuv");
        map.put("9","wxyz");
        if(digits.length()!=0) go("",digits,map,output);
        return output;
    }
    private void go(String cur,String num,Map<String,String> map,List<String> output) {
        if(num.length()==0) {
            output.add(cur);
            return;
        }
        String curnum = num.substring(0,1);
        String alphalist= map.get(curnum);
        for(int i=0;i<alphalist.length();i++) {
            String next = map.get(curnum).substring(i,i+1);
            go(cur+next,num.substring(1),map,output);
        }
    }
}