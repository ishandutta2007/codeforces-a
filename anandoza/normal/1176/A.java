import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ADivideIt solver = new ADivideIt();
        solver.solve(1, in, out);
        out.close();
    }

    static class ADivideIt {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                long n = in.nextLong();
                long answer = 0;
                while (n > 1) {
                    if (n % 2 == 0) {
                        n = n / 2;
                    } else if (n % 3 == 0) {
                        n -= n / 3;
                    } else if (n % 5 == 0) {
                        n -= n / 5;
                    } else {
                        answer = -1;
                        break;
                    }
                    answer++;
                }

                out.println(answer);
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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

    }
}