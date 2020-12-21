public class Millepatte extends Animal{
	public Millepatte(String nom,int age){
		super(nom,age);
	}
	
	public Millepatte(String nom){
		super(nom);
	}
	
	
	public String toString(){
		return "Mille-patte : " + super.toString();
	}
	
	public void crier(){
		System.out.println("Mille-patte " + nom + " crie!");
	}

}
