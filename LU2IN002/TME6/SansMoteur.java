public class SansMoteur extends Vehicule{
	
	public SansMoteur(){
		super();
	}
	
	public String toString(){
		return "Je suis un SansMoteur";
	}
	
	public void transporter(String depart,String arrivee){
		System.out.println("Le vélo n°" + super.numero_vehicule + " a roulé de " + depart + " à " + 							arrivee);
	}
}
