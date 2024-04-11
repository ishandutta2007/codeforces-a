import java.io.*;
import java.util.*;
/*
 * Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid...
 */
public class Main
{
	static class segtree
	{
		//segment tree
		
		//n is segment tree size
		//take input from i=n to 2*n-1
		int n;
		int[]tr;
		void build()
		{
			for(int i=n-1; i>0; i--)
				tr[i]=tr[i<<1]+tr[(i<<1)|1];
		}
		void modify(int p, int value)
		{
			for(tr[p+=n]=value; p>1; p>>=1)
				tr[p>>1]=tr[p]+tr[p^1];
		}
		int query(int l, int r)
		{
			int res=0;
			for(l+=n, r+=n; l<r; l>>=1,r>>=1)
			{
				if(l%2!=0) res+=tr[l++];
				if(r%2!=0) res+=tr[--r];
			}
			return res;
		}
	}
	public static void main(String[]args) throws Exception
	{
		int n=ni(),k=ni();
		int[]a=nia(n);
		int[]b=nia(k);
		int[]c=new int[n],d=new int[n];
		boolean[]holor=new boolean[n+1];
		for(int i=0; i<k; i++)
			holor[b[i]]=true;
		Stack<pair> ho=new Stack<pair>();
		ho.add(new pair(-1,-1));
		for(int i=0; i<n; i++) {
			if(!holor[a[i]]) {
				int l=0,r=ho.size()-1,m=(l+r)/2;
				while(l<r) {
					if(ho.elementAt(ho.size()-1-m).a>a[i])
						l=m+1;
					else
						r=m;
					m=(l+r)/2;
				}
				c[i]=ho.elementAt(ho.size()-1-m).b+1;
			}
			else {
				while(ho.peek().a>a[i])
					ho.pop();
				ho.add(new pair(a[i],i));
			}
		}
		ho.clear();
		ho.add(new pair(-1,n));
		for(int i=n-1; i>=0; i--) {
			if(!holor[a[i]]) {
				int l=0,r=ho.size()-1,m=(l+r)/2;
				while(l<r)
				{
					if(ho.elementAt(ho.size()-1-m).a>a[i])
						l=m+1;
					else
						r=m;
					m=(l+r)/2;
				}
				d[i]=ho.elementAt(ho.size()-1-m).b;
			}
			else {
				while(ho.peek().a>a[i])
					ho.pop();
				ho.add(new pair(a[i],i));
			}
		}
		int[][]e=new int[n-k][];
		for(int i=0,j=0,l=0; i<n; i++)
			if(j!=k&&a[i]==b[j])
				j++;
			else
				e[l++]=new int[]{a[i],i};
		sort(e);
		segtree f=new segtree();
		f.tr=new int[2*n];
		f.n=n;
		Arrays.fill(f.tr,n,2*n,1);
		f.build();
		long ans=0;
		for(int i=0; i<n-k; i++)
		{
			ans+=f.query(c[e[i][1]],d[e[i][1]]);
			f.modify(e[i][1],0);
		}
		pr(ans);
		System.out.print(output);
	}
	///////////////////////////////////////////
	///////////////////////////////////////////
	///template from here
	static final int mod=1000_000_007;
	static final double eps=1e-9;
	static final long inf=100000000000000000L;
	static class pair
	{
		int a,b;
		pair(){}
		pair(int c,int d){a=c;b=d;}
		@Override
		public int hashCode()
		{
			return (a+" "+b).hashCode();
		}
		public boolean equals(Object c)
		{
			return (a==(((pair)c).a)&&b==(((pair)c).b));
		}
	}
	public static void sort(int[][]a)
	{
		Arrays.sort(a, new Comparator<int[]>()
				{
			public int compare(int[]a,int[]b)
			{
				if(a[0]>b[0])
					return 1;
				if(a[0]<b[0])
					return -1;
				return 0;
			}
				});
	}
	static interface combiner
	{
		public int combine(int a, int b);
	}
	static void pr(Object a){output.append(a+"\n");}
	static void pr(){output.append("\n");}
	static void p(Object a){output.append(a);}
	static void pra(int[]a){for(int i:a)output.append(i+" ");output.append("\n");}
	static void pra(long[]a){for(long i:a)output.append(i+" ");output.append("\n");}
	static void pra(String[]a){for(String i:a)output.append(i+" ");output.append("\n");}
	static void pra(double[]a){for(double i:a)output.append(i+" ");output.append("\n");}
	static void sop(Object a){System.out.println(a);}
	static void flush(){System.out.print(output);output=new StringBuilder();}
	static int ni(){return Integer.parseInt(in.next());}
	static long nl(){return Long.parseLong(in.next());}
	static String ns(){return in.next();}
	static double nd(){return Double.parseDouble(in.next());}
	static int[] nia(int n){int a[]=new int[n];for(int i=0; i<n; i++)a[i]=ni();return a;}
	static int[] pnia(int n){int a[]=new int[n+1];for(int i=1; i<=n; i++)a[i]=ni();return a;}
	static long[] nla(int n){long a[]=new long[n];for(int i=0; i<n; i++)a[i]=nl();return a;}
	static String[] nsa(int n){String a[]=new String[n];for(int i=0; i<n; i++)a[i]=ns();return a;}
	static double[] nda(int n){double a[]=new double[n];for(int i=0; i<n; i++)a[i]=nd();return a;}
	static Reader in=new Reader();
	static StringBuilder output=new StringBuilder();
	static Random rn=new Random();
	static void reverse(int[]a){for(int i=0; i<a.length/2; i++){a[i]^=a[a.length-i-1];a[a.length-i-1]^=a[i];a[i]^=a[a.length-i-1];}}
	static int log2n(long a)
	{
		int te=0;
		while(a>0)
		{
			a>>=1;
			++te;
		}
		return te;
	}
	static class vectorl implements Iterable<Long>
	{
		long a[];
		int size;
		vectorl(){a=new long[10];size=0;}
		vectorl(int n){a=new long[n];size=0;}
		public void add(long b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
		@Override
		public Iterator<Long> iterator() {
			Iterator<Long> hola=new Iterator<Long>()
					{
				int cur=0;
						@Override
						public boolean hasNext() {
							return cur<size;
						}
						@Override
						public Long next() {
							return a[cur++];
						}				
					};
			return hola;
		}
	}
	static class vector implements Iterable<Integer>
	{
		int a[],size;
		vector(){a=new int[10];size=0;}
		vector(int n){a=new int[n];size=0;}
		public void add(int b){if(++size==a.length)a=Arrays.copyOf(a, 2*size);a[size-1]=b;}
		public void sort(){Arrays.sort(a, 0, size);}
		public void sort(int l, int r){Arrays.sort(a, l, r);}
		@Override
		public Iterator<Integer> iterator() {
			Iterator<Integer> hola=new Iterator<Integer>()
					{
				int cur=0;
						@Override
						public boolean hasNext() {
							return cur<size;
						}
						@Override
						public Integer next() {
							return a[cur++];
						}				
					};
			return hola;
		}
	}
	static void exit(){System.out.print(output);System.exit(0);}
	static int min(int... a){int min=a[0];for(int i:a)min=Math.min(min, i);return min;}
	static int max(int... a){int max=a[0];for(int i:a)max=Math.max(max, i);return max;}	
	static int gcd(int... a){int gcd=a[0];for(int i:a)gcd=gcd(gcd, i);return gcd;}	
	static long min(long... a){long min=a[0];for(long i:a)min=Math.min(min, i);return min;}
	static long max(long... a){long max=a[0];for(long i:a)max=Math.max(max, i);return max;}	
	static long gcd(long... a){long gcd=a[0];for(long i:a)gcd=gcd(gcd, i);return gcd;}	
	static String pr(String a, long b){String c="";while(b>0){if(b%2==1)c=c.concat(a);a=a.concat(a);b>>=1;}return c;}
	static long powm(long a, long b, long m){long an=1;long c=a;while(b>0){if(b%2==1)an=(an*c)%m;c=(c*c)%m;b>>=1;}return an;}
	static int gcd(int a, int b){if(b==0)return a;return gcd(b, a%b);}
	static long gcd(long a, long b){if(b==0)return a;return gcd(b, a%b);}
	static class Reader{
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
    }
}