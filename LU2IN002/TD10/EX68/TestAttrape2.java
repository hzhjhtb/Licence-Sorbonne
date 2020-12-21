public class TestAttrape2{
	public static int moyenne(String[] tab){
		int s = 0;
		int n = 0;
		for (String num : tab){
			try{
				int note = Integer.parseInt(num);
				s += note;
				++n;
			}catch (NumberFormatException e){
				System.out.println("note non entier");
			}
		}
		return s/n; 
	}
	
	public static void main(String[] args){
		int m = moyenne(args);
		System.out.println("la moyenne est " + m);
	}
}
