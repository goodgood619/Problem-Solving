class Solution {
    public int[] plusOne(int[] digits) {
        digits[digits.length-1]++;
        List<Integer> list = new ArrayList<>();
        int carry=0;
        for(int i=digits.length-1;i>=0;i--) {
            int num = digits[i];
            int newnum = num+carry;
            if(newnum>=10) {
                newnum-=10;
                carry=1;
                list.add(newnum);
            }
            else {
                list.add(newnum);
                carry=0;
            }
        }
        if(carry==1) list.add(carry);
        int[] arr = new int[list.size()];
        int idx=0;
        for(int i=list.size()-1;i>=0;i--) {
            arr[idx++] = list.get(i);
        }
        return arr;
    }
}