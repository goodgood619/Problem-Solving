import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val st = StringTokenizer(br.readLine())
    val a = st.nextToken().toInt()
    val b = st.nextToken().toInt()
    bw.write((a + b).toString()+"\n")
    bw.write((a-b).toString()+"\n")
    bw.write((a*b).toString()+"\n")
    bw.write((a/b).toString()+"\n")
    bw.write((a%b).toString()+"\n")
    bw.flush()
    bw.close()
}