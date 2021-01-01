public class Competition{
	private Sport[] sport;
	
	public Competition(int nombre){
		sport = new Sport[5];
		sport[0] = new Basket(nombre);	
		sport[1] = new Foot(nombre);
		sport[2] = new Volley(nombre);
		sport[3] = new Cent(nombre);
		sport[4] = new SautHauteur(nombre);
	}
	
	public void Derouler(Equipes equipes){
		for (int i = 0; i < 5; i++){
			sport[i].Derouler(equipes);
		}
	}
	
	public String toString(){
		return "On fait une competition sportive maintenant:\n"
				+ "le premier est Basket\n"
				+ "le deuxieme est Foot\n"
				+ "le troisieme est Volley\n"
				+ "le quartieme est Cent\n"
				+ "le cinquieme est SautHauteur\n";
	}
}
