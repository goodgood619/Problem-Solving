import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val array = mutableListOf<Int>()
    dfs(n,m,0,array)
    bw.flush()
    bw.close()
}

fun dfs(n : Int, m : Int,count : Int, array : MutableList<Int>)  {
    if (count == m) {
        for (value in array) {
            bw.write("$value ")
        }
        bw.write("\n")
        return
    }

    for (i in 0 until n) {
            array.add(i+1)
            dfs(n,m,count+1,array)
            array.removeLast()
    }

}