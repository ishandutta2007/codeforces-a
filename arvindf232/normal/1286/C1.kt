// 2022-05-18, Wed, 15:00
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.math.ceil
import kotlin.math.exp
import kotlin.random.Random
import kotlin.random.nextInt

// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x ; var E =e ; var Y = 1
    while(E > 0){
        if(E and 1 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
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
//4. more outputs
fun List<Char>.conca():String = this.joinToString("")
val CharArray.conca :String get() = this.joinToString("")
val IntArray.conca :String get() = this.joinToString(" ")
@JvmName("concaInt")
fun List<Int>.conca():String = this.joinToString(" ")
val LongArray.conca:String get() = this.joinToString(" ")
@JvmName("concaLong")
fun List<Long>.conca():String = this.joinToString(" ")
//5. Pair of ints
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)
//8 TIME
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}
object Reader{
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
            put("Custom test enabled")
            println("Custom test enabled")
            warningActive = false
        }
        val S = fakein.toString()
        println("New Case ")
        println(S.take(80))
        println("...")
        fakein.clear()
        IN = BufferedInputStream(S.byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){ Reader.OUT.println(aa)}
fun done(){ Reader.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){Reader.fakein.append(aa.toString())}
    else{Reader.fakein.append(aa.toString())}
    Reader.fakein.append("\n")
}

val getintfast:Int get() = Reader.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = Reader.nextLong()
val getstr:String get() = Reader.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
var dmark = -1
infix fun Any.dei(a:Any){
    dmark++
    var str = "<${dmark}>   "
    debug()
    if(this is String){ str += this
    }else if(this is Int){ str += this.toString()
    }else if(this is Long){ str += this.toString()
    }else{ str += this.toString()}
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is BooleanArray){ println("$str :${a.map{if(it)'1' else '0'}.joinToString(" ")}")
    }else if(a is Array<*>){
        println("$str : ")
        for(c in a){if(c is IntArray){println(c.joinToString(" "))}
        else if(c is LongArray){println(c.joinToString(" "))}
        else if(c is BooleanArray){println(c.map { if(it) '1' else '0' }.joinToString(""))
        }
        }
        println()
    }else{ println("$str : $a")
    }
}
val just = " "
fun crash(){
    throw Exception("Bad programme")}
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Not usual primes!")
        }
        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                Reader.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                Reader.rerouteInput()
            }
            onecase()
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
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }
}
private typealias ei = Int
private typealias earr = IntArray
//NOT batle tested
class fastDeque(val l:Int, val r:Int) {
    val total = r - l + 1
    val st = earr(total)
    var startpointer = 0 - l
    var endpointer = startpointer - 1
    val size: Int get() = endpointer - startpointer + 1

    fun reset(){
        startpointer = -l
        endpointer = startpointer -1
    }

    fun isEmpty(): Boolean {
        return endpointer < startpointer
    }
    fun isNotEmpty():Boolean{
        return endpointer >= startpointer
    }
    fun first():ei{
        assert(isNotEmpty())
        return st[startpointer]
    }
    fun last():ei{
        assert(isNotEmpty())
        return st[endpointer]
    }
    fun addFirst(v:ei ){
        startpointer --
        st[startpointer]= v
    }
    fun addLast(v:ei){
        endpointer ++
        st[endpointer] = v
    }
    fun removeFirst(): Int {
        assert(isNotEmpty())
        val ret = st[startpointer]
        startpointer ++
        return ret
    }
    fun removeLast(): Int {
        assert(isNotEmpty())
        val ret = st[endpointer]
        endpointer --
        return ret
    }
    fun toArray():earr{
        return st.sliceArray(startpointer..endpointer)
    }
    fun toList():List<ei>{
        return st.slice(startpointer..endpointer)
    }

