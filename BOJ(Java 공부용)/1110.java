import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        boolean[] visited = new boolean[201];
        int cnt = 0;
        if(n == 0) System.out.println(1);
        else {
            visited[n] = true;
            while(true) {
                int a,b,c,sum=0;
                if(n<10) {
                    a = 0;
                    b = n;
                    c = a + b;
                    if(c>=10) sum = b*10+c%10;
                    else sum = b*10 +c;
                    cnt++;
                    n = sum;
                }
                else{
                    a= n/10;
                    b = n%10;
                    c = a+b;
                    if(c>=10) sum = b*10 + c%10;
                    else sum = b*10 +c;
                    cnt++;
                    n = sum;
                }
                if(visited[n]) break;
            }
            System.out.println(cnt);
        }
    }
}