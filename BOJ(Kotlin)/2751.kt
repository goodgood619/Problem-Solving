import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min

var ans = 0
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    var list : MutableList<Int> = mutableListOf()
    for (i in 1..n) {
        list.add(br.readLine().toInt())
    }
    list.sort()
    for (value in list) {
        bw.write(value.toString()+"\n")
    }
    bw.flush()
    bw.close()
}