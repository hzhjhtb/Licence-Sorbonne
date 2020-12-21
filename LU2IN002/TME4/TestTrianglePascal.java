public class TestTrianglePascal{
	
	public static void main(String args[]){
		int length = 7;
		TrianglePascal tri = new TrianglePascal(length);
		tri.remplirTriangle();
		
		for (int i=0;i<length;i++){
			for (int j=0;j<i+1;j++){
				System.out.print(tri.getTij(i,j)+" ");
			}
			System.out.print("\n");
 		}
 	}
 	
}
