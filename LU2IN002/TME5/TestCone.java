public class TestCone{

	public static void main(String[] args){
		System.out.println("Le nombre de cones avant est " + Cone.getnbCones() + ".");
		Cone cone1 = new Cone();
		Cone cone2 = new Cone();
		System.out.println("Le nombre de cones après est " + Cone.getnbCones() + ".");
	}	
	
}
