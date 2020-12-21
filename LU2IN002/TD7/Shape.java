public abstract class Shape{
	protected double x,y;
	
	
	public Shape(){
		x = 0;
		y = 0;
	}
	
	public Shape(double x,double y){
		this.x = x;
		this.y = y;
	}
	
	
	public String toString(){
		return "Position :(" + x + ","+ y +")";
	}
	
	public abstract double surface();
	
	public static void main(String[] args){
		Shape[] tab = new Shape[3];
		tab[0] = new Rectangle();
		tab[1] = new Circle();
		tab[2] = new Circle(1,2,4);
		double s = 0;
		//for (int i = 0;i < tab.length; i++){
		//	s += tab[i].surface();	
		//}
		for (Shape sh : tab){
			s += sh.surface();
		}
	}
}
