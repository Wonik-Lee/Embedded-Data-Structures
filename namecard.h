#ifndef NAMECARD_H
#define NAMECARD_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 21
#define CORP_SIZE 31
#define TEL_SIZE 16
#define REC_SIZE (NAME_SIZE + CORP_SIZE + TEL_SIZE)

typedef struct _card {
    char name[NAME_SIZE];
    char corp[CORP_SIZE];
    char tel[TEL_SIZE];
    struct _card* next;
} card;

extern card* head;
extern card* tail;

void init_card();
void input_card();
int delete_card(char* s);
card* search_card(char* s);
void save_card(char* s);
void load_card(char* s);
void print_header(FILE* f);
void print_card(card* t, FILE* f);
int select_menu();

#endif // NAMECARD_H