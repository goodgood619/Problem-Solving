import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<p> v = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int o = Integer.parseInt(st.nextToken()), num = Integer.parseInt(st.nextToken());
            v.add(new p(o, num));
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            int ok = v.get(i).o, num = v.get(i).num;
            go(ok, i, v, num);
            int[] check = new int[11]; //1루수 후보
            int[] nocheck = new int[11]; // 1루수 아닌 후보
            for (int j = 0; j < v.size(); j++) {
                int o = v.get(j).o, num2 = v.get(j).num;
                if (o == 1) check[num2]++;
                else nocheck[num2]++;
            }
            int sum = 0, nosum = 0;
            for (int j = 1; j <= 10; j++) {
                sum += check[j];
                nosum += nocheck[j];
            }
            // 전부 No인경우=> 될수도있는 경우는 평가를 안받은 놈들은 무조건 후보대상 ㅇㅇ
            if (nosum == 9) {
                for (int j = 1; j <= 9; j++) {
                    if (nocheck[j] == 0) ans.add(j);
                }
                go(ok == 0 ? 1 : 0, i, v, num);
                continue;
            }
            if (nosum + sum == 9) {
                int cnt = 0;
                for (int j = 1; j <= 9; j++) {
                    if (check[j] >= 1 && nocheck[j] == 0) cnt++;
                }
                //확실한 놈들이 2명이상이면 이건아니지
                if (cnt >= 2) {
                    go(ok == 0 ? 1 : 0, i, v, num);
                    continue;
                }
                //투표를 받은 대상이 여러명인경우 무조건아님(1명인데도, 어차피 누군가 평가안된대상이 존재를 만약에 한다면,
                // 그건 무조건 내가 아닌 다른 사람이 여러번 평가받았다는 소리이므로, 투표를 받은대상이 여러명인경우에 속한다)
                int sumsum = 0;
                for (int j = 1; j <= 9; j++) {
                    if (check[j] >= 1) sumsum++;
                }
                if (sumsum >= 2) {
                    go(ok == 0 ? 1 : 0, i, v, num);
                    continue;
                }
                for (int j = 1; j <= 9; j++) {
                    if (check[j] >= 1 && nocheck[j] == 0) ans.add(j);
                }
                go(ok == 0 ? 1 : 0, i, v, num);
            }


        }
        if (ans.size() != 1) {
            System.out.println(-1);
        } else {
            System.out.println(ans.get(0));
        }
    }

    private static void go(int ok, int i, ArrayList<p> v, int num) {
        if (ok == 0) {
            v.set(i, new p(1, num));
        } else {
            v.set(i, new p(0, num));
        }
    }

    private static class p {
        int o, num;

        private p(int o, int num) {
            this.o = o;
            this.num = num;
        }
    }
}