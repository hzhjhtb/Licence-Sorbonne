public class PasEntre6et8Exception extends Exception{
	public PasEntre6et8Exception(String message){
		super(message);
	}
	
	public String toString(){
		return "le nombre des equipes n'est pas valide.";
	}
}
