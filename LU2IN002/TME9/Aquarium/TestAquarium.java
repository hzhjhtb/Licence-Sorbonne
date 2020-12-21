public class TestAquarium{
	public static void main(String[] args){
		Aquarium aquarium = null;
		try{
			int nbThons = Integer.parseInt(args[0]);
			int nbRequins = Integer.parseInt(args[1]);
			aquarium = new Aquarium(nbThons,nbRequins);
			System.out.print("la liste des poissons :\n");
			System.out.println(aquarium.toString());
			aquarium.PL.faireUnPas();
			System.out.print("la liste des poissons après un pas :\n");
			System.out.println(aquarium.toString());
		}catch (NumberFormatException e){
			System.out.println("donnee non entier");
		}catch (PoissonInconnuException e){
			System.out.println(e.getMessage());
		}
	}
}
