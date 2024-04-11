import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import kotlin.math.abs
import kotlin.system.measureTimeMillis
import java.util.*
import java.math.BigInteger

class FastScanner {
	private val BS = 1 shl 16
	private val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC
	private var `in`:BufferedInputStream? = null

	constructor() {
		`in` = BufferedInputStream(System.`in`, BS)
	}

	private val char:Char
		private get() {
			while(bId == size) {
				size = try {
					`in`!!.read(buf)
				} catch(e:Exception) {
					return NC
				}
				if(size == -1) return NC
				bId = 0
			}
			return buf[bId++].toChar()
		}

	fun nextInt():Int {
		var neg = false
		if(c == NC) c = char
		while(c < '0' || c > '9') {
			if(c == '-') neg = true
			c = char
		}
		var res = 0
		while(c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if(neg) -res else res
	}

	fun nextLong():Long {
		var neg = false
		if(c == NC) c = char
		while(c < '0' || c > '9') {
			if(c == '-') neg = true
			c = char
		}
		var res = 0L
		while(c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if(neg) -res else res
	}

	fun nextString():String {
		if(c == NC) c = char
		val ret = StringBuilder()
		while(true) {
			c = char
			if(!isWhitespace(c)) {
				break
			}
		}
		ret.appendCodePoint(c.toInt())
		while(true) {
			c = char
			if(isWhitespace(c)) {
				break
			}
			ret.appendCodePoint(c.toInt());
		}
		return ret.toString()
	}

	fun isWhitespace(c:Char):Boolean {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}

class reading {
	companion object {
		var jin = FastScanner()
		var pw = PrintWriter(System.out)
	}
}

fun put(aa:Any) {
	reading.pw.println(aa)
}

fun done() {
	reading.pw.close()
}

fun getint():Int {
	return reading.jin.nextInt()
}

fun getlong():Long {
	return reading.jin.nextLong()
}

fun getline(n:Int):List<Int> {
	return (1..n).map { reading.jin.nextInt() }
}

fun getlineL(n:Int):List<Long> {
	return (1..n).map { reading.jin.nextLong() }
}

fun getstr():String {
	return reading.jin.nextString()
}

fun List<Int>.out() {
	put(this.joinToString(" "))
}

val List<Char>.ret:String
	get() = this.joinToString("")

fun just(a:Boolean) {
	put(if(a) "YES" else "NO")
}

inline fun cases(ask:() -> Unit) {
	val t = getint()
	repeat(t) {
		ask()
	}
}

infix fun Long.divCeil(b:Long):Long {
	//Positives numbers only!
	if(this == 0L) {
		return 0
	}
	return (this - 1) / b + 1
}

inline fun BinarySearchLastTrue(l:Int, r:Int, isTrue:(Int) -> Boolean):Int? {
	//inclusive
	var L = l
	var R = r
	while(L < R) {
		val m = (L + R) / 2 + 1
		if(isTrue(m)) {
			L = m
		} else {
			R = m - 1
		}
	}
	return if(isTrue(L)) {
		L
	} else {
		null
	}
}

inline fun BinarySearchFirstTrue(l:Int, r:Int, isTrue:(Int) -> Boolean):Int? {
	//inclusive
	var L = l
	var R = r
	while(L < R) {
		val m = (L + R) / 2
		if(isTrue(m)) {
			R = m
		} else {
			L = m + 1
		}
	}
	return if(isTrue(L)) {
		L
	} else {
		if(L == r) {
			null
		} else {
			L + 1
		}
	}
}

inline fun BinarySearchExact(value:Int, l:Int, r:Int, find:(Int) -> Int):Int? {
	//find shoudl be increasing
	var L = l
	var R = r
	while(L < R) {
		val m = (L + R) / 2
		if(value <= find(m)) {
			R = m
		} else {
			L = m + 1
		}
	}
	return if(find(L) == value) {
		L
	} else {
		null
	}
}

inline fun TIME(f:() -> Unit) {
	val t = measureTimeMillis() {
		f()
	}
	println(t)
}

val powersOfTwo =
	intArrayOf(1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144)

class Graph(val n:Int, val directed:Boolean) {
	val E = Array<MutableList<Int>>(n + 1) { mutableListOf() }

	fun streamEdges(m:Int) {
		repeat(m) {
			val x = getint()
			val y = getint()
			E[x].add(y)
			if(!directed) {
				E[y].add(x)
			}
		}
	}

	fun BFS() {
		val root = 1
		val toDo:Queue<Int> = LinkedList<Int>()
		val explored = IntArray(n + 1)
		toDo.add(root)
		explored[root] = 1

		while(toDo.size > 0) {
			val x = toDo.remove()
			val things = E[x]
			for(a in things) {
				if(explored[a] == 0) {
					explored[a] = 1
					toDo.add(a)
				}
			}
		}
	}

	fun DFS() {
		val root = 1
		val toDo = ArrayDeque<Int>()
		val explored = IntArray(n + 1)
		toDo.add(root)
		explored[root] = 1

		while(toDo.size > 0) {
			val x = toDo.removeLast()
			val things = E[x]
			for(a in things) {
				if(explored[a] == 0) {
					explored[a] = 1
					toDo.addLast(a)
				}
			}
		}
	}

	val parents = IntArray(n + 1)
	val depth = IntArray(n + 1)
	val DFSorder = IntArray(n + 1)
	var DFSPointer = 1
	val treeSize = IntArray(n + 1)
	val transOrder = mutableListOf<Int>()
	val transCount = IntArray(n + 1)
	var nes = IntArray(n + 1)

	fun reached(i:Int) {
		nes[i] *= -1
		transOrder.add(i)
	}

	fun DFSTransversalDiTree() {
		fun go(i:Int, from:Int, d:Int):Int {
			depth[i] = d
			DFSorder[DFSPointer] = i
			DFSPointer += 1
			reached(i)
			var size:Int = 1
			for(v in E[i]) {
				if(v != from) {
					size += go(v, i, d + 1)
					parents[v] = i
					reached(i)
				}
			}
			if(nes[i] == -1 && i != 1) {
				nes[i] = 1
				nes[from] *= -1
				transOrder.add(from)
				transOrder.add(i)
			}
//            f(i)
			treeSize[i] = size
			return size
		}
		DFSPointer = 1
		go(1, 0, 0)
		parents[1] = 1

		if(nes[1] == -1) {
			val any = E[1].first()
			transOrder.add(any)
			transOrder.add(1)
			transOrder.add(any)
		}

		println(transOrder.joinToString(" "))
	}

	fun add(a:Int, b:Int) {
		E[a].add(b)
		if(!directed) {
			E[b].add(a)
		}
	}

	fun DFSrecur() {
		val root = 1
		val explored = IntArray(n + 1)
		//        var calls = 0
		fun go(i:Int, from:Int) {
//            calls += 1
			for(v in E[i]) {
				if(v != from) {
					go(v, i)
				}
			}
		}
		go(1, 0)
	}

	val quickParents = mutableListOf<IntArray>()
	fun calQuickPA() {
		var needed = 1
		var total = this.n
		while(total > 1) {
			total = total shr 1
			needed += 1
		}
		quickParents.add(parents)
		for(i in 1..needed) {
			val previous = quickParents.last()
			val new = IntArray(n + 1)
			for(a in new.indices) {
				new[a] = previous[previous[a]]
			}
			quickParents.add(new)
		}
	}

	fun calParent(i:Int, l:Int):Int {
		var now = i
		var layer = l

		for((i, p) in powersOfTwo.withIndex()) {
			if(p > layer) {
				break
			}
			if(p and layer > 0) {
				now = quickParents[i][now]
				layer -= p
			}
		}
		return now
	}

	fun isParent(i:Int, of:Int):Boolean {
		val a = depth[i]
		val b = depth[of]
		if(a > b) {
			return false
		} else {
			return calParent(of, b - a) == a
		}
	}
}

fun <K> MutableMap<K, Int>.addone(key:K) {
	this[key] = this.getOrDefault(key, 0) + 1
}

fun <K> MutableMap<K, Int>.subone(key:K) {
	val pe = this[key]
	if(pe == 0 || pe == null) {
		throw Exception("Removing what is already empty ")
	} else {
		this[key] = pe - 1
		if(pe == 1) {
			this.remove(key)
		}
	}
}

fun generic2D(n:Int, m:Int):List<List<Int>> {
	val thing = mutableListOf<List<Int>>()
	for(i in 0 until n) {
		thing.add(List(m) { it + i * m })
	}
	return thing
}

fun <T> List<List<T>>.printSquare() {
	for(a in this) {
		println(a.joinToString(" "))
	}
}
//100ms for standard
fun main() {
	val n = getint()
	val k = getlong()
	val F = getline(n)
	val W = getlineL(n)

	val quickF = mutableListOf<IntArray>()
	val qsum = mutableListOf<LongArray>()
	val qweight = mutableListOf<LongArray>()

	quickF.add(F.toIntArray())
	qsum.add(W.toLongArray())
	qweight.add(W.toLongArray())

	for(i in 1..64){
		if((1L shl i) > 1e11){
			break
		}
//		val size = 1 shl i
		val last = quickF.last()
		val lastSum = qsum.last()
		val lastWeight = qweight.last()

		val new = IntArray(n)

		val newSum = LongArray(n)
		val newWeight = LongArray(n)
		for(i in 0 until n){
			val a = i
			val b = last[i]
			val c = last[b]

			new[i] = c
			newSum[i] = lastSum[a] + lastSum[b]
			newWeight[i] = minOf(lastWeight[a], lastWeight[b])
		}
		quickF.add(new)
		qsum.add(newSum)
		qweight.add(newWeight)
	}

//	var remaining = k
	var current = IntArray(n){it}
	val retSum = LongArray(n)
	val retWeight = LongArray(n){Long.MAX_VALUE}
	for(a in 0..64){
		val s = 1L shl a

		if(s > k){
			break
		}
//		println("$s $a")
		if(s and k == 0L){
			continue
		}
//		println("Proceeded $a")
		for(i in 0 until n ){
			val cu = current[i]
			retSum[i] += qsum[a][cu]
			retWeight[i] = minOf(retWeight[i],qweight[a][cu])
		}
		val newCurrent = IntArray(n)
		for(i in 0 until n){
			newCurrent[i] = quickF[a][current[i]]
		}
		current = newCurrent
	}
	for(i in 0 until n){
		put(retSum[i])
		put(retWeight[i])
	}
	done()

}

tailrec fun gcd(a:Int, b:Int):Int {
	return if(a % b == 0) Math.abs(b) else gcd(b, a % b)
}