public class CompetitionTest{
	public static int obtenirNb(String[] args) 
	throws PasEntierException,PasEntre6et8Exception{
		int nombre = 0;
		try{
			nombre = Integer.parseInt(args[0]);
		}catch(NumberFormatException e){
			throw new PasEntierException("PasEntierException :\n");
		}
		if ((nombre >=9) || (nombre <= 5)){
			throw new PasEntre6et8Exception("PasEntre6et8Exception :\n");
		}
		return nombre;
	}

	public static void main(String[] args){
		int nombre = 0;
		try{
			nombre = obtenirNb(args);
		}catch (PasEntierException e){
			System.out.println(e.getMessage() + e.toString());
			return;
		}catch (PasEntre6et8Exception e){
			System.out.println(e.getMessage() + e.toString());
			return;
		}
		System.out.println("On utilise le premier nombre : " + nombre);
		
		Equipes equipes = Equipes.getEquipes(nombre);
		Competition competition = new Competition(nombre);
		
		System.out.println(competition.toString());
		
		competition.Derouler(equipes);
		
		System.out.println();
		System.out.print(equipes.toString());
	}
}
