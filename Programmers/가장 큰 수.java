import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        String[] arr = new String[numbers.length];
        for(int i=0;i<numbers.length;i++) {
            arr[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(arr,(a,b)->compare(a,b));
        
        if(arr[0].equals("0")) return "0";
        StringBuilder answer = new StringBuilder();
        for(int i=0;i<arr.length;i++) {
            answer.append(arr[i]);
        }
        return answer.toString();
    }
    private int compare(String a,String b) {
        String s1 = a+b;
        String s2 = b+a;
        return s2.compareTo(s1);
    }
}