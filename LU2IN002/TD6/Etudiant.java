public class Etudiant extends Personne{
	
	private String cursus;
	
	public Etudiant(String n,String t,String c){
		super(n,t);
		cursus = c;
	}
	
	public boolean estEnL2(){ return cursus.equals("L2"); }
	
	public void afficherInfo(){
		System.out.println("Nom " + nom);
		System.out.println("NumTel " + numTel);
		/* System.out.println("NbEnfants " + nbEnfants); private nbEnfants; */
		System.out.println("Cursus " + cursus);
	}
	
	public void modifierInfo(){
		/* nom = "toto"; final nom */
		numTel = "0102030405";
		/* nbEnfants = -1; private nbEnfants; */
		cursus = "L0";
	}

}
