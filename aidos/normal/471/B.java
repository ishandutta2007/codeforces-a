import java.io.*;
import java.math.*;
import java.util.*;

public class SolutionA {

	public static void main(String[] args){
		new SolutionA().run();
	}
	Pair p[];
	void solve(){
		int n = in.nextInt();
		p = new Pair[n];
		for(int i=0; i <n; i++){
			p[i] = new Pair(in.nextInt(), i);
		}
		Arrays.sort(p);
		long dif = 1;
		for(int i = 0; i < n && dif < 3; ){
			int j = i;
			while(i < n && p[j].x == p[i].x) i++;
			dif *= (i - j);
		}
		if( dif < 3){
			out.println("NO");
			return;
		}
		out.println("YES");
		for(int i = 0; i<3; i++){
			for(int j = 0; j < n;j++){
				if(j > 0) out.print(" ");
				out.print(p[j].y+1);
			}
			out.println();
			for(int j = 1; j<n; j++){
				if(p[j].x == p[j-1].x && p[j].y > p[j-1].y){
					int tmp=p[j].y;
					p[j].y = p[j-1].y;
					p[j-1].y = tmp;
					break;
				}
			}
		}
	}
	
	class Pair implements Comparable<Pair>{
		int x, y;
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
		@Override
		public int compareTo(Pair o) {
			if(o.x == x) return ((Integer) y).compareTo(o.y); 
			return ((Integer) x).compareTo(o.x);
		}
		
	}
	FastScanner in;
	PrintWriter out;
	void run(){
		in = new FastScanner(System.in);
		out = new PrintWriter(new OutputStreamWriter(System.out));
		solve();
		out.close();
	}
	
	void runIO(){
		try{
			in = new FastScanner(new File("expr.in"));
			out = new PrintWriter(new FileWriter(new File("expr.out")));
			solve();
			out.close();
		}catch(Exception ex){
			ex.printStackTrace();
		}
	}
	class FastScanner{
		BufferedReader bf;
		StringTokenizer st;
		public FastScanner(File f){
			try{
				bf = new BufferedReader(new FileReader(f));
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
		}
		public FastScanner(InputStream is){
			bf = new BufferedReader(new InputStreamReader(is));
		}
		String next(){
			while(st == null || !st.hasMoreTokens()){
				try{
					st = new StringTokenizer(bf.readLine());
				}
				catch(IOException ex){
					ex.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		float nextFloat(){
			return Float.parseFloat(next());
		}
		String nextLine(){
			try{
				return bf.readLine();
			}
			catch(Exception ex){
				ex.printStackTrace();
			}
			return "";
		}
		long nextLong(){
			return Long.parseLong(next());
		}
	}
}