package Contador;

public class ContadorTest {
	
	public static void main(String[] args) {
		Thread thr1 = new Thread(new Contador(1,1000));
		Thread thr2 = new Thread(new Contador(2,500));
		
		thr1.start();
		thr2.start();
		
		try {
			thr1.join();
			thr2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("Ambas Threads Terminaram.");
	}
	
	
}
