#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Head Head;
typedef struct Node Node;

enum Options {
  ADD = 1,
  REMOVE,
  LIST,
  IMPORT,
  QUIT,
};

struct Node {
  Node* next_2000;
  Node* next_1990;
  int data_2000;
  int data_1990;
  char* city;
};

struct Head {
  Node* first_2000;
  Node* first_1990;
  int size;
};

Node* CreateNode() {
  Node* node = calloc(1, sizeof *node);
  *node = (Node) {
    .next_2000 = NULL,
    .next_1990 = NULL,
    .data_2000 = 0,
    .data_1990 = 0,
    .city = NULL
  };
  return node;
}

Head* CreateList() {
  Head* head = calloc(1, sizeof *head);
  *head = (Head) {
    .first_2000 = NULL,
    .first_1990 = NULL,
    .size = 0,
  };
  return head;
}

void ShowNode(char *city, int data_2000, int data_1990) {
  printf("|%-32s|%-10d|%-10d|\n", city, data_2000, data_1990);
}

void Show(Head* list) {
  Node* first_2000 = list->first_2000;
  Node* first_1990 = list->first_1990;
  printf("|City                            |2000      |1990      |\n");
  while(first_2000) {
    ShowNode(first_2000->city, first_2000->data_2000, first_2000->data_1990);
    first_2000 = first_2000->next_2000;
  }
  printf("\n\n\n\n");
  printf("|City                            |2000      |1990      |\n");

  while(first_1990) {
    ShowNode(first_1990->city, first_1990->data_2000, first_1990->data_1990);
    first_1990 = first_1990->next_1990;
  }
}

int CityExists(Head* head, char* city) {
  Node* node = head->first_2000;
  while (node) {
    if (strcmp(node->city, city) == 0) {
      return 1;
    }
    node = node->next_2000;
  }
  return 0;
}

void Push(Head* head, char* city, int value_2000, int value_1990) {
  if (CityExists(head, city)) {
    printf("Warning: City '%s' already exists in the list.\n", city);
    printf("Press Enter to return to the main menu\n");
    getchar();
    return;
  }

  Node* new = CreateNode();
  new->data_2000 = value_2000;
  new->data_1990 = value_1990;
  new->city = city;

  if (head->size == 0) {
    head->first_2000 = new;
    head->first_1990 = new;
    head->size += 1;
    return;
  }

  if (new->data_2000 < head->first_2000->data_2000) {
    new->next_2000 = head->first_2000;
    head->first_2000 = new;
  } else {
    Node* node = head->first_2000;
    Node* last = NULL;
    while (node && node->data_2000 < new->data_2000) {
      last = node;
      node = node->next_2000;
    }

    if (!node) {
      last->next_2000 = new;
    } else {
      last->next_2000 = new;
      new->next_2000 = node;
    }

  }

  if (new->data_1990 < head->first_1990->data_1990) {
    new->next_1990 = head->first_1990;
    head->first_1990 = new;
  } else {
    Node* node = head->first_1990;
    Node* last = NULL;
    while (node && node->data_1990 < new->data_1990) {
      last = node;
      node = node->next_1990;
    }

    if (!node) {
      last->next_1990 = new;
    } else {
      last->next_1990 = new;
      new->next_1990 = node;
    }

  }

  head->size += 1;
}

char RemoveNode_2000(Node** head, char* city, Node** node_del) {
  if (*head == NULL) return 0;

  Node* temp = *head;
  Node* prev = NULL;

  if (temp != NULL && strcmp(temp->city, city) == 0) { // caso inicio
    *head = temp->next_2000;
    *node_del = temp; // salva o nó para remover
    return 1;
  }

  while (temp != NULL && strcmp(temp->city, city) != 0) { // percorre a lista
    prev = temp;
    temp = temp->next_2000;
  }

  if (temp == NULL) return 0; // não encontrado

  prev->next_2000 = temp->next_2000;
  *node_del = temp; // salva o nó para remover

  return 1;
}

char RemoveNode_1990(Node** head, char* city, Node** node_del) {
  if (*head == NULL) return 0;

  Node* temp = *head;
  Node* prev = NULL;

  if (temp != NULL && strcmp(temp->city, city) == 0) { // caso inicio
    *head = temp->next_1990;
    *node_del = temp; // salva o nó para remover
    return 1;
  }

  while (temp != NULL && strcmp(temp->city, city) != 0) { // percorre a lista
    prev = temp;
    temp = temp->next_1990;
  }

  if (temp == NULL) return 0; // não encontrado

  prev->next_1990 = temp->next_1990;
  *node_del = temp; // salva o nó para remover

  return 1;
}

void Remove(Head* head, char* city) {
  Node* node_del = NULL;

  if (RemoveNode_2000(&(head->first_2000), city, &node_del) && RemoveNode_1990(&(head->first_1990), city, &node_del)) {
    head->size--;
    free(node_del);
  } else {
    printf("City not found!\n");
    printf("Press Enter to return to the main menu\n");
    getchar();

  }
}

void ReadFromFile(Head* list) {
  FILE* file = fopen("EUA.txt", "r");
  if (!file) {
    printf("EUA.txt file not found, list starts empty\n");
    printf("If you want to use the file, use this format in the lines: Brazil, 01234, 56789\n");
    printf("Press Enter to return to the main menu\n");
    getchar();
    return;
  } else {
    printf("EUA.txt file found, importing list...\n");
    printf("Press Enter to return to the main menu\n");
    getchar();
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    char city[100];
    int value_2000, value_1990;
    if (sscanf(line, "%99[^,],%d,%d", city, &value_2000, &value_1990) == 3) {
      char *city_push = malloc(strlen(city) + 1);
      strcpy(city_push, city);
      Push(list, city_push, value_2000, value_1990);
    }
  }
  fclose(file);
}

int main() {
  int option = 0;
  Head* list = CreateList();

  while ((enum Options)option != QUIT) {
    printf("\e[1;1H\e[2J"); // clear universal

    printf("--- MENU ---\n");
    printf("1: ADD\n2: REMOVE\n3: LIST\n4: IMPORT FROM FILE\n5: QUIT\nOption: ");
    scanf("%d", &option);
    scanf("%*c");
    char city[100];

    switch((enum Options)option) {
      case ADD:
        printf("\e[1;1H\e[2J"); // clear universal
        printf("--- What city? ---\n");
        fgets(city, sizeof(city), stdin);
        city[strcspn(city, "\n")] = '\0'; // detecta onde está a qubra de linha e substitui por NULL
        char *city_push = malloc(strlen(city) + 1);
        strcpy(city_push, city);
        int value_2000 = 0, value_1990 = 0;
        printf("Year 2000: ");
        scanf("%d", &value_2000);
        printf("Year 1990: ");
        scanf("%d", &value_1990);
        Push(list, city_push, value_2000, value_1990);
        break;
      case REMOVE:
        printf("\e[1;1H\e[2J"); // clear universal
        printf("--- What city to remove? ---\n");
        fgets(city, sizeof(city), stdin);
        city[strcspn(city, "\n")] = '\0';
        Remove(list, city);
        break;
      case LIST:
        printf("\e[1;1H\e[2J"); // clear universal
        printf("--- List ---\n");
        Show(list);
        printf("Press Enter to return to the main menu\n");
        getchar();
        break;
      case IMPORT:
        ReadFromFile(list);
        break;
      case QUIT:
        printf("\e[1;1H\e[2J"); // clear universal
        break;
      default:
        continue;
    }
  }

  return 0;
}

