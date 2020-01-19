import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            String[] input = br.readLine().split(" ");
            if(input[0].length() < input[1].length()) {
                String temp = input[0];
                input[0] = input[1];
                input[1] = temp;
            }
            if(Integer.parseInt(input[0]) == 0 && Integer.parseInt(input[1])==0) break;
            int carry = 0,cnt=0;
            for (int i = input[0].length() - 1, j = input[1].length() - 1; i >= 0 && j >= 0; i--, j--) {
                int num1 = input[0].charAt(i)-'0',num2 = input[1].charAt(j)-'0';
                num1 = num1 + num2+carry;
                if(num1>=10) {
                    carry = 1;
                    cnt++;
                } else {
                    carry = 0;
                }
            }
            if(carry == 1 && input[0].length() != input[1].length()) {
                int num = input[0].length() - input[1].length()-1;
                for(int j=num;j>=0;j--) {
                    if (input[0].charAt(num) - '0' + carry >= 10) {
                        cnt++;
                        carry = 1;
                    } else carry =0;
                }
            }
            bw.write(String.valueOf(cnt)+"\n");
            bw.flush();
        }
    }
}