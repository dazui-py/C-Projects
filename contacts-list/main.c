#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char phone[50];
    char email[100];
} Contact;

int main() {
  int choice = 0;
  FILE *pSave;
  char load[1024] = {0};
  int value = 0;

	system("mkdir -p data");

  pSave = fopen("data/save.txt", "r");

  if (pSave == NULL) {}
  else {
    while (fgets(load, sizeof(load), pSave) != NULL) {
      value = atoi(load);
    }
    fclose(pSave);
  }

  int j = value; // added contacts

  Contact *list = NULL; /* malloc(sizeof(Contact)); */
  FILE *pContacts;

  char buffer[1024] = {0};

  // if (list == NULL) {
  //     printf("Memory allocation failed!");
  //     return 1;
  // }

  while (choice != 3) {
    printf("\nContact List:\n");
    printf("1. Add\n2. List\n3. Exit\n");

    printf("Enter a choice (1-3): ");
    scanf("%d", &choice);
    (void)getchar();

    Contact *temp;
    switch (choice) {
			case 1:
				temp = realloc(list, (j + 1) * sizeof(Contact));

        if (temp == NULL) {
          printf("Could not re-allocate memory");
          return 1;
        }
        else {
          list = temp;
        }

        printf("\nName: ");
        fgets(list[j].name, sizeof(list[j].name), stdin);

        printf("Phone: ");
        fgets(list[j].phone, sizeof(list[j].phone), stdin);

        printf("Email: ");
        fgets(list[j].email, sizeof(list[j].email), stdin);

        pContacts = fopen("data/contacts.txt", "a");
        if(pContacts == NULL){
          printf("Could not write contacts.txt");
        }
        else {
          fprintf(pContacts, "#%d\nName: %sPhone: %sEmail: %s\n", j + 1, list[j].name, list[j].phone, list[j].email);
          fclose(pContacts);
        }
        j++;
        break;

      case 2:
        pContacts = fopen("data/contacts.txt", "r");

        if (pContacts == NULL) {
          printf("Could not read contacts.txt");
        }
        else {
          while (fgets(buffer, sizeof(buffer), pContacts) != NULL) {
            printf("%s", buffer);
          }
          fclose(pContacts);
        }
        break;

      case 3:
        pSave = fopen("data/save.txt", "w");
        if(pSave == NULL){
          printf("Could not save the current state");
        }
        else {
          fprintf(pSave, "%d", j);
          fclose(pSave);
        }
        break;
        default:
          printf("Invalid option");
  	}
  }

  free(list);
  list = NULL;

  return 0;
}
