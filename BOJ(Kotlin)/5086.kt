import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    while (true) {

        val st = StringTokenizer(br.readLine())
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        if (a == 0 && b==0) break
        if (b % a== 0 && b>a) println("factor")
        else if (a%b ==0 && a>b) println("multiple")
        else println("neither")
    }
}