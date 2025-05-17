package ArquivosBinarios;

public class Login {
	private String usuario;
	private int senha;
	
	Login(String usuario, int senha){
		this.usuario = usuario;
		this.senha = senha;
	}
	
	public String getUsuario() {
		return usuario;
	}
	public void setUsuario(String usuario) {
		usuario = usuario;
	}
	public int getSenha() {
		return senha;
	}
	public void setSenha(int senha) {
		this.senha = senha;
	}
	
	
}
