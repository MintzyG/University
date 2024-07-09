import java.util.Scanner;

public class MediaNotas {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double[] notas = new double[6];
        int[] pesos = {1, 1, 1, 1, 2, 2};
        double somaNotas = 0;
        int somaPesos = 0;

        for (int i = 0; i < 6; i++) {
            System.out.print("Digite a nota " + (i + 1) + ": ");
            notas[i] = scanner.nextDouble();
            somaNotas += notas[i] * pesos[i];
            somaPesos += pesos[i];
        }

        double media = somaNotas / somaPesos;

        System.out.printf("Média: %.2f\n", media);

        if (media >= 6) {
            System.out.println("Aprovado");
        } else {
            System.out.println("Reprovado");
        }
        
        scanner.close();
    }
}

