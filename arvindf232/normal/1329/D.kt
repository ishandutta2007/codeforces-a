
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.lang.IndexOutOfBoundsException
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
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int, asTrue:Char):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == asTrue}
}

val List<Char>.ret:String
get() = this.joinToString("")
var dmark = -1
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
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
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){
    throw Exception("Bad programme")} // because assertion does not work
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
    var answersChecked = 0
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        //safety checks
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Modding a wrong prime!")
        }
        if(withBruteForce){
            println("Brute force is active")
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
inline fun<T> T.alsoBrute(cal:() -> T){
    if(!withBruteForce) return
    val also = cal()
    if(this != also){
        println("Checking failed: Got ${this} Brute ${also}")
        crash()
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


fun String.sliceTo(right:Boolean,i:Int):Int {
    var end = i
    while(true){
        val next = if(right) end + 1 else end - 1
        if(next < 0 || next >= this.size){
            break
        }
        if(this[next] == this[end]){
            if(right){
                end++
            } else {
                end--
            }
        }else{
            break
        }
    }
    return end
}
fun debug(){}
const val withBruteForce = false
const val singleCase = false

class item(var l:Int, var r:Int, val c:Char):Comparable<item>{
    override fun compareTo(other:item):Int {

        return this.l.compareTo(other.l)
    }

    val able = BooleanArray(2)

    fun dies(){
        if(able[0] or able[1]){
            allable[c.code].remove(this)
        }

    }
    fun setable(i:Int,new:Boolean ){
        val olda = able[0] or able[1]
        able[i] = new
        val newa = able[0] or able[1]
        if(olda != newa){
            if(newa){
                allable[c.code].add(this)
            }else{
                allable[c.code].remove(this)
            }
        }
    }


    fun update(){
        val left = all.lower(this)
        val useleft = left != null && left.c != this.c
        val right = all.higher(this)
        val useright = right != null && right.c != this.c
        setable(0,useleft)
        setable(1,useright)
    }

    var len:Int = r - l + 1
}
class simpleSegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val arr = IntArray(n * 2 + 1 )
    val arrSize = n * 2 + 1

    constructor(withArray:IntArray):this(withArray.size){
        for(i in withArray.indices){
            arr[i+n] = withArray[i]
        }

        updateAll()
    }

    private fun updateNode(i:Int){
        arr[i] = arr[i shl 1 ] + arr[(i shl 1) + 1]
    }
    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        // bottom up, recalculate
        var here = i
        while(here > 1){
            here = here shr 1
            updateNode(here)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i)
        }
    }
    fun setValue(i:Int,value:Int){
        arr[n+i] = value
        updatePath(n+i)
    }
    fun addValue(i:Int, inc:Int){
        arr[n+i] += inc
        updatePath(n+i)
    }

    val firstIndex = n
    val lastIndex = (n shl 1 ) - 1
    val indices = firstIndex..lastIndex


    fun primitiveIndex(a:Int) = a + n
    inline fun segmentOrder(act:(here:Int, left:Int,right:Int)->Unit ){
        //iterate over all segments bottom up, probably to rebuild tree
        for(i in (n-1) downTo 1){
            act(i, (i shl 1 ), (i shl 1) + 1)
        }
    }
    inline fun primitiveOrder(act:(here:Int,primitiveIndex:Int)->Unit){
        //iterate over all the leaf nodes
        for(i in 0 until n){
            act(i+n,i)
        }
    }


    fun query(l:Int,r:Int): Int {
        var ret:Int = 0
        var left = l + n
        var right = r + n+1
        while(left < right){
            if(left and 1 != 0){
                ret += arr[left]
                left += 1
            }
            if(right and 1 != 0){
                right -= 1
                ret += arr[right]
            }
            left = left shr 1
            right = right shr 1
        }
        return ret
    }
    inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
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

    fun queryFunctional(l:Int,r:Int):Int{
        var ret = 0
        segDivision(l,r){i, _ ->
            ret += arr[i]
        }
        return ret
    }
    fun indexOf(req:Int):Int{
        // -1 if not enough
        val req = req + 1
        if(req > arr[1]){
            throw IndexOutOfBoundsException()
        }else if(req <= 0 ){
            return -1
        }
        var i = 1
        var rightPoint = -1
        var cur = 0
        for(l in 1..levels){
            i = i shl 1
            if(cur + arr[i] < req){
                rightPoint += 1 shl (levels - l)
                cur += arr[i]
                i += 1
            }
        }
        return rightPoint +1
    }


    val Int.leftNode:Int get(){
        // assert(this <= n )
        return this shl 1
    }
    val Int.rightNode:Int get(){
        // assert(this <= n)
        return (this shl 1) + 1
    }
    val Int.endpoints:Pair<Int,Int> get(){
        val offSet = this - this.takeHighestOneBit()
        val widthLevel = levels - (31 - this.countLeadingZeroBits())
        return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
    }



    //like set
    fun contains(a:Int): Boolean {
        return arr[a+n] == 1
    }
    fun add(a:Int){
        if(!contains(a)){
            addValue(a,1)
        }
    }
    fun remove(a:Int){
        if(contains(a)){
            addValue(a,-1)
        }
    }
    fun numberInRange(l:Int, r:Int):Int{
        return query(l,r)
    }
    val size:Int get() = this.arr[1]
    operator fun get(a:Int):Int{
        return indexOf(a)
    }
    fun first():Int{
        return get(0)
    }
    fun last():Int{
        return get(size - 1)
    }
}

