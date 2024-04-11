import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.math.absoluteValue
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
fun getline(n:Int):IntArray{
    val ret = IntArray(n);repeat(n){ret[it] = getint()};return ret
}
fun getlineL(n:Int):LongArray{
    val ret = LongArray(n);repeat(n){ret[it] = getlong()};return ret
}
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
        //safety checks
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Modding a wrong prime!")
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
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this * 1L * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
val Char.code :Int get() = this.toInt() -  'a'.toInt()

/*
1 3
3 5
1 5

 */
class DisjointUnionSets(val n: Int) {
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}
    var components:Int = n

    val successfulUnions:Int get() = n - components

    fun find(x: Int): Int {
        if (parent[x] != x) {
            parent[x] = find(parent[x])
        }
        return parent[x]
    }

    fun union(x: Int, y: Int) {
        val xRoot = find(x)
        val yRoot = find(y)
        if (xRoot == yRoot) return
        components--
        if(size[xRoot] < size[yRoot]){
            parent[xRoot] = yRoot
            size[yRoot] += size[xRoot]
        }else{
            parent[yRoot] = xRoot
            size[xRoot] += size[yRoot]
        }
    }
    fun getsize(a:Int):Int{
        return size[find(a)]
    }

    var modified = mutableListOf<Int>()
    inline fun eachComponent(act:(Int)->Unit){
        for(i in 0 until n){
            if(parent[i] == i){
                act(i)
            }
        }
    }

    fun printAll(){
        val comps = Array(n){ mutableListOf<Int>()}
        for(i in 0 until n){
            comps[find(i)].add(i)
        }
        println(comps.filter { it.isNotEmpty() }.joinToString("     "))
    }
}

class kruskalEdge(val from:Int, val to:Int, val price:Int, val hash:Long = Random.nextLong()):Comparable<kruskalEdge>{
   companion object{
       var x = 0
   }
    override fun compareTo(other: kruskalEdge): Int {
        return (this.price - x).absoluteValue - (other.price - x).absoluteValue
    }
    fun oppo(a:Int):Int{
        return if(a == from)to else from
    }
}

fun List<kruskalEdge>.hash():Long{
    var ret =0L
    for(a in this){
        ret = ret xor a.hash
    }
    return ret
}
class weightedGraph(val n:Int, val directed:Boolean) {
    companion object{
        const val useKruskal = true
    }
    val edgeSets = mutableListOf<kruskalEdge>()
    val adjList = List(n){ mutableListOf<kruskalEdge>()}
    fun addEdgeWithPrice(a:Int,b:Int,price:Int){
        val e = kruskalEdge(a,b,price)
        if(useKruskal){ edgeSets.add(e) }

        adjList[a].add(e)
        if(!directed){ adjList[b].add(e)}
    }
    fun dijkstra(): IntArray {
        val q = PriorityQueue<Pair<Int,Int>>{a,b -> a.second - b.second}
        val dist = IntArray(n){Int.MAX_VALUE}
        dist[0] = 0
        for(i in 0 until n){
            q.add(Pair(i,dist[i]))
        }
        while (!q.isEmpty()) {
            val u = q.poll().first
            if (dist[u] == Int.MAX_VALUE) break

            for (e in adjList[u]) {
                val v = e.to
                val alternateDist = dist[u] + e.price
                if (alternateDist < dist[v]) { // shorter path to neighbour found
                    q.remove(Pair(v,dist[v]))
                    dist[v] = alternateDist
                    q.add(Pair(v,alternateDist))
                }
            }
        }
        return dist
    }


