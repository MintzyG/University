import java.util.Scanner;

public class EquacaoLinear {
    // Coeficientes da equação linear ax + by = e
    private double A;
    private double B;
    private double C;
    private double D;
    private double E;
    private double F;

    // Construtor
    public EquacaoLinear(double A, double B, double C, double D, double E, double F) {
        this.A = A;
        this.B = B;
        this.C = C;
        this.D = D;
        this.E = E;
        this.F = F;
    }

    // Método para verificar se o sistema é solucionável
    public boolean isSolucionavel() {
        // Calcula o determinante
        double determinante = A * D - B * C;
        // O sistema é solucionável se o determinante for diferente de zero
        return determinante != 0;
    }

    // Método para obter o valor de x
    public double getX() {
        // Calcula x utilizando as fórmulas de Cramer
        double numeradorX = E * D - B * F;
        double determinante = A * D - B * C;
        return numeradorX / determinante;
    }

    // Método para obter o valor de y
    public double getY() {
        // Calcula y utilizando as fórmulas de Cramer
        double numeradorY = A * F - E * C;
        double determinante = A * D - B * C;
        return numeradorY / determinante;
    }

    // Método principal para teste de entrada do usuário
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicita ao usuário para inserir os coeficientes da primeira equação
        System.out.println("Digite o coeficiente A da primeira equação:");
        double coefA = scanner.nextDouble();

        System.out.println("Digite o coeficiente B da primeira equação:");
        double coefB = scanner.nextDouble();

        System.out.println("Digite o coeficiente E da primeira equação (parte direita):");
        double coefE = scanner.nextDouble();

        // Solicita ao usuário para inserir os coeficientes da segunda equação
        System.out.println("Digite o coeficiente C da segunda equação:");
        double coefC = scanner.nextDouble();

        System.out.println("Digite o coeficiente D da segunda equação:");
        double coefD = scanner.nextDouble();

        System.out.println("Digite o coeficiente F da segunda equação (parte direita):");
        double coefF = scanner.nextDouble();

        // Criação do objeto EquacaoLinear com os coeficientes fornecidos pelo usuário
        EquacaoLinear equacao = new EquacaoLinear(coefA, coefB, coefC, coefD, coefE, coefF);

        // Verifica se o sistema é solucionável
        if (equacao.isSolucionavel()) {
            // Calcula e exibe as soluções para x e y
            double x = equacao.getX();
            double y = equacao.getY();
            System.out.println("\nSolução do sistema de equações lineares:");
            System.out.println("x = " + x);
            System.out.println("y = " + y);
        } else {
            // Caso o sistema não seja solucionável
            System.out.println("\nO sistema de equações não possui solução única.");
        }

        scanner.close();
    }
}

