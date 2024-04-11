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

 

	operation Solve (theta : Double, U : (Qubit => Unit is Adj+Ctl)) : Int {
		mutable res = 0;
        using (q = Qubit()){

        	for(i in 0..10){
        		reset(q);
				mutable s = 0.0;
				repeat {
					U(q);
					set s = s + theta;
				} until(s + theta > 3.1415);

				if(M(q) == One){
					set res = 1;
				}
        	}

        	reset(q);
 		}
 		return res;
    }

	

//	 @EntryPoint()

 

    operation main() : Unit {

 

        using ( q = Qubit[2] ){

 

 			H(q[0]);
 			H(q[1]);


 			Controlled R1 ([q[0]],(4.0 * ArcCos(0.0), q[1]));
 			

 			H(q[0]);
 			H(q[1]);

 			

 

 

			DumpMachine("a.txt");

 

 

 

			ResetAll(q);

 

 

 

		}

 

        

 

    }



}