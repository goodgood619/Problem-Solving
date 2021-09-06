import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
var ans = 0
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val board = Array(n){IntArray(m)}
    for (i in 0 until n) {
        st = StringTokenizer(br.readLine())
        for (j in 0 until m) {
            board[i][j] = st.nextToken().toInt()
        }
    }

    val visited = Array(n){BooleanArray(m)}
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (!visited[i][j]) {
                dfs(i*m+j,board,visited,0,n,m,n*m+m)
            }
        }
    }
    println(ans)
}

fun dfs(index : Int, board : Array<IntArray>, visited : Array<BooleanArray>, total : Int,n : Int, m : Int, end : Int) {

    if (index == end) {
        ans = Math.max(ans,total)
        return
    }
    val x = index / m
    val y = index % m
    var tempTotal = total
    for (i in 0 .. 3) {
        when (i) {
            0 -> {
                if(!check(x,y,x,y+1,x-1,y,visited,n,m)) {
                    continue
                }
                makeVisited(x,y,x,y+1,x-1,y,visited)
                tempTotal += makeTotal(x,y,x,y+1,x-1,y,board)
                dfs(index+1,board,visited,tempTotal,n,m,end)
                tempTotal -= makeTotal(x,y,x,y+1,x-1,y,board)
                makeUnVisited(x,y,x,y+1,x-1,y,visited)
            }
            1-> {
                if(!check(x,y,x-1,y,x,y-1,visited,n,m)) {
                    continue
                }

                makeVisited(x,y,x-1,y,x,y-1,visited)
                tempTotal += makeTotal(x,y,x-1,y,x,y-1,board)
                dfs(index+1,board,visited,tempTotal,n,m,end)
                tempTotal -= makeTotal(x,y,x-1,y,x,y-1,board)
                makeUnVisited(x,y,x-1,y,x,y-1,visited)
            }
            2 -> {
                if(!check(x,y,x,y-1,x+1,y,visited,n,m)) {
                    continue
                }
                makeVisited(x,y,x,y-1,x+1,y,visited)
                tempTotal += makeTotal(x,y,x,y-1,x+1,y,board)
                dfs(index+1,board,visited,tempTotal,n,m,end)
                tempTotal -= makeTotal(x,y,x,y-1,x+1,y,board)
                makeUnVisited(x,y,x,y-1,x+1,y,visited)
            }
            3-> {
                if(!check(x,y,x+1,y,x,y+1,visited,n,m)) {
                    continue
                }
                makeVisited(x,y,x+1,y,x,y+1,visited)
                tempTotal += makeTotal(x,y,x+1,y,x,y+1,board)
                dfs(index+1,board,visited,tempTotal,n,m,end)
                tempTotal -= makeTotal(x,y,x+1,y,x,y+1,board)
                makeUnVisited(x,y,x+1,y,x,y+1,visited)
            }
        }
    }
    dfs(index+1,board,visited,tempTotal,n,m,end)
    ans = Math.max(ans,tempTotal)
}

fun check(x : Int, y : Int, nx : Int, ny : Int, nx2 : Int, ny2: Int, visited : Array<BooleanArray>,n : Int, m : Int) : Boolean {

    if (x < 0 || x>=n || y<0 || y>=m || visited[x][y] ) return false
    if (nx <0 || nx>=n || ny <0 || ny>=m || visited[nx][ny]) return false
    if (nx2<0 || nx2>=n || ny2<0 || ny2>=m || visited[nx2][ny2]) return false
    return true
}

fun makeTotal(x : Int, y : Int, nx : Int, ny : Int, nx2 : Int, ny2: Int,board : Array<IntArray>) : Int {
    return board[x][y]*2 + board[nx][ny] + board[nx2][ny2]
}

fun makeVisited(x : Int, y : Int, nx : Int, ny : Int, nx2 : Int, ny2: Int, visited : Array<BooleanArray>)  {

    visited[x][y] = true
    visited[nx][ny] = true
    visited[nx2][ny2] = true
}

fun makeUnVisited(x : Int, y : Int, nx : Int, ny : Int, nx2 : Int, ny2: Int, visited : Array<BooleanArray>) {

    visited[x][y] = false
    visited[nx][ny] = false
    visited[nx2][ny2] = false
}