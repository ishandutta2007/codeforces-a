import java.util.*;
import java.io.*;

public class _1042_C {

	static class Pair{
		int l, r;
		public Pair(int l, int r) {
			this.l = l; this.r =r ;
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt();
		int arr[] = new int[N+1];
		boolean tkn[] = new boolean[N+1];
		int negcnt = 0, min = Integer.MIN_VALUE;
		for(int i = 1; i<=N; i++) {
			arr[i] = readInt();
			if(arr[i] < 0) min = Math.max(arr[i], min);
			if(arr[i] < 0) negcnt++;
		}
		LinkedList<Pair> ll = new LinkedList<>();
		int s = 0;
		for(int i = 1; i<=N; i++) {
			if(arr[i] == 0 || (arr[i] == min && negcnt%2 == 1)) {
				if(s != 0 && (arr[i] == 0)) {
					ll.add(new Pair(s, i));
				}
				else if(s != 0 && (arr[i] == min)) {
					ll.add(new Pair(s, i));
					min = 0;
				}
				else if(arr[i] == min) min = 0;
				s = i;
				tkn[i] = true;
			}
		}
		if(s != 0) ll.add(new Pair(-1, s));
		s = 0;
		for(int i = 1; i<=N; i++) {
			if(tkn[i]) continue;
			if(s != 0) ll.add(new Pair(s, i));
			s = i;
		}
		int cnt = 0;
		while(!ll.isEmpty() && cnt < N-1) {
			if(ll.peek().l == -1){
				println(2 + " " + ll.remove().r);
			}
			else println(1 + " " + ll.peek().l + " " + ll.remove().r);
			cnt++;
		}
		exit();
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