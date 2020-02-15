import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] eat = new int[n][n];
        int[][] board = new int[n][n];
        int[][][] tree = new int[n][n][1002];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                eat[i][j] = Integer.parseInt(st.nextToken());
                board[i][j] = 5;
            }
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), age = Integer.parseInt(st.nextToken());
            x--;
            y--;
            tree[x][y][age]++;
        }
        for (int i = 0; i < k; i++) {
            springandsummer(tree, board, n);
            fall(tree, n);
            winter(board, eat, n);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p < 1000; p++) {
                    ans += tree[i][j][p];
                }
            }
        }
        System.out.println(ans);
    }

    private static void springandsummer(int[][][] tree, int[][] board, int n) {
        ArrayList<p>[][] die = new ArrayList[n][n];
        ArrayList<Integer>[][] live = new ArrayList[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                die[i][j] = new ArrayList<>();
                live[i][j] = new ArrayList<>();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 500; k++) {
                    int treecnt = tree[i][j][k];
                    if (treecnt == 0) continue;
                    int p = k, ok = 0, treecnt2 = treecnt;
                    while (p <= board[i][j] && treecnt > 0) {
                        board[i][j] -= p;
                        ok++;
                        treecnt--;
                        live[i][j].add(k + 1);
                    }
                    int rest = treecnt2 - ok;
                    if (rest > 0) {
                        tree[i][j][k] -= rest;
                        die[i][j].add(new p(k, rest));
                    }
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < live[i][j].size(); k++) {
                    int age = live[i][j].get(k);
                    tree[i][j][age]++;
                    tree[i][j][age - 1]--;
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < die[i][j].size(); k++) {
                    int age = die[i][j].get(k).age, cnt = die[i][j].get(k).cnt;
                    board[i][j] += age / 2 * cnt;
                }
            }
        }
    }

    private static void fall(int[][][] tree, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 5; k <= 1000; k += 5) {
                    if (tree[i][j][k] == 0) continue;

                    for (int p = 0; p < 8; p++) {
                        int nx = i + gox[p], ny = j + goy[p];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        tree[nx][ny][1] += tree[i][j][k];
                    }
                }
            }
        }
    }

    private static void winter(int[][] board, int[][] eat, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] += eat[i][j];
            }
        }
    }

    private static class p {
        int age, cnt;

        private p(int age, int cnt) {
            this.cnt = cnt;
            this.age = age;
        }
    }
}