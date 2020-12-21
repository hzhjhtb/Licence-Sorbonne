public class TestTracteur{

	public static void main(String args[]){
		Roue g = new Roue();
		Roue d = new Roue();
		Roue G = new Roue(120);
		Roue D = new Roue(120);
		/*System.out.println(g.toString());
		System.out.println(d.toString());
		System.out.println(G.toString());
		System.out.println(D.toString());*/
		
		Cabine cabine = new Cabine(10,"jaune");
		cabine.setCouleur("bleue");
		/*System.out.println(cabine.toString());*/
		
		Tracteur t1 = new Tracteur(cabine,g,d,G,D);
		System.out.println(t1.toString());
		
		Tracteur t2 = t1.clone();
		t2.peindre("rose");
		System.out.println(t2.toString());
	}
	
}
