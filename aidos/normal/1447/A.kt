

import kotlin.math.max

fun solve(){
    var n = readLine()!!.toInt()
    println(n)
    for(i in 1 until n) {
        print(i)
        print(" ")
    }
    println(n)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}