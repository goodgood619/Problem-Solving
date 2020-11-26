class Solution {
    int[] gox = {0,-1,0,1};
    int[] goy = {1,0,-1,0};
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length==0) return new ArrayList<Integer>();
        boolean[][] visited = new boolean[matrix.length][matrix[0].length];
        int n = matrix.length;
        int m= matrix[0].length;
        int x = 0 , y=0,cnt=1;
        List<Integer> list = new ArrayList<>();
        list.add(matrix[0][0]);
        visited[0][0]=true;
        while(true) {
            if(cnt== n*m) break;
            for(int i=0;i<4;i++) {
                while(x+gox[i]>=0 && y+goy[i]>=0 && x+gox[i]<n&& y+goy[i]<m && !visited[x+gox[i]][y+goy[i]]) {
                    x+=gox[i];
                    y+=goy[i];
                    visited[x][y]=true;
                    list.add(matrix[x][y]);
                    cnt++;
                }
            }
        }
        return list;
    }
}