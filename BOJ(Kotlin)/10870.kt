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
    val res = fibo(n)
    bw.write(res.toString()+"\n")
    bw.flush()
    bw.close()
}
fun fibo(n : Int) : Int {
    if (n == 0 || n == 1) return n
    else return fibo(n-1 )+ fibo(n-2)
}