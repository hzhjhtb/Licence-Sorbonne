public class Volley extends Ballon{
	public Volley(int nombre){
		super(nombre);
	}
	
	@Override
	public String toString(){
		return "Dans Volley :\n" + super.toString();
	}
	
	public void Derouler(Equipes equipes){
		this.creerRes();
		System.out.print(this.toString());
		this.ajouterRes(equipes);
	}
}
