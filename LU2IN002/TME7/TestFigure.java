public class TestFigure{
	public static void main(String[] args){
		Figure[] tab = new Figure[4];
		tab[0] = new Rectangle(3.0 , 4.0);
		tab[1] = new Carre(3.0);
		tab[2] = new Ellipse(3.0 , 5.0);
		tab[3] = new Cercle(3.0);
		
		for (int i = 0;i < tab.length;i++){
			System.out.println(tab[i].toString()+"\n");
		}
	}
}
