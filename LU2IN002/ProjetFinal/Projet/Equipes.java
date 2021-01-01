public class Equipes implements Medaille{
	private static Equipes INSTANCE = null;
	public static Equipe[] equipes;
	public int nombre;
	
	private Equipes(int nombre){
		this.nombre = nombre;
		equipes = new Equipe[nombre];
		for (int i = 0; i < nombre; i++) equipes[i] = new Equipe(i);
	}
	
	private synchronized static void createEquipes(int nombre){
		if (INSTANCE == null) INSTANCE = new Equipes(nombre);
	} 
	
	public static Equipes getEquipes(int nombre){
		if (INSTANCE == null) createEquipes(nombre);
		return INSTANCE;
	}
	
	public String toString(){
		String res = "Dans ce compétition sportive :\n";
		for (int i = 0; i < nombre; i++){
			res += equipes[i].toString();
		}
		return res;
	}
	
	@Override
	public void ajouterOr(int i){
		equipes[i].ajouterOr();
	}
	
	public void ajouterArgent(int i){
		equipes[i].ajouterArgent();
	}
	
	public void ajouterCuivre(int i){
		equipes[i].ajouterCuivre();
	}
}
