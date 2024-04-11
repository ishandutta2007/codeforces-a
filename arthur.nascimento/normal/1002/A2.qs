
 namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    

	operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
			let n = Length(qs);
            H(qs[0]);
            for(i in 1..n-1){
                if(bits[i] == true){
                    CNOT(qs[0],qs[i]);
                }   
            }
        }
    
    }
}