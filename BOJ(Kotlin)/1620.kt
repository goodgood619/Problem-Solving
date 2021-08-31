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
    val m = st.nextToken().toInt()
    val map1 = mutableMapOf<Int,String>()
    val map2 = mutableMapOf<String,Int>()
    for (i in 1..n) {
        val s = br.readLine()
        map1[i] = s
        map2[s] = i
    }

    for (i in 0 until m) {
        val s = br.readLine()
        if(s[0] in '1'..'9') {
            bw.write(map1[s.toInt()]+"\n")
        }
        else {
            bw.write(map2[s].toString()+"\n")
        }
    }
    bw.flush()
    bw.close()
}