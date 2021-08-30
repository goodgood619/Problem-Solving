import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val gox = intArrayOf(-1,1,0,0)
val goy = intArrayOf(0,0,1,-1)
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    val board = Array(n){CharArray(n)}
    for (i in 0 until n) {
        val s = br.readLine()
        for (j in s.indices) {
            board[i][j] = s[j]
        }
    }
    val visited = Array(n){BooleanArray(n)}
    var cnt = 0
    val arr = arrayListOf<Int>()
    for (i in 0 until n) {
        for (j in 0 until n) {
            if (board[i][j] == '1' && !visited[i][j]) {
                cnt++
                arr.add(dfs(i,j,visited,n,board))
            }
        }
    }

    bw.write(cnt.toString()+"\n")
    arr.sort()
    for (value in arr) {
        bw.write(value.toString()+"\n")
    }
    bw.flush()
    bw.close()
}
fun dfs(x : Int, y : Int, visited : Array<BooleanArray>,n : Int,board : Array<CharArray>) : Int {

    visited[x][y] = true
    var ans = 1
    for (i in 0 until 4) {
        val nx = x+gox[i]
        val ny = y+goy[i]
        if (nx < 0 || nx>= n || ny<0 || ny>=n || visited[nx][ny] || board[nx][ny]=='0') continue
        ans += dfs(nx,ny,visited,n,board)
    }
    return ans
}
