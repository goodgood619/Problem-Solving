import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("     /~\\");
        System.out.println("    ( oo|");
        System.out.println("    _\\=/_");
        System.out.println("   /  _  \\");
        System.out.println("  //|/.\\|\\\\");
        System.out.println(" ||  \\ /  ||");
        System.out.println("============");
        for (int i = 0; i < 3; i++) {
            System.out.println("|          |");
        }
    }
}