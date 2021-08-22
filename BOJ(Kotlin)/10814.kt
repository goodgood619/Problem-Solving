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
    var list : MutableList<User> = mutableListOf()
    for (i in 1..n) {
        val inputList : List<String> = br.readLine().split(" ")
        list.add(User(inputList.get(0).toInt(),i,inputList.get(1)))
    }
   list.sortWith(Comparator<User> {o1, o2 ->
       when {
           o1.age < o2.age -> -1
           o1.age == o2.age -> {
               when {
                   o1.index < o2.index -> -1
                   o1.index  == o2.index -> 0
                   else -> 1
               }
           }
           else -> 1
       }
   })
    for (value in list) {
        bw.write(value.age.toString() + " "+ value.name+"\n")
    }
    bw.flush()
    bw.close()
}

class User(val age : Int, val index : Int, val name : String) {

}