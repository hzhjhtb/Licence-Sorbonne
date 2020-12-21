public class Complexe{
	private double reelle, imag;
	
	public Complexe(double reelle, double imag){
		this.reelle = reelle;
		this.imag = imag;
	} 
	
	public Complexe(){
		this(Math.random()*4-2,Math.random()*4-2);
	}
	
	public String toString(){
		return "(" + reelle + " + " + imag + " i)"; 
	}
	
    public boolean estReel(){
        if (imag == 0) {return true;} else {return false;}
    }
    
    public Complexe addition(Complexe a){
        Complexe r = new Complexe(reelle+a.reelle,imag+a.imag);
        return r;
    }
    
    public Complexe multiplication(Complexe a){
        Complexe r = new Complexe(reelle*a.reelle-imag*a.imag,reelle*a.imag+imag*a.reelle);
        return r;
    }
    
}
