public class Divise extends Operation{
	private Expression e1,e2;
	
	
	public Divise(Expression e1,Expression e2){
		super();
		this.e1 = e1;
		this.e2 = e2;
	}
	
	
	public double getVal(){
		return e1.getVal() / e2.getVal();
	}
	
	public String toString(){
		return "(" + e1.toString() + "/" + e2.toString() + ")";
	}
}
