import java.util.ArrayList;

public class Train{
	private Motrice motrice;
	private ArrayList<Wagon> wagon;	
	
	
	public Train(Motrice motrice){
		this.motrice = motrice;
		wagon = new ArrayList<Wagon>();
	}
	
	
	public void ajoute(Wagon w){
		wagon.add(w);
	}
	
	public String toString(){
		String s = motrice.toString() + "\n";
		for (Wagon w : wagon){
			s = s + w.toString() + "\n";
		}
		return s;
	}
	
	public double poids(){
		double poids = 0;
		for (Wagon w : wagon){
			if (w instanceof WMarchandise){
				poids += ((WMarchandise) w).getPoid_max();
			}
		}
		return poids;
	}
	
	public int nbplace(){
		int nbplace = 0;
		for (Wagon w : wagon){
			if (w instanceof WVoyageur){
				nbplace += ((WVoyageur) w).getNb_place();
			}
		}
		return nbplace;
	}
}









