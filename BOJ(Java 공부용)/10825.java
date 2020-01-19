import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        ArrayList<p> v = new ArrayList<>();
        for(int i=0;i<n;i++) {
            String[] s = br.readLine().split(" ");
            v.add(new p(s[0],Integer.parseInt(s[1]),Integer.parseInt(s[2]),Integer.parseInt(s[3])));
        }

        Collections.sort(v, new Comparator<p>() {
            @Override
            public int compare(p a, p b) {
                if(a.kor == b.kor) {
                    if(a.eng == b.eng ) {
                        if(a.math == b.math) {
                            return a.name.compareTo(b.name);
                        } else if(a.math<b.math) {
                            // 내림차순
                            return 1;
                        }
                        else return -1;
                    } else if(a.eng > b.eng) {
                        // 오름차순
                        return 1;
                    } else return -1;
                } else if(a.kor<b.kor) {
                    return 1;
                } else {
                    return -1;
                }
            }
        });

        for(int i=0;i<v.size();i++) {
            bw.write(v.get(i).name+"\n");
        }
        bw.flush();
        bw.close();

    }
    static class p {
        String name;
        int kor,eng,math;

        public p(String name,int kor,int eng,int math) {
            this.name = name;
            this.kor = kor;
            this.eng = eng;
            this.math = math;
        }
    }

}