import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()

    val arr = IntArray(n)

    for (i in 0 until n) {
        st = StringTokenizer(br.readLine())
        arr[i] = st.nextToken().toInt()
    }

    Arrays.sort(arr)

    for (i in n-1 downTo  0 ) {
        bw.write(arr[i].toString()+"\n")
    }

    bw.flush()
    bw.close()

}