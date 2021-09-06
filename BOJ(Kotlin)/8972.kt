import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val gox = intArrayOf(0, 1, 1, 1, 0, 0, 0, -1, -1, -1)
val goy = intArrayOf(0, -1, 0, 1, -1, 0, 1, -1, 0, 1)
fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var st = StringTokenizer(br.readLine())
    val n = st.nextToken().toInt()
    val m = st.nextToken().toInt()
    var board = Array(n) { CharArray(m) }
    for (i in 0 until n) {
        st = StringTokenizer(br.readLine())
        board[i] = st.nextToken().toCharArray()
    }
    val moveArray = br.readLine()

    var sx = 0
    var sy = 0
    var dq = ArrayDeque<Pos>()
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (board[i][j] == 'I') {
                sx = i
                sy = j
            } else if (board[i][j] == 'R') {
                dq.add(Pos(i, j))
            }
        }
    }

    var move = 0
    var check = false
    for (i in moveArray) {
        var tempBoard = Array(n) { CharArray(m) { '.' } }
        val choice = i.toInt() - 48
        val nx = sx + gox[choice]
        val ny = sy + goy[choice]
        tempBoard[sx][sy] = '.'
        sx = nx
        sy = ny
        move++
        if (board[sx][sy] != 'R') {
            tempBoard[sx][sy] = 'I'
        } else {
            check = true
            break
        }


        val tempDq = ArrayDeque<Pos>()
        val visited = Array(n) { BooleanArray(m) }

        while (!dq.isEmpty()) {
            val x = dq.first.x
            val y = dq.first.y
            dq.pop()
            if (x == sx) {
                if (y < sy) {
                    tempDq.add(Pos(x, y + 1))
                } else {
                    tempDq.add(Pos(x, y - 1))
                }
            } else if (y == sy) {
                if (x < sx) {
                    tempDq.add(Pos(x + 1, y))
                } else {
                    tempDq.add(Pos(x - 1, y))
                }
            } else {
                if (x < sx && y < sy) {
                    tempDq.add(Pos(x + 1, y + 1))
                } else if (x < sx && y > sy) {
                    tempDq.add(Pos(x + 1, y - 1))
                } else if (x > sx && y < sy) {
                    tempDq.add(Pos(x - 1, y + 1))
                } else if (x > sx && y > sy) {
                    tempDq.add(Pos(x - 1, y - 1))
                }
            }
        }
        val map = mutableMapOf<Pos, Int>()
        while (!tempDq.isEmpty()) {
            val x = tempDq.first.x
            val y = tempDq.first.y
            if (x == sx && y == sy) {
                check = true
                break
            }
            if (map[Pos(x, y)] == null) {
                map[Pos(x, y)] = 1
            } else {
                var value = map[Pos(x, y)]
                map.remove(Pos(x, y))
                if (value != null) {
                    map[Pos(x, y)] = value + 1
                }
            }
            tempDq.pop()
        }

        while (!dq.isEmpty()) {
            dq.pop()
        }

        for (key in map) {
            if (key.value == 1) {
                dq.add(Pos(key.key.x, key.key.y))
                tempBoard[key.key.x][key.key.y] = 'R'
            }
        }

        if (check) {
            break
        }

        board = tempBoard
    }

    if (check) {
        bw.write("kraj $move\n")
        bw.flush()
        bw.close()
        return
    }

    for (i in 0 until n) {
        for (j in 0 until m) {
            bw.write(board[i][j].toString())
        }
        bw.write("\n")
    }
    bw.flush()
    bw.close()


}

data class Pos(val x: Int, val y: Int) {}