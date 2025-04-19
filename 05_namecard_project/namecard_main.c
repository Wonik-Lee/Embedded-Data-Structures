#include "namecard.h"

int main()
{
    char* fname = "NameCard.dat";
    char name[NAME_SIZE];
    int i;
    card* t;

    init_card();

    while ((i = select_menu()) != 7) {
        switch (i) {
        case 1:
            input_card();
            break;
        case 2:
            printf("\nInput name to delete->");
            gets_s(name, sizeof(name));
            if (!delete_card(name))
                printf("\nCan't find the name...");
            break;
        case 3:
            printf("\nInput name to search->");
            gets_s(name, sizeof(name));
            t = search_card(name);
            if (t == NULL)
                break;
            print_header(stdout);
            print_card(t, stdout);
            break;
        case 4:
            load_card(fname);
            break;
        case 5:
            save_card(fname);
            break;
        case 6:
            t = head->next;
            print_header(stdout);
            while (t != tail) {
                print_card(t, stdout);
                t = t->next;
            }
            break;
        }
    }

    return 0;
}
