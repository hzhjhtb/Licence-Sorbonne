public abstract class Sport{
	public int[] res;
	public int nombre;	

	public Sport(int nombre){
		this.nombre = nombre;
		res = new int[nombre];
	} 
	
	public void creerRes(){
		int i = 0,s = nombre;
		i = (int)(Math.random()*nombre);
		res[i] = s;
		s--;
		while (s > 0){
			while (res[i] != 0){
				i = (int)(Math.random()*nombre);
			}
			res[i] = s;
			s--;
		}  	
	}
	
	public String toString(){
		String resultat = "";
		for (int i = 0; i < nombre; i++){
			resultat += "l'equipe " + i + " est le " + res[i] + "ieme.\n";
		}
		return resultat;
	}
	
	public void ajouterRes(Equipes equipes){
		for (int i = 0; i < nombre; i++){
			if (res[i] > 3){
				continue;
			}
			if (res[i] == 1) equipes.ajouterOr(i);
			if (res[i] == 2) equipes.ajouterArgent(i);
			if (res[i] == 3) equipes.ajouterCuivre(i);
		}
	}
	
	public abstract void Derouler(Equipes equipes);
}
