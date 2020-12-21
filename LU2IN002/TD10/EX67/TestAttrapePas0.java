public class TestAttrapePas0{
	public static void main(String[] args){
		int[] tab = {1,2,3,4,5};
		try{
			for (int i  = 0; i < 15; i++){
				System.out.print(tab[i] + " ");
			}
		}catch (ArrayIndexOutOfBoundsException e){
			System.out.println("Exception : depasse de bounds " + i.getMessage);
		}
		System.out.print("Fin");	
	}

}
