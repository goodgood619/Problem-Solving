import java.util.*;
class Solution {
    public int solution(int[][] board, int[] moves) {
        int score=0;
        Deque<Integer> stack = new ArrayDeque<>();
        for(int j=0;j<moves.length;j++) {
            int sy = moves[j];
            sy--;
            int pick = -1;
            for(int i=0;i<board.length;i++) {
                if(board[i][sy] !=0) {
                    pick = board[i][sy];
                    board[i][sy]=0;
                    break;
                }
            }
            
            if(pick==-1) continue; //인형이 없는 경우
            if(stack.isEmpty())  stack.add(pick);
            else {
                int top = stack.peekLast();
                if(top== pick){ 
                    score +=2;
                    stack.pollLast();
                    continue;
                }
                stack.add(pick);
            }
        }
        return score;
    }
}