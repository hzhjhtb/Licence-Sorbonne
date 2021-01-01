public class Basket extends Ballon{
	public Basket(int nombre){
		super(nombre);
	}
	
	@Override
	public String toString(){
		return "Dans Basket :\n" + super.toString();
	}
	
	public void Derouler(Equipes equipes){
		this.creerRes();
		System.out.print(this.toString());
		this.ajouterRes(equipes);
	}
}
