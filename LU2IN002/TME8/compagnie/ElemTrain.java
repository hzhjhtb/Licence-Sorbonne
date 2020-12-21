public abstract class ElemTrain{
	protected static int compteur = 10000;
	protected int numero_de_serie;
	protected String marque;

	public ElemTrain(String marque){
		this.marque = marque;
		compteur++;
		this.numero_de_serie = compteur;
	}
	
	public String toString(){
		return "< ElemTrain " + numero_de_serie + " (" + marque + ")" + ">";
	}
}
