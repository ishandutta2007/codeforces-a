// 2022.10.20 at 15:49:04 BST
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet

// 1. Modded
const val p = 998244353L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.mm(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.mp(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
infix fun Int.ms(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + pI else ans }
fun Int.inverse():Int = intPow(this,pI-2,pI)
infix fun Int.modDivide(b:Int):Int{ return this mm (b.inverse()) }
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
// 3. convenience conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong())
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
//9.ordered pair
fun order(a:Int, b:Int):Pair<Int,Int>{
    return Pair(minOf(a,b), maxOf(a,b))
}
const val interactive = false
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
            if(interactive){
                return System.`in`.read().toChar()
            }
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
    fun flush(){
        OUT.flush()
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun eat(){ val st1 = TreeSet<Int>(); val st2 = TreeMap<Int,Int>()}
fun put(aa:Any){
    Reader.OUT.println(aa)
    if(interactive){ Reader.flush()}
}
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
const val just = " "
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
fun debug(){}



infix fun Long.modM(b:Long):Long{
    return (this * b) % p
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
                store[i] = store[i-1] mm i
            }
            invStore[upto] = store[upto].inverse()
            for(i in upto-1 downTo 1){
                invStore[i] = invStore[i+1] mm (i+1)
            }
        }
        fun choose(n:Int,r:Int):Int{
            if(r < 0 || r > n) return 0
            val a = store[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a mm b) mm c
        }

        fun bigChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret mm (n - i)
            }
            ret = ret mm (invStore[r])
            return ret
        }

    }
}

tailrec fun gcd(a: Int, b: Int): Int {
    if(b == 0) return a
    return if (a % b == 0) Math.abs(b) else gcd(b, a % b)
}
tailrec fun gcd(a: Long, b: Long): Long {
    if(b == 0L) return a
    return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}

fun lcm(a:Long, b:Long):Long{
    return a * b / gcd(a,b)
}


object sieve{

