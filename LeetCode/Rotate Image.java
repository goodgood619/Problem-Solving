class Solution {
    public void rotate(int[][] matrix) {
        
        int length = matrix.length;
        // transpose
        for(int i=0;i<length;i++) {
            for(int j=i;j<length;j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        // reverse
        for(int i=0;i<length;i++) {
            for(int j=0;j<length/2;j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][length-j-1];
                matrix[i][length-j-1] = tmp;
            }
        }
    }
}