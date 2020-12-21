public class Vehicule{
		
	public int numero_vehicule;
	protected static int nbvehicule = 0;
	public double distance;
	
	public Vehicule(){
		nbvehicule++;
		numero_vehicule = nbvehicule;
		distance = 0;
	}
	
	public String toString(){
		return "Je suis une Vehicule";
	}
	public void rouler(double distance){
		this.distance = distance;
	}
	
	
	
}
