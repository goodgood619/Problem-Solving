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
            int kor = Integer.parseInt(input[1]);
            int eng = Integer.parseInt(input[2]);
            int math = Integer.parseInt(input[3]);
            v.add(new p(kor,math,eng,input[0]));
        }
        v.sort((a, b) -> {
            if(a.kor > b.kor) return -1;
            else if(a.kor < b.kor) return 1;
            else {
                if(a.eng<b.eng) return -1;
                else if(a.eng>b.eng) return 1;
                else {
                    if(a.math>b.math) return -1;
                    else if(a.math<b.math) return 1;
                    else {
                        return a.name.compareTo(b.name);
                    }
                }
            }
        });
        for(int i=0;i<v.size();i++) {
            bw.write(v.get(i).name+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static class p{
        int kor,math,eng;
        String name;
        private p(int kor,int math,int eng,String name) {
            this.kor = kor;
            this.math = math;
            this.eng = eng;
            this.name = name;
        }
    }
}