public class TestAttrapePas1{
	public static int moyenne(String[] tab){
		int s = 0;
		for (String n : tab){
			s += Integer.parseInt(n);
		}
		return s/tab.length; 
	}
	
	public static void main(String[] args){
		int m = moyenne(args);
		System.out.println("la moyenne est " + m);
	}
}
