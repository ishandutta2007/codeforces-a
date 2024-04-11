import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        DSecretPasswords solver = new DSecretPasswords();
        solver.solve(1, in, out);
        out.close();
    }

    static class DSecretPasswords {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            HashSet<Character>[] s = new HashSet[n];
            for (int i = 0; i < n; i++) {
                s[i] = new HashSet<>();
                char[] input = in.next().toCharArray();
                for (char x : input)
                    s[i].add(x);
            }

            UnionFind uf = new UnionFind(n);
            List<Integer>[] index = new List[26];
            for (int i = 0; i < 26; i++)
                index[i] = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                for (char c : s[i]) {
                    index[c - 'a'].add(i);
                }
            }
            for (List<Integer> ind : index) {
                for (int i = 0; i + 1 < ind.size(); i++) {
                    uf.union(ind.get(i), ind.get(i + 1));
                }
            }

            int answer = 0;
            for (int i = 0; i < n; i++) {
                if (uf.rep(i) == i)
                    answer++;
            }

            out.println(answer);
        }

    }

    static class UnionFind {
        private int[] __rep;
        private int[] __size;

        public UnionFind(int n) {
            __rep = new int[n];
            __size = new int[n];
            for (int i = 0; i < n; i++) {
                __rep[i] = i;
                __size[i] = 1;
            }
        }

        public int rep(int x) {
            if (__rep[x] == x) {
                return x;
            }

            int r = rep(__rep[x]);
            __rep[x] = r;
            return r;
        }

        public int size(int x) {
            return __size[rep(x)];
        }

        public boolean union(int x, int y) {
            x = rep(x);
            y = rep(y);

            if (x == y) {
                return false;
            }

            if (size(x) < size(y)) {
                int t = x;
                x = y;
                y = t;
            }

            // now size(x) >= size(y)

            __rep[y] = x;
            __size[x] += __size[y];
            return true;
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