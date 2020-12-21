public class Requin extends Poisson{
	public Requin(){
		super();
	}
	
	
	public String toString(){
		return "Requin" + getPosition().toString(); 
	}
	
	@Override
	public void move(Point cible){
		position.x = (position.x + cible.x)/2;
		position.y = (position.y + cible.y)/2;
		verifierPoisson();
	}
}
