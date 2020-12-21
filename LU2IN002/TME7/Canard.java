public class Canard extends Animal{
	public Canard(String nom,int age){
		super(nom,age);
	}
	
	public Canard(String nom){
		super(nom);
	}
	
	
	public String toString(){
		return "Canard : " + super.toString();
	}
	
	public void crier(){
		System.out.println("Canard " + nom + " crie!");
	}

}
