public class Valeur extends Expression{
	private double val;
	
	
	public Valeur(double v){
		super();
		val = v;
	}

	
	public double getVal(){
		return val;
	}
	
	public String toString(){
		return "le valeur est " + val;
	}
	
	public void setVal(double v){
		val = v;
	}
}
