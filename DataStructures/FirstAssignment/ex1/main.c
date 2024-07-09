#include <stdio.h>

#include "agenda.h"

int main() {
    Contacts *A = InitiateContacts(); 
    int option = 0;

    while ((Options)option != QUIT) {
        printf("1: ADD\n2: EDIT\n3: SHOW\n");
        printf("4: REMOVE\n5: SEARCH\n6: INFO\n7: QUIT\nOpcao: ");
        scanf("%d[^\n]", &option);
        scanf("%*c");

        switch((Options)option) {
            case ADD:
                A->CreateContact(A);
                break;
            case EDIT:
                A->GenericSearch(A, Place);
                break;
            case SHOW:
                A->ShowContacts(A);
                break;
            case REMOVE:
                A->GenericSearch(A, DeleteContact);
                break;
            case SEARCH:
                A->GenericSearch(A, NULL);
                break;
            case INFO:
                A->Info(A);
                break;
            case QUIT:
                break;
            default:
                continue;
        }
    } 
    return 0;
}
