public class Cabine{

	private int volume;
	private String couleur;
	
	
	public Cabine(int volume,String couleur){
		this.volume = volume;
		this.couleur = couleur;
	}
	
	
	public String toString(){
		return "le volume de ce tracteur est " + volume + 
			   ".\nle couleur de ce tracteur est " + couleur + "."; 			
	}
	
	public void setCouleur(String couleur){ this.couleur = couleur; }
	
	public Cabine clone(){ return new Cabine(volume,couleur); }

	
	public static void main(String args[]){
		
	}
}
