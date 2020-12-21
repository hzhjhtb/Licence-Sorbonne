public class Vecteur{
	private double x,y,z;
	
	public Vecteur(double v1,double v2,double v3){
		x = v1; y = v2; z = v3;
	}
	
	public Vecteur(){
		this(Math.random()*10,Math.random()*10,Math.random()*10);
	}
	
	public String toString(){
		return "(" + x + ", " + y + ", " + z + ")";
	}
	
	public Vecteur somme(Vecteur v){  /* méthode de d'instance */
		return new Vecteur(x+v.x,y+v.y,z+v.z);
	}
	
	public static Vecteur somme(Vecteur v,Vecteur w){ /* méthode de class */
		return new Vecteur(v.x+w.x,v.y+w.y,v.z+w.z);
	}
	
	public static void main(String[] args){
		Vecteur v1 = new Vecteur(1,2,3);
		Vecteur v2 = new Vecteur(10,20,30);
		Vecteur w1 = v1.somme(v2);
		Vecteur w2 = Vecteur.somme(v1,v2);
	}
}
