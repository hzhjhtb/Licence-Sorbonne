public abstract class Poisson{
	protected Point position;
	
	
	public Poisson(){
		position = new Point();
	}
	
	public Point getPosition(){
		return position;
	}
	
	public abstract void move(Point cible);
	
	public boolean siVoisin(Poisson proche){
		if (position.distanceTo(proche.getPosition()) < 2){
			return true;
		}else{
			return false;
		}
	}
	
	public void verifierPoisson(){
		position.x %= 500;
		position.y %= 500;
	}
}
