import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    st = StringTokenizer(br.readLine())
    val array = mutableListOf<Int>()
    for (i in 0 until n) {
        array.add(st.nextToken().toInt())
    }
    val k = br.readLine().toInt()
    var curTotal: Long = 0
    var ans: Long = 0
    var left = 0
    var right = 0

    while (left <= right) {
        if (curTotal > k) {
            ans++
            ans += (n - right)
            curTotal -= array[left]
            left++
        } else {
            if (right >= n) {
                break
            }
            curTotal += array[right]
            right++
        }
    }
    println(ans)
}