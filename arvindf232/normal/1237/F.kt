import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
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
const val p = 998244353L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
val Char.code :Int get() = this.toInt() -  'a'.toInt()

const val singleCase = true
const val withBruteForce = false
const val randCount = 100

fun roll(ok:BooleanArray):IntArray {
    val k = 1801
    val ret = Array(ok.size +1){IntArray(1801)}
    ret[0][0] = 1


    for(phrase in 0 until ok.size){
        for(i in 0 until k){
            ret[phrase+ 1][i] += ret[phrase][i]
            ret[phrase+1][i] = ret[phrase+1][i].adjust()
        }
        if(ok[phrase] == false){
            continue
        }else{
            if(phrase +1 < ok.size && ok[phrase + 1]){
                for(i in 0 until k-1){
                    ret[phrase + 2][i+1] += ret[phrase][i]
                    ret[phrase +2] [i+1] =  ret[phrase +2] [i+1].adjust()
                }
            }

        }
    }
    return ret.last()
}
infix fun Int.divCeil(b:Int):Int{
    //Positives numbers only!
    if(this == 0) {
        return 0
    }
    return (this-1)/b + 1
}
infix fun Long.divCeil(b:Long):Long{
    //Positives numbers only!
    if(this == 0L) {
        return 0
    }
    return (this-1)/b + 1
}

infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
infix fun Int.modM(b:Int):Int{
    return ((this * 1L * b) % pI).toInt()
}
infix fun Int.modPlus(b:Int):Int{
    return (this + b).adjust()
}
infix fun Int.modMinus(b:Int):Int{
    return (this - b).adjust()
}
fun Int.additiveInverse():Int{
    return if(this == 0) 0 else pI - this
}


fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0){
            X = ((1L * X * X) % m).toInt()
            E /= 2
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
            for(i in 1..r){
                ret = ret modM (invStore[i])
            }
            return ret
        }

    }
}

fun main(){
    FACT.preCal(3603)
    solve.cases{
        val h = getint()
        val w = getint()
        val n = getint()

        val hr = BooleanArray(w){true}
        val wr = BooleanArray(h){true}



        for(i in 0 until n){
            val r1 = getint() - 1
            val c1 = getint() -1
            val r2 = getint() - 1
            val c2 = getint() - 1
            hr[c1] = false
            hr[c2] = false
            wr[r1]  = false
            wr[r2] = false
        }
        val R1 = roll(hr)
        val R2 = roll(wr)

        val xspace = hr.count { it }
        val yspace = wr.count{it}


        var ret = 0

        for(x in 0..1800){
            for(y in 0..1800){
                val EX = R1[x] modM FACT.choose(xspace - 2 * x ,y)
                val EY = R2[y] modM FACT.choose(yspace -  2 * y,x)
                val also = FACT.store[x] modM FACT.store[y]
                val all = EX modM EY modM also

//                if(all != 0)
//                "$x $y " dei all
                ret = (ret + all).adjust()
            }
        }

        put(ret)
    }
    done()
}

/*
natural subproblem observations

a horizontal tiles
b vertical tiles

a! b! something choose both of them

a 1s
b 2s

board rolling is cubic..
but equivalent of spaecs and 1s

wrong choose formula


So fast
10 think
15 code
5 final debug (one mistake)
 */