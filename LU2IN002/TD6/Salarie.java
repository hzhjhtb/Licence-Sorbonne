public class Salarie extends Personne{

	protected double salaire;
	
	public Salarie(String nom,double salaire){
		super(nom);
		this.salaire = salaire;
	}
	
	public double getSalaire(){ return salaire; }
	
	public double prime(){ return getNbEnfants()*0.05*salaire; }
	
	public void modifierNumTel(String numTel){
		super.numTel = numTel;
		System.out.println("La salarie " + nom + " a pour numéro " + super.numTel);
	}
	
}
