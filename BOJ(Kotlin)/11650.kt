import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.Comparator
import kotlin.collections.ArrayList

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    val arr = mutableListOf<Pos>()
    for (i in 0 until n) {
        val st = StringTokenizer(br.readLine())
        val x = st.nextToken().toInt()
        val y = st.nextToken().toInt()
        arr.add(Pos(x,y))
    }

    arr.sortWith { o1, o2 ->
        when {
            o1.x < o2.x -> -1
            o1.x > o2.x -> 1
            else -> {
                when {
                    o1.y < o2.y -> -1
                    o1.y > o2.y -> 1
                    else -> 0
                }
            }
        }
    }

    for (value in arr) {
        bw.write(value.x.toString()+" "+value.y.toString()+"\n")
    }
    bw.flush()
    bw.close()
}
class Pos(val x : Int, val y: Int){}
