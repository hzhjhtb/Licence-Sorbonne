public class Nom{
	
	private static final char[] consonnes = new char[]{'B','C','D','F', 'G', 'H', 'J', 'K','L','M','N','P','Q','R','S','T','V','W','X','Z'};
	private static final char[] voyelles = new char[]{'A','E','I','O','U','Y'};
	
	public static int rendAlea(int inf,int sup){
		return (int)(Math.random()*(sup-inf+1)+inf);
	}
	
	public static boolean estPair(int n){
		if (n%2 == 0){
			return true;
		}else{
			return false;
		}
	}
	
	public static char rendVoyelle(){
		return voyelles[(int)(Math.random()*6)];
	}
	
	public static char rendConsonne(){
		return consonnes[(int)(Math.random()*20)];
	}
	
	public static char[] genereNom(){
		char[] nom = new char[(int)(Math.random()*(6-3+1)+3)];
		boolean voy = Math.random() < 0.5;
		for (int i=0;i<nom.length;i++){
			if (voy == true){
				nom[i] = Nom.rendVoyelle();
				voy = false; 
			}else{
				nom[i] = Nom.rendConsonne();
				voy = true;
			}
		}
		return nom;
	}
	
}