val allable = List(26){TreeSet<item>()}
val all = TreeSet<item>()
fun main(){
    val choice = listOf('a','b','c')
    solve.tc {
        share(List(200000){choice.random()}.conca())
    }
//    solve.usetc()
//    solve.userand()
    solve.cases{
        all.clear()
        for(a in allable){
            a.clear()
        }
		val str = getstr
        val n = str.length

        val here = TreeSet<Int>()
        val st = simpleSegTree(IntArray(n){1})

        for(i in 0 until n){
            here.add(i)
        }
        fun firstIn(l:Int, r:Int):Int{
            val ret = here.ceiling(l)!!
            assert(ret <= r)
            return ret
        }
        fun lastIn(l:Int, r:Int):Int{
            val ret = here.floor(r)!!
            assert(ret >= l)
            return ret
        }
        fun delete(l:Int, r:Int){
            while(true){
                val next = here.ceiling(l) ?: return
                if(next <= r){
                    here.remove(next)
                    st.remove(next)
                }else{
                    return
                }
            }
        }

        val ret = mutableListOf<Pair<Int,Int>>()
        fun give(l:Int, r:Int){
            val ll = st.query(0,l-1)
            val rr = st.query(0,r) - 1
            assert(ll <= rr)
            ret.add(Pair(ll,rr))
        }

        val aaaaa = all
        var left = 0
        val maxtypes = IntArray(26)
        while(left < n){
            val right = str.sliceTo(true,left)
            val new = item(left,right,str[left])
            if(new.len != 1) all.add(new)
            maxtypes[new.c.code] += new.len - 1
            left = right +  1
        }
        for(a in all){
            a.update()
        }


        while(true){
//            assert(all.all { it.len != 1 })
            val m = maxtypes.maxOrNull()!!
            if(m == 0 ) break
            val c = maxtypes.indexOf(m)
            if(allable[c].isEmpty()){
                break
            }
            val taking = allable[c].first()

            val goright = taking.able[1]
            val consider = (if(goright) all.higher(taking) else all.lower(taking))!!

            val l :Int
            val r:Int
//            val l = if(goright) taking.r else consider.r
//            val r = if(goright) consider.l else taking.l

            if(goright){
                l = lastIn(taking.l,taking.r)
                r = firstIn(consider.l,consider.r)
            }else{
                l = lastIn(consider.l, consider.r)
                r = firstIn(taking.l,taking.r)
            }
            consider.len --
            taking.len --
            if(consider.len == 1){
                all.remove(consider)
                consider.dies()
                all.higher(consider)?.update()
                all.lower(consider)?.update()
            }
            if(taking.len == 1){
                all.remove(taking)
                taking.dies()
                all.higher(taking)?.update()
                all.lower(taking)?.update()
            }
            maxtypes[consider.c.code] --
            maxtypes[taking.c.code] --
            give(l,r)
            delete(l,r)
        }
        for(a in all){
            repeat(a.len - 1){
                val f = firstIn(a.l,a.r)
                give(f,f)
                delete(f,f)
            }
        }
        give(0,n-1)

        put(ret.size)
        for((a,b) in ret){
            put("${a+1} ${b+1}")
        }






    }
    done()
}
/*
abbcbba
1
aaabbb

1
aaaaaabccbbacccccaba
 */