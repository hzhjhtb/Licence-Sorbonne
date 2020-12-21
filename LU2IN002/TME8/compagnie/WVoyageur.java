public class WVoyageur extends Wagon{
	private int nb_place;
	
	
	public WVoyageur(String marque){
		super(marque);
		nb_place = 100;
	}
	
	public WVoyageur(String marque, int nb_place){
		super(marque);
		this.nb_place = nb_place;
	}


	public int getNb_place(){
		return nb_place;
	}
	
	@Override
	public String toString(){
		return "< Wagon Voyageur " + numero_de_serie + " (" + marque + ")" + ">";
	}
}
