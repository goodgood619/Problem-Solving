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

    val st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    var list : MutableList<WordList> = mutableListOf()
    for (i in 1..n) {
        val item = br.readLine()
        list.add(WordList(item,i))
    }
   list.sortWith { o1, o2 ->
       when {
           o1.alpha.length < o2.alpha.length -> -1
           o1.alpha.length == o2.alpha.length -> {
               o1.alpha.compareTo(o2.alpha)
           }
           else -> 1
       }
   }
    var setList = mutableSetOf<String>()
    for (value in list) {
        setList.add(value.alpha)
    }
    for (value in setList) {
        bw.write(value + "\n")
    }
    bw.flush()
    bw.close()
}

class WordList(val alpha : String, val index : Int) {}