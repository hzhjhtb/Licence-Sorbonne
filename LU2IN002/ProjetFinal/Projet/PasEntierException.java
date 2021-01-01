public class PasEntierException extends Exception{
	public PasEntierException(String message){
		super(message);
	}
	
	public String toString(){
		return "le nombre des equipes n'est pas valide.";
	}
}
