import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()) , m = Integer.parseInt(st.nextToken());
        Trie trie = new Trie();
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            insert(s,trie);
        }
        int cnt = 0;
        for(int i=0;i<m;i++) {
            String s = br.readLine();
            if(check(s,0,trie)) cnt++;
        }
        bw.write(cnt+"\n");
        bw.flush();
        bw.close();
    }
    private static class Trie {
        private Trie[] letter;
        private boolean finish;
        private Trie() {
            this.letter = new Trie[26];
            this.finish = false;
        }
    }
    private static boolean check(String s, int here,Trie trie) {
        if(here == s.length() && trie.finish) return true;
        else if(here == s.length()) return false;
        if(trie.letter[s.charAt(here)-'a']!=null && check(s,here+1,trie.letter[s.charAt(here)-'a'])) return true;
        else return false;
    }
    private static void insert(String s,Trie trie) {
        for(int i=0;i<s.length();i++) {
            int c = s.charAt(i)-'a';
            if(trie.letter[c] == null) trie.letter[c] = new Trie();
            trie = trie.letter[c];
        }
        trie.finish = true;
    }
}