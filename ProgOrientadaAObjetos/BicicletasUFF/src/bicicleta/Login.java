package bicicleta;

public class Login {
	private String login;
	private int senha;
	
	public Login() {
		
	}
	
	public Login(String login, int senha) {
		this.login = login;
		this.senha = senha;
	}
	
	public String getLogin() {
		return this.login;
	}
	
	public int getSenha() {
		return this.senha;
	}
	
	public void setLogin(String login) {
		this.login = login;
	}
	
	public void setSenha(int senha) {
		this.senha = senha;
	}
}
