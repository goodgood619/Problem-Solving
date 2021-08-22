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
    val res = factorial(n)
    bw.write(res.toString())
    bw.flush()
    bw.close()
}
fun factorial(fact : Int) : Int {
    if (fact == 0) return 1
    else return fact * factorial(fact-1)
}