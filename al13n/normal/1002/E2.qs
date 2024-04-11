namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Bitwise;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Arithmetic;

    function ToInt(r : Result) : Int {
        if (r == One) {
            return 1;
        } else {
            return 0;
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => Unit)) : Int[] {
        mutable ans = new Int[N];
        using ((qs, y) = (Qubit[N], Qubit())) {
            Uf(qs, y);
            if (ToInt(M(y)) != N%2) {
                set ans w/= 0 <- 1;
            }
            Reset(y);
        }
        return ans;
    }

    //@EntryPoint()
    //operation test() : Unit {
    //    mutable c = 0;
    //    for (i in 1..100) {
    //        using (q = Qubit()) {
    //            H(q);
    //            set c += Solve(q);
    //            Reset(q);
    //        }
    //    }
    //    Message($"{c}");
    //}
}