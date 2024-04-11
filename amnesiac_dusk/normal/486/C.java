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
	static final long mod=1000000007;
	static final double eps=1e-8;
	static final boolean debug=false;
	static Reader in=new Reader();
	public static void main(String[] args) throws IOException
	{
		int n=ni(),p=ni()-1;
		String a=ns();
		long ans1=0;
		boolean toch[]=new boolean[n/2];
		for(int i=0; i<n/2; i++)
			if(a.charAt(i)!=a.charAt(n-1-i))
				toch[i]=true;
		int st=-1,stop=0;
		for(int i=0; i<n/2; i++)
		{
			if(toch[i]&&st==-1)
				st=i;
			if(toch[i])
				stop=i;
		}
		if(st==-1)
			pr(0);
		else 
		{
			pd(st+" "+stop);
			for(int i=st; i<=stop; i++)
				ans1+=Math.min(Math.min(Math.abs(a.charAt(i)-a.charAt(n-i-1)), Math.abs(26+a.charAt(i)-a.charAt(n-i-1))),Math.min(Math.abs(-a.charAt(i)+a.charAt(n-i-1)), Math.abs(26-a.charAt(i)+a.charAt(n-i-1))));
			if(p>=n/2)
				p=n-p-1;
			pd(stop+" "+p+" "+st);
			if(st>=p)
				ans1+=stop-p;
			else if(stop<=p)
				ans1+=p-st;
			else
				ans1+=Math.min(p-2*st+stop, stop-p+stop-st);
			pr(ans1);
		}
		System.out.println(ans);
	}
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
	static void pd(){if(debug)ans.append("hola");}
	static void pd(Object a){if(debug)ans.append(a+"\n");}
	static void pr(Object a){ans.append(a+"\n");}
	static void p(Object a){ans.append(a);}
	static int ni(){return in.nextInt();}
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
}