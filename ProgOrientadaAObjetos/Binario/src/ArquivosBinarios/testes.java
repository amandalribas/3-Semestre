package ArquivosBinarios;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Arrays;

public class testes {
	public static void main(String[] args) {
		final int TAM_REG = 10 + 4 + 4;

		FileOutputStream fo = null;
		
		try {
			fo = new FileOutputStream("binario.bin");
			byte[] b = new byte[TAM_REG];
			Arrays.fill(b, (byte)0);
			ByteBuffer bb = ByteBuffer.wrap(b);
			bb.put("Amanda".getBytes());
			bb.putInt(170);
			bb.putInt(7841);

			fo.write(b);
		}catch(Exception e) {
			System.out.println(e);
		}finally {
			try {
				if (fo!=null) fo.close();
			}catch(Exception e) {
				System.out.println(e);
			}
		}
		/*LENDO ARQUIVO*/
		FileInputStream fi = null;
		DataInputStream di = null;
		try {
			fi = new FileInputStream("binario.bin");
			di = new DataInputStream(fi);
			byte[] b = new byte[10];
			boolean eof = false;
			do {
				if (di.read(b,0,10)!=-1) {
					String nome = new String(b);
					int n1 = di.readInt();
					int n2 = di.readInt();
					System.out.println(nome + n1 + n2);
				}else {
					eof = true;
				}
			}while (!eof);
		}catch(IOException e) {
			System.out.println(e);
		}finally {
			try {
				if (di != null) di.close();
				if (fi != null) fi.close();

			}catch(Exception e) {
				System.out.println(e);
			}
		}
		
		try {
	        FileInputStream fi2 = new FileInputStream("binario.bin");
	        byte[] b = new byte[TAM_REG];
	        boolean eof = false;
	        do{
	            
	            if (fi2.read(b,0,TAM_REG)!=-1){
	                ByteBuffer bb = ByteBuffer.wrap(b);
	                byte[] strbytes = new byte[10];
	                bb.get(strbytes, 0, 10);
	                String nome = new String(strbytes);
	                
	                int n1 = bb.getInt(10);
	                int n2 = bb.getInt(14);
	                System.out.println(nome+" "+n1+" "+n2);
	            }
	            else{
	                eof = true;
	            }
	        }while(!eof);
	          
	        fi2.close();

	        
	    } catch (IOException e) {
	        System.out.println(e);
	    }
	}
	
	/**/
	
}
