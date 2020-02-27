import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String origin = br.readLine();
        String after = br.readLine();
        for (int i = 0; i < n; i++) {
            origin = go(origin);
        }
        if (origin.equals(after)) System.out.println("Deletion succeeded");
        else System.out.println("Deletion failed");
    }

    private static String go(String origin) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < origin.length(); i++) {
            if (origin.charAt(i) == '1') {
                sb.append('0');
            } else {
                sb.append('1');
            }
        }
        return sb.toString();
    }
}