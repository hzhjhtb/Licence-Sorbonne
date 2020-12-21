import java.util.ArrayList;

public class Simulation{
	
	private static Terrain terrain = new Terrain(10,10); 
	private Ressource[] pollen;
	private Abeille[] abeille;
	public static Ruche ruche = new Ruche(); // le ruche reste le meme


	public Simulation(int m,int n){
		pollen = new Ressource[m];
		for (int i = 0;i < pollen.length;i++){
			pollen[i] = new Ressource("Pollen",(int)(Math.random()*10+1)); 
		 	terrain.setCase((int)(Math.random()*10),(int)(Math.random()*10),pollen[i]);
		}
		abeille = new Abeille[n];
		for (int i = 0;i < abeille.length;i++){
			abeille[i] = new Abeille();
			abeille[i].setX(ruche.getX());
			abeille[i].setY(ruche.getY());
		}
	}

	public void simulation_recolte_production(){
		int pollen_quantite = 0;
		int quantite,capacite,x,y;
		
		for (int i = 0;i < abeille.length;i++){
			// abeille arrive à une case
			System.out.println("Abeille " + i + " vient pour récolte !\n");
			abeille[i].seDeplacer((int)(Math.random()*10),(int)(Math.random()*10));
			x = abeille[i].getX();
			y = abeille[i].getY();
			
			// abeille recolte si possible
			if (terrain.caseEstVide(x,y) == false){
				quantite = terrain.getCase(x,y).getQuantite();
				capacite = abeille[i].capacite;
				
				if ( quantite <= capacite){
					// recolte et productiton : 1 pollen vaut 1 miel 
					pollen_quantite = pollen_quantite + quantite;
					
					System.out.print("Elle trouve " + quantite + " pollen ");
					System.out.println("et depose " + quantite + " miel\n");
					
					ruche.addMiel(new Ressource("Miel",quantite));
					// vidage de cette case 
					terrain.videCase(x,y);				
				}else{
					// recolte et productiton : 1 pollen vaut 1 miel 
					pollen_quantite = pollen_quantite + capacite;
					
					System.out.print("+++++Elle trouve " + capacite + " pollen ");
					System.out.println("et depose " + capacite + " miel+++++\n");
					
					ruche.addMiel(new Ressource("Miel",capacite));
					// changement de la quantite de la ressource dans cette case
					quantite -= capacite;
					Ressource newpollen = new Ressource("Pollen",quantite);		
					terrain.setCase(x,y,newpollen);		
					if (terrain.getCase(x,y).getQuantite() == 0){
						terrain.videCase(x,y);	
					}	
				}	
			}
			
			// abeille rentres à la ruche 
			abeille[i].seDeplacer(ruche.getX(),ruche.getY());
		}
		
		// affichage des statisques sur les quantités récoltées et produites
		System.out.println("les abeilles recoltent " + pollen_quantite + " pollen\n");
		System.out.println("les abeilles produisent " + ruche.sommeMiel() + " miel\n");
	}

}






