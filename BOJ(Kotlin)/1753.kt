import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var st = StringTokenizer(br.readLine())
    val v = st.nextToken().toInt()
    val e = st.nextToken().toInt()
    val graph = Array(v+1){ mutableListOf<NextNode>()}
    val start = br.readLine().toInt()
    for (i in 0 until e) {
        st= StringTokenizer(br.readLine())
        val here = st.nextToken().toInt()
        val next = st.nextToken().toInt()
        val cost = st.nextToken().toInt()
        graph[here].add(NextNode(next,cost))
    }

    dijk(start,v,graph)
}
fun dijk(start : Int, v : Int,  graph : Array<MutableList<NextNode>>) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

        val pq = PriorityQueue<HereNode> { a, b ->
            when {
                a.cost < b.cost -> -1
                a.cost > b.cost -> 1
                else -> {
                    when {
                        a.here < b.here -> -1
                        a.here > b.here -> 1
                        else -> 0
                    }
                }
            }
        }

    val dist = IntArray(v+1){Integer.MAX_VALUE}
    dist[start] = 0
    pq.add(HereNode(start,0))

    while(!pq.isEmpty()) {
        val here = pq.peek().here
        val cost = pq.peek().cost
        pq.poll()
        if (dist[here] < cost) continue
        for (i in 0 until graph[here].size) {
            val next = graph[here][i].next
            val nextCost = graph[here][i].cost

            if (dist[next] > nextCost + dist[here]) {
                dist[next] = nextCost + dist[here]
                pq.add(HereNode(next,dist[next]))
            }
        }
    }

    for (i in 1..v) {
        if (dist[i] == Int.MAX_VALUE) bw.write("INF\n")
        else bw.write(dist[i].toString()+"\n")
    }

    bw.flush()
    bw.close()
}

class NextNode (val next : Int, val cost : Int){}
class HereNode (val here : Int, val cost : Int){}