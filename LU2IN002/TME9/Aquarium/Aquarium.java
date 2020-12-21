public class Aquarium{
	public PoissonList PL;

	
	public Aquarium(int nbThons,int nbRequins){
		PL = new PoissonList();
		for (int i = 0; i < nbThons; i++){
			PL.add(new Thon());
		}
		for (int i = 0; i < nbRequins; i++){
			PL.add(new Requin());
		}
	}
	
	public String toString(){
		return PL.toString();
	}
	
	public void run(){
		while (true){
			try{
				PL = PL.faireUnPas();	
				Thread.sleep(300);
			}catch (PoissonInconnuException e){
				System.out.println(e.getMessage());
			}catch (InterruptedException e){
				System.out.println("nb total de poissons : " + PL.size() + ", nb de thons : " + PL.nbThons());
			}
		}
	}
}
