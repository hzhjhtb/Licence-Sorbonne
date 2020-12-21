public class TestStringReversible{
	public static void main(String[] args){
		System.out.println("le premier exemple :");
		System.out.println(args[0]);
		StringReversible stringreversible = new StringReversible(args[0]);
		
		stringreversible.reverse();
		System.out.println(stringreversible.toString()); 
		
		stringreversible.reverse();
		System.out.println(stringreversible.toString()); 
	}	
}

/* C'est impossible de déclarer une variable de type Reversible */
