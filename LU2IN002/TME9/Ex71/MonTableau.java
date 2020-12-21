public class MonTableau{
	private int[] tab;
	private static int IgReelle = 0;
	
	
	public MonTableau(int taille){
		tab = new int[taille];
	}
	
	
	public void ajouter(int n) throws TabPleinException{
		tab[IgReelle] = n;
		IgReelle++;
		if (IgReelle >= tab.length){
			throw new TabPleinException("Depassement des bornes à la position " + IgReelle + "\n");
		}
	}
	
	
	public static void main(String[] args){
		MonTableau t = new MonTableau(3);
		for (int i = 0; i < 10; i++){
			try{
				t.ajouter(i);
			}catch (TabPleinException e){
				System.out.println(e.toString()+e.getMessage());
				break;
			}
		}
	}
}


/*  Ex71.Q2 :
	Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 3 out of bounds for length 3
*/
