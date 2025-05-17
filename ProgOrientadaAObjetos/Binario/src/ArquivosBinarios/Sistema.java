package ArquivosBinarios;

import java.io.FileOutputStream;
import java.nio.ByteBuffer;
import java.util.Arrays;

public class Sistema {
	final static int TAM_REG = 12 + 4;
	
	public static void escreveArquivo() {
		
		Login l1 = new Login("Amanda",123);
		Login l2 = new Login("Diogo", 231);
		Login l3 = new Login("Lais", 456);
		Login[] l = {l1,l2,l3};
		
		try {
			System.out.append("executando...");
			FileOutputStream fo = new FileOutputStream("binario.bin");
			byte[] b = new byte[TAM_REG];
			for (int i = 0; i < 3; i++) {
				Arrays.fill(b, (byte)0);
				ByteBuffer bb = ByteBuffer.wrap(b);
				bb.put(l[i].getUsuario().getBytes());
				bb.putInt(12,l[i].getSenha());
			}
			fo.close();
		}catch (Exception e) {
			System.out.println(e);
		}
		
		
		
		
	}
	
	public static void main(String[] args) {
		escreveArquivo();

	}
		
		
	

}
