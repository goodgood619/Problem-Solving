import java.io.*;
import java.util.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[] arr = new int[n];
        HashSet<Integer> set = new HashSet<>();
        for(int i=0;i<n;i++) {
            arr[i] = Integer.parseInt(br.readLine().split(" ")[0]);
            set.add(arr[i]);
        }
        int max = 1;
        Iterator<Integer> it1 = set.iterator();
        while(it1.hasNext()) {
            int num = it1.next();
            ArrayList<Integer> v = new ArrayList<>();
            for(int i=0;i<n;i++) {
                if(arr[i] != num) v.add(arr[i]);
            }
            int cnt = 1;
            for(int i=0;i<v.size() - 1;i++) {
                if(v.get(i).equals(v.get(i + 1))) {
                    cnt++;
                    max = max(max,cnt);
                }
                else {
                    max = max(max,cnt);
                    cnt = 1;
                }
            }
        }
        System.out.println(max);
    }
}
