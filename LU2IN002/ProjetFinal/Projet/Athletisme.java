public class Athletisme extends Sport{
	public Athletisme(int nombre){
		super(nombre);
	}
	
	@Override
	public void Derouler(Equipes equipes){
		this.creerRes();
		System.out.print(this.toString());
		this.ajouterRes(equipes);
	}
}
