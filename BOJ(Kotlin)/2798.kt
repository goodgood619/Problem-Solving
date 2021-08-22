import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min

var ans = 0
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val StringList : List<String> = br.readLine().split(" ")
    val visited : BooleanArray = BooleanArray(n)
    BlackZack(0,0,3,StringList,0,visited,m)
    bw.write(ans.toString()+"\n")
    bw.flush()
    bw.close()
}

fun BlackZack(idx : Int, cnt : Int, depth : Int, s : List<String>, total : Int, visited : BooleanArray, m : Int) {
    if (cnt == depth) {
        if (total <= m ) ans = max(ans, total)
        return
    }
    for (i in idx until s.size) {
        val num = s.get(i).toInt()
        if (!visited[i]) {
            visited[i] = true
            BlackZack(idx + 1, cnt + 1, depth, s, total + num, visited, m )
            visited[i] = false
        }
    }
}