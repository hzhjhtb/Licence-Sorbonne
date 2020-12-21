public class Tracteur{

	public Roue g,d,G,D;
	public Cabine cabine;
	
	
	public Tracteur(Cabine cabine,Roue g,Roue d,Roue G,Roue D){
		this.cabine = cabine.clone();
		this.g = g.clone();
		this.d = d.clone();
		this.G = G.clone();
		this.D = D.clone();
	}
	
	public String toString(){
		return  "Il y a un tracteur agricole.\n" + 
				cabine.toString() + "\n" +			
				g.toString() + "\n" + 
				d.toString() + "\n" + 
				G.toString() + "\n" + 
				D.toString();
	} 
	
	public Tracteur clone(){ return new Tracteur(cabine,g,d,G,D);}
	
	public void peindre(String couleur){ cabine.setCouleur(couleur); }
	
}
