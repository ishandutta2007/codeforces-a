// 2022.06.23 at 21:52:44 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.random.Random
import kotlin.random.nextInt

// 1. Modded

var pI = 0
val p:Long get()  = pI.toLong()
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
//        if(pI != 998_244_353 && pI != 1_000_000_007){
//            throw Exception("Not usual primes!")
//        }
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
fun debug(){}
const val singleCase = true


infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
//infix fun Int.modPlus(b:Int):Int{
//    val ans = this + b
//    return if(ans >= pI) ans - pI else ans
//}
infix fun Int.modMinus(b:Int):Int{
    val ans = this - b
    return if(ans < 0) ans + pI else ans
}
infix fun Int.modDivide(b:Int):Int{
    return this modM (b.inverse())
}
fun Int.additiveInverse():Int{
    return if(this == 0) 0 else pI - this
}

fun intPowEXP(x:Int,e:Long,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0L){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}

fun pow(x:Long,e:Long,m:Long):Long{
    var X = x
    var E =e
    var Y = 1L
    while(E > 0){
        if(E % 2 == 0L){
            X = (X * X) % m
            E /= 2
        }else{
            Y = (X * Y) % m
            E -= 1
        }
    }
    return Y
}
fun Long.inverse():Long{
    return pow(this,p-2,p)
}
fun Int.inverse():Int{
    return intPow(this,pI-2,pI)
}
fun min_rem(m:Int, r:Int, c:Int):Int {
    if(c < 1){
        return Int.MIN_VALUE
    }else if(r == 0){
        return 0
    }else{
        val step = m % r
        val mx = ((1L * c * r) /m ).toInt()
        val t = max_rem(r,step,mx)
        return r- t
    }
}
fun max_rem(m:Int, r:Int, c:Int):Int {
    if(r == 0|| c <= m/r){
        return r * c
    }else{
        val step =  m % r
        val mx = ((1L * (c+1) * r )/m).toInt()
        val t = min_rem(r,step,mx)
        return  m - t
    }
}
fun Int.reconstruct():String{
    val num = min_rem(pI,this, 10000)
    val denom = (this modDivide num).inverse()
    return "$num / $denom"
}

//make this int instead
class FACT{
    companion object {
        var store = IntArray(0)
        var invStore = IntArray(0)

        var slowStore:IntArray = IntArray(0)

        fun preCal(upto:Int){
            store = IntArray(upto+1)
            invStore = IntArray(upto + 1 )
            store[0] = 1
            invStore[0] = 1

            for(i in 1..upto) {
                store[i] = store[i-1] modM i
                invStore[i] = invStore[i-1] modM (i.inverse())
            }
        }
        fun choose(n:Int,r:Int):Int{
            if(r < 0 || r > n) return 0
            val a = store[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a modM b) modM c
        }

        fun bigChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret modM (n - i)
            }
            ret = ret modM (invStore[r])
            return ret
        }

    }
}


class rsq(val arr:IntArray) {
    val ps = IntArray(arr.size + 1)
    constructor(arr:List<Int>):this(arr.toIntArray()){

    }
    init{
        for(i in 0 until arr.size){
            ps[i+1] = ps[i] modPlus arr[i]
        }
    }
    fun sumQuery(l:Int,r:Int):Int{
        if(l > r || l >= arr.size || r < 0) return 0
        val ll = maxOf(l,0)
        val rr = minOf(arr.lastIndex,r) + 1
        return ps[rr] modMinus ps[ll]
    }
}
fun IntArray.torsq(): rsq {
    return rsq(this)
}
fun List<Int>.torsq():rsq{
    return rsq(this)
}

class stuff(val arr:IntArray, var start:Int){
    fun shiftby(x:Int){
        start -= x
    }
    fun convolute(z:Int):stuff{
        val q = this.arr.torsq()
        val new = IntArray(arr.size + z -1) {q.sumQuery(it - z +  1, it )}
        return stuff(new, start)
    }
    fun get(x:Int):Int{
        val nn = x + start
        if(nn in arr.indices){
            return arr[nn]
        }else{
            return 0
        }
    }
}

