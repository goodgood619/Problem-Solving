import java.io.*;
import java.util.ArrayList;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int u = Integer.parseInt(input[0]);
        int n = Integer.parseInt(input[1]);
        ArrayList<p> v = new ArrayList<>();
        int[] cnt = new int[u+1];
        for(int i=0;i<n;i++) {
            String[] input2 = br.readLine().split(" ");
            v.add(new p(input2[0],Integer.parseInt(input2[1])));
            cnt[Integer.parseInt(input2[1])]++;
        }
        int min = 10000000;
        int minvalue = -1;
        for(int i=1;i<=u;i++) {
            if(cnt[i]>0 && min>cnt[i]) {
                min = cnt[i];
                minvalue = i;
            }
        }
        for(int i=0;i<v.size();i++) {
            if(v.get(i).cost == minvalue) {
                bw.write(v.get(i).name + " "+v.get(i).cost+"\n");
                break;
            }
        }
        bw.flush();
        bw.close();
    }
    private static class p {
        String name;
        int cost;
        private p(String name,int cost) {
            this.name = name;
            this.cost = cost;
        }
    }
    private static class pp{
        int cnt,cost;
        private pp(int cnt,int cost) {
            this.cost = cost;
            this.cnt = cnt;
        }
    }
}