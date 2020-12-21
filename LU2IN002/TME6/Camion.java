public class Camion extends AMoteur{
	
	public double volume;
	
	public Camion(double reservoir,int essence,double volume){
		super(reservoir,essence);
		this.volume = volume;
	}	
	public Camion(double reservoir,double volume){
		this(reservoir,0,volume);
	}
	
	public String toString(){
		return "Je suis un Camion";
	}
	
}
