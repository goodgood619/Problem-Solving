import java.io.*;
import java.math.BigInteger;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long mod = 1000000007;
        String[] input = br.readLine().split(" ");
        BigInteger two = BigInteger.valueOf(2);
        BigInteger n = new BigInteger(input[0]), m = new BigInteger(input[1]);
        n = gcd(n,m);
        long[][] matrix = new long[][]{{1,0},{0,1}};
        long[][] fibo = new long[][]{{1,1},{1,0}};
        while(n.compareTo(BigInteger.ZERO) > 0) {
            if(n.remainder(two).equals(BigInteger.ONE)) {
                matrix = operator(matrix,fibo,mod);
            }
            fibo = operator(fibo,fibo,mod);
            n = n.divide(two);
        }

        System.out.println(matrix[0][1]);
    }
    private static BigInteger gcd(BigInteger a,BigInteger b) {
        if(a.remainder(b).equals(BigInteger.ZERO)) return b;
        return gcd(b.remainder(a),a);
    }
    private static long[][] operator(long[][] a, long[][] b,long mod) {
        long[][] matrix = new long[2][2];

        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                for(int k=0;k<2;k++) {
                    matrix[i][j]+= (a[i][k] *b[k][j])%mod;
                }
                matrix[i][j]%= mod;
            }
        }
        return matrix;
    }
}