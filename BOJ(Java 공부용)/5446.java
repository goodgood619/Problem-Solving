import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while(t-- >0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            Trie trie = new Trie();
            cnt = 0;
            // 지워도 되는것
            for(int i=0;i<n;i++) {
                String s = br.readLine();
                insert(s,trie,true);
            }
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            for(int i=0;i<m;i++) {
                String s = br.readLine();
                insert(s,trie,false);
            }
            check(trie);
            bw.write(cnt+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static class Trie {
        private Trie[] letter;
        private boolean finish;
        private boolean del;
        private Trie() {
            this.letter = new Trie[80];
            this.finish = false;
            this.del = false;
        }
    }
    private static void check(Trie trie) {
        if(trie.del) {
            cnt++;
            return;
        }
        else if(trie.finish) cnt++;
        for(int i=0;i<80;i++) {
            if(trie.letter[i] != null) check(trie.letter[i]);
        }
    }
    private static void insert(String s,Trie trie,boolean d) {
        for(int i=0;i<s.length();i++) {
            int c = s.charAt(i)-'.';
            if(trie.letter[c] == null) trie.letter[c] = new Trie();
            trie.del = d;
            trie = trie.letter[c];
        }
        trie.finish = d;
        trie.del = d;
    }
}