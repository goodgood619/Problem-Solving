import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static double win = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int one = Integer.parseInt(input[0]);
        int two = Integer.parseInt(input[1]);
        int[] card = new int[11];
        for(int i=1;i<=10;i++) {
            card[i] = 2;
            if(one == i) card[i]--;
            if(two == i ) card[i]--;
        }
        ArrayList<Integer> v = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        boolean[] visited = new boolean[18];
        double total = 18*17/2;
        for(int i=1;i<=10;i++) {
            int rest = card[i];
            for(int j=1;j<=rest;j++) {
                v.add(i);
            }
        }
        go(0,0,2,one,two,v,temp,visited);
        double ans = win/total;
        bw.write(String.format("%.3f",ans));
        bw.flush();
        bw.close();
    }
    private static void go(int here,int cnt,int depth,int one,int two,ArrayList<Integer> v,ArrayList<Integer> temp, boolean[] visited) {
        if(cnt == depth) {
            int opone = temp.get(0);
            int optwo = temp.get(1);
            if(opone != optwo) {
                if(one == two) win++;
                else {
                    one += two;
                    opone += optwo;
                    one%=10;
                    opone%=10;
                    if(one>opone) win++;
                }
            }
            else {
                if(one == two && one > opone) win++;
            }
            return;
        }
        for(int i=here;i<v.size();i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.add(v.get(i));
                go(i+1,cnt+1,depth,one,two,v,temp,visited);
                visited[i] = false;
                temp.remove(temp.size()-1);
            }
        }
    }
}
