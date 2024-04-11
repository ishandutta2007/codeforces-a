/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.min
import kotlin.math.max
import kotlin.reflect.KProperty0
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
	val t = measureTimeMillis(){
		f()
	}
	println(t)
}

class FastScanner {
	private val BS = 1 shl 16
	private val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC
	private var `in`: BufferedInputStream? = null

	constructor() {
		`in` = BufferedInputStream(System.`in`, BS)
	}

	private val char: Char
		get() {
			while (bId == size) {
				size = try {
					`in`!!.read(buf)
				} catch (e: Exception) {
					return NC
				}
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
		while (c >= '0' && c <= '9') {
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
		while (c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if (neg) -res else res
	}
	fun nextString():String{
		if (c == NC) c = char
		val ret = StringBuilder()
		while (true){
			c = char
			if(!isWhitespace(c)){ break}
		}
		ret.appendCodePoint(c.toInt())
		while (true){
			c = char
			if(isWhitespace(c)){ break}
			ret.appendCodePoint(c.toInt());

		}
		return ret.toString()
	}
	fun isWhitespace(c:Char):Boolean{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}
class reading{
	companion object{
		var jin = FastScanner()
		var pw = PrintWriter(System.out)
	}
}
fun put(aa:Any){ reading.pw.println(aa)}
fun done(){ reading.pw.close() }

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

val List<Char>.ret:String
	get() = this.joinToString("")
infix fun Any.dei(a:Any){
	//does not stand for anything it is just easy to type
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
fun prefixSumL(arr:List<Long>):MutableList<Long>{
	val ret = mutableListOf<Long>()

	var previous = 0L
	for(a in arr){
		previous += a
		ret.add(previous)
	}
	return ret
}
class rMINq(val arr:List<Long>){
	val n = arr.size
	val store = mutableListOf<LongArray>()
	fun preprocess(){
		var s = 1
		var olds = 0
		while(s <= n){
			if(s == 1){
				val new = arr.toLongArray()
				store.add(new)
			}else{
				val size = n-s+1
				val old = store.last()
				val new = LongArray(size)
				for(i in 0 until size){
					new[i] = minOf(old[i],old[i+olds])
				}
				store.add(new)
			}
			olds = s
			s = s shl 1
		}
	}
	fun minQuery(l:Int,r:Int):Long{
		val d = r - l + 1
		val i = 31 - d.countLeadingZeroBits()
		val s = 1 shl i
		val a1 = l
		val a2 = r - s + 1
		val ret1 = store[i][a1]
		val ret2 = store[i][a2]
		return minOf(ret1,ret2)
	}
	init {
		preprocess()
	}
}
class rMAXq(val arr:List<Long>){
	val n = arr.size
	val store = mutableListOf<LongArray>()
	fun preprocess(){
		var s = 1
		var olds = 0
		while(s <= n){
			if(s == 1){
				val new = arr.toLongArray()
				store.add(new)
			}else{
				val size = n-s+1
				val old = store.last()
				val new = LongArray(size)
				for(i in 0 until size){
					new[i] = maxOf(old[i],old[i+olds])
				}
				store.add(new)
			}
			olds = s
			s = s shl 1
		}
	}
	fun maxQuery(l:Int,r:Int):Long{
		val d = r - l + 1
		val i = 31 - d.countLeadingZeroBits()
		val s = 1 shl i
		val a1 = l
		val a2 = r - s + 1
		val ret1 = store[i][a1]
		val ret2 = store[i][a2]
		return maxOf(ret1,ret2)
	}
	init {
		preprocess()
	}
}


fun main() {
	val n = getint()
	val q = getint()
	 val A = getlineL(n)
	val B = getlineL(n)

	val score = MutableList(n){0L}
	for(i in 0 until n){
		score[i] = B[i] - A[i]
	}
//	just dei score
	val Asum = prefixSumL(score)

	val MIN = rMINq(Asum)
	val MAX = rMAXq(Asum)

	repeat(q) {
		val a = getint() - 1
		val b = getint() - 1
		val presum = Asum.getOrNull(a - 1) ?: 0L
		val min = MIN.minQuery(a, b)
		if(min < presum) {
			put(-1)
		} else if(Asum[b] != presum){
			put(-1)
		}else{
			val max = MAX.maxQuery(a,b)
			put(max - presum)
		}
	}
	done()



    // Write your solution here
}