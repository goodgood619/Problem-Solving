import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while(t-- >0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            HashMap<Integer,Integer> map = new HashMap<>();
            int p = 2;
            while(n > 1) {
                if(n%p ==0 ){
                    if(map.get(p)== null) {
                        map.put(p,1);
                    }
                    else {
                        int value = map.get(p);
                        map.remove(p);
                        value++;
                        map.put(p,value);
                    }
                    n /= p;
                    p = 2;
                }
                else p++;
            }
            ArrayList<p> v= new ArrayList<p>();
            Iterator it = map.keySet().iterator();
            while(it.hasNext()) {
                int key = (int) it.next();
                v.add(new p(key,map.get(key)));
            }
            v.sort((a,b)->{
               if(a.num<b.num) return -1;
               else if(a.num>b.num) return 1;
               else {
                   if(a.cnt <b.cnt) return -1;
                   else if(a.cnt>b.cnt) return 1;
                   else return 0;
               }
            });
            for(int i=0;i<v.size();i++) {
                bw.write(v.get(i).num+" "+v.get(i).cnt+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
    private static class p {
        int num,cnt;
        private p(int num,int cnt) {
            this.num = num;
            this.cnt = cnt;
        }
    }
}