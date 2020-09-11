import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = "";
        StringBuilder sb = new StringBuilder();
        Map<String, String> map = new HashMap<>();
        map.put("<br>", "\n");
        map.put("<hr>", "--------------------------------------------------------------------------------");
        int curLength = 0;
        while ((input = br.readLine()) != null) {
            String[] arr = input.split(" |\t");

            for (int i = 0; i < arr.length; ++i) {
                int length = arr[i].length();
                String s = arr[i];
                if (s.equals("")) continue;
                if (s.equals("<br>")) {
                    bw.write("\n");
                    curLength = 0;
                    continue;
                }
                if (s.equals("<hr>")) {
                    if (curLength != 0) bw.write("\n" + map.get("<hr>") + "\n");
                    else bw.write(map.get("<hr>") + "\n");
                    curLength = 0;
                    continue;
                }

                if (curLength + s.length() > 80) {
                    bw.write("\n");
                    curLength = 0;
                }
                curLength += s.length() + 1;
                bw.write(s + " ");
            }
        }
        bw.flush();
        bw.close();
    }
}
