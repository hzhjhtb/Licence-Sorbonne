import java.util.ArrayList;
public class Orchestre{
	
	public static int nbInstrument = 0;
	public static ArrayList<Instrument> orchestre = new ArrayList<Instrument>();	
	public  ArrayList<Instrument> O = new ArrayList<Instrument>();
	
	public Orchestre(){
		O = orchestre;
	}
	
	public  void ajouterInstrument(Instrument i){
		nbInstrument++;
		orchestre.add(i);
	}
	public  void jouer(){
		for (Instrument i : orchestre){
			i.jouer();
		}
	}
	
}
