import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val n = br.readLine().toInt()
    val m = br.readLine().toInt()
    val graph : Array<MutableList<Int>> = Array(n+1){ mutableListOf<Int>()}
    val visited = BooleanArray(n+1)
    for (i in 0 until m) {
        val st = StringTokenizer(br.readLine())
        val here = st.nextToken().toInt()
        val next = st.nextToken().toInt()
        graph[here].add(next)
        graph[next].add(here)
    }

    dfs(1, graph,visited)
    var cnt = 0
    for (i in 2..n) {
        if (visited[i]) cnt++
    }
    bw.write(cnt.toString())
    bw.flush()
    bw.close()
}

fun dfs(here : Int, graph : Array<MutableList<Int>>,visited : BooleanArray ) {
    visited[here] = true
    for(i in 0 until graph[here].size) {
        val next = graph[here].get(i)
        if (!visited[next]) {
            dfs(next,graph,visited)
        }
    }
}