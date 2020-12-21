public class TestAttrape3{
	public static int moyenne(String[] tab) throws AucuneNoteEntiereException{
		int s = 0;
		int n = 0;
		for (int i = 0; i < tab.length; i++){
			try{
				s += Integer.parseInt(tab[i]);
				++n;
			}catch (NumberFormatException e){
				System.out.println("Note non entiere , position : " + (i+1));
			}	
		}
		if (n == 0){
			throw new AucuneNoteEntiereException("Lance AucuneNoteEntiereException ");
		}
		return s/n;
	}
	
	public static void main(String[] args){
		try{
			int m = moyenne(args);
			System.out.println("la moyenne est " + m);
		}catch (AucuneNoteEntiereException e){
			System.out.println(e.getMessage()+e.toString());	
		}
	}
}
