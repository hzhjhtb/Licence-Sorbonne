public class TestOrchestre{

	public static void main(String[] args){
		Orchestre O = new Orchestre();
		Instrument G = new Guitare(2,2);
		O.ajouterInstrument(G);
		Instrument P = new Piano(5,5);
		O.ajouterInstrument(P);
		Instrument T1 = new Trompette(3,3);
		O.ajouterInstrument(T1);
		O.jouer();
		Instrument T2 = new Trompette(3,3);
		O.ajouterInstrument(T2);
		O.jouer();
	}

}
