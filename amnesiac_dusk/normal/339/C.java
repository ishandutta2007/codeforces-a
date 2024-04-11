import java.io.*;
import java.util.*;
/*
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main 
{
	public static void main(String[] args) throws IOException
	{
		String a=ns();
		boolean w[]=new boolean[11];
		for(int i=0; i<10; i++)
			if(a.charAt(i)=='1')
				w[i+1]=true;
		int m=ni();
		boolean dp[][][]=new boolean[m+1][21][11];
		dp[0][10][0]=true;
		for(int i=1; i<=m; i++)
		{
			for(int j=0; j<21; j++)
			{
				for(int k=0; k<=10; k++)
				{
					if(dp[i-1][j][k])
					{
						for(int l=0; l<=10; l++)
						{
							if(k!=l&&w[l])
							{
								if(i%2!=0&&j+l>10)
								{
									dp[i][j+l][l]=true;
								}
								else if(i%2==0&&j-l<10)
								{
									dp[i][j-l][l]=true;
								}
							}
						}
					}
				}
			}
		}
		boolean pos=false;
		int ai=0,aj=0;
		for(int i=0; i<=20; i++)
			for(int j=0; j<=10; j++)
				if(dp[m][i][j])
				{
					pos=true;
					ai=i;
					aj=j;
				}
		List<Integer> hola=new ArrayList<Integer>();
		if(!pos)
			pr("NO");
		else
		{
			pr("YES");
			for(int i=m; i>0; i--)
			{
				hola.add(aj);
				if(i%2==0)
					ai+=aj;
				else
					ai-=aj;
				for(int j=0; j<=10; j++)
					if(dp[i-1][ai][j]&&aj!=j)
					{
						aj=j;
						break;
					}
			}
			Collections.reverse(hola);
			for(int i=0; i<m; i++)
				p(hola.get(i)+" ");
		}
		System.out.println(ans);
	}
	static final int mod=1000000007;
	static final double eps=1e-8;
	static final long inf=100000000000000000L;
	static final boolean debug=true;
	static Reader in=new Reader();
	static StringBuilder ans=new StringBuilder();
	static long powm(long a, long b, long m)
	{
		long an=1;
		long c=a;
		while(b>0)
		{
			if(b%2==1)
				an=(an*c)%m;
			c=(c*c)%m;
			b>>=1;
		}
		return an;
	}
	static Random rn=new Random();
	static void pd(){if(debug)ans.append("hola");}
	static void pd(Object a){if(debug)ans.append(a+"\n");}
	static void pr(Object a){ans.append(a+"\n");}
	static void pr(){ans.append("\n");}
	static void p(Object a){ans.append(a);}
	static int ni(){return in.nextInt();}
	static int[] nia(int n){int a[]=new int[n];for(int i=0; i<n; i++)a[i]=ni();return a;}
	static long[] nla(int n){long a[]=new long[n];for(int i=0; i<n; i++)a[i]=nl();return a;}
	static String[] nsa(int n){String a[]=new String[n];for(int i=0; i<n; i++)a[i]=ns();return a;}
	static long nl(){return in.nextLong();}
	static String ns(){return in.next();}
	static double nd(){return in.nextDouble();}
	static String pr(String a, long b)
	{
		String c="";
		while(b>0)
		{
			if(b%2==1)
				c=c.concat(a);
			a=a.concat(a);
			b>>=1;
		}
		return c;
	}
	static class Reader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
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
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
    }
	static class dyns 
	{
		dyns(long le,long ri)
		{
			lb=le;
			rb=ri;
		}
		dyns l,r;
		long val,lb,rb;
		void set(long te)
		{
			val++;
			if(lb!=te||rb!=te)
			{
				if((lb+rb)/2>=te)
				{
					if(l==null)
						l=new dyns(lb, (lb+rb)/2);
					l.set(te);
				}
				else
				{
					if(r==null)
						r=new dyns(((lb+rb)/2)+1,rb);
					r.set(te);
				}
			}
		}
		void reset(long a)
		{
			val--;
			if(val==0)
			{
				l=null;
				r=null;
				return;
			}
			if(lb!=a||rb!=a)
			{
				if((lb+rb)/2>=a)
					l.reset(a);
				else
					r.reset(a);
			}
		}
		long count(long le, long ri)
		{
			if(le<=lb&&ri>=rb)
				return val;
			if(le>rb)
				return 0;
			if(ri<lb)
				return 0;
			int a=0;
			if(l!=null)
				a+=l.count(le,ri);
			if(r!=null)
				a+=r.count(le,ri);
			return a;
		}
	}
}