    fun KruskalMST():Pair<IntArray,Long>{
//        val result = mutableListOf<kruskalEdge>()
        val ret = IntArray(n-1)
        var pointer = -1
        var hash =0L
        var e = 0
//        edgeSets.sort()
        val ES = edgeSets.sorted()
        val S = DisjointUnionSets(n)

        for(next_edge in ES){
            val x: Int = S.find(next_edge.from)
            val y: Int = S.find(next_edge.to)

            if (x != y) {
                pointer ++
                ret[pointer] = next_edge.price
                hash = hash xor next_edge.hash
//                result.add(next_edge)
                S.union(x,y)
                e += 1
                if(e >= n - 1){
                    break
                }
            }
        }
        return Pair(ret,hash)
    }
    fun BFS01(){
        val root = 0
        val toDo = ArrayDeque<Int>()
        val explored = IntArray(n+1)
        toDo.add(root)
        explored[root] = 1

        while(toDo.size > 0){
            val x = toDo.remove()
            for(e in adjList[x]){
                val a = e.oppo(x)
                if(explored[a] == 0){
                    explored[a] = 1
                    if(e.price == 0){
                        toDo.addFirst(a)
                    }else{
                        toDo.addLast(a)
                    }
                }
            }
        }
    }
}

inline fun BinarySearchFirstTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
        val m = (L + R) shr 1
        if(isTrue(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(isTrue(L)){
        L
    }else{
        if(L == r){
            null
        }else{
            L + 1
        }
    }
}

inline fun BinarySearchLastTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
       val m = ((L + R) shr 1) + 1
        if(isTrue(m)){ L = m }else{ R = m - 1 }
    }
    return if(isTrue(L)){ L }else{ null }
}

fun List<kruskalEdge>.costwith(x:Int):Long {
    var ret = 0L
    for(a in this){
        ret += (x - a.price).absoluteValue
    }
    return ret
}

fun IntArray.costWith(x:Int):Long{
    var ret = 0L
    for(a in this){
        ret += (x - a).absoluteValue
    }
    return ret
}

/*
50
1 2
 */
const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.tc {
        share("50 49")
        for(i in 1..49){
            share("$i ${i+1} $i")
        }
        share("""1 10000000 0 0 100000000
75
""")
    }
//    solve.usetc()
    solve.cases{
        val n = getint()
        val m = getint()
        val G = weightedGraph(n,false)
        repeat(m){
            G.addEdgeWithPrice(getint()-1, getint() - 1 , getint())
        }
        G.edgeSets.sort()
        var now = 0
        val ret = TreeMap<Int,IntArray>()
        val (new,h) = G.KruskalMST()
        ret[0] = new
        var lasthash = h
        val max = 100_000_007

        fun dothis(x:Int, y:Int, lhash:Long, rhash:Long){
            if( y -x <= 1 ){
                kruskalEdge.x = y
                val (new,h) = G.KruskalMST()
                ret[y] = new
                return
            }
            val mid = (x + y) shr 1
            kruskalEdge.x = mid
            val (newset,h) = G.KruskalMST()
            if(h == lhash){
                dothis(mid,y,lhash,rhash)
            }else if(h == rhash){
                dothis(x,mid,lhash,rhash)
            }else{
                dothis(x,mid,lhash,h)
                dothis(mid,y,h,rhash)
            }
        }
        dothis(0,max,Random.nextLong(),Random.nextLong())
//        while(now <= max){
//            val next = BinarySearchFirstTrue(now+1,max){
//                kruskalEdge.x = it
//                G.KruskalMST().hash() != lasthash
//            } ?: break
//            kruskalEdge.x = next
//            val newset = G.KruskalMST()
//            lasthash = newset.hash()
//            now = next
//            ret[next] = newset
//        }
//        val ret2 = TreeMap<Int,IntArray>()
//        for((v,l) in ret.entries){
//            ret2[v] = l.map{it.price}.toIntArray()
//        }

        val p = getint()
        val k = getint()
         val a = getint()
        val b = getint()
        val c = getint()
        val first = getline(p)
        var last = 0
        var finalxor = 0L
        for(i in 0 until k){
            val query = if(i < first.size){
                first[i]
            }else{
                ((1L * last * a + b) % c ).toInt()
            }
            last = query

            val ans = ret.floorEntry(query)!!.value.costWith(query)
//            just dei Pair(query,ans)
            finalxor = finalxor xor ans
        }
        put(finalxor)
    }
    done()
}
const val singleCase = true