import java.util.*
import kotlin.math.min

fun main()=with(Scanner(System.`in`)){
    val s = readLine()!!.split(" ")
    val n = s[0].toInt()
    val k = s[1].toInt()

    val array = IntArray(n+1){0}
    for(i in 1..n){
        array[i] = readLine()!!.toInt()
    }
    array.sort()
    val dp = IntArray(k+1){-1}

    for (i in 1..n){
        if(array[i]>k) break
        dp[array[i]] = 1
    }

    for(i in 2..k){
        if(dp[i]!=1){
            for (j in 1 until i){
                if(j>i/2) break
                if(dp[i-j]!=-1 && dp[j]!= -1) {
                    if(dp[i]==-1){
                        dp[i] = 99999999
                    }
                    dp[i] = min(dp[i],dp[i - j] + dp[j])
                }
            }

        }
    }
    print(dp[k])
}