    const val sieveMx = 300005
    val primeOf = IntArray(sieveMx + 1)
    var primeCounter = 0
    val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(Math.log(sieveMx.toDouble()) -4)).toInt() +3)
    val primes = IntArray(primeUpperBound)
    var sieveCalculated = false
    val nextPrime = IntArray(sieveMx+1)
    val nextPrimePower = IntArray(sieveMx+1)
    val afterPrimePowerDivison = IntArray(sieveMx+1)
    var mobius = IntArray(0)
    var fstart = IntArray(0)
    var factor = IntArray(0)

    var factors:List<MutableList<Int>> = mutableListOf()

    fun calculateSieveFast(){
        if(sieveCalculated){
            return
        }
        sieveCalculated = true
        for(i in 2..sieveMx){
            if(primeOf[i] == 0 ){
                primeOf[i] = i
                primes[primeCounter] = i
                primeCounter += 1
            }
            for(j in 0 until primeCounter){
                val p = primes[j]
                val pd = p * i
                if(p <= i && pd <= sieveMx){
                    primeOf[pd] = p
                }else{
                    break
                }
            }
        }
    }
    fun preparePrimePower(){
        nextPrime[1] = -1
        nextPrimePower[1] = -1
        afterPrimePowerDivison[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            val new = i / p
            nextPrime[i] = p
            if(nextPrime[new] == p){
                nextPrimePower[i] = nextPrimePower[new]
                afterPrimePowerDivison[i] = afterPrimePowerDivison[new]
            }else{
                afterPrimePowerDivison[i] = new
            }
            nextPrimePower[i] += 1
        }
    }
    fun primeID():Pair<IntArray,IntArray>{
        assert(sieveCalculated)
        var now =0
        val primes = IntArray(primeCounter)
        val id = IntArray(sieveMx) {
            if (it > 0 && primeOf[it] == it) {
                primes[now] = it
                return@IntArray now++
            } else -1}
        return Pair(primes,id)
    }
    fun prepareFactor(){
        val fcount = IntArray(sieveMx +1)
        fcount[1] = 1
        var total = 1
        for(i in 2..sieveMx){
            fcount[i] = fcount[afterPrimePowerDivison[i]] * (nextPrimePower[i] + 1)
            total += fcount[i]
        }
        factor = IntArray(total)
        val who = IntArray(total)
        fstart = IntArray(sieveMx+1)
        factor[0] = 1
        who[0] = 1

        for(i in 2..sieveMx){
            fstart[i] = fstart[i-1] + fcount[i-1]
            val prev = i / nextPrime[i]
            val pcount = fcount[afterPrimePowerDivison[i]]
            factor.copyInto(factor,fstart[i],fstart[prev],fstart[prev+1])
            for(x in (fstart[i] + fcount[i] - 2 * pcount) until (fstart[i] + fcount[i] - pcount)){
                factor[x+pcount] = factor[x] * nextPrime[i]
            }
            for(c in 0 until fcount[i]){
                who[fstart[i] + c] = i
            }
        }
        factor.radixCarry(who)
        who.radixCarry(factor)
    }
    fun calculateMobius(){
        assert(sieveCalculated)
        mobius = IntArray(sieveMx + 1)
        mobius[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            if(p == primeOf[i/p]){
                mobius[i] = 0
            }else{
                mobius[i] = -1 * mobius[i/p]
            }
        }
    }
}
fun IntArray.radixCarry(other:IntArray){
    error("Did not replace with radix sort implementation")
}
inline fun Int.eachPrimePower(act:(Int,Int)->Unit){
    assert(sieve.sieveCalculated)
    var here = this
    while(here > 1){
        act(sieve.nextPrime[here], sieve.nextPrimePower[here])
        here = sieve.afterPrimePowerDivison[here]
    }
}
fun Int.factors():List<Int>{
    val ret = mutableListOf(1)
    this.eachPrimePower { p, e ->
        val s = ret.toList()
        var now = 1
        repeat(e){
            now *= p
            ret.addAll(s.map{it * now})
        }
    }
    return ret
}
fun totient(a:Int):Int{
    var ret = a
    a.eachPrimePower{
            p, _ ->
        ret /= p
        ret *= (p-1)
    }
    return ret
}
fun Int.numOfDivisors():Int{
    var ret = 1
    this.eachPrimePower { _, e -> ret *= (e+1) }
    return ret
}
inline fun Int.eachFactor(act:(Int)->Unit){
    val end = if(this == sieve.sieveMx) sieve.factor.lastIndex else (sieve.fstart[this+1]-1)
    for(i in sieve.fstart[this]..end){
        act(sieve.factor[i])
    }
}
fun Int.factorLook():IntArray{
    val end = if(this == sieve.sieveMx) sieve.factor.lastIndex else (sieve.fstart[this+1]-1)
    return sieve.factor.sliceArray(sieve.fstart[this]..end)
}


const val singleCase = true
fun main(){
    sieve.calculateSieveFast()
    solve.cases{
        val n= getint
        val m = getlong


        var mustbe = 1L
        var bad = 1
        var ret = 0
        var over = false
        for(len in 1..n){
            if(!over && sieve.primeOf[len] == len)
                mustbe = lcm(mustbe,len.toLong())
            if(mustbe > m){
                bad =0
                over = true
            }
//            "must $len " dei mustbe
            bad = bad mm ((m/mustbe.toLong() ) %pI).toInt()


//            "bad" dei bad

            val here = intPow((m % pI).toInt(), len, pI) ms bad
//            len dei here
            ret = ret mp here
        }

//        var total = n
//        val usable = BooleanArray(n+1){if(it ==0) false else true}
//        var ret = 1
        put(ret)
//        val base = intPowEXP(n,m, pI)
//        put(base ms bad)

//        for(i in 1..minOf(n.toLong(),m)){
//            val i = i.toInt()
//            ret = ret mm total
//
//            i dei total
//            if(i == 1) continue
//            for(v in i..n step i){
//                if(usable[v]){
//                    usable[v] = false
//                    total --
//                }
//            }
//        }
//        put(ret)




    }
    done()
}