public class WMarchandise extends Wagon{
	private double poid_max;
	
	
	public WMarchandise(String marque){
		super(marque);
		poid_max = 5000;
	}

	public WMarchandise(String marque, double poid_max){
		super(marque);
		this.poid_max = poid_max;
	}
	
	
	public double getPoid_max(){
		return poid_max;
	}
	
	@Override
	public String toString(){
		return "< Wagon Marchandise " + numero_de_serie + " (" + marque + ")" + ">";
	}
}
