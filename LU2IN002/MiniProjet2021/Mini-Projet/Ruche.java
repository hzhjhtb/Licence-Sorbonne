import java.util.ArrayList;

public class Ruche{
	
	private static int x,y; // le ruche occupe une case du terrain
	private static ArrayList<Ressource> ruche = new ArrayList<Ressource>();	
	public static int somme_miel;
	
	public Ruche(){
		this(0,0);
	}
	
	public Ruche(int x,int y){ // la postion de ruche est static
		this.x = x;
		this.y = y;
	}
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	public void addMiel(Ressource miel){ 
	// les abeilles deposent ses miel à la ruche
		ruche.add(miel);
	}

	public int sommeMiel(){
	// la somme de les producetion du miel de toutes les abeilles
		int somme = 0;
		for (Ressource miel : ruche){
			somme += miel.getQuantite();
		}	
		ruche.clear();
		somme_miel += somme;
		return somme;
	}

}
