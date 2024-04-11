// 2022.08.16 at 23:26:49 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.ln
import kotlin.system.measureTimeMillis

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
fun debug(){}

object sieve{

    const val sieveMx = 200005
    val primeOf = IntArray(sieveMx + 1)
    var primeCounter = 0
    val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(ln(sieveMx.toDouble()) -4)).toInt() +3)
    val primes = IntArray(primeUpperBound)
    var sieveCalculated = false
    val nextPrime = IntArray(sieveMx+1)
    val nextPrimePower = IntArray(sieveMx+1)
    val afterPrimePowerDivison = IntArray(sieveMx+1)
    var mobius = IntArray(0)

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
    fun prepareFactors(){
        // 700ms in 1M
        // shoudl not be used for 1M
        // 200ms codeforces for 200k
        factors = List(sieveMx + 1){ mutableListOf()}
        factors[1].add(1)

        for(i in 2..sieveMx){
            val p = nextPrime[i]
            val a = nextPrimePower[i]
            val old = afterPrimePowerDivison[i]

            var here = 1
            repeat(a+1){
                for(c in factors[old]){
                    factors[i].add(c * here )
                }
                here *= p
            }
//            factors[1].ad
//            factors[i].addAll(i.factors())
        }
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
fun Int.factorLook():List<Int>{
    return sieve.factors[this]
}




typealias SI = Long
typealias SA = LongArray

const val sumactive = false
const val minactive = false
const val maxactive = true

const val rangeAdd = false
const val rangeAddLinear = false
const val rangeSet = false


val Int.Companion.zero get() = 0
val Long.Companion.zero get() = 0L
inline fun Int.Companion.convert(v:Int):Int{ return v }
inline fun Long.Companion.convert(v:Int):Long{ return v.toLong()}
const val push = rangeAdd || rangeAddLinear || rangeSet
class ST(nSuggest:Int) {

    val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val len = n * 2 + 1

    inline val Int.left get() = (this shl 1)
    inline val Int.right get() = (this shl 1) + 1
    inline val Int.level get() = levels + this.countLeadingZeroBits() - 31


    val sum = SA(if(sumactive) len else 0  )
    val min = SA(if(minactive) len else 0 )
    val max = SA(if(maxactive) len else 0 )


    val radd = SA(if(rangeAdd) len else 0 )

    val rset = SA(if(rangeSet) len else 0 )
    val setactive = BooleanArray(if(rangeSet) len else 0)

    //Constructor
    constructor(withArray:SA):this(withArray.size){
        for(i in withArray.indices){
            justSetValue(i,withArray[i])
        }
        updateAll()
    }
    constructor(nSuggest: Int, v:SI):this(nSuggest){
        for(i in 0 until n){
            justSetValue(i,v)
        }
        updateAll()
    }


    //Key functions
    fun justSetValue(i:Int, v:SI){
        if(sumactive){ sum[n+i] = v }
        if(minactive){ min[n+i] = v}
        if(maxactive){ max[n+i] = v}
    }
    fun realget(i:Int):SI{
        //assume pushed
        if(sumactive){return sum[n+i]}
        else if(minactive){return min[n+i]}
        else if(maxactive){return max[n+i]}
        return SI.MIN_VALUE
    }
    private fun updateNode(i:Int){
        if(rangeSet){
            if(setactive[i]){
                if(sumactive) sum[i] = rset[i] * (1 shl i.level)
                if(minactive) min[i] = rset[i]
                if(maxactive) max[i] = rset[i]
                return
            }
        }
        if(sumactive) sum[i] = sum[i.left] + sum[i.right]
        if(minactive) min[i] = minOf(min[i.left], min[i.right])
        if(maxactive) max[i] = maxOf(max[i.left], max[i.right])
        if(rangeAdd){
            if(sumactive) sum[i] += radd[i] * (1 shl i.level)
            if(minactive) min[i] += radd[i]
            if(maxactive) max[i] += radd[i]
        }
    }
    fun push(i:Int){
        if(rangeAdd){
            val v = radd[i]
            nodeadd(i.left,v)
            nodeadd(i.right,v)
            radd[i] = SI.zero
        }
        if(rangeSet){
            if(setactive[i]){
                nodeset(i.left, rset[i])
                nodeset(i.right,rset[i])
                setactive[i] = false
            }
        }
    }


    //Basic updates
    fun set(i:Int,v:SI){
        if(push) pushPath(i+n)
        justSetValue(i,v)
        updatePath(n+i)
    }
    fun add(i:Int, v:SI){
        if(push) pushPath(i+n)
        justSetValue(i,realget(i)+v)
        updatePath(n+i)
    }
    fun consider(i:Int, v:SI){
        if(push) pushPath(i+n)
        val new = if(minactive) minOf(realget(i),v) else maxOf(realget(i),v)
        justSetValue(i,new)
        updatePath(n+i)
    }
    fun nodeset(x:Int, newvalue:SI){
        if(maxactive) max[x] = newvalue
        if(minactive) min[x] = newvalue
        if(sumactive) sum[x] = newvalue
        if(x < n) {
            rset[x] = newvalue
            setactive[x] = true
        }
    }
    fun nodeadd(x:Int, inc:SI){
        if(maxactive) max[x] += inc
        if(minactive) min[x] += inc
        if(sumactive) sum[x] += inc
        if(x < n) {
            radd[x] += inc
        }
    }


    //Group Updates
    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        var here = i
        while(here > 1){
            here = here shr 1
            updateNode(here)
        }
    }
    private fun pushPath(i:Int){
        // i must be in [n,2n)
        for(s in levels downTo 1){
            push(i shr s)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i)
        }
    }
    fun pushAll(){
        for(i in 1..n-1){
            push(i)
        }
    }


    inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        var left = l + n
        var right = r + n + 1
        var level = 0
        while(left < right){
            if(left and 1 != 0){

                act(left,level)
                left += 1
            }
            if(right and 1 != 0){
                right -= 1
                act(right,level)
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
    }

    fun rangeSet(l:Int, r:Int, new:SI){
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        if(r < l) return
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,_ ->
            nodeset(i,new)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeAdd(l:Int, r:Int, new:SI){
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        if(r < l) return
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,_ ->
            nodeadd(i,new)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun sumQuery(l:Int, r:Int):SI{
        if(push){
            pushPath(l+n)
            pushPath(r+n)
        }
        var ret = SI.convert(0)
        segDivision(l,r){i,_ -> ret += sum[i]}
        return ret
    }
    fun minQuery(l:Int, r:Int):SI{
        if(push){
            pushPath(l+n)
            pushPath(r+n)
        }
        var ret = SI.MAX_VALUE
        segDivision(l,r){i,_ -> ret = minOf(ret,min[i])}
        return ret
    }
    fun maxQuery(l:Int, r:Int):SI{
        if(push){
            pushPath(l+n)
            pushPath(r+n)
        }
        var ret = SI.MIN_VALUE
        segDivision(l,r){i,_ -> ret = maxOf(ret,max[i])}
        return ret
    }


    //descends
    fun sumdescent(req:SI, i:Int = 1):Int{
        if(req >= sum[i]) throw IndexOutOfBoundsException()
        if(req < SI.zero) return -1
        var req = req
        var i = i
        while(i < n){
            if(push) push(i)
            i = i shl 1
            if(req >= sum[i]){
                req -= sum[i]
                i ++
            }
        }
        return i - n
    }
    fun maxdescent(i:Int = 1, want:Int?):Int{
        val want = want ?: max[i]  // assume already pushed
        var i = i
        while(i  < n){
            if(push) push(i)
            i = i shl 1
            if(want != max[i]){
                i++
            }
        }
        return i - n
    }
    fun mindescent(i:Int = 1, want:Int?):Int{
        val want = want ?: min[i]  // assume already pushed
        var i = i
        while(i  < n){
            if(push) push(i)
            i = i shl 1
            if(want != min[i]){
                i++
            }
        }
        return i - n
    }

    //debug
    override fun toString(): String {
        if(push) pushAll()
        val ret = SA(n)
        for(i in 0 until n){ ret[i] = realget(i)}
        return ret.joinToString(" ")
    }
}
const val singleCase = false
fun main(){
    sieve.calculateSieveFast()
    sieve.preparePrimePower()
    solve.cases{
        val n = getint
        val q = getint
        val primes = mint
        val invert = mint
        n.eachPrimePower { p, e ->
            primes.add(p)
            invert.add(n/p)
        }

        val ps = primes.size
        val stuff = Array(ps){ST(invert[it])}
        val start = getline(n)
        val L = IntArray(n)

        fun modify(i:Int, new:Int){
            val offset = new - L[i]
            L[i] = new
            for(pi in 0 until ps){
                stuff[pi].add(i % invert[pi], offset.toLong())
            }
        }
        fun output():Long {
            var best = 0L
            for(pi in 0 until ps){
                best = maxOf(best, stuff[pi].max[1]  * invert[pi])
            }
            return best
        }
        for(i in 0 until n){
            modify(i,start[i])
        }
        put(output())
        repeat(q){
            val i = getint - 1
            val v = getint
            modify(i,v)
            put(output())
        }






    }
    done()
}
/*
1
6 3
1 1 1 1 1 1
1 5
4 4
3 8
 */