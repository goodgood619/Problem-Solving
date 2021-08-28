import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.max

fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toLong()
    var arr = LongArray(n)
    var left : Long = 1
    var right : Long = 0

    for (i in 0 until n) {
        arr[i] = br.readLine().toLong()
        right = max(right,arr[i])
    }

    while (left <= right) {
        val mid = (left + right ) / 2
        var cnt : Long = 0
        for (i in 0 until arr.size) {
            cnt += (arr[i] / mid)
        }

        if (cnt < m) right = mid -1
        else left = mid + 1
    }
    left--
    bw.write(left.toString()+"\n")
    bw.flush()
    bw.close()

}