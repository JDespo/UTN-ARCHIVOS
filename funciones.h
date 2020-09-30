#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "define.h"
#include "struct.h"
//#include <ctype.h>

FILE* OpenFile(const char *name_file, const char *mode);

// DEFINE PARAMETROS ARCHVIO DAT
void read_user_dat();
int recor_quantity(FILE *pFile);


// ENUM OPTIONS
enum OPTIONS { INITIALIZE = 1, LOGIN, REGISTER_USER, ORDERS, READ_DATA, READ_FILE_ORDERS, READ_FILE_REJECTED, READ_FILE_ORDERS_TXT, END_PROGRAM};
void showMenu();
enum OPTIONS getOption();
void printHastagLine();


void read_users(); 
void parcear(const char *line_read, STR_USER *user);
void read_rejected();
bool check_email(char *email);
int check_Password(char *password);
bool check_List(STR_USER *user);

// Point 2
void login();
int serch_email( const char *user_aux, STR_USER *user, int op );

//Point 3
int search_user(const char *search_aux, STR_USER *user);
void register_user();
void rename_file();
void file_remove(const char *name_file);
void file_rename(const char *file_rename, const char *file_name);
void funcion_aux(int pos, STR_USER *user_aux);

//Point 4
void read_orders();
void saveTxt(STR_ORDER_TOTAL *orderTotal);
void read_orders_dat();

//ADICIONALES
void read_orders_txt();
void parcear_orders(char line_read[L_read_user], STR_ORDER_TOTAL *order);