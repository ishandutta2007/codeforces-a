import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.random.Random
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
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

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
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount

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
            a()
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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
val Char.code :Int get() = this.toInt() -  'a'.toInt()

const val singleCase = true
const val withBruteForce = false
const val randCount = 100

class functional(val next:IntArray){
    val n = next.size

    val quick = mutableListOf<IntArray>()
    fun calculateQuick(order:Int){
        quick.add(next)
        repeat(order){
            val last = quick.last()
            val new = IntArray(n)
            for(i in 0 until n) {
                new[i] = last[last[i]]
            }
            quick.add(new)
        }
    }
    fun getCycleRoots():List<Int>{
        val found = IntArray(n){-1}
        val roots = mutableListOf<Int>()
        tailrec fun search(a:Int,ID:Int){
            if(found[a] == ID){
                roots.add(a)
            }
            if(found[a] != -1) return
            found[a] = ID
            search(next[a],ID)
        }
        for(i in 0 until n){
            if(found[i] == -1){
                search(i,i)
            }
        }
        return roots
    }
    inline fun actOnCycle(root:Int,act:(Int)->Unit){
        var here = next[root]
        while(true){
            act(here)
            if(here == root){
                break
            }
            here = next[here]
        }
    }

    val roots by lazy{getCycleRoots()}
    val inCycle by lazy{getincycle()}

    fun getincycle():BooleanArray{
        val ret = BooleanArray(n)
        for(r in roots) {
            actOnCycle(r) { ret[it] = true }
        }
        return ret
    }
    fun getfirstCycle():IntArray{
        val firstCycles = IntArray(n){-1}
        val inCycle = inCycle
        for(i in 0 until n){
            if(inCycle[i]){
                firstCycles[i] = i
            }
        }
        fun markCycle(a:Int):Int{
            if(firstCycles[a] != -1) return firstCycles[a]
            val v = markCycle(next[a])
            firstCycles[a] = v
            return v
        }
        for(i in 0 until n){
            markCycle(i)
        }
        return firstCycles
    }
    val firstCycles by lazy{getfirstCycle()}


}
const val HighestBit = 30
inline fun Int.eachBits(act:(Int)->Unit){
    for(i in HighestBit - 1 downTo 0){
        if(this and (1 shl i) != 0){
            act(1 shl i)
        }
    }
}
inline fun Int.eachBitIndex(act:(Int)->Unit){
    for(i in HighestBit -1  downTo 0){
        if(this and (1 shl i) != 0){
            act(i)
        }
    }
}
inline fun Int.submask(act:(Int)->Unit){
    var here = this
    while (here > 0) {
        act(here)
        here = (here - 1) and this
    }
    act(here)
}
inline fun Int.eachDown1(act:(Int)->Unit){
    for(i in 0 until HighestBit){
        if(this and (1 shl i) != 0){
            act(this - (1 shl i))
        }
    }
}
inline fun Int.eachUp1(act:(Int)->Unit){
    for(i in 0 until HighestBit){
        if(this and (1 shl i) == 0){
            act(this + (1 shl i))
        }
    }
}
fun Int.hasElement(a:Int):Boolean{
    return (this and ( 1 shl a)) != 0
}
fun Long.hasElement(a:Int):Boolean{
    return (this and ( 1L shl a)) != 0L
}
fun Int.allexceptlast(a:Int):Int{
    return (this and ((1 shl a) - 1).inv())
}
inline fun Int.breakIntoIntervals(act:(Int,Int)->Unit){ // inclusive
    val a = this + 1
    for(k in 30 downTo 0){
        if(!a.hasElement(k)) continue
        act(allexceptlast(k + 1),k)
    }
}
inline fun Long.breakIntoIntervals(act:(Long,Int)->Unit){ // inclusive
    val a = this + 1
    for(k in 63 downTo 0){
        if(!a.hasElement(k)) continue
        act((this and ((1L shl (k+1)) - 1).inv()),k)
    }
}
data class br(val start:Int,val i:Int){// binary range
init{
    kotlin.assert(start and ((1 shl i) - 1) == 0)
}
    fun print(){
        println("[$start, ${start + (1 shl i) - 1 }]")
    }
}
fun rangeIntervalBreaks(left:Int,right:Int,act:(Int,Int)->Unit){
    var left = left
    val right = right + 1
    for(k in 0 until HighestBit){
        if(left.hasElement(k) && left + (1 shl k) <= right){
            act(left,k)
            left += 1 shl k
        }
    }
    for(k in HighestBit -1 downTo 0 ){
        if(right.hasElement(k) && !left.hasElement(k)){
            act(left,k)
            left += 1 shl k
        }
    }
}
const val sep = 5000
fun main(){
    solve.cases{
        val k = getint()
        val boxes = List(k){ mutableListOf<Int>()}
        repeat(k){i ->
            val  n = getint()
            repeat(n){
                boxes[i].add(getint())
            }
        }
        val allsum = boxes.sumOf { it.sumOf{it.toLong()} }
        if(allsum % k != 0L){
            put("No")
            return@cases
        }
        val eachsum = allsum / k
        val off = LongArray(k){boxes[it].sumOf{it.toLong()} - eachsum}
        val label = TreeMap<Long,Int>()
        val gotoBox = IntArray(k * sep + 1 ){-1}

        val last = k * sep
        for(i in 0 until k){
            for(ci in boxes[i].indices){
                val here = sep * i  + ci
                label[boxes[i][ci].toLong()] = here
            }
        }

        val next = IntArray(k * sep + 1 ){last}
        for( i in 0 until k){
            for(ci in boxes[i].indices) {
                val here = i * sep + ci
                val want = boxes[i][ci] - off[i]
                val to = label[want]
                if(to == null) {
                    next[here] = last
                } else {
                    next[here] = to
                    gotoBox[here] = to / sep
                }
            }
        }
        val F = functional(next)

        val doable = MutableList<List<Int>?>((1 shl k)){null}
        val roots = F.getCycleRoots()

        for(r in roots){
            var mask = 0
            val ret = mutableListOf<Int>()
            F.actOnCycle(r){
                if(mask == -1) return@actOnCycle
                val type = it/sep
                ret.add(it)
                if(type == k){
                    mask = -1
                    return@actOnCycle
                }
                if(mask and (1 shl type) == 0 ){
                    mask = mask or (1 shl type)
                }else{
                    mask = -1
                }
            }
            if(mask != -1){
                doable[mask] = ret
            }
        }
        for(mask in 1 until ( 1 shl k)){
            mask.submask {
                submask ->
                if(doable[mask] != null)
                    return@submask
                val other = mask - submask
                if(doable[submask] == null || doable[other] == null)
                    return@submask
                doable[mask] = doable[submask]!! + doable[other]!!
            }
        }

        if(doable[(1 shl k) -1 ] == null){
            put("No")
        }else{
            put("Yes")
            val so = doable[(1 shl k) -1 ]!!.sorted()
            val ret = TreeMap<Int,Int>()
            for(c in so){
                ret[next[c]] = (c/sep)+ 1
            }
            for(c in so){
                put(boxes[c/sep][c % sep])
                put(ret[c] !!)
            }
        }
    }
    done()
}

/*
receiev == send

linear shift

point this cycle
how to point this cycle

time wasted: did not read all the conditions
 */