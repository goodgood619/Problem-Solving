import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val gox = intArrayOf(-1,1,0,0)
val goy = intArrayOf(0,0,1,-1)
val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val array = mutableListOf<Int>()
    val visited = BooleanArray(n)
    dfs(n,m,0,array,visited)
    bw.flush()
    bw.close()
}

fun dfs(n : Int, m : Int,count : Int, array : MutableList<Int>, visited : BooleanArray)  {
    if (count == m) {
        for (value in array) {
            bw.write("$value ")
        }
        bw.write("\n")
        return
    }

    for (i in 0 until n) {
        if (!visited[i]) {
            visited[i] = true
            array.add(i+1)
            dfs(n,m,count+1,array,visited)
            array.removeLast()
            visited[i] = false
        }
    }

}