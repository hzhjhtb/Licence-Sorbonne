public class Triangle{
	
	private Point A,B,C;
	
	
	public Triangle(){
		this.A = A.clone();
		this.B = B.clone();
		this.C = C.clone();
	}
	
	public Triangle(Point a,Point b,Point c){
		A = a.clone();
		B = b.clone();
		C = c.clone();
	}
	
	
	public double getPerimetre(){ return A.distance(B) + B.distance(C) + C.distance(A); }
	
	public String toString(){
		return "A est " + A.toString() + 
				"\nB est  " + B.toString() + 
				"\nC est " + C.toString() + 
				"\nAB est " + A.distance(B) +
				"\nBC est " + B.distance(C) +
				"\nCA est " + C.distance(A) + 
				"\nla perimetre est " +  this.getPerimetre(); 
	}
	
	public boolean egaStructurel(Triangle Tri){
	if ((this.A.distance(this.B)/Tri.A.distance(Tri.B) == this.B.distance(this.C)/Tri.B.distance(Tri.C)) && (this.C.distance(this.A)/Tri.C.distance(Tri.A) == this.B.distance(this.C)/Tri.B.distance(Tri.C))) { return true; } else {return false; }
	}
	
}
