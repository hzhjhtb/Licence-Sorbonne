public class Cent extends Athletisme{
	public Cent(int nombre){
		super(nombre);
	}
	
	@Override
	public String toString(){
		return "Dans Cent :\n" + super.toString();
	}
	
	public void Derouler(Equipes equipes){
		this.creerRes();
		System.out.print(this.toString());
		this.ajouterRes(equipes);
	}
}
