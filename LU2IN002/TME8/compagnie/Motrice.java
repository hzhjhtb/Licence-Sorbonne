public class Motrice extends ElemTrain{
	private double puissance;
	
	
	public Motrice(String marque){
		super(marque);
		puissance = 10000;
	}
	
	public Motrice(String marque, double puissance){
		super(marque);
		this.puissance = puissance;
	}
	
	
	@Override
	public String toString(){
		return "< Motrice " + numero_de_serie + " (" + marque + ")" + ">";
	}
}
