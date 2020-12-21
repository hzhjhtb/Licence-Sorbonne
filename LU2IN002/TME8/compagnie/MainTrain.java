public class MainTrain{
	public static void main(String[] args){
		Motrice m = new Motrice("Alstom");
		Train t = new Train(m);
		for (int i = 0;i < 5;i++){
			t.ajoute(new WVoyageur("EUROSTAR"));
			t.ajoute(new WMarchandise("SNCF"));
		}
		System.out.println(t);
		System.out.println("Nombre de place : " + t.nbplace());
		System.out.println("Poids max : " + t.poids());
	}

}
