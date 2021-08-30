import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = br.readLine().toInt()
    for (i in 0 until t) {
        val l = br.readLine().toInt()
        var st = StringTokenizer(br.readLine())
        val sx = st.nextToken().toInt()
        val sy = st.nextToken().toInt()
        st = StringTokenizer(br.readLine())
        val ex = st.nextToken().toInt()
        val ey = st.nextToken().toInt()
        bw.write(bfs(l,sx,sy,ex,ey).toString()+"\n")
    }
    bw.flush()
    bw.close()
}
fun bfs(l : Int, sx : Int, sy : Int, ex : Int, ey : Int) : Int {
    val visited = Array(l){BooleanArray(l)}
    val dq = ArrayDeque<Night>()
    dq.add(Night(sx,sy,0))
    val gox = intArrayOf(-1,-1,-2,-2,1,1,2,2)
    val goy = intArrayOf(-2,2,-1,1,-2,2,-1,1)
    var ans = 0
    while(!dq.isEmpty()) {
        val x = dq.first.x
        val y = dq.first.y
        val move = dq.first.move
        dq.pollFirst()
        if (x == ex && y == ey) {
            ans = move
            break
        }
        for (i in 0..7) {
            val nx = x + gox[i]
            val ny = y+goy[i]
            if (nx < 0 || nx>= l || ny<0 || ny>=l || visited[nx][ny]) continue
            dq.add(Night(nx,ny,move+1))
            visited[nx][ny] = true
        }
    }

    return ans
}

class Night(val x : Int, val y : Int, val move : Int){}