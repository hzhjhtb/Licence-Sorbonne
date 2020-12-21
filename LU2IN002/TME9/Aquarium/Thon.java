public class Thon extends Poisson{
	public Thon(){
		super();
	}
	
	
	public String toString(){
		return "Thon" + getPosition().toString(); 
	}
	
	@Override
	public void move(Point cible){
		if (getPosition().distanceTo(cible) > 60){
			position.x = position.x + (int)(Math.random()*30+1)-15;
			position.y = position.y + (int)(Math.random()*30+1)-15;
		}else{
			position.x = (position.x + cible.x)/2;
			position.y = (position.y + cible.y)/2;
		}
		verifierPoisson();
	}
}
