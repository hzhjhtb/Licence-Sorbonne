public class Cone{
	
	private double r; /* le rayon du cone */
	private double h; /* le hauteur du cone */
	public static final double PI = 3.14159;
	private static int nbCones = 0;	
	
	public Cone(double r,double h){
		this.r = r;
		this.h = h;
		nbCones++;
	}
	
	public Cone(){
		this(Math.random()*10,Math.random()*10);
	}
	
	public static double getVolume(double r,double h){
		return (1/3)*PI*r*r*h; 
	}
	
	public String toString(){
		return "Cone r="+ r + " h=" + h + " V=" + Cone.getVolume(r,h);
	}
	
	public static int getnbCones(){
		return nbCones;
	}	
	
}
