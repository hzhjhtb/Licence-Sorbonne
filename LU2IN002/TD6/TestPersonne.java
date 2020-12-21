public class TestPersonne{
	
	public static void main(String[] args){
		Personne p = new Personne("Albert");
		p.ajouterEnfant();
		/* p.prime(); pas un méthode de Personne */
		/* p.estEnL2(); pas un méthode de Personne */
		
		Etudiant e = new Etudiant("Ahmed",null,"L2");
		e.ajouterEnfant();
		/* e.prime(); pas un méthode de Etudiant */
		e.estEnL2();
		
		// Il faut 2 arguments avec String nom, double salaire
		// Salarie s1 = new Salarie("Amelle");
		// Salarie s2 = new Salarie("Pauline","0122334455");
		// Salarie s3 = new Salarie("Amelle","0123401234",2000);
	}	
	
}
