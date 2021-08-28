import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    val m = br.readLine().toInt()
    val board = Array(n + 1) { IntArray(n + 1) { 1e9.toInt() } }
    for (i in 1..n) {
        board[i][i] = 0
    }

    for (i in 1..m) {
        val st = StringTokenizer(br.readLine())
        val here = st.nextToken().toInt()
        val next = st.nextToken().toInt()
        val cost = st.nextToken().toInt()
        if (board[here][next] > cost) board[here][next] = cost
    }

    for (k in 1..n) {
        for (i in 1..n) {
            for (j in 1..n) {
                if (board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j]
            }
        }
    }

    for (i in 1..n) {
        for (j in 1..n) {
            if (i ==j || board[i][j] == 1e9.toInt()) bw.write("0 ")
            else bw.write(board[i][j].toString()+" ")
        }
        bw.write("\n")
    }
    bw.flush()
    bw.close()
}