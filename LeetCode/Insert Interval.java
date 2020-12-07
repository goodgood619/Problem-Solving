class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int[][] tempIntervals = new int[intervals.length+1][2];
        int tempidx=0;
        for(int i=0;i<intervals.length;i++) {
            tempIntervals[tempidx][0] = intervals[i][0];
            tempIntervals[tempidx++][1] = intervals[i][1];
        }
        tempIntervals[tempidx][0] = newInterval[0];
        tempIntervals[tempidx++][1] = newInterval[1];
        Arrays.sort(tempIntervals,(a,b)->{
           if(a[0]<b[0]) return -1;
           else if(a[0]>b[0]) return 1;
           else {
               return Integer.compare(a[1], b[1]);
           }
        });
        int curStart = tempIntervals[0][0];
        int curEnd = tempIntervals[0][1];
        List<Pair> tempAns = new ArrayList<>();
        for(int i=1;i<tempIntervals.length;i++) {
            int start = tempIntervals[i][0];
            int end = tempIntervals[i][1];
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