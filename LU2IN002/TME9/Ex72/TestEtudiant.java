public class TestEtudiant{
	public static void main(String[] args){	
		int note;
		Etudiant current = null;
		
		for (int i = 0; i < args.length; i++){
			try{
				note = Integer.parseInt(args[i]);
				current.entrerNote(note);
				//System.out.println(args[i] + "est une note; ");
			}catch (NumberFormatException e){
				current = new Etudiant(args[i]);
				//System.out.println("\n" + args[i] + "est un nom;\n");			
			}catch (TabNotesPleinException e){
				System.out.println("Le tableau de note de l'etudiant  "+current.getNom() + " est plein pour "+args[i]);
			}
		}
		
		System.out.println(Etudiant.printRes());
	}
}
