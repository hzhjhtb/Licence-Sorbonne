public abstract class Wagon extends ElemTrain{
	protected int nb_portes;


	public Wagon(String marque){
		super(marque);
	}
	
	
	@Override
	public String toString(){
		return "< Wagon " + numero_de_serie + " (" + marque + ")" + ">";
	} 
}
