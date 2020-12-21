public class Roue{
	
	private int diametre;
	 
	public Roue(int diametre){
		this.diametre = diametre;
	}
	
	public Roue(){
		this(60);
	}
	
	public String toString(){
		return "C'est une roue dont diametre est " + diametre + "cm. ";
	}
	
	public Roue clone(){ return new Roue(diametre); }
	
}
