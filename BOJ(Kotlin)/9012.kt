import com.sun.org.apache.xpath.internal.operations.Bool
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

    for (i in 0 until n) {
        val dq : Deque<Char> = ArrayDeque()
        val s = br.readLine()
        var check = false
        for (j in s.indices) { // s.indices : Returns the range of valid character indices for this char sequence
            if (s[j] == '(') {
                dq.push(s[j])
            }
            else {
                if (dq.isEmpty()) {
                    check = true
                    break
                }
                dq.pop()
            }
        }

        if (check || !dq.isEmpty()) bw.write("NO\n")
        else bw.write("YES\n")
    }

    bw.flush()
    bw.close()
}