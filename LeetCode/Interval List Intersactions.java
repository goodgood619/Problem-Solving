class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        int aIdx = 0, bIdx = 0;
        List<Pair> tempAns = new ArrayList<>();
        while(aIdx< A.length && bIdx < B.length) {
            int aFirst = A[aIdx][0], aEnd = A[aIdx][1], bFirst = B[bIdx][0], bEnd = B[bIdx][1];
            if(aEnd<bFirst) {
                aIdx++;
            }
            else if(bEnd<aFirst) {
                bIdx++;
            }
            else if(aEnd < bEnd && aEnd>=bFirst && bFirst>aFirst) {
                tempAns.add(new Pair(bFirst,aEnd));
                aIdx++;
            }
            else if(bEnd < aEnd && bEnd>=aFirst && aFirst>bFirst) {
                tempAns.add(new Pair(aFirst,bEnd));
                bIdx++;
            }
            else if(aEnd>=bEnd && bFirst>=aFirst) {
                tempAns.add(new Pair(bFirst,bEnd));
                bIdx++;
            }
            else if(bEnd>=aEnd && aFirst>=bFirst) {
                tempAns.add(new Pair(aFirst,aEnd));
                aIdx++;
            }
        }
        
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