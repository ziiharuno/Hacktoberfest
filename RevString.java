package college;

public class RevString {
	public static void main(String[] args) {
		String a = "Something"; 
		String c = "";
		for(int i=(a.length()-1);i>=0;i--) 
			c = c + a.charAt(i);	
		
		System.out.print(c);
	}
}