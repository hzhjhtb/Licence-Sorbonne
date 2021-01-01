public class Foot extends Ballon{
	public Foot(int nombre){
		super(nombre);
	}
	
	@Override
	public String toString(){
		return "Dans Foot :\n" + super.toString();
	}
	
	public void Derouler(Equipes equipes){
		this.creerRes();
		System.out.print(this.toString());
		this.ajouterRes(equipes);
	}
}
