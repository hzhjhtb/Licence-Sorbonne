public class SautHauteur extends Athletisme{
	public SautHauteur(int nombre){
		super(nombre);
	}
	
	@Override
	public String toString(){
		return "Dans SautHauteur :\n" + super.toString();
	}
	
	public void Derouler(Equipes equipes){
		this.creerRes();
		System.out.print(this.toString());
		this.ajouterRes(equipes);
	}
}
