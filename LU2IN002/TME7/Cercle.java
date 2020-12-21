public class Cercle extends Ellipse{
	public Cercle(double r){
		super(r,r);
	}
	
	public String toString(){
		return "Cercle("+a+") : surface "+super.surface()+" , perimetre "+super.perimetre();
	}
}
