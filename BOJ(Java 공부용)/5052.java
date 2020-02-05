import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t =Integer.parseInt(st.nextToken());
        while(t-- >0) {
            Trie trie = new Trie();
            st = new StringTokenizer(br.readLine());
            int n =Integer.parseInt(st.nextToken());
            for(int i=0;i<n;i++) {
                String s = br.readLine();
                insert(s,trie);
            }
            if(check(trie)) bw.write("NO\n");
            else bw.write("YES\n");
        }
        bw.flush();
        bw.close();
    }
    private static class Trie {
        private Trie[] letter;
        private boolean cur;
        private boolean finish;
        private Trie() {
            this.cur = false;
            this.letter = new Trie[10];
            this.finish = false;
        }
    }
    private static boolean check(Trie trie) {
        if(trie.finish && trie.cur ) return true;
        for(int i=0;i<10;i++) {
            if(trie.letter[i] == null) continue;
            if(check(trie.letter[i])) {
                return true;
            }
        }
        return false;
    }
    private static void insert(String s,Trie trie) {
        for(int i=0;i<s.length();i++) {
            int c = s.charAt(i)-'0';
            if(trie.letter[c] == null) trie.letter[c] = new Trie();
            trie.cur = true;
            trie = trie.letter[c];
        }
        trie.finish = true;
    }
}