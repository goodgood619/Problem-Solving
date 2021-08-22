import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val sizeList = br.readLine().split(" ")
    val n = sizeList.get(0).toInt()
    val m = sizeList.get(1).toInt()
    val st = sizeList.get(2).toInt()
    var graph  = Array(n+1){ mutableListOf<Int>()}
    var visited = BooleanArray(n+1)
    for (i in 1..m) {
        val s = br.readLine().split(" ")
        val here = s.get(0).toInt()
        val next = s.get(1).toInt()
        graph[here].add(next)
        graph[next].add(here)
    }

    for (i in 1..n) {
        graph[i].sort()
    }

    dfs(st,graph,visited)
    bw.write("\n")
    visited = BooleanArray(n+1)
    bfs(st,graph,visited)
    bw.flush()
    bw.close()
}

fun dfs(here : Int, graph : Array<MutableList<Int>>,visited : BooleanArray ) {
    visited[here] = true
    bw.write(here.toString()+" ")
    for(i in 0 until graph[here].size) {
        val next = graph[here].get(i)
        if (!visited[next]) {
            dfs(next,graph,visited)
        }
    }
}

fun bfs(here : Int, graph : Array<MutableList<Int>>, visited : BooleanArray) {
    val q = ArrayDeque<Int>()
    q.add(here)
    visited[here] = true
    while(!q.isEmpty()) {
        val here = q.first()
        bw.write(here.toString()+" ")
        q.pollFirst()
        for (i in 0 until graph[here].size) {
            val next = graph[here].get(i)
            if (!visited[next]) {
                visited[next] = true
                q.add(next)
            }
        }
    }
}