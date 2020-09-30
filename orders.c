#include "funciones.h"

void read_orders()
{
    FILE *pFile = OpenFile(f_orders_b, "ab+");

    STR_ORDERS *order = (STR_ORDERS*)malloc(sizeof(STR_ORDERS));
    STR_ORDER_TOTAL *orderTotal =(STR_ORDER_TOTAL*)malloc(sizeof(STR_ORDER_TOTAL));

    fseek( pFile, 0, SEEK_SET );
    fread(order, sizeof(STR_ORDERS), 1, pFile);

    strcpy(orderTotal->email, order->email);

    orderTotal->quantity = 0;
    orderTotal->value_final = 0;

    while(!feof(pFile))
    {
        if(strcmp(orderTotal->email, order->email)== 0)
        {
            orderTotal->quantity += order->quantity;
            orderTotal->value_final += order->quantity * order->value;
        }
        else
        {
            saveTxt(orderTotal);
            orderTotal->quantity = order->quantity;
            orderTotal->value_final = order->quantity * order->value;
            strcpy(orderTotal->email, order->email);
        }
        fread(order, sizeof(STR_ORDERS), 1, pFile);
    } 
    saveTxt(orderTotal);

    printf("\n FINALIZO LA CARGA DE PEDFIDOS EXITOSAMENTE\n\n");
    fclose(pFile);
}

void saveTxt(STR_ORDER_TOTAL *orderTotal)
{
    FILE *pFile = OpenFile(f_orders, "a+");
    STR_USER *user = (STR_USER*) malloc(sizeof(STR_USER));

    serch_email(orderTotal->email, user, search_email);
    fprintf(pFile,"%s %s %i %0.2f\n", orderTotal->email,user->name, orderTotal->quantity, orderTotal->value_final);
    
    fclose(pFile);
}