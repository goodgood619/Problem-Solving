import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val StringList : List<String> = br.readLine().split(" ")
    var max = -10000001
    var min = 10000001
    for (value in StringList) {
        max = max(value.toInt(),max)
        min = min(value.toInt(),min)
    }
    bw.write(min.toString() + " " + max.toString())
    bw.flush()
    bw.close()
}