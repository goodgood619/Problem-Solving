import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    val arr = mutableListOf<Pos>()
    for (i in 0 until n) {
        val st = StringTokenizer(br.readLine())
        val name = st.nextToken()
        val kor = st.nextToken().toInt()
        val eng = st.nextToken().toInt()
        val math = st.nextToken().toInt()
        arr.add(Pos(kor,eng,math,name))
    }

    arr.sortWith {a,b ->
        when {
            a.kor > b.kor -> -1
            a.kor < b.kor -> 1
            else -> {
                when {
                    a.eng < b.eng -> -1
                    a.eng > b.eng -> 1
                    else -> {
                        when {
                            a.math > b.math -> -1
                            a.math < b.math -> 1
                            else -> a.name.compareTo(b.name)
                        }
                    }
                }
            }
        }
    }

    for (value in arr) {
        bw.write(value.name+"\n")
    }
    bw.flush()
    bw.close()
}
// parameter에 val을 붙이고 안붙이고 무슨 차이지?
class Pos(val kor : Int, val eng: Int, val math: Int, val name : String){}