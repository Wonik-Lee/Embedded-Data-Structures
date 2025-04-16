#include "namecard.h"

card* head, * tail;


// initialize the namecard
void init_card()
{
    head = (card*)calloc(1, sizeof(card));
    tail = (card*)calloc(1, sizeof(card));
    head->next = tail;
    tail->next = tail;
}


// input new namecard after head
void input_card()
{
    card* t = (card*)calloc(1, sizeof(card));
    printf("\nInput namecard menu : ");
    printf("\nInput name : ");
    gets_s(t->name, sizeof(t->name));
    printf("\nInput corporation : ");
    gets_s(t->corp, sizeof(t->corp));
    printf("\nInput telephone number : ");
    gets_s(t->tel, sizeof(t->tel));
    t->next = head->next;
    head->next = t;
}


// delete card that contains "s" string as name
int delete_card(char* s)
{
    card* t, * p;
    p = head;
    t = p->next;
    while (strcmp(s, t->name) != 0 && t != tail) {   // if two string is same, return 0
        p = p->next;                                 // if str1 is bigger, return poisitive number
        t = p->next;                                 // if str2 is bigger, return negative number
    }
    if (t == tail)
        return 0;
    p->next = t->next;
    free(t);
    return 1;
}


// search card that contains "s" string as name
card* search_card(char* s)
{
    card* t = head->next;
    while (strcmp(s, t->name) != 0 && t != tail) {
        t = t->next;
    }
    if (t == tail)
        return NULL;
    else
        return t;
}


// save namecard (file name is "s")
void save_card(char* s)
{
    FILE* fp;
    card* t;
    fopen_s(&fp, s, "wb");       // open file as binary write mode
    t = head->next;
    while (t != tail) {
        fwrite(t, REC_SIZE, 1, fp);

        t = t->next;
    }
    fclose(fp);
}


// load namecard (file name is "s")
void load_card(char* s)
{
    FILE* fp;
    card* t, * u;
    fopen_s(&fp, s, "rb");      // open file as binary read mode

    t = head->next;
    while (t != tail) {
        u = t;
        t = t->next;
        free(u);
    }
    head->next = tail;

    while (1) {
        t = (card*)calloc(1, sizeof(card));
        if (!fread(t, REC_SIZE, 1, fp)) {
            free(t);
            break;
        }
        t->next = head->next;
        head->next = t;
    }
    fclose(fp);
}


// print namecard
void print_card(card* t, FILE* f)
{
    fprintf(f, "\n%-20s %-30s %-15s", t->name, t->corp, t->tel);
}



void print_header(FILE* f)
{
    fprintf(f, "\nName"
        "\t\t      Corportation "
        "\t\t     Telephone number");
    fprintf(f, "\n--------------------- "
        "------------------------------ "
        "--------------------");
}


int select_menu()
{
    int j;
    char s[10];
    printf("\nName Card Manager");
    printf("\n------------------------");
    printf("\n1.Input name card");
    printf("\n2.Delete name card");
    printf("\n3.Search name card");
    printf("\n4.Load name card");
    printf("\n5.Save name card");
    printf("\n6.Show list");
    printf("\n7.Program end¡¦");
    do {
        printf("\n: selection operation->");
        gets_s(s, sizeof(s));
        j = atoi(s);
    } while (j < 0 || j > 7);

    return j;
}
