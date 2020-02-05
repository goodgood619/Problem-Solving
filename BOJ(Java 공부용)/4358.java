import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        Trie trie = new Trie();
        char[] buffer = new char[31];
        int total = 0;
        while((s=br.readLine())!= null) {
            insert(s,trie);
            total++;
        }
        print(0,trie,total,buffer);
        bw.flush();
        bw.close();
    }
    private static class Trie {
        private Trie[] letter;
        private int count;
        private Trie() {
            this.count = 0;
            this.letter = new Trie[96];
        }
    }
    private static void insert(String s,Trie trie) {
        for(int i=0;i<s.length();i++) {
            int c = s.charAt(i)-32;
            if(trie.letter[c] == null) trie.letter[c] = new Trie();

            trie = trie.letter[c];
        }
        trie.count++;
    }
    private static void print(int n, Trie trie,int total,char[] buffer) throws IOException {
        if(trie.count>=1) {
            bw.write(buffer,0,n);
            bw.write(String.format(" %.4f\n",(double)(trie.count*100)/total));
        }
        for(int i=0;i<96;i++) {
            if(trie.letter[i] == null) continue;
            buffer[n] = (char)(i+32);
            print(n+1,trie.letter[i],total,buffer);
        }
    }
}