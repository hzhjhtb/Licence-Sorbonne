public class TestNom{

	public static void main(String[] args){
		String[] resultat = new String[10];
		for (int i=0;i<10;i++){
			resultat[i] = String.valueOf(Nom.genereNom());
			System.out.println(resultat[i]);
		}
	}	

}
