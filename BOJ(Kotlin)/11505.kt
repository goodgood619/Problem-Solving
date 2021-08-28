import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val mod = 1000000007

fun main(args : Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val k = st.nextToken().toInt()
    var h = 1
    while(h<n) h *= 2
    val v = LongArray(h*2){0}

    for (i in 1 .. n) {
        val num = br.readLine().toLong()
        update(i,num,h,v)
    }

    for (i in 0 .. m+k -1) {
        st = StringTokenizer(br.readLine())
        val a = st.nextToken().toInt()
        val b = st.nextToken().toInt()
        val c : Long = st.nextToken().toLong()
        if (a == 1) {
            update(b,c,h,v)
        }
        else {
            val ans = query(1,b,c.toInt(),1,h,v)
            bw.write(ans.toString()+"\n")
        }
    }
    bw.flush()
    bw.close()
}

fun update(i : Int, value : Long, h : Int, v : LongArray) {
    var index = i
    index += h-1

    v[index] = value
    while (index > 1) {
        index /= 2
        v[index] = (v[index*2] * v[index*2+1] ) % mod
    }
}

fun query(nodeNum : Int, left : Int, right : Int, nodeLeft : Int, nodeRight: Int, v : LongArray) : Long {
    if (nodeLeft > right || nodeRight < left)  return 1
    else if (left <= nodeLeft && nodeRight <= right) return v[nodeNum]
    val mid  = (nodeLeft+nodeRight) / 2
    return (query(nodeNum * 2, left, right,nodeLeft,mid,v) *  query(nodeNum * 2 +1, left,right, mid+1,nodeRight, v)) %mod
}