public class TestSimulation{
	private static int n = 5; // C'est le nombre de simulation qu'on fait 
	
	public static void main(String args[]){
		for (int i = 1;i <= n;i++){
			System.out.println("=======le " + i + "ième fois de simulation=======\n");
			
			Simulation simu = new Simulation (10,5);
			simu.simulation_recolte_production();
			
			System.out.println("la miel dans la ruche maintenant est " + Ruche.somme_miel + "\n");
		}	
	}
	
}
