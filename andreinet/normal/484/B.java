import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; ++i)
            A[i] = in.nextInt();

        Arrays.sort(A);

        int maxValue = 2000000;
        int[] last = new int[maxValue + 1];

        for (int i = 0; i < N; ++i)
            last[A[i]] = A[i];

        for (int i = 1; i <= maxValue; ++i)
            if (last[i] == 0)
                last[i] = last[i - 1];

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] == A[i - 1])
                continue;

            for (int j = A[i] * 2; j <= maxValue; j += A[i])
                ans = Math.max(ans, last[j - 1] % A[i]);
        }

        out.println(ans);
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String nextString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));

        return res.toString();
    }

    private boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

}