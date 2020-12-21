public class Saumon extends Animal{
	public Saumon(String nom,int age){
		super(nom,age);
	}
	
	public Saumon(String nom){
		super(nom);
	}
	
	
	public String toString(){
		return "Saumon : " + super.toString();
	}
	
	public void crier(){
		System.out.println("Saumon " + nom + " crie!");
	}

}
