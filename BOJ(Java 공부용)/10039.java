import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.OptionalDouble;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<P> list = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            int value = Integer.parseInt(br.readLine());
            list.add(new P(value));
        }
        OptionalDouble arg = list.stream()
                .mapToInt(n -> {
                    if (n.getNum() < 40) n.setNum(40);
                    return n.getNum();
                }).average();
        if (arg.isPresent()) {
            System.out.println((int) arg.getAsDouble());
        }

    }
}

class P {
    int num;

    P(int num) {
        this.num = num;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }
}