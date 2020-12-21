public class GenerateurIP{
	
	private static int[] tab = new int[]{192,168,0,0};

	private GenerateurIP(){}	
	
	public static String getAdresseIP(){
		if (tab[3] > 255) {
			tab[3] = 0;
			tab[2]++;
		}else {
			tab[3]++;
		}
		return tab[0] + "." + tab[1] + "." + tab[2] + "." + tab[3];
	}
}
