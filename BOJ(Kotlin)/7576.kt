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
    var st = StringTokenizer(br.readLine())
    val m = st.nextToken().toInt()
    val n = st.nextToken().toInt()
    var zeroCount = 0
    val board = Array(n){IntArray(m)}
    for (i in 0 until n) {
        st = StringTokenizer(br.readLine())
        for (j in 0 until m) {
            val item = st.nextToken().toInt()
            board[i][j] = item
            if (board[i][j] == 0) zeroCount++
        }
    }

    if (zeroCount == 0) {
        println(0)
        return
    }

    val ans = bfs(board,n,m)

    for (i in 0 until n) {
        for (j in 0 until m) {
            if (board[i][j] == 0) {
                println(-1)
                return
            }
        }
    }
    println(ans)
}
fun bfs(board : Array<IntArray>,n : Int, m: Int) : Int {
    val visited = Array(n){BooleanArray(m)}
    val dq = ArrayDeque<Tomato>()

    for (i in 0 until n) {
        for(j in 0 until m) {
            if (board[i][j] == 1) {
                visited[i][j] = true
                dq.push(Tomato(i,j,0))
            }
        }
    }

    var ans = 0
    while(!dq.isEmpty()) {
        val x = dq.first.x
        val y = dq.first.y
        val count = dq.first.count
        dq.pop()
        ans = Math.max(ans,count)
        for (i in 0 until 4) {
            val nx = x+gox[i]
            val ny = y+goy[i]
            if (nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || board[nx][ny] == -1 || board[nx][ny] == 1) continue
            visited[nx][ny] = true
            board[nx][ny] = 1
            dq.add(Tomato(nx,ny,count+1))
        }
    }

    return ans
}

class Tomato(val x : Int, val y : Int, val count : Int){}