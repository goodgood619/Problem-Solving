import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n =Integer.parseInt(br.readLine());
        int[] arr= new int[n];
        StringTokenizer st= new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) arr[i]=Integer.parseInt(st.nextToken());

        if(next_permutation(arr)) {
            for(int i=0;i<arr.length;i++) bw.write(arr[i]+" ");
            bw.flush();
            bw.close();
        }
        else System.out.println("-1");
    }

    private static boolean next_permutation(int[] arr) {
        int i=arr.length-1;
        while(i>0 && arr[i-1]>=arr[i]) {
            i--;
        }
        if(i<=0) return false;

        int j=arr.length-1;
        while(arr[j]<=arr[i-1] && j>=i) {
            j--;
        }
        int temp = arr[j];
        arr[j]=arr[i-1];
        arr[i-1]=temp;

        j=arr.length-1;
        while(i<j) {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        return true;
    }
}