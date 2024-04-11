namespace Solution {

 

    open Microsoft.Quantum.Canon;

    open Microsoft.Quantum.Diagnostics;

    open Microsoft.Quantum.Primitive;

 	open Microsoft.Quantum.Math;

	open Microsoft.Quantum.Convert;


	operation reset(x : Qubit) : () {

 		if(M(x) == One){

 			X(x);

 		}

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


	operation r0 (q : Qubit) : Unit is Adj+Ctl {
		Y(q);

	}
	operation r1 (q : Qubit) : Unit is Adj+Ctl {
		Z(q);
		X(q);

		X(q);
		Z(q);
		X(q);
		Z(q);
		
	}
	operation r2 (q : Qubit) : Unit is Adj+Ctl {
		Y(q);

		X(q);
		Z(q);
		X(q);
		Z(q);
		
		//Y(q);
	}
	operation r3 (q : Qubit) : Unit is Adj+Ctl {

		Z(q);
		X(q);
	}
 

	operation Solve (U : (Qubit[] => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
        using (Q = Qubit[2]){
			X(Q[1]);
			U(Q);
			let m1 = M(Q[0]);
			let m2 = M(Q[1]);
			if(m1 == Zero && m2 == One){
				reset(Q[0]);
				reset(Q[1]);
				X(Q[0]);
				U(Q);
				if(M(Q[1]) == One){
					set res = 1;
				}
				else {
					set res = 0;
				}
			}
			if(m1 == One && m2 == One){
				set res = 2;
			}
			if(m1 == One && m2 == Zero){
				set res = 3;
			}
			reset(Q[0]);
			reset(Q[1]);
        }
        return res;
    }

	

//	 @EntryPoint()
 
    operation main() : Unit {
 
        using ( q = Qubit[4] ){
 
 
 			
 			
 
 
			DumpMachine("a.txt");
 
 
 
			ResetAll(q);
 
 
 
		}
 
        
 
    }



}