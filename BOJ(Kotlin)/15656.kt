import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val bw = BufferedWriter(OutputStreamWriter(System.out))
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    st = StringTokenizer(br.readLine())
    val array = mutableListOf<Int>()
    for (i in 0 until n) {
        array.add(st.nextToken().toInt())
    }
    array.sort()
    val permutationArray = mutableListOf<Int>()
    val visited = BooleanArray(n)
    dfs(n, m, 0, array, permutationArray, visited)
    bw.flush()
    bw.close()

}

fun dfs(
    n: Int,
    m: Int,
    count: Int,
    array: MutableList<Int>,
    permutationArray: MutableList<Int>,
    visited: BooleanArray
) {
    if (count == m) {
        for (value in permutationArray) {
            bw.write("$value ")
        }
        bw.write("\n")
        return
    }

    for (i in 0 until n) {
        permutationArray.add(array[i])
        dfs(n, m, count + 1, array, permutationArray, visited)
        permutationArray.removeLast()
    }

}