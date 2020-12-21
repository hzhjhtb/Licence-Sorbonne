public class TestTriangle{
	
	public static void main(String args[]){
		Point A = new Point(0,0);
		Point B = new Point(3,0);
		Point C = new Point(0,4);
		Triangle Tri = new Triangle(A,B,C);
		System.out.println(Tri.toString());
		Point As = new Point(0,0);
		Point Bs = new Point(7,0);
		Point Cs = new Point(0,8);
		Triangle Tris = new Triangle(As,Bs,Cs);
		System.out.println(Tri.egaStructurel(Tris));
	}
}
