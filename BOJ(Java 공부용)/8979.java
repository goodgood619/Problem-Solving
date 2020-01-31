import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]), k = Integer.parseInt(input[1]);
        ArrayList<p> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String[] input2 = br.readLine().split(" ");
            int nation = Integer.parseInt(input2[0]), gold = Integer.parseInt(input2[1]), silver = Integer.parseInt(input2[2]), bronze = Integer.parseInt(input2[3]);
            v.add(new p(nation,gold,silver,bronze));
        }
        v.sort((a,b)->{
           if(a.gold > b.gold) return -1;
           else if(a.gold < b.gold) return 1;
           else {
               if(a.silver>b.silver) return -1;
               else if(a.silver<b.silver) return 1;
               else {
                   if(a.bronze >b.bronze) return -1;
                   else if(a.bronze < b.bronze) return 1;
                   else {
                       if(a.nation < b.nation) return -1;
                       else if(a.nation > b.nation) return 1;
                       return 0;
                   }
               }
           }
        });
        boolean[] visited = new boolean[n+1];
        int[] ranking = new int[n+1];
        int rank = 1;
        for(int i=0;i<v.size();i++) {
            if(visited[v.get(i).nation]) continue;
            rank = i+1;
            if(!visited[v.get(i).nation]) {
                visited[v.get(i).nation] = true;
                ranking[v.get(i).nation] = rank;
            }
            for(int j=i+1;j<v.size();j++) {
                if(v.get(i).gold != v.get(j).gold || v.get(i).silver != v.get(j).silver || v.get(i).bronze != v.get(j).bronze) break;
                ranking[v.get(j).nation] = rank;
                visited[v.get(j).nation] = true;
            }
        }
        System.out.println(ranking[k]);
    }
    private static class p {
        int nation,gold,silver,bronze;
        private p(int nation,int gold, int silver, int bronze) {
            this.nation = nation;
            this.gold = gold;
            this.silver = silver;
            this.bronze = bronze;
        }
    }
}