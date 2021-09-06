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
    dfs(0,n, m, 0, array, permutationArray)
    bw.flush()
    bw.close()

}

fun dfs(index : Int,
    n: Int,
    m: Int,
    count: Int,
    array: MutableList<Int>,
    permutationArray: MutableList<Int>,
) {
    if (count == m) {
        for (value in permutationArray) {
            bw.write("$value ")
        }
        bw.write("\n")
        return
    }

    var prevNum = -1
    for (i in index until n) {
        if (prevNum != array[i]) {
            prevNum = array[i]
            permutationArray.add(array[i])
            dfs(i,n, m, count + 1, array, permutationArray)
            permutationArray.removeLast()
        }
    }

}