data class permutation(val p:IntArray){
    val n:Int get() = p.size
    companion object{
        fun identity(n:Int): permutation {
            return permutation((0 until n).toList().toIntArray())
        }
        fun all(n:Int): MutableList<permutation> {
            val ret = mutableListOf<permutation>()
            val A = IntArray(n){it}
            val c = IntArray(n)

            ret.add(permutation(A.copyOf()))

            var i = 0
            while(i < n){
                if(c[i] < i){
                    if(i %2 == 0){
                        A[0] = A[i].also { A[i] = A[0] }
                    }else{
                        A[c[i]] = A[i].also { A[i] = A[c[i]] }
                    }
                    ret.add(permutation(A.copyOf()))
                    c[i] += 1
                    i = 0
                }else{
                    c[i] = 0
                    i += 1
                }
            }
            return ret
        }
        fun kthpermutation(n:Int, k:Long):permutation{
            val all = (0 until n).toMutableList()
            val FACT = LongArray(n)
            FACT[0] =1L
            for(i in 1 until FACT.size) {
                FACT[i] = i * FACT[i-1]
            }
            val ret = mutableListOf<Int>()
            var indexnow = k
            for(l in n-1 downTo 0){
                val v = (indexnow / FACT[l] ).toInt()
                indexnow %= FACT[l]
                ret.add(all[v])
                all.removeAt(v)
            }
            return permutation(ret.toIntArray())
        }
    }
    // 0 based
    fun inverse():permutation{
        val ret = IntArray(p.size)
        for(i in 0..p.lastIndex){
            ret[p[i]] = i
        }
        return permutation(ret)
    }
    operator fun get(i:Int):Int{
        return p[i]
    }
    infix fun compose(other:permutation):permutation{
        val ret = IntArray(p.size)
        for(i in 0..p.lastIndex){
            ret[p[other.p[i]]] = i
        }
        return permutation(ret)
    }
    fun swapDistances():Int{
        var ret = 0
        cyclesOfPermutations { ret += it.size - 1  }
        return ret
    }
    fun shiftRightBy(a:Int):permutation{
        val ret = IntArray(p.size)
        var here = a - 1
        for(i in 0 until p.size){
            here += 1
            if(here >= p.size){
                here -= p.size
            }
            ret[here] = p[i]
        }
        return permutation(ret)
    }
    fun swapAt(a:Int,b:Int):permutation{
        val new = p.copyOf()
        new[a] = new[b].also{new[b] = new[a]}
        return permutation(new)
    }
    inline fun cyclesOfPermutations(doit:(List<Int>)->Unit){
        val arr = this.p
        val n = arr.size
        val done = BooleanArray(n)
        var haveDone = 0
        var pointer = 0
        while(haveDone < n){
            while(done[pointer]){
                pointer++
            }
            haveDone += 1
            val x = pointer
            val todo = mutableListOf(x)
            var cur = x
            done[x] = true
            while(true){
                val next = arr[cur]
                if(done[next]){
                    break
                }
                done[next] = true
                todo.add(next)
                haveDone += 1
                cur = next
            }
            doit(todo)
        }
    }

    fun subpermutation(mask:Int):permutation{
        val things = mutableListOf<Int>()
        for(i in 0 until p.size){
            if(mask and 1 shl i != 0){
                things.add(i)
            }
        }
        val firstThings = things.withIndex().sortedBy { it.value }
        return (permutation(firstThings.map{it.index}.toIntArray()).inverse())
    }
    fun uniqueCode():Int{
        var use = 0
        var i = 0
        var r = 0
        for(x in this.p){
            r = r * ( ++ i ) + (use and (-(1 shl x))).countOneBits()
            use = use or (1 shl x)
        }
        return r
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as permutation

        if (!p.contentEquals(other.p)) return false
        return true
    }

    override fun hashCode(): Int {
        return p.contentHashCode()
    }

    override fun toString(): String {
        return p.joinToString(" ")
    }
    fun print(){
        println(this.toString())
    }
    fun inversions():Int{
        var ret = 0
        for(i in 0 until n){
            for(j in i+1 until n){
                if(p[i] > p[j]){
                    ret ++
                }
            }
        }
        return ret
    }
}
fun main(){
    var ret = 0
    var t1 = 0
    val xx = 3
    for(p1 in permutation.all(xx)){
        for(p2 in permutation.all(xx)){
            if(p1.p.conca < p2.p.conca && p1.inversions() > p2.inversions()){
                ret ++

            }
        }
    }
//    just dei ret
    //45926
    //2725016

    solve.cases{
        val n = getint
        pI = getint
        val max = 505
        //remaining integers
        //negated breaking
        val have = Array(max + 1){IntArray(max+1)}

        var begin = stuff(intArrayOf(1), 0)
        for(i in 1..max){
            begin = begin.convolute(i)
            begin = begin.convolute(i)
            begin.shiftby(-(i-1))

//            just dei begin.arr
//            just dei begin.start
            val q = begin.arr.torsq()
            for(breaks in 0..max){
                have[i][breaks] = q.sumQuery(begin.start + breaks + 1 , plarge)
            }
        }
        var ret = 0
        var mul =1
        for(firstbreak in 0 until n){
            val rem = n - 1 - firstbreak
            for(dif in 1 until n){
                val options = (n-firstbreak - dif)
                if(options < 0) continue
                val now = options modM have[rem][dif]
//                "$firstbreak $dif" dei now
                ret = ret modPlus (now modM mul)
            }
            mul = mul modM (n- firstbreak)
        }
        put(ret)





    }
    done()
}
/*
21 minutes ok la


934

500
998244353

5
10000

that's a single slip
on the multipliers
then just died

500 1000000000


 */