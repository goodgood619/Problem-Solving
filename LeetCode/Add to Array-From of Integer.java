class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        int idx = A.length;
        List<Integer> list = new ArrayList<>();
        int cur = K;
        while(--idx>=0 || cur>0) {
            if(idx>=0) cur += A[idx];
            list.add(cur%10);
            cur/=10;
        }
        Collections.reverse(list);
        return list;
    }
}