#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
	char letra;
	int amount;
} Element;

typedef struct Vector {
	int size;
	Element* letras;
} Vector;

int main() {

	FILE *arquivo;
	Vector text;
	text.size = 256;
	arquivo = fopen("text.txt", "r");
	if(!arquivo) {
		printf("Couldn't open file");
		exit(1);
	}
	
	text.letras = (Element*)malloc(text.size * sizeof(Element));
	for (int i = 0; i < text.size; i++) text.letras[i].amount = 0;

	char letra;
	int added = 0, found = 0, position = 0;

	while((letra = fgetc(arquivo)) != EOF){
		if (added == 0) {
			text.letras[0].letra = letra;
			text.letras[0].amount += 1;
			added += 1;
		} else {
			for (int i = 0; i < added; i++){
				if (text.letras[i].letra == letra){
					found = 1;
					position = i;
				}
			}
			if (found == 1){
				text.letras[position].letra = letra;
				text.letras[position].amount += 1;
				found = 0;
			} else {
				text.letras[added+1].letra = letra;
				text.letras[added+1].amount += 1;
				added += 1;
			}
		}	
	}

	fclose(arquivo);

	for (int i = 0; i < text.size - 1; i++)
		for (int j = 0; j < text.size - i; j++)
			if (text.letras[j].amount < text.letras[j+1].amount){
				Element tmp = text.letras[j];
				text.letras[j] = text.letras[j+1];
				text.letras[j+1] = tmp;
			}

	for (int i = 0; i < text.size; i++){
		if (text.letras[i].amount != 0)
		printf("%c aparece %d vezes\n", text.letras[i].letra, text.letras[i].amount);
	}


	return 0;
}
