import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val x = st.nextToken().toInt()
    val StringList : List<String> = br.readLine().split(" ")
    for (value in StringList) {
        val item = value.toInt()
        if (item < x.toInt()) {
            bw.write("$item ")
        }
    }
    bw.flush()
    bw.close()
}