    inline fun forEach(act:(v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(st[i])
        }
    }
    inline fun withIndex(act:(i:Int,v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(i-startpointer,st[i])
        }
    }
    operator fun get(v:Int): Int {
        return st[startpointer + v]
    }
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}
fun debug(){}
const val fake = false
val fakestring = "abcdef"
const val singleCase = true
fun main(){
    fun usable(n :Int, options:IntArray):Boolean{
        val explored = BooleanArray(n)
        val Q = fastDeque(0,n)
        for(a in options){
            if(a %2 == 0 && a/2 in 0 until n && !explored[a/2]){
                explored[a / 2 ] = true
                Q.addLast(a/2)
            }
        }
        while(Q.isNotEmpty()){
            val v = Q.removeLast()
            for(c in options){
                val new = c - v
                if(new in 0 until n){
                    if(!explored[new]){
                        explored[new ] = true
                        Q.addLast(new)
                    }
                }
            }
        }
        return explored.all { it }
    }
    fun inlimits(n:Int ,options:IntArray):Boolean {
        val limit = ceil(0.777 * (n+1) * (n+1)).toInt()
        var ret = 0
        for(c in options){
            val max = (0..n).lastOrNull { c + it in 0..(2 * (n-1)) &&  c - it in 0..(2 * (n-1)) } ?: continue
            val l = (c - max)/2
            val r = (c + max) /2
            val w =  r- l + 1
            ret += ( w * (w+1) / 2)
        }
        return ret <= limit
    }
    fun findUsable(n:Int):IntArray {
        for(l in 0 until 2 * n){
            for(r in 0 until 2 * n){
                val arr = intArrayOf(n-1,l,r)
                if(inlimits(n,arr) && usable(n,arr)){
                    return arr
                }
            }
        }
        crash()
        return intArrayOf()
    }
    fun solve(n:Int, l:List<String>):String{
        val bins = Array(n+1){ mutableListOf<String>() }
        for(a in l){
            bins[a.size].add(a)
        }
        val counts = Array(n+1){IntArray(26)}
        for((i,b) in bins.withIndex()){
            for(s in b){
                for(c in s){
                    counts[i][c.code] ++
                }
            }
        }
        val layers = Array(n+1){IntArray(26)}
        for(i in n downTo 1){
            for(c in 0 until 26){
                layers[n+1-i][c] = counts[i-1][c] - counts[i][c]
            }
        }
        for(c in 0 until 26){
            layers[0][c] = counts[n][c]
        }

        val ret = CharArray(n)
        for(left in 0 until n){
            val right = n-1-left
            if(left <= right){
                var str = ""
                for((i,v) in layers[left].withIndex()){
                    repeat(v - layers[left+1][i]){
                        str += (i + 'a'.toInt()).toChar()
                    }
                }
                ret[left] = str[0]
                 if(right != left){
                     ret[right] = str[1]
                 }
            }
        }
        return ret.conca
    }

    fun ask(l:Int, r:Int):MutableList<String> {
        assert( l <= r)
        val len = r - l + 1
        println("? ${l+1} ${r+1}")
        System.out.flush()
        if(!fake){
            val strings = len * (len + 1)/2
            val ret = mutableListOf<String>()
            repeat(strings){
                ret.add(getstr)
            }
            return ret
        }else{
            val ret = mutableListOf<String>()
            for(i in l..r){
                for(j in i..r){
                    ret.add(fakestring.slice(i..j))
                }
            }
            return ret
        }

    }
    fun others(from:List<Char>, except:Char):Char {
        return if(from[0] == except) from[1] else from[0]
    }
//    for(i in 1..100){
//        just dei findUsable(i)
//    }
    solve.cases{
//        just dei usable(9, intArrayOf(8,1,3))
        val n = getint
        val arr = findUsable(n)
//        just dei arr
//        just dei usable(6,arr)
//        just dei arr

//        just dei usa

        fun tobounds(c:Int):Pair<Int,Int>{
            val max = (0..n).lastOrNull { c + it in 0..(2 * (n-1)) &&  c - it in 0..(2 * (n-1)) } ?: return Pair(-1,-1)
            val l = (c - max)/2
            val r = (c + max) /2
            return Pair(l,r)
        }
        val retstring = Array<String>(3){""}
        for((i,r) in arr.withIndex()){
            val (l,r) = tobounds(r)
            if(l == -1) continue
            val str = solve(r - l + 1 ,ask(l,r))
            retstring[i] = str
        }
        val answers = CharArray(n){'*'}
        val Q = fastEmptyList(n)
        for(i in 0 until 3){
            if(retstring[i].size %2 == 1){
                val pos = arr[i]/2
                if(answers[pos] == '*'){
                    val c = retstring[i][retstring[i].size / 2 ]
                    answers[pos] = c
                    Q.addLast(pos)
                }
            }
        }
        while(Q.isNotEmpty()){
            val v = Q.removeFirst()
            for(i in 0 until 3){
                val other = arr[i] - v
                if(other !in 0 until n) continue
                if(answers[other] != '*') continue
                val l = tobounds(arr[i]).first
                assert( v != other)
                val c1 = retstring[i][v - l]
                val c2 = retstring[i][other - l]
                val new = others(listOf(c1,c2), answers[v])
                answers[other] = new
                Q.addLast(other)
            }
        }
        assert(answers.all { it != '*' })
        println("! ${answers.conca}")
        System.out.flush()






    }
    done()
}

//there is no option, you have to clean it





/*
a a b c aa ab bc aab abc aabc
ccba
c c b a cc cb ba ccb cba ccba
 */