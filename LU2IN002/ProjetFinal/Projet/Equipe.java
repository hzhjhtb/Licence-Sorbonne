public class Equipe{
	private int medaille_or, medaille_argent, medaille_cuivre, scores,numero;
	
	public Equipe(int numero){
		this.numero = numero;
		medaille_or = 0;
		medaille_argent = 0;
		medaille_cuivre = 0;
		scores = 0;
	}
	
	public Equipe clone(){
		Equipe equipe = new Equipe(numero);
		equipe.medaille_or = this.medaille_or;
		equipe.medaille_argent = this.medaille_argent;
		equipe.medaille_cuivre = this.medaille_cuivre;
		equipe.scores = this.scores;
		
		return equipe;
	}
	
	public void ajouterOr(){
		medaille_or++;
		scores += 3;
	}
	
	public void ajouterArgent(){
		medaille_argent++;
		scores += 2;
	}
	
	public void ajouterCuivre(){
		medaille_cuivre++;
		scores += 1;
	}
	
	public String toString(){
		String res = "l'equipe " + numero + " obtient " + scores + " points :\n" +
				   "[medaille_or: " + medaille_or + 
				   ", medaille_argent: " + medaille_argent +
				   ", medaille_cuivre: " + medaille_cuivre + "]\n";
		return res;
	}
}
