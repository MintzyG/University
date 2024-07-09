public class Carro {
    // Atributos
    String cor;
    String modelo;
    int ano;

    // Construtor
    public Carro(String cor, String modelo, int ano) {
        this.cor = cor;
        this.modelo = modelo;
        this.ano = ano;
    }

    // Métodos
    void acelerar() {
        System.out.println("O carro está acelerando.");
    }

    void frear() {
        System.out.println("O carro está freando.");
    }
}

public class TesteCarro {
    public static void main(String[] args) {
        // Criação de um objeto da classe Carro
        Carro meuCarro = new Carro("Vermelho", "Ferrari", 2020);

        // Acessando atributos e métodos do objeto
        System.out.println(meuCarro.cor); // Vermelho
        System.out.println(meuCarro.modelo); // Ferrari
        System.out.println(meuCarro.ano); // 2020

        meuCarro.acelerar(); // O carro está acelerando.
        meuCarro.frear(); // O carro está freando.
    }
}

