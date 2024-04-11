import java.awt.*;
import java.io.*;
import java.math.*;
import java.util.*;


public class SolutionA {
	public static void main(String[] args) {
		new SolutionA().run();
	}
	
	void solve(){
		char a[] = in.next().toCharArray();
		char b[] = in.next().toCharArray();
		int n = a.length;
		a[n-1]++;
		for(int i =  n-1; i>=0; i--){
			if(a[i] > 'z') {
				a[i] = 'a';
				a[i-1]++;
			}
		}
		boolean ok = false;
		for(int i = 0; i < n; i++){
			if(a[i] != b[i]) ok = true;
		}
		if(ok){
			for(int i = 0; i < n; i++)
				out.print(a[i]);
		}
		else out.println("No such string");
	}
	FastScanner in;
	PrintWriter out;
	void run() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		StringTokenizer st;
		BufferedReader bf;

		public FastScanner(InputStream is) {
			bf = new BufferedReader(new InputStreamReader(is));
		}

		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(Exception ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		float nextFloat(){
			return Float.parseFloat(next());
		}
		short nextShort(){
			return Short.parseShort(next());
		}
		BigInteger nextBigInteger(){
			return new BigInteger(next());
		}
		BigDecimal nextBigDecimal(){
			return new BigDecimal(next());
		}
		int[] nextIntArray(int n){
			int a[] = new int[n];
			for(int i = 0; i < n; ++i)
				a[i] = Integer.parseInt(next());
			return a;
		}
		long[] nextLongArray(int n){
			long a[] = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = Long.parseLong(next());
			return a;
		}
	}

}