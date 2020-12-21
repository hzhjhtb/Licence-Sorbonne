public class Voiture extends AMoteur{
	
	public int nbplace;
	
	public 	Voiture(double reservoir,double essence,int nbplace){
		super(reservoir,essence);
		this.nbplace = nbplace;
	}
	public Voiture(double reservoir,int nbplace){
		this(reservoir,0,nbplace);
	}
	
	public String toString(){
		return "Je suis une Voiture";
	}
	
}
