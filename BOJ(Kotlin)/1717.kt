import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val itemList = br.readLine().split(" ")
    val n = itemList[0].toInt()
    val m = itemList[1].toInt()
    var arr = IntArray(n+1)
    var parent = IntArray(n+1)
    for (i in 0..n) {
        parent[i] = i
    }

    for (i in 0 until m) {
        val itemList = br.readLine().split(" ")
        val choice = itemList[0].toInt()
        val a = itemList[1].toInt()
        val b = itemList[2].toInt()
        if (choice == 0) {
            union(a,b,parent)
        }
        else {
            if (find(a,parent) == find(b,parent)) {
                bw.write("YES\n")
            }
            else bw.write("NO\n")
        }
    }
    bw.flush()
    bw.close()
}

fun find(u : Int, parent : IntArray) : Int {
    if (u == parent[u]) return u
    parent[u] = find(parent[u],parent)
    return parent[u]
}

fun union( u : Int, v : Int, parent : IntArray) {
    val u = find(u,parent)
    val v = find(v, parent)

    if (u==v) return
    parent[u] = v
}