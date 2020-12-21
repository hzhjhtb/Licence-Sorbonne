import java.util.ArrayList;       

public class ArrayListReversible extends ArrayList<Object> implements Reversible{
	private boolean reversible;
	private int nb_recursive;
	
	public boolean estReversible(){
		return reversible;
	}

	public void voirReversible(){
		reversible = true;
		for (Object object : this){
			if (!(object instanceof Reversible)){
				reversible = false;
				return ;
			}
		}
	}
	
	public String toString(){
		String res = "ArrayListReversible[reversible=" + reversible +"]";
		for (Object object : this){
			res += object.toString() + "\n";
		}
		return res;
	}
	
	/*  <itératif> 
	public void reverse(){
		voirReversible();
		if (reversible == false){
			System.out.println("C'est pas reversible !");
			return ;
		}
		for (Object object : this){
			if (object instanceof Reversible){
				((Reversible) object).reverse();
			}
		}
		ArrayListReversible tmptab = new ArrayListReversible();
		for (int i = this.size() - 1;i >= 0;i--){
			tmptab.add(this.get(i));
			this.remove(i);
		} 
		for (int i = 0;i < tmptab.size();i++){
			this.add(tmptab.get(i));	
		}
	}
	*/
	// récursive
	public void reverse(){
		((Reversible) this.get(this.size())).reverse();
		ArrayListReversible tmptab = new ArrayListReversible();
		tmptab.add(this.size());
		this.remove(this.size());
		this.reverse();
	}
}







