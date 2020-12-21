public class AMoteur extends Vehicule{
	
	public double reservoir;	
	public double essence;
	
	public AMoteur(double reservoir,double essence){
		super();
		this.reservoir = reservoir;
		this.essence = essence;
	}
	public AMoteur(double reservoir){
		this(reservoir,0);
	}
	
	public String toString(){
		return "Je suis un AMoteur";
	}
	public void approvisionner(double nbLittres){
		essence = nbLittres;
	}
	public boolean enPanne(){
		return (essence == 0);
	}
	
	public void transporter(int n,int km){
		System.out.println("La voiture n°" + super.numero_vehicule + " a transporté " + n 
							+ " personnes sur " + km + " km");
		if ( this.enPanne() ) { System.out.println("plus d'essence!"); }
	}
	public void transporter(String materiau,int km){
		System.out.println("Le camion n°" + super.numero_vehicule + " a transporté des " + materiau
							+ " sur " + km + " km");
		if ( this.enPanne() ) { System.out.println("plus d'essence!"); }
	}
	
}
