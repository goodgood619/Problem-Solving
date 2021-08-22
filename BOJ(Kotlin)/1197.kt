import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val itemList = br.readLine().split(" ")
    val v = itemList[0].toInt()
    val e = itemList[1].toInt()
    val parent = IntArray(v+1)
    val pq = PriorityQueue<P> { a, b -> a.cost - b.cost }

    for (i in 1..v) {
        parent[i] = i
    }
    for (i in 0 until e) {
        val inputList = br.readLine().split(" ")
        val here = inputList[0].toInt()
        val next = inputList[1].toInt()
        val cost = inputList[2].toInt()
        pq.add(P(here,next,cost))
    }

    var ans = 0
    while(!pq.isEmpty()) {
        val here = pq.peek().here
        val next = pq.peek().next
        val cost = pq.peek().cost
        pq.poll()
        if (find(here,parent) != find(next,parent)) {
            union(here,next,parent)
            ans += cost
        }
    }
    bw.write(ans.toString())
    bw.flush()
    bw.close()

}

fun find(u : Int, parent : IntArray) : Int{
    if (u == parent[u]) return u
    parent[u] = find(parent[u],parent)
    return parent[u]
}

fun union(u : Int, v : Int, parent : IntArray) {
    val u = find(u,parent)
    val v = find(v,parent)
    if (u == v) return
    parent[u] = v
}

class P(val here : Int, val next : Int, val cost : Int){

}