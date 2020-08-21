import java.util.*;
import java.io.*;
class Solution {
    public long solution(int n, int[] times) {
        long ans = 0;
        Arrays.sort(times);
        long left = 0, right = (long)1e18;
        while(left<=right) {
            long mid = (left+right)/2;
            long sum = 0;
            for(int i=0;i<times.length;i++) {
                sum += mid/times[i];
                if(sum>n) break;
            }
            if(sum>=n) {
                right = mid-1;
                ans = mid;
            }
            else {
                left = mid+1;
            }
        }
        return ans;
    }
}