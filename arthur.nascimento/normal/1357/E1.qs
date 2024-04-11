namespace Solution {
 
 
 
    open Microsoft.Quantum.Canon;
 
    open Microsoft.Quantum.Diagnostics;
 
    open Microsoft.Quantum.Primitive;
 
 	open Microsoft.Quantum.Math;
 
	open Microsoft.Quantum.Convert;
 
 	    open Microsoft.Quantum.Arithmetic;
	//    open Microsoft.Quantum.Extensions.Math;
 
 
	operation reset(x : Qubit) : () {
 
 		if(M(x) == One){
 
 			X(x);
 
 		}
 
	}
 
 
 
	operation pot(a : Int, b : Int) : Int {
 
		mutable ret = 1;
 
		for(i in 1..b){
 
			set ret *= a;
 
		}
 
		return ret;
 
	}
 
 
 
	operation phase(q : Qubit, i : Int, Re : Double, Im : Double) : Unit {
 
		body {
 
			if(i == 0){
 
				X(q);
 
			}
 
			if(Im > 0.0){
 
				R1(ArcCos(Re),q);
 
			}
 
			else {
 
				R1(-ArcCos(Re),q);
 
			}
 
			if(i == 0){
 
				X(q);
 
			}
 
		}
 
		controlled auto;
 
		adjoint auto;
 
	}
 
 
 
	operation genEq(pos : Int, n : Int, cont : Int, Q : Qubit[], states : Int[], p2 : Int) : Unit {
 
		if(pos == n || Length(states) == 0){
 
			return ();
 
		}
 
		mutable l0 = new Int[0];
 
		mutable l1 = new Int[0];
 
		for(s in states){
 
			if(s%2 == 0){
 
				set l0 = l0 + [s/2];
 
			}
 
			else {
 
				set l1 = l1 + [s/2];
 
			}
 
		}
 
		let a = Length(l0);
 
		let b = Length(l1);
 
		let theta = 2.0 * ArcCos(Sqrt(IntAsDouble(a)/(IntAsDouble(a+b))));
 
		(ControlledOnInt(cont,Ry)) (Q[0..pos-1],(theta,Q[pos]));
 
		
 
		genEq(pos+1,n,cont,Q,l0,2*p2);
 
		genEq(pos+1,n,cont+p2,Q,l1,2*p2);
 
	}
 
 
 
	operation sum(x : Qubit[], y : Qubit[], carry : Qubit) :  Unit {
 
		body {
 
			let n = Length(x);
 
			if(n > 0){
 
				CNOT(carry,x[0]);
 
				CNOT(carry,y[0]);
 
				Controlled X([x[0],y[0]],carry);
 
				sum(x[1..n-1],y[1..n-1],carry);
 
				Controlled X([x[0],y[0]],carry);
 
				CNOT(carry,x[0]);
 
				CNOT(x[0],y[0]);
 
			}
 
		}
 
		controlled auto;
 
		adjoint auto;
 
	}
 
 
 
	operation S2 (qs : Qubit[], parity : Int) : Unit {
 
		mutable need = One;
 
		if(parity == 0){
 
			set need = Zero;
 
		}
 
        using (aux = Qubit()){
 
			repeat {
 
				for(q in qs){
 
					reset(q);
 
				}
 
				reset(aux);
 
				for(q in qs){
 
					H(q);
 
				}
 
				for(q in qs){
 
					Controlled X([q],aux);
 
				}
 
 
 
			} until(M(aux) == need);
 
			reset(aux);	
 
       	}
 
    }
 
    operation Incm (register : LittleEndian) : Unit is Adj+Ctl {
		let n=Length(register!);
		if(n>0) {
		Controlled Incm(register![0..0], LittleEndian(register![1..n-1]));
		X(register![0]);
		}
	}
 
    operation Solve (p : Int, LE : LittleEndian) : Unit is Adj+Ctl {
		let n = p%4;
		let Q = LE!;
		for(i in 0..n-1){
			QFTLE(LittleEndian(Q));
		}
	}
 
	
 
	
 
    //@EntryPoint()
 
    operation main() : Unit {
 
        using ( q = Qubit[4] ){
 
 
			genEq(0,4,0,q,[0,2,5,6],1);
 
			(ControlledOnInt(0,phase)) ([q[0],q[2],q[3]], (q[1],1,0.0,1.0) );
 
			Solve(2,LittleEndian(q));
 
 
 
 
			DumpMachine("a.txt");
 
 
 
			ResetAll(q);
 
 
 
		}
 
        
 
    }
 
}