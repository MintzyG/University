import java.util.Scanner;

public class EquacaoQuadratica {
    // Coeficientes da equação quadrática
    private double A;
    private double B;
    private double C;

    // Construtor
    public EquacaoQuadratica(double A, double B, double C) {
        this.A = A;
        this.B = B;
        this.C = C;
    }

    // Métodos para retornar os coeficientes A, B e C
    public double getA() {
        return A;
    }

    public double getB() {
        return B;
    }

    public double getC() {
        return C;
    }

    // Método para calcular o delta (discriminante)
    public double calcularDelta() {
        return B * B - 4 * A * C;
    }

    // Métodos para obter as raízes da equação quadrática
    public double pegarRaiz1() {
        double delta = calcularDelta();
        if (delta < 0) {
            return 0; // Retorna 0 se o discriminante for negativo
        } else {
            return (-B + Math.sqrt(delta)) / (2 * A);
        }
    }

    public double pegarRaiz2() {
        double delta = calcularDelta();
        if (delta < 0) {
            return 0; // Retorna 0 se o discriminante for negativo
        } else {
            return (-B - Math.sqrt(delta)) / (2 * A);
        }
    }

    // Método principal para teste de entrada do usuário
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o coeficiente A da equação quadrática:");
        double coefA = scanner.nextDouble();

        System.out.println("Digite o coeficiente B da equação quadrática:");
        double coefB = scanner.nextDouble();

        System.out.println("Digite o coeficiente C da equação quadrática:");
        double coefC = scanner.nextDouble();

        // Criação do objeto EquacaoQuadratica com os coeficientes fornecidos pelo usuário
        EquacaoQuadratica equacao = new EquacaoQuadratica(coefA, coefB, coefC);

        // Exibe os coeficientes A, B e C da equação
        System.out.println("\nCoeficientes da equação:");
        System.out.println("A = " + equacao.getA());
        System.out.println("B = " + equacao.getB());
        System.out.println("C = " + equacao.getC());

        // Calcula e exibe o valor do delta
        double delta = equacao.calcularDelta();
        System.out.println("\nDelta (discriminante) = " + delta);

        // Obtém e exibe as raízes da equação
        double raiz1 = equacao.pegarRaiz1();
        double raiz2 = equacao.pegarRaiz2();

        if (raiz1 == 0 && raiz2 == 0) {
            System.out.println("A equação não possui raízes reais.");
        } else {
            System.out.println("\nRaízes da equação quadrática:");
            System.out.println("Raiz 1 = " + raiz1);
            System.out.println("Raiz 2 = " + raiz2);
        }

        scanner.close();
    }
}

