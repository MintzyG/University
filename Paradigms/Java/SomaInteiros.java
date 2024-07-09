import java.util.Scanner;

public class SomaInteiros {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite o valor de A: ");
        int A = scanner.nextInt();
        System.out.println("Digite o valor de B: ");
        int B = scanner.nextInt();
        if (A > B) {
            int temp = A;
            A = B;
            B = temp;
        }
        int soma = 0;
        for (int i = A; i <= B; i++) {
            soma += i;
        }
        System.out.println("A soma dos inteiros de " + A + " a " + B + " é: " + soma);
        scanner.close();
    }
}
