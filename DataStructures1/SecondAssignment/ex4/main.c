#include <stdio.h>
#include <ctype.h>
#include <string.h>

int Operador(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

float OpBas(char operador, float n1, float n2) {
  switch (operador) {
    case '+': return n1 + n2;
    case '-': return n1 - n2;
    case '*': return n1 * n2;
    case '/': return n1 / n2;
    default: return 0;
  }
}

float Expressao(char* expression) {
  float PilhaNum[20];
  int ind = -1;
  int Tam = strlen(expression);

  for (int i = Tam - 1; i >= 0; i--) {
    if (expression[i] == ' ') continue; // se for espaço, vai pro próximo caractere

    if (Operador(expression[i])) {
      float n1 = PilhaNum[ind--];
      float n2 = PilhaNum[ind--];
      float result = OpBas(expression[i], n1, n2);

      ind++;
      PilhaNum[ind] = result;

    } else if (isdigit(expression[i])) {
      int num = 0;
      int multiplicador = 1;

      while (i >= 0 && isdigit(expression[i])) {
        num = (expression[i] - '0') * multiplicador + num;
        multiplicador *= 10;
        i--;
      }

      ind++;
      PilhaNum[ind] = num;
    }
  }

  return PilhaNum[ind];
}

int main() {
  char exp[100];
  char op = 'Y';
  while(op == 'Y' || op == 'y'){
  printf("\e[1;1H\e[2J"); // clear universal
  printf("Calculador de expressão prefixa\n\n");
  printf("Informe a expressão prefixa:\n");
  fgets(exp, sizeof(exp), stdin);
  exp[strcspn(exp, "\n")] = '\0'; // detecta onde está a quebra de linha e substitui por N
  printf("A expressão prefixa inserida foi: %s\n\n", exp);
  float resultado = Expressao(exp);
  printf("Resultado da expressão prefixa: %f\n", resultado);

  printf("Deseja consultar outra expressão? (Y/y ou N/n):\n");
  scanf("%c", &op);
  scanf("%*c");
}
}
