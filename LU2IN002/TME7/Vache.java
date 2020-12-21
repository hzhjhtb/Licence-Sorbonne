public class Vache extends Animal{
	public Vache(String nom,int age){
		super(nom,age);
	}
	
	public Vache(String nom){
		super(nom);
	}
	
	
	public String toString(){
		return "Vache : " + super.toString();
	}
	
	public void crier(){
		System.out.println("Vache " + nom + " crie!");
	}

}
