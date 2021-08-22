import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.max
import kotlin.math.min

var ans = 0
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    var deque  : Deque<Int> = ArrayDeque<Int>()
    for (i in 1..n) {
       val addList : List<String> = br.readLine().split(" ")
       val command = addList.get(0)
        when (command) {
            "push" -> {
                deque.addFirst(addList.get(1).toInt())
            }
            "top" -> {
                if (deque.size == 0) {
                    println(-1)
                }
                else {
                    println(deque.first)
                }
            }
            "size" -> {
                println(deque.size)}
            "empty"-> {
                if (deque.size == 0 ) {
                    println(1)
                }
                else {
                    println(0)
                }
            }
            "pop" -> {
                if (deque.size == 0) {
                    println(-1)
                }
                else {
                    println(deque.pollFirst())
                }
            }
        }
    }
}