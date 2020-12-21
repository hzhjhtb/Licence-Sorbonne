public class Instrument{
	
	public double poids;
	public double prix;
	
	public Instrument(double poids,double prix){
		this.poids = poids;
		this.prix = prix;
	}
	
	public void jouer(){

	}
	public String toString(){
		return "Le poids est " + poids + "g, le prix est " + prix + "euro.";
	}

}
