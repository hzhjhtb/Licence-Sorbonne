public class TabPleinException extends Exception{
	public TabPleinException(String message){
		super(message);
	}

	
	@Override
	public String toString(){
		return "TabPleinException\n";
	}
}
