import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[] arr = new long[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        long[] arr2 = new long[m];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++) {
            arr2[i] = Long.parseLong(st.nextToken());
        }
        ArrayList<Long> v1 = new ArrayList<>();
        ArrayList<Long> v2 = new ArrayList<>();
        for(int i=0;i<n;i++) {
            long sum = 0;
            for(int j=i;j<n;j++) {
                sum += arr[j];
                v1.add(sum);
            }
        }
        for(int i=0;i<m;i++) {
            long sum = 0;
            for(int j=i;j<m;j++) {
                sum += arr2[j];
                v2.add(sum);
            }
        }
        Collections.sort(v1);
        Collections.sort(v2);
        long cnt = 0;
        for(int i=0;i<v1.size();i++) {
            int it = lowerbound(0,v2.size(),v2,t-v1.get(i));
            int it2 = upperbound(0,v2.size(),v2,t-v1.get(i));
            if(it == v2.size()) continue;
            if(v1.get(i) + v2.get(it) == t) {
                cnt += (it2- it);
            }
        }
        System.out.println(cnt);
    }
    private static int lowerbound(int left,int right,ArrayList<Long> v,long num) {
        while(left < right) {
            int mid = (left + right) /2;
            if(v.get(mid)<num) left = mid+1;
            else right = mid;
        }
        return right;
    }
    private static int upperbound(int left,int right,ArrayList<Long> v, long num) {
        while(left < right) {
            int mid = (left + right) / 2;
            if(v.get(mid)<=num) left = mid + 1;
            else right = mid;
         }
        return right;
    }
}