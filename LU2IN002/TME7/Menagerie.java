import java.util.ArrayList;
public class Menagerie{
	private int nb;
	private ArrayList<Animal> tab;
	
	
	public Menagerie(ArrayList<Animal> tab){
		this.tab = tab;
		nb = tab.size();
	}
	
	
	public void ajouter(Animal a){
		tab.add(a);
		nb ++;
	}
	
	public String toString(){
		String s = "";
		for (Animal a : tab){
			s += a.toString() + "\n";
		}
		return s; 
	}
	
	public void midi(){
		for (Animal a : tab){
			a.crier();
		}
		System.out.println();
	}
	
	public void vieillirTous(){
		for (Animal a : tab){
			a.age ++;
		}
	}
	
	
	public static void main(String[] args){
		Menagerie menagerie = new Menagerie(new ArrayList<Animal>());
	 
		menagerie.ajouter(new Canard("canard"));
		menagerie.ajouter(new Boa("boa"));
		menagerie.ajouter(new Vache("vache"));
		menagerie.ajouter(new Saumon("saumon"));
		menagerie.ajouter(new Millepatte("mille-patte"));
			
		System.out.println(menagerie.toString());	
	
		menagerie.midi();
	
		menagerie.vieillirTous();
		System.out.println(menagerie.toString());
	}
}
