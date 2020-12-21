import java.util.ArrayList;

public class PoissonList extends ArrayList{
	public PoissonList(){
		super();
	}

	public PoissonList(PoissonList L){
		super(L);
	}
	
	
	public int nbThons(){
		int nbthons = 0;
		for (int i = 0; i < size(); i++){
			if (get(i) instanceof Thon){
				nbthons++;
			}
		}
		return nbthons;
	}
	
	public int rangPoissonProche(int index){
		int indice = 0;
		Poisson cible = (Poisson)get(index);
		double dmin = 10000;
		for (int i = 0; i < size(); i++){
			if (i != index){
				Poisson temp = (Poisson)get(i);
				double d = cible.getPosition().distanceTo(temp.getPosition());
				if (d < dmin){
					dmin = d;
					indice = i;
				}
			}
		}
		return indice;
	}
	
    public void bougeTousPoisson(){
    	for (int i = 0; i < size(); i++){
    		Poisson p1 = (Poisson)get(i);
    		Poisson p2 = (Poisson)get(rangPoissonProche(i));
    		Point cible = new Point(250,250);
    		if (p2 instanceof Thon){
    			cible = p2.getPosition();
    		}
    		p1.move(cible);
    	}
    }
	
	public PoissonList faireUnPas() throws PoissonInconnuException{
		bougeTousPoisson();
		// creation d'un double de this
		PoissonList PL = new PoissonList(this);
		// parcours de this 
		for (int i = 0; i < size(); i++){
			// on recupere le poisson courant et son plus proche dans l'aquarium
			Poisson p1 = (Poisson)get(i);
    		// traitement du couple si les deux poissons sont differents
    		if (rangPoissonProche(i) > i){
    			Poisson p2 = (Poisson)get(rangPoissonProche(i));
    			if (p1.siVoisin(p2)){
    				if ((p1 instanceof Thon) && (p2 instanceof Thon)){
    					PL.add(new Thon());
    					continue;
    				}
    				if ((p1 instanceof Requin) && (p2 instanceof Thon)){
    					PL.remove(p2);
    					continue;
    				}
    				if ((p2 instanceof Requin) && (p1 instanceof Thon)){
    					PL.remove(p1);
    					continue;
    				}
    				throw new PoissonInconnuException("Poisson inconnu");
    			}
    		}	
		}
		return PL;
	}
}


















