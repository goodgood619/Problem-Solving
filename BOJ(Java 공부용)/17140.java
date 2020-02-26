import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        r--;
        c--;
        int[][] board = new int[100][100];
        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int cnt = 0;
        for (int p = 0; p <= 100; p++) {
            if (check(r, c, k, board)) {
                System.out.println(cnt);
                return;
            }
            int rowmax = 0, colmax = 0;
            for (int i = 0; i < 100; i++) {
                int temp = 0;
                for (int j = 0; j < 100; j++) {
                    if (board[i][j] != 0) temp++;
                    else break;
                }
                colmax = max(colmax, temp);
            }
            for (int j = 0; j < 100; j++) {
                int temp = 0;
                for (int i = 0; i < 100; i++) {
                    if (board[i][j] != 0) temp++;
                    else break;
                }
                rowmax = max(rowmax, temp);
            }
            //행연산
            if (rowmax >= colmax) {

                for (int i = 0; i < 100; i++) {
                    HashMap<Integer, Integer> map1 = new HashMap<>();
                    for (int j = 0; j < 100; j++) {
                        if (board[i][j] == 0) continue;
                        else {
                            if (map1.get(board[i][j]) == null) {
                                map1.put(board[i][j], 1);
                            } else {
                                int value = map1.get(board[i][j]);
                                value++;
                                map1.remove(board[i][j]);
                                map1.put(board[i][j], value);
                            }
                        }
                    }
                    ArrayList<p> v = new ArrayList<>();
                    for (Integer key : map1.keySet()) {
                        v.add(new p(key, map1.get(key)));
                    }
                    v.sort((a, b) -> {
                        if (a.numcnt < b.numcnt) return -1;
                        else if (a.numcnt > b.numcnt) return 1;
                        else {
                            if (a.num < b.num) return -1;
                            else if (a.num > b.num) return 1;
                            else return 0;
                        }
                    });
                    if (v.size() == 0) continue;
                    for (int j = 0; j < 100; j++) board[i][j] = 0;
                    //다시 넣기
                    int idy = 0;
                    for (int j = 0; j < v.size(); j++) {
                        if (idy == 100) break;
                        board[i][idy++] = v.get(j).num;
                        board[i][idy++] = v.get(j).numcnt;
                    }
                }
            }
            //열연산
            else {
                for (int j = 0; j < 100; j++) {
                    HashMap<Integer, Integer> map1 = new HashMap<>();
                    for (int i = 0; i < 100; i++) {
                        if (board[i][j] == 0) continue;
                        else {
                            if (map1.get(board[i][j]) == null) {
                                map1.put(board[i][j], 1);
                            } else {
                                int value = map1.get(board[i][j]);
                                value++;
                                map1.remove(board[i][j]);
                                map1.put(board[i][j], value);
                            }
                        }
                    }
                    ArrayList<p> v = new ArrayList<>();
                    for (Integer key : map1.keySet()) {
                        v.add(new p(key, map1.get(key)));
                    }
                    v.sort((a, b) -> {
                        if (a.numcnt < b.numcnt) return -1;
                        else if (a.numcnt > b.numcnt) return 1;
                        else {
                            if (a.num < b.num) return -1;
                            else if (a.num > b.num) return 1;
                            else return 0;
                        }
                    });
                    if (v.size() == 0) continue;
                    for (int i = 0; i < 100; i++) board[i][j] = 0;
                    //다시 넣기
                    int idx = 0;
                    for (int i = 0; i < v.size(); i++) {
                        if (idx == 100) break;
                        board[idx++][j] = v.get(i).num;
                        board[idx++][j] = v.get(i).numcnt;
                    }

                }
            }
            cnt++;
        }
        System.out.println(-1);
    }

    private static class p {
        int num, numcnt;

        private p(int num, int numcnt) {
            this.num = num;
            this.numcnt = numcnt;
        }
    }

    private static boolean check(int r, int c, int k, int[][] board) {
        if (board[r][c] == k) return true;
        else return false;
    }
}