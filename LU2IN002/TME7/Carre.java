public class Carre extends Rectangle{
	public Carre(double c){
		super(c,c);
	}
	
	public String toString(){
		return "Carre("+l+") : surface "+super.surface()+" , perimetre "+super.perimetre();
	}
}
