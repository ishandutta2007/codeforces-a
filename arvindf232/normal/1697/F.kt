// 2022.06.12 at 23:35:59 HKT
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
class fastmint (var array:IntArray){
    val size:Int get() = pt + 1
    var pt = -1
    //iterate with 0..pt
    val lastIndex:Int get() = pt
    init{
        if(array.size < 5){
            array = array.copyOf(5)
        }
    }
    constructor(initialCapacity:Int = 10):this(IntArray(initialCapacity)){
        pt = -1
    }
    inline fun foreach(act:(Int)->Unit){
        for(i in 0..pt){
            act(array[i])
        }
    }
    inline fun withIndex(act:(i:Int, v:Int)->Unit){
        for(i in 0..pt){
            act(i,array[i])
        }
    }
    operator fun get(v:Int):Int{
        return array[v]
    }
    operator fun set(i:Int, v:Int){
        array[i] = v
    }
    fun add(v:Int){
        if(pt + 1 == array.size){
            array = array.copyOf(array.size * 3 / 2  )
        }
        pt ++
        array[pt] = v
    }
    fun addLast(v:Int) = add(v)
    fun removeLast():Int{
        pt--
        return array[pt+1]
    }
    fun clear(){
        pt = -1
    }
    fun reduceMemory(){
        array = array.copyOf(size)
    }
    override fun hashCode(): Int {
        return array.hashCode()
    }
    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as fastmint

        if (pt != other.pt) return false
        if (!array.contentEquals(other.array)) return false

        return true
    }
}
class SAT2(var n:Int){
    var lastnode = n-1
    val next = fastmint()
    val head = fastmint(IntArray(2 * n){-1})
    val to = fastmint()

    val next_r = fastmint()
    val head_r = fastmint(IntArray(2 * n){-1})
    val to_r = fastmint()


    fun newnode():Int{
        lastnode ++
        val new = lastnode
        lastnode ++
        repeat(2){
            head.add(-1)
            head_r.add(-1)
        }
        return (new shr 1)
    }
    fun newSeries(count: Int): IntArray {
        return IntArray(count) { newnode() }
    }
    fun primitive_add(a:Int, b:Int, reversed:Boolean){
        if(reversed){
            next_r.add(head_r[a])
            head_r[a] = next_r.lastIndex
            to_r.add(b)
        }else{
            next.add(head[a])
            head[a] = next.lastIndex
            to.add(b)
        }
    }

    fun add(na:Boolean,a:Int, nb:Boolean,b:Int){ // gives or
        val aa = (a shl 1 ) xor (na.chi )
        val bb = (b shl 1 ) xor (nb.chi)
        val neg_a = aa xor 1
        val neg_b = bb xor 1
        primitive_add(neg_a,bb,false)
        primitive_add(neg_b,aa,false)
        primitive_add(bb,neg_a,true)
        primitive_add(aa,neg_b,true)
    }
    inline fun NS(a:Int, act:(Int)->Unit){
        var i= head[a]
        while(i != -1){
            act(to[i])
            i = next[i]
        }
    }
    inline fun NS_R(a:Int, act:(Int)->Unit){
        var i= head_r[a]
        while(i != -1){
            act(to_r[i])
            i = next_r[i]
        }
    }
    fun notBoth(na:Boolean, a:Int, nb:Boolean, b:Int){
        add(!na,a,!nb,b)
    }
    fun atmost1(neg:BooleanArray, v:IntArray){
        val s = neg.size
        val nodes = IntArray(s){newnode()}
        for(i in 0 until s){
            imply(neg[i], v[i], false, nodes[i])
        }
        for(i in 0 until (s-1)){
            imply(false, nodes[i], false , nodes[i+1])
            imply(false,nodes[i], !neg[i], v[i])
        }
    }

    fun imply(na:Boolean, a:Int, nb:Boolean, b:Int){
//        println("imply ${na} $a   $nb $b ")
        notBoth(na,a,!nb,b)
    }
    fun solve():BooleanArray?{
        val nn = head.size
        val used = BooleanArray(nn)
        val order = fastmint()
        val comp = IntArray(nn){-1}
        val ret = BooleanArray(head.size/2)
        fun dfs1(v:Int){
            used[v] = true
            NS(v){ u ->
                if(!used[u]){
                    dfs1(u)
                }
            }
            order.addLast(v)
        }
        fun dfs2(v:Int, cl:Int){
            comp[v] = cl
            NS_R(v){ u ->
                if(comp[u] == -1){
                    dfs2(u,cl)
                }
            }
        }
        for(i in 0 until nn){
            if(!used[i])
                dfs1(i)
        }
        var j = 0
        for(i in 0 until nn){
            val v = order[nn-i-1]
            if(comp[v] == -1)
                dfs2(v,j++)
        }
        for(i in 0 until nn step 2){
            if(comp[i] == comp[i+1])
                return null
            ret[i/2] = comp[i] > comp[i+1]
        }
        return ret
    }
}
fun debug(){}
const val singleCase = false
fun main(){
    solve.cases{
        val n = getint
        val m = getint
        val k = getint
        val box = SAT2(0)
        val LEQ = Array(n){ box.newSeries(k+1)}
        for(v in 0 until n){
            for(i in 0 until k){
                box.imply(false,LEQ[v][i], false, LEQ[v][i+1])
            }
        }
        for(v in 0 until n-1){
            for(i in 0..k){
                box.imply(true,LEQ[v][i],true,LEQ[v+1][i])
            }
        }
        for(v in 0 until n){
            box.notBoth(false,LEQ[v][0],false, LEQ[v][0])
            box.notBoth(true,LEQ[v][k], true, LEQ[v][k])
        }
        repeat(m){
            val t = getint
            if(t == 1){
                val i = getint  -1
                val x = getint
                box.notBoth(false,LEQ[i][x], true, LEQ[i][x-1])
            }else if(t == 3){
                val i = getint - 1
                val j = getint - 1
                val x = getint - 1
                for(x1 in 1..k){
                    val x2 = x - x1
                    if(x2 in 1..k){
                        box.notBoth(false, LEQ[i][x1], false, LEQ[j][x2])
                    }
                }
            }else if(t == 2){
                val i = getint - 1
                val j = getint - 1
                val x = getint + 1
                for(x1 in 1..k){
                    val x2 = x - x1
                    if(x2 in 1..k){
                        box.notBoth(true,LEQ[i][x1-1], true, LEQ[j][x2-1])
                    }
                }
            }
        }
        val got = box.solve()

        if(got == null){
            put(-1)
            return@cases
        }else{
            val ret = IntArray(n){v->
                (0..k).first { got[LEQ[v][it]] }
            }
            put(ret.conca)
        }







    }
    done()
}