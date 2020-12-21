public class Abeille{
	
	private int x,y;
	public static final int capacite = 5;
	private static int nb=0;


	public Abeille(){
		nb++;
	}
	
	public Abeille(int x,int y){
		nb++;
		this.x = x;
		this.y = y;
	}
	

	public double distance(int x,int y){
		return Math.sqrt(Math.pow(this.x-x,2)+Math.pow(this.y-y,2));
	}
	
	public void seDeplacer(int xnew,int ynew){
		this.x = xnew;
		this.y = ynew;
	}
	
	public String toString(){
		return "l'abeille est en ("+ x +","+ y +")"+",de capacité " + capacite;
	}
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	public void setX(int x){
		this.x = x;
	}
	
	public void setY(int y){
		this.y = y;
	}
}
	
		
