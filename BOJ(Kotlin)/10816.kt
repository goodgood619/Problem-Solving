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
    var st = StringTokenizer(br.readLine())
    var map = mutableMapOf<Int,Int>()
    for (i in 0 until n) {
        val num = st.nextToken().toInt()
        if (map[num] == null) {
            map[num] = 1
        }
        else {
            var value = map[num]
            map.remove(num)
            if (value != null) {
                map[num] = value + 1
            }

        }
    }

    val m = br.readLine().toInt()
    st = StringTokenizer(br.readLine())
    for (i in 0 until m) {
        val num = st.nextToken().toInt()
        if (map[num] == null) bw.write("0 ")
        else bw.write(map[num].toString()+" ")
    }
    bw.flush()
    bw.close()
}