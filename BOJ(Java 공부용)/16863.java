import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    //    static int[] gox = {0, 1, -1, 0};
    //    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int home = 0, away = 0, hseconds = 0, aseconds = 0, check = 0, curminute = 0, cursecond = 0;
        for (int i = 0; i < n; i++) {
            if (home > away) check = 1;
            if (home < away) check = 2;
            if (home == away) check = 0;
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            if (s.equals("H")) {
                int score = Integer.parseInt(st.nextToken());
                home += score;
                String[] input = st.nextToken().split(":");
                int minute = Integer.parseInt(input[0]), second = Integer.parseInt(input[1]);
                //이전에 리드했었던 팀이
                int hseconds1 = 60 * minute + second - curminute * 60 - cursecond;
                if (check == 1) {
                    hseconds += hseconds1;
                } else if (check == 2) {
                    aseconds += hseconds1;
                }
                curminute = minute;
                cursecond = second;
            } else {
                int score = Integer.parseInt(st.nextToken());
                away += score;
                String[] input = st.nextToken().split(":");
                int minute = Integer.parseInt(input[0]), second = Integer.parseInt(input[1]);
                int hseconds1 = 60 * minute + second - curminute * 60 - cursecond;
                if (check == 1) {
                    hseconds += hseconds1;
                } else if (check == 2) {
                    aseconds += hseconds1;
                }
                curminute = minute;
                cursecond = second;
            }
        }
        if (home > away) {
            hseconds += 60 * 32 - 60 * curminute - cursecond;
        }
        if (home < away) {
            aseconds += 60 * 32 - 60 * curminute - cursecond;
        }
        if (home > away) {
            if (hseconds % 60 < 10 && aseconds % 60 < 10) {
                System.out.println("H " + hseconds / 60 + ":0" + hseconds % 60 + " " + aseconds / 60 + ":0" + aseconds % 60);
            } else if (hseconds % 60 >= 10 && aseconds % 60 < 10) {
                System.out.println("H " + hseconds / 60 + ":" + hseconds % 60 + " " + aseconds / 60 + ":0" + aseconds % 60);
            } else if (hseconds % 60 >= 10 && aseconds % 60 >= 10) {
                System.out.println("H " + hseconds / 60 + ":" + hseconds % 60 + " " + aseconds / 60 + ":" + aseconds % 60);
            } else {
                System.out.println("H " + hseconds / 60 + ":0" + hseconds % 60 + " " + aseconds / 60 + ":" + aseconds % 60);
            }
        } else if (home < away) {
            if (hseconds % 60 < 10 && aseconds % 60 < 10) {
                System.out.println("A " + hseconds / 60 + ":0" + hseconds % 60 + " " + aseconds / 60 + ":0" + aseconds % 60);
            } else if (hseconds % 60 >= 10 && aseconds % 60 < 10) {
                System.out.println("A " + hseconds / 60 + ":" + hseconds % 60 + " " + aseconds / 60 + ":0" + aseconds % 60);
            } else if (hseconds % 60 >= 10 && aseconds % 60 >= 10) {
                System.out.println("A " + hseconds / 60 + ":" + hseconds % 60 + " " + aseconds / 60 + ":" + aseconds % 60);
            } else {
                System.out.println("A " + hseconds / 60 + ":0" + hseconds % 60 + " " + aseconds / 60 + ":" + aseconds % 60);
            }
        }

    }
}