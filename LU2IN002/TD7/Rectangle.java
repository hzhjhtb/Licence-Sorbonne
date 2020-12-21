public class Rectangle extends Shape{
	private double h,l;
	
	
	public Rectangle(){
		super();
		h = 1;
		l = 1;
	} 
	
	public Rectangle(double x,double y,double h,double l){
		super(x,y);
		this.h = h;
		this.l = l;
	}
	
	
	public String toString(){
		return super.toString() + " Rectangle h:" + h + " l:" + l + "surface:" + surface();
	}
	
	public double surface(){
		return l*h;
	}
}
