#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Dados {
	unsigned int** MatE, ** MatI, ** MatS;
	unsigned int* Params, * NewParams, * ParamCount;
	unsigned int ParamSize, MatrizX, MatrizY;
};

void InicializarDados(struct Dados* dados) {
	struct Dados passar = *dados;
	
	while (1) {
		printf("Escolha o tamanho da matriz \n");
		printf("Escolha X: ");
		scanf("%d", &passar.MatrizX);
		printf("Escolha Y: ");
		scanf("%d", &passar.MatrizY);

		if ((passar.MatrizX <= 0) || (passar.MatrizY <= 0) || (passar.MatrizX > 1000) || (passar.MatrizY > 1000)) {
			printf("Você escolheu um valor invalido por favor escolha novamente");
			continue;
		}
		break;
	}

	passar.MatE = (unsigned int**)malloc(passar.MatrizX * sizeof(int*));
	for (unsigned int i = 0; i < passar.MatrizX; i++) {
		passar.MatE[i] = (unsigned int*)malloc(passar.MatrizY * sizeof(int));
		for (unsigned int j = 0; j < passar.MatrizY; j++)
			passar.MatE[i][j] = 0;
	}

	passar.MatI = (unsigned int**)malloc(passar.MatrizX * sizeof(int*));
	for (unsigned int i = 0; i < passar.MatrizX; i++) {
		passar.MatI[i] = (unsigned int*)malloc(passar.MatrizY * sizeof(int));
		for (unsigned int j = 0; j < passar.MatrizY; j++)
			passar.MatI[i][j] = 0;
	}

	passar.MatS = (unsigned int**)malloc(passar.MatrizX * sizeof(int*));
	for (unsigned int i = 0; i < passar.MatrizX; i++) {
		passar.MatS[i] = (unsigned int*)malloc(passar.MatrizY * sizeof(int));
		for (unsigned int j = 0; j < passar.MatrizY; j++)
			passar.MatS[i][j] = 0;
	}

	for (unsigned int i = 0; i < passar.MatrizX; i++)
		for (unsigned int j = 0; j < passar.MatrizY; j++)
			passar.MatE[i][j] = rand() % 100;

	while (1) {
		printf("Para quantas numeros voce quer reduzir a matriz: ");
		scanf("%d", &passar.ParamSize);
		if ((passar.ParamSize <= 0) || (passar.ParamSize > passar.MatrizX * passar.MatrizY)) {
			printf("Voce digitou um numero invalido, escolha outro!\n");
			continue;
		} else if ((passar.ParamSize > 5) && (passar.MatrizX * passar.MatrizY < 100)) {
			printf("Para matrizes menores que 100 elementos voce so tem 5 parametros, escolha outro valor!\n");
			continue;
		}
		else if ((passar.ParamSize > (passar.MatrizX * passar.MatrizY) / 10) && ((passar.MatrizX * passar.MatrizY) >= 100)) {
			printf("Para matrizes maiores que 100 elementos voce so tem 10%% dos elementos em parametros, escolha outro valor!\n");
			continue;
		}
		else {
			passar.NewParams = (unsigned int*)malloc(passar.ParamSize * sizeof(int));
			passar.ParamCount = (unsigned int*)malloc(passar.ParamSize * sizeof(int));
			passar.Params = (unsigned int*)malloc(passar.ParamSize * sizeof(int));
			for (unsigned int i = 0; i < passar.ParamSize; i++) {
				passar.NewParams[i] = 0;
				passar.ParamCount[i] = 0;
				passar.Params[i] = 0;
			}
			break;
		}
	}
	*dados = passar;
}

void MostrarMatriz(const struct Dados dados, unsigned int **Mat) {
	printf("Matriz \n");
	for (unsigned int i = 0; i < dados.MatrizX; i++) {
		for (unsigned int j = 0; j < dados.MatrizY; j++)
			printf(" %d", Mat[i][j]);
		printf("\n");
	}
}

void ReduzirMatriz(struct Dados* dados) {
	int rMin = 0, d, dMin;
	for (unsigned int i = 0; i < dados->MatrizX; i++)
		for (unsigned int j = 0; j < dados->MatrizY; j++) {
			dMin = 442;
			for (unsigned int r = 0; r < dados->ParamSize; r++) {
				d = abs(dados->MatE[i][j] - dados->Params[r]);
				if (dMin > d) {
					dMin = d;
					rMin = r;
				}
			}
			dados->MatI[i][j] = rMin;
			dados->MatS[i][j] = dados->Params[rMin];
		}
}

void NovosParams(struct Dados *dados) {
	for (unsigned int i = 0; i < dados->ParamSize; i++) {
		dados->ParamCount[i] = 0;
		dados->NewParams[i] = 0;
	}

	for (unsigned int i = 0; i < dados->MatrizX; i++) {
		for (unsigned int j = 0; j < dados->MatrizY; j++) {
			dados->NewParams[dados->MatI[i][j]] += dados->MatE[i][j];
			dados->ParamCount[dados->MatI[i][j]] += 1;
		}
	}
	for (unsigned int i = 0; i < dados->ParamSize; i++) {
		if (dados->ParamCount == 0)
			continue;
		dados->NewParams[i] = dados->NewParams[i] / dados->ParamCount[i];
	}
}

int VerifcaDiferenca(struct Dados *dados) {
	int melhorar = 0;
	for (unsigned int i = 0; i < dados->ParamSize; i++) {
		if (abs(dados->NewParams[i] - dados->Params[i]) > 1) {
			melhorar = 1;
			break;
		}
	}

	if (melhorar)
		for (unsigned int i = 0; i < dados->ParamSize; i++) {
			dados->Params[i] = dados->NewParams[i];
		}
	return melhorar;
}

void PegarElementos(struct Dados *dados, int* Counter) {
	int denovo = 0;
	
	while (1) {
		for (unsigned int i = 0; i < dados->ParamSize; i++)
			Counter[i] = 0;
		
		for (unsigned int i = 0; i < dados->ParamSize; i++)
			dados->Params[i] = dados->MatE[rand() % dados->MatrizX][rand() % dados->MatrizY];	

		int rMin = 0, d, dMin;
		for (unsigned int i = 0; i < dados->MatrizX; i++)
			for (unsigned int j = 0; j < dados->MatrizY; j++) {
				dMin = 1000;
				for (unsigned  r = 0; r < dados->ParamSize; r++) {
					d = abs(dados->MatE[i][j] - dados->Params[r]);
					if (dMin > d) {
						dMin = d;
						rMin =:wq r;
					}
				}
				Counter[rMin] += 1;
			}

		for (unsigned int i = 0; i < dados->ParamSize; i++) {
			if (Counter[i] == 0) {
				denovo = 1;
				break;
			}
		}

		if (denovo) {
			denovo = 0;
			continue;
		}

		for (unsigned int i = 0; i < dados->ParamSize; i++)
			Counter[i] = 0;

		break;
	}
	free(Counter);
}

int main(void) {
	srand((int)time(0));
	
	struct Dados entrada;
	struct Dados* passar;
	passar = &entrada;

	InicializarDados(passar);
	MostrarMatriz(*passar, entrada.MatE);

	int* Counter = (int*)malloc(entrada.ParamSize * sizeof(int));
	PegarElementos(passar, Counter);
	ReduzirMatriz(&entrada);

	while(1){
		NovosParams(&entrada);

		if (VerifcaDiferenca(&entrada)) {
			ReduzirMatriz(&entrada);
			MostrarMatriz(*passar, entrada.MatS);
			continue;
		}
		else
			break;
	}
	return 0;
}
