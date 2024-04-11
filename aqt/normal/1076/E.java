import java.util.*;
import java.io.*;

public class _1076_E_VasyaAndATree {

	static ArrayList<Integer> graph[];
	static ArrayList<Integer> ht[];
	static ArrayList<Integer> val[];
	static int dep[], par[];
	static long ans[];
	static long BIT[];
	
	public static void main(String[] args) throws IOException {
		int N = readInt();
		graph = new ArrayList[N+1];
		ht = new ArrayList[N+1];
		val = new ArrayList[N+1];
		for(int i=1; i<=N; i++) {
			graph[i] = new ArrayList<>();
			ht[i] = new ArrayList<>();
			val[i] = new ArrayList<>();
		}
		for(int i =1; i<N; i++) {
			int a = readInt(), b = readInt();
			graph[a].add(b);
			graph[b].add(a);
		}
		int Q = readInt();
		for(int i = 1; i<=Q; i++) {
			int n = readInt(), d = readInt(), v = readInt();
			ht[n].add(d);
			val[n].add(v);
		}
		BIT = new long[N+1];
		ans = new long[N+1];
		dep = new int[N+1];
		par = new int[N+1];
		dep[1] = 1;
		dfs(1);
		for(int i = 1; i<=N; i++) {
			print(ans[i] + " ");
		}
		exit();
	}
	
	static void dfs(int n) {
		for(int i = 0; i<ht[n].size(); i++) {
			upd(dep[n], val[n].get(i));
			upd(dep[n] + ht[n].get(i) + 1, -val[n].get(i));
		}
		for(int i = dep[n]; i>0; i-=i&-i) {
			ans[n] += BIT[i];
		}
		for(int e : graph[n]) {
			if(e != par[n]) {
				dep[e] = dep[n] + 1;
				par[e] = n;
				dfs(e);
			}
		}
		for(int i = 0; i<ht[n].size(); i++) {
			upd(dep[n], -val[n].get(i));
			upd(dep[n] + ht[n].get(i) + 1, val[n].get(i));
		}
	}
	
	static void upd(int n, int v) {
		for(int i = n; i<BIT.length; i+=i&-i) {
			BIT[i]+=v;
		}
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; // line length
		int cnt = 0, c;
		while ((c = Read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}

	public static String read() throws IOException {
		byte[] ret = new byte[1024];
		int idx = 0;
		byte c = Read();
		while (c <= ' ') {
			c = Read();
		}
		do {
			ret[idx++] = c;
			c = Read();
		} while (c != -1 && c != ' ' && c != '\n' && c != '\r');
		return new String(ret, 0, idx);
	}

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = Read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}