#include "define.h"
// ESTRUCTURA DEL USUARIO
typedef struct
{
    char name [L_string_limit];
    char email [L_string_limit];
    char password [L_string_limit];

}STR_USER;

//ESTRUCTURA DE PEDIDOS.DAT
typedef struct
{
    char email [L_string_limit];
    int id_product;
    int quantity;
    float value;

}STR_ORDERS;

// ESTRUCTURA DE PEDIDOS.TXT
typedef struct
{
    char name [L_string_limit];
    char email [L_string_limit];
    int quantity;
    float value_final;

}STR_ORDER_TOTAL;