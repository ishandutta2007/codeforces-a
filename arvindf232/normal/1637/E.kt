
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}

object IO{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC

    var warningActive = true
    var fakein = StringBuilder()

    private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)

    private val char: Char
        get() {
            while (bId == size) {
                size = IN.read(buf) // no need for checked exceptions
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextLong(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextString():String{
        val ret = StringBuilder()
        while (true){
            c = char
            if(!isWhitespace(c)){ break}
        }
        ret.append(c)
        while (true){
            c = char
            if(isWhitespace(c)){ break}
            ret.append(c)
        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
    }
    fun rerouteInput(){
        if(warningActive){
            put("You forgot to disable tests you digital dummy!")
            println("You forgot to disable tests you digital dummy!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):IntArray{
    val ret = IntArray(n);repeat(n){ret[it] = getint()};return ret
}
fun getlineL(n:Int):LongArray{
    val ret = LongArray(n);repeat(n){ret[it] = getlong()};return ret
}
fun getstr():String{ return IO.nextString() }

val List<Char>.ret:String
get() = this.joinToString("")
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
    var str = ""
    if(this is String){ str = this
    }else if(this is Int){ str = this.toString()
    }else if(this is Long){ str = this.toString()
    }
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){
    if(!a){throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
const val withBruteForce = false
const val randCount = 100
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount
        //safety checks
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Modding a wrong prime!")
        }

        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                IO.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                IO.rerouteInput()
            }
            currentAnswer = null
            currentBruteAnswer = null
            onecase()
        }
        if(withBruteForce){
            put("Checked ${answersChecked}")
        }
        if(t == 1 && mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            println("Time $dt ms ")
        }
    }
    inline fun singleCase(a:solve.()->Unit){
        val t = if(mode != solveMode.rand){1} else randCount
        repeat(t) { a() }
    }
    fun rand(a:()->Unit){
        this.rand = a
    }
    fun tc(id:Int = 0,a:()->Unit){
        TC[id] = a
    }
    inline fun brute(a:()->Unit){
        if(withBruteForce){
            a()
        }
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }


    var currentAnswer:String? = null
    var currentBruteAnswer:String? = null
    fun answer(a:Any){
        currentAnswer = a.toString()
        if(currentBruteAnswer != null){
            checkAnswer()
        }
    }
    fun put2(a:Any){answer(a);put(a) }

    fun bruteAnswer(a:Any){
        currentBruteAnswer = a.toString()
        if(currentAnswer != null){
            checkAnswer()
        }
    }
    fun checkAnswer(){
        if(currentAnswer != currentBruteAnswer){
            throw Exception("Failed Test: BF $currentBruteAnswer Current $currentAnswer")
        }
        answersChecked ++
    }
}
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this * 1L * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
// 3. conveniecen conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val Char.code :Int get() = this.toInt() -  'a'.toInt()
//3. hard to write stuff
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val mint:MutableList<Int> get() = mutableListOf<Int>()
val mong:MutableList<Long> get() = mutableListOf<Long>()




var A:List<Int> = listOf()
var B:List<Int> = listOf()

class pp(val first:Int, val second:Int):Comparable<pp>{
    override fun compareTo(other:pp):Int {
        val x = A[this.first] + B[this.second]
        val y = (A[other.first] + B[other.second])
        if(x != y) {
            return x.compareTo(y)
        }else{
            if(this.first != other.first){
                return this.first.compareTo(other.first)
            }
            return this.second.compareTo(other.second)
        }
    }

    override fun equals(other:Any?):Boolean {
        if(this === other) return true
        if(javaClass != other?.javaClass) return false

        other as pp

        if(first != other.first) return false
        if(second != other.second) return false

        return true
    }

    override fun hashCode():Int {
        return javaClass.hashCode()
    }
}

const val singleCase = false
fun main(){
    solve.cases{
        val n = getint()
        val m = getint()
        val L = getline(n)
        val bad = HashSet<Long>(m/3 * 4 + 5 )

        repeat(m){
            val a = getint()
             val b = getint()
            val aa = minOf(a,b)
            val bb = maxOf(a,b)
            bad.add(aa.toLong() shl 32 xor bb.toLong() )
        }
        val counts = mutableMapOf<Int,Int>()
        for(a in L){
            counts[a] = counts.getOrDefault(a,0) + 1
        }
        fun solve(a:List<Int>,b:List<Int>):Int?{
            A = a
            B = b
            val queue = TreeSet<pp>()
//            val queue = TreeSet<Pair<Int,Int>>(compareBy<Pair<Int, Int>> {a[it.first] + b[it.second] }.thenBy { it.first }.thenBy { it.second })
            queue.add(pp(0,0))
            while(queue.isNotEmpty()){
//                println(queue.toList().map{"${it.first} ${it.second}"}.joinToString(" "))
                val x = queue.last()
                queue.remove(x)
                val x1 = a[x.first]
                val x2 = b[x.second]
                val xx = minOf(x1,x2)
                val yy = maxOf(x1,x2)
                if(x1 == x2 || bad.contains(xx.toLong() shl 32 xor yy.toLong())){
                    if(x.first < a.lastIndex){
                        queue.add(pp(x.first + 1 , x.second))
                    }
                    if(x.second < b.lastIndex){
                        queue.add(pp(x.first, x.second + 1 ))
                    }
                }else{
                    return x1 + x2
                }
            }
            return null
        }

        val gbcounts = mutableMapOf<Int,MutableList<Int>>()
        for((k,v) in counts.entries){
            if(gbcounts[v] == null){
                gbcounts[v] = mutableListOf()
            }
            gbcounts[v]!!.add(k)
        }
        for(a in gbcounts.values){
            a.sortDescending()
        }
        val things = gbcounts.entries.toList()
        var max = Long.MIN_VALUE
        for(i in things.indices){
            for(j in i..things.lastIndex){
                val best = solve(things[i].value,things[j].value)
                if(best != null){
                    max = maxOf(max, 1L * (things[i].key + things[j].key) * (best))
                }
            }
        }
        put(max)
    }
    done()
}
/*

4,6

1,3
(6+3)


1
4 6
1 2 3 4
3 4
2 4
2 3
1 4
1 3
1 2

1
6 0
3 3 3 1 1 1



1
4 0
3 1 4 2
1 2 3 4 5 6 7
1 2 3 4 5 6 7

1
9 0
1 2 3 3 4 4 5 5 5


3 4 5 6
1 2 3 4

123
345
123
345
*/