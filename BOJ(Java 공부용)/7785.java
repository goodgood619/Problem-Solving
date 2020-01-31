import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t = 0, total = 0;
    static ArrayDeque<Integer> st = new ArrayDeque<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<String> v = new ArrayList<>();
        HashMap<String,Integer> m = new HashMap<>();
        HashMap<Integer,String> mm = new HashMap<>();
        boolean[] visited = new boolean[n];
        int k = 0;
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            if(input[1].equals("enter")) {
                m.put(input[0],k);
                mm.put(k,input[0]);
                k++;
            }
            else if(input[1].equals("leave")) {
                visited[m.get(input[0])] = true;
            }
        }
        Iterator it = mm.keySet().iterator();
        while(it.hasNext()) {
            int key = (int) it.next();
            if(!visited[key]) {
                v.add(mm.get(key));
            }
        }
        v.sort(Comparator.naturalOrder());
        for(int i=v.size()-1;i>=0;i--) {
            bw.write(v.get(i)+"\n");
        }
        bw.flush();
        bw.close();
    }
}