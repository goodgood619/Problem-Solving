class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->{
           if(a[0]<b[0]) return -1;
           else if(a[0]>b[0]) return 1;
           else {
               return Integer.compare(a[1], b[1]);
           }
        });
        int curStart = intervals[0][0];
        int curEnd = intervals[0][1];
        List<Pair> tempAns = new ArrayList<>();
        for(int i=1;i<intervals.length;i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(curEnd>=start) {
                if(curEnd<end) curEnd = end;
            }
            else {
                tempAns.add(new Pair(curStart,curEnd));
                curStart = start;
                curEnd = end;
            }
        }
        tempAns.add(new Pair(curStart,curEnd));
        int[][] ans = new int[tempAns.size()][2];
        int idx=0;
        for(Pair p : tempAns) {
            ans[idx][0] = p.x;
            ans[idx++][1] = p.y;
        }
        return ans;
    }
    class Pair {
        int x,y;
        Pair(int x,int y) {
            this.x = x;
            this.y = y;
        }
    }
}