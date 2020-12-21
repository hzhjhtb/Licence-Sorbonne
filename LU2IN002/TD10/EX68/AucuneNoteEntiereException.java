public class AucuneNoteEntiereException extends Exception{
	public AucuneNoteEntiereException(String s){
		super(s);
	}
	
	public String toString(){
		return "Aucune note n'est valide";
	}
}


