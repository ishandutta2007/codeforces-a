import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        BMahmoudAndATriangle solver = new BMahmoudAndATriangle();
        solver.solve(1, in, out);
        out.close();
    }

    static class BMahmoudAndATriangle {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();

            Arrays.sort(a);

            boolean answer = false;
            for (int i = 0; i + 2 < n; i++) {
                if (a[i] + a[i + 1] > a[i + 2]) {
                    answer = true;
                }
            }

            out.println(answer ? "YES" : "NO");
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

    }
}