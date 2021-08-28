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
    val treeMap = TreeMap<Long,Int>()
    for (i in 0 .. n-1) {
        val num : Long = br.readLine().toLong()
        if (treeMap[num] == null) {
            treeMap[num] = 1
        }
        else {
            val value  = treeMap[num]
            treeMap.remove(num)
            if (value != null) {
                treeMap[num] = value + 1
            }
        }
    }

    val it = treeMap.iterator()
    var max = 0
    var temp : Long = 0
    while(it.hasNext()) {
        var key : Long = it.next().key
        val value = treeMap[key]
        if (max < value!!) {
            max = value
            temp = key
        }
    }
    bw.write(temp.toString())
    bw.flush()
    bw.close()
}
