import java.io.*;
import java.util.ArrayList;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        ArrayList<p> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            int age = Integer.parseInt(input[0]);
            v.add(new p(age,i,input[1]));
        }
        v.sort((a, b) -> {
            if (a.age < b.age) return -1;
            else if (a.age > b.age) return 1;
            else {
                if(a.index<b.index) return -1;
                else if(a.index>b.index) return 1;
                else return 0;
            }
        });
        for(int i=0;i<v.size();i++) {
            bw.write(v.get(i).age + " "+ v.get(i).name+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static class p{
        int age;
        int index;
        String name;
        private p(int age,int index,String name) {
            this.name = name;
            this.index = index;
            this.age = age;
        }
    }
}