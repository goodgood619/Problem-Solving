import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
val gox = intArrayOf(0,1,-1,0)
val goy = intArrayOf(1,0,0,-1)
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    val t = st.nextToken().toInt()
    val board = Array(n+1){IntArray(m){0}}
    for (i in 1..n) {
        st = StringTokenizer(br.readLine())
        for (j in 0 until m) {
            board[i][j] = st.nextToken().toInt()
        }
    }

    for (r in 0 until t) {
        st = StringTokenizer(br.readLine())
        val x = st.nextToken().toInt()
        val d = st.nextToken().toInt()
        val k = st.nextToken().toInt()
        for (j in x .. n step x) {
            rotate(board,j,d,k,n,m)
        }

        var check = false
        val visited = Array(n+1){BooleanArray(m){false} }

        for (i in 1 .. n) {
            for(j in 0 until m) {
                if (!visited[i][j] && board[i][j] > 0) {
                    val temp = mutableListOf<Int>()
                    dfs(i,j,board[i][j],temp,visited,n,m,board)
                    if (temp.size >= 2) {
                        check = true
                        for(p in 0 until temp.size) {
                            val nx = temp[p] / m
                            val ny = temp[p] % m
                            board[nx][ny] = 0
                        }
                    }
                }
            }
        }


        if (!check) {
            var sum = 0.0
            var ahr = 0.0

            for(i in 1 .. n) {
                for(j in 0 until m) {
                    if(board[i][j] != 0) {
                        sum += board[i][j]
                        ahr++
                    }
                }
            }

            sum /= ahr

            for (i in 1..n) {
                for (j in 0 until m) {
                    if(board[i][j] == 0)  continue
                    if(board[i][j] > sum) board[i][j]--
                    else if(board[i][j] < sum) {
                        board[i][j]++
                    }
                }
            }



        }

    }


    var ans = 0
    for (i in 1..n) {
        for(j in 0 until m) {
            ans += board[i][j]
        }
    }
    println(ans)
}
fun dfs(x :Int, y : Int, num : Int, temp : MutableList<Int>, visited : Array<BooleanArray>, n : Int, m : Int, board : Array<IntArray>) {
    visited[x][y] = true
    temp.add(x*m+y)
    for (i in 0 until 4) {
        val nx = x+gox[i]
        var ny = y+goy[i]
        if (ny < 0) ny = m-1
        if (ny >= m) ny = 0
        if (nx<=0 || nx>n || ny<0 || ny>=m || visited[nx][ny] || board[nx][ny] != num) continue
        dfs(nx,ny,num,temp,visited,n,m,board)
    }
}
fun rotate(board: Array<IntArray>, num: Int, d: Int, k: Int, n : Int, m: Int) {
    val tempBoard = Array(n+1){IntArray(m){0} }

    for (i in 0..n) {
        System.arraycopy(board[i],0,tempBoard[i],0,board[i].size)
    }

    if (d == 0) {
        for (i in 0 until k) {
            val first = board[num][m - 1]
            for (j in 1 until board[num].size) {
                tempBoard[num][j] = board[num][j - 1]
            }
            tempBoard[num][0] = first

            for (r in 0..n) {
                System.arraycopy(tempBoard[r],0,board[r],0,tempBoard[r].size)
            }
        }
    } else {
        for (i in 0 until k) {
            val first = board[num][0]
            for (j in 0 until board[num].size - 1) {
                tempBoard[num][j] = board[num][j + 1]
            }
            tempBoard[num][m - 1] = first

            for (r in 0..n) {
                System.arraycopy(tempBoard[r],0,board[r],0,tempBoard[r].size)
            }
        }
    }

    for (r in 0..n) {
        System.arraycopy(tempBoard[r],0,board[r],0,tempBoard[r].size)
    }
}