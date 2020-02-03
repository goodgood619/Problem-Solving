import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), p = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[1000001];
        ArrayList<Integer> v = new ArrayList<>();
        visited[n] = true;
        int temp = n, cnt = 0;
        v.add(n);
        while(true) {
            temp = (temp*n) % p;
            if(visited[temp]) {
                v.add(temp);
                break;
            }
            visited[temp] = true;
            v.add(temp);
        }
        int last = v.get(v.size()-1);
        for(int i=v.size()-2;i>=0;i--) {
            if(last == v.get(i)) break;
            cnt++;
        }
        System.out.println(cnt+1);
    }
}