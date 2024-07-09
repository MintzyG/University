#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <inttypes.h>

#define RAND 200

typedef struct Ponto {
  float x, y;
  float ang, dist;
} Ponto;

Ponto CreatePoint(Ponto ponto){
  int sign1 = 0, sign2 = 0;
  sign1 = rand() % 2;
  if (sign1 == 0)
    sign1 = -1;
  sign2 = rand() % 2;
  if (sign2 == 0)
    sign2 = -1;
  ponto.x = sign1 * (float)(((double)rand()/(double)(RAND_MAX)) * RAND);
  ponto.y = sign2 * (float)(((double)rand()/(double)(RAND_MAX)) * RAND);
  return ponto;
}

void CreatePoints(Ponto* ponto, int size){
  for (int i = 0; i < size; i++) ponto[i] = CreatePoint(ponto[i]);

  Ponto nova_origem;
  nova_origem.x = 0; nova_origem.y = 0;
  for (int i = 0; i < size; i++){
    nova_origem.x += ponto[i].x;
    nova_origem.y += ponto[i].y;
  }

  nova_origem.x = nova_origem.x/size;
  nova_origem.y = nova_origem.y/size;

  for (int i = 0; i < size; i++){
    ponto[i].x -= nova_origem.x;
    ponto[i].y -= nova_origem.y;
  }
}

void CalcularAngulos(Ponto* ponto, int size){
  for (int i = 1; i < size; i++) {
    float dir = ponto[i].x * ponto[0].y - ponto[0].x * ponto[i].y;
    float produto_escalar = ponto[0].x * ponto[i].x + ponto[0].y * ponto[i].y;
    float distancia_um = sqrt(pow(ponto[0].x, 2) + pow(ponto[0].y, 2));
    float distancia_dois = sqrt(pow(ponto[i].x, 2) + pow(ponto[i].y, 2));
    ponto[i].dist = distancia_dois;
    float proj = produto_escalar / (distancia_um * distancia_dois);
    // Not the problem
    if (proj < -1) proj = 0;
    if (proj > 1) proj = 1;
    float cosseno_radianos = acos((proj));
    float ang = cosseno_radianos * 180.0 / M_PI;
    if (dir > 0) { ponto[i].ang = 360 - ang; }
    else { ponto[i].ang = ang; }
  }
}

void Swap(Ponto* ponto, int index_a, int index_b){
  Ponto tmp;
  tmp = ponto[index_a];
  ponto[index_a] = ponto[index_b];
  ponto[index_b] = tmp;
}

void QuickSort(Ponto* ponto, int first, int last) {
  if (last - first < 2)
    return;

  int pivot = ponto[first].ang;
  int pointer_b = last - 1;
  int swap_marker = last;

  for (int i = pointer_b; i >= first; i--) {
    if (ponto[i].ang >= pivot) {
      swap_marker--;
      if (i < swap_marker)
        Swap(ponto, i, swap_marker);
    }
  }

  QuickSort(ponto, first, swap_marker);
  QuickSort(ponto, swap_marker+1, last);

}

float CalcularArea(Ponto* ponto, int size) {
  float area = 0, angulo = 0;
  for (int i = 0; i < size; i++){
    if ((i + 1) != size)
      angulo = ponto[i + 1].ang - ponto[i].ang;
    else
      angulo = 360.0 - ponto[i].ang + ponto[i + 1].ang;
    angulo = angulo * (M_PI / 180.0);
    area += (ponto[i].dist * ponto[(i+1)%size].dist * (sin(angulo))) / 2;
  }
  return area;
}

int main(int argc, char** argv) {

  clock_t begin = clock();

  intmax_t size = 0;

  if (argc == 1) {
    printf("No arguments provided");
    exit(-1);
  } else if (argc > 2) {
    printf("Too many arguments provided");
    exit(-1);
  } else {
    intmax_t num = strtoimax(argv[1], NULL, 10);
    if (num == INTMAX_MAX && errno == ERANGE){
      printf("Could not convert");
      exit(-1);
    } else {
      size = num;
    }
  }

  srand(clock());

  Ponto* pontos = (Ponto*)malloc(size * sizeof(Ponto));

  CreatePoints(pontos, size);
  CalcularAngulos(pontos, size);
  QuickSort(pontos, 0, size);
  float area = CalcularArea(pontos, size);

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time spent: %f\n", time_spent);
  printf("Area: %f", area);

  return 0;
}
