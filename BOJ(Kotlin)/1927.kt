import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    var pq = PriorityQueue<Int>()
    for (i in 0 until n) {
        val num = br.readLine().toInt()
        when {
            num == 0 -> {
                if (!pq.isEmpty()) bw.write(pq.poll().toString()+"\n")
                else bw.write("0\n")
            }
            else -> {
                pq.add(num)
            }
        }
    }
    bw.flush()
    bw.close()
}