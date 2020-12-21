public class Rectangle extends Figure2D{
	protected double l,h;
	
	
	public Rectangle(double l,double h){
		this.l = l;
		this.h = h;
	}
	
	
	
	public double surface(){
		return l*h;
	} 
	
	public double perimetre(){
		return 2*(l+h);
	}
	
	public String toString(){
		return "Rectangle("+l+" , "+h+") : surface "+surface()+" , perimetre "+perimetre();
	}
}
