import java.io.*;
public class Main {

    public static void main(String[] args) throws IOException {
	    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
	    String[] arr = bufferedReader.readLine().split(" ");
	    int sum =0;
	    for(int i = 0; i < arr.length; i++) {
	        sum += Integer.parseInt(arr[i]);
        }
	    System.out.println(sum);
    }
}
