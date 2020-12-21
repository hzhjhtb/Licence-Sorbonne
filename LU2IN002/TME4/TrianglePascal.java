public class TrianglePascal{
	
	private int[][] t;
	
	public TrianglePascal(int n){
		/* n>0 */	
		t = new int[n][];
		for (int i=0;i<n;i++){
			t[i] = new int[i+1];
		}	
	}
	
	public void remplirTriangle(){
		for (int i=0;i<t.length;i++){
			t[i][0]=1;
			t[i][i]=1;
			if (i>0) {
				for (int j=1;j<i;j++){
					t[i][j]=t[i-1][j-1]+t[i-1][j];
				}
			}
		}
	}
	
	public int getTij(int i ,int j){
		return t[i][j];
	}	
	
}
