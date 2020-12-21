public class Point{
	
	private int posx,posy;
	
	
	public Point(){
		this.posx = posx;
		this.posy = posy;
	}
	
	public Point(int x,int y){
		posx = x;
		posy = y;
	}
	
	
	public Point clone(){ return new Point(posx,posy);}
	
	public void setPosx(Point p){ this.posx = p.posx; }
	
	public void setPosy(Point p){ this.posy = p.posy; }
	
	public int getPosx(){ return posx; }
	
	public int getPosy(){ return posy; }
	
	public String toString(){ return "(" + posx + "," + posy + ")"; }
	
	public double distance(Point p){ 
		double i = Double.valueOf(p.posx-this.posx);
		double j = Double.valueOf(p.posy-this.posy);
		return Math.sqrt(Math.pow(i,2)+Math.pow(j,2)); 
	}
	
	public void deplaceToi(int newx,int newy){ posx = newx; posy = newy; }
	
	
	public static void main(String args[]){
		Point P = new Point(2,3);
		Point Q = new Point(3,4);
		System.out.println(P.toString());
		System.out.println(Q.toString());
	}
	
}
