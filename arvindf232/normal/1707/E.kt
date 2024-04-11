// 2022.07.17 at 18:25:26 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
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
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
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
typealias rmqType = Int
typealias rmqArrayType = IntArray
class rmqboth(val arr: rmqArrayType){
    val n = arr.size
    val min = mutableListOf<rmqArrayType>()
    val max = mutableListOf<rmqArrayType>()
    init{
        preprocess()
    }
    private fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr
                min.add(new)
            }else{
                val size = n-s+1
                val oldmin = min.last()
                val oldmax = max.last()
                val newmin = rmqArrayType(size)
                val newmax = rmqArrayType(size)
                for(i in 0 until size){
                    newmin[i] = maxOf(oldmin[i],oldmin[i+olds])
                    newmax[i] = minOf(oldmax[i],oldmax[i+olds])
                }
                min.add(newmin)
                max.add(newmax)
            }
            olds = s
            s = s shl 1
        }
    }
    fun minquery(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = min[i][a1]
        val ret2 = min[i][a2]
        return  minOf(ret1,ret2)
    }

    fun maxquery(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = max[i][a1]
        val ret2 = max[i][a2]
        return  maxOf(ret1,ret2)
    }
}
class rmq(val arr: rmqArrayType){
    val n = arr.size
    val store = mutableListOf<rmqArrayType>()
    init{
        preprocess()
    }
    companion object{
        const val max = false
    }
    private fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr
                store.add(new)
            }else{
                val size = n-s+1
                val old = store.last()
                val new = rmqArrayType(size)
                for(i in 0 until size){
                    if(max){
                        new[i] = maxOf(old[i],old[i+olds])
                    }else{
                        new[i] = minOf(old[i],old[i+olds])
                    }

                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun query(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return if(max) maxOf(ret1,ret2) else minOf(ret1,ret2)
    }
}
class rmaxq(val arr: rmqArrayType){
    val n = arr.size
    val store = mutableListOf<rmqArrayType>()
    init{
        preprocess()
    }
    companion object{
        const val max = true
    }
    private fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr
                store.add(new)
            }else{
                val size = n-s+1
                val old = store.last()
                val new = rmqArrayType(size)
                for(i in 0 until size){
                    if(max){
                        new[i] = maxOf(old[i],old[i+olds])
                    }else{
                        new[i] = minOf(old[i],old[i+olds])
                    }

                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun query(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return if(max) maxOf(ret1,ret2) else minOf(ret1,ret2)
    }
}


fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val q = getint
        if(n == 1){
            repeat(q){
                put(0)
            }
            return@cases
        }
        val L = getline(n)
        for(i in 0 until n){
            L[i] --
        }

        val maps = mutableListOf<IntArray>()
        val mins = mutableListOf<rmq>()
        val maxs = mutableListOf<rmaxq>()

        val b1 = IntArray(n-1){minOf(L[it], L[it+1])}
        val b2 = IntArray(n-1){ maxOf(L[it], L[it+1]) }
        mins.add(rmq(b1))
        maxs.add(rmaxq(b2))
        maps.add(L)

        fun act(l:Int,r:Int,level:Int):Pair<Int,Int>{
            if(l == r){
                return Pair(maps[level][l], maps[level][l])
            }else{
                return Pair(mins[level].query(l,r-1), maxs[level].query(l,r-1))
            }
        }
        val max = 19
        repeat(max){
            val c1 = IntArray(n-1)
            val c2 = IntArray(n-1)
            for(i in 0 until n-1){
                val l1 = mins.last().query(i,i)
                val r1 = maxs.last().query(i,i)
                val l2:Int
                val r2:Int
                if(l1 == r1){
                    l2 = maps.last()[l1]
                    r2= maps.last()[l1]
                }else{
                    l2 = mins.last().query(l1,r1-1)
                    r2 = maxs.last().query(l1,r1-1)
                }
                c1[i] = l2
                c2[i] = r2
            }
            val last = maps.last()
            val newL = IntArray(n){last[last[it]]}
            mins.add(rmq(c1))
            maxs.add(rmaxq(c2))
            maps.add(newL)
        }
        repeat(q){
            var a = getint - 1
            var b = getint - 1
            if(a == 0 && b == n-1){
                put(0)
                return@repeat
            }
            var res = 0L
            for(level in max downTo 0){
                val new = act(a,b,level)
                if(new.first != 0 || new.second != n-1){
                    a = new.first
                    b = new.second
                    res += (1L shl level)
                }
            }
            res ++
            if(res >= (1L shl (max+1))){
                put(-1)
            }else{
                put(res)
            }

        }





    }
    done()
}