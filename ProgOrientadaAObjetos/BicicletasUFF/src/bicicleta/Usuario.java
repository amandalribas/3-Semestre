package bicicleta;

public class Usuario {
	private int id;
	private int matricula;
	private String nome;
	private String endereco;
	private String telefone;
	private String email;
	private Bicicleta bicicleta;
	private Login login;

	/*Na classe Usuario adicione os campos endereço (String), telefone(String), e-mail(String)*/

	
	Usuario(int id, int matricula, String nome, String endereco, String telefone, String email){
		this.id = id;
		this.matricula = matricula;
		this.nome = nome;
		this.bicicleta = null;
		this.endereco = endereco;
		this.telefone = telefone;
		this.email = email;
		this.login = new Login();
	}
	
	@Override
	public String toString() {
		return "Usuario [id=" + id + ", matricula=" + matricula + ", bicicleta=" + bicicleta + ", nome=" + nome
				+ ", endereco=" + endereco + ", telefone=" + telefone + ", email=" + email + "]";
	}
	
	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public int getMatricula() {
		return matricula;
	}
	
	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}
	
	public Bicicleta getBicicleta() {
		return bicicleta;
	}
	
	public void setBicicleta(Bicicleta bicicleta) {
		this.bicicleta = bicicleta;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public Login getLogin() {
		return this.login;
	}
	
}
