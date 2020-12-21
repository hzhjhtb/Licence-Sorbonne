import java.util.ArrayList;

public class Etudiant{
	private String nom;
	private final int nbNotesMax = 5;
	private int[] notes = new int[nbNotesMax];	
	private int IgRelle;
	private static ArrayList<Etudiant> etudiants = new ArrayList<Etudiant>();
	
	
	public Etudiant(){}
	
	public Etudiant(String nom){
		this.nom = nom;
		etudiants.add(this);
	}
	
	public String toString(){
		String all_notes = "";
		for (int i = 0; i < IgRelle; i++){
			all_notes += " " + notes[i];
		}
		return nom + all_notes;
	}

	public void entrerNote(int note) throws TabNotesPleinException{
		if (IgRelle < notes.length){
			notes[IgRelle] = note;
			IgRelle++;
		}else{
			throw new TabNotesPleinException("Le tableau de notes de l'etudiant " + nom + " est plein\n");
		}
	} 
	
	public String getNom(){
		return nom;
	}
	
	public static String printRes(){
		String res = "les " + etudiants.size() + " etudiants :\n[";
		for (Etudiant etudiant : etudiants){
			res += etudiant.toString() + "; ";
		}
		res += "]\n";
		return res;
	}
}




















