#include "funciones.h"

void read_rejected()
{
    FILE *file_rejected = OpenFile(f_rejected, "a+" );

    STR_USER user;
    char *line_read = (char*) malloc(sizeof(char)*L_read_user);
    fgets (line_read, L_read_user, file_rejected);

    printf("\n Listado de REJECTED: \n");

    while(!feof(file_rejected))
    {
        parcear(line_read, &user);
        printf("Nombre: %s ", user.name);
        printf("Email: %s ", user.email);
        printf("Password: %s \n", user.password);
        fgets (line_read, L_read_user, file_rejected);
    }
    printf("\n");
    fclose(file_rejected);
}

void read_user_dat()
{
    FILE *file_users_b = OpenFile(f_users_b, "ab+" );
    STR_USER *user = (STR_USER*) malloc(sizeof(STR_USER));
    fread(user, sizeof(STR_USER), 1, file_users_b);

    printf("\n Listado de USER.DAT: \n");

    while(!feof(file_users_b))
    {
        printf("Nombre: %s ", user->name);
        printf("Email: %s ", user->email);
        printf("Password: %s", user->password);
        printf("\n");
        fread(user, sizeof(STR_USER), 1, file_users_b);
    }
    printf("\n");
    fclose(file_users_b);
}

void read_orders_dat()
{
    FILE *file_orders_b = OpenFile(f_orders_b, "ab+" );
    STR_ORDERS *order = (STR_ORDERS*) malloc(sizeof(STR_ORDERS));
    fseek(file_orders_b,0,SEEK_SET);
    fread(order, sizeof(STR_ORDERS), 1, file_orders_b);

    printf("\n Lista de PEDIDOS.DAT: \n");

    while(!feof(file_orders_b))
    {
        printf("Email: %s  ID: %i  Cantidad: %i  Precio: %0.2f \n", order->email, order->id_product, order->quantity, order->value);
        fread(order, sizeof(STR_ORDERS), 1, file_orders_b);
    }
    printf("\n");
    fclose(file_orders_b);
}

void read_orders_txt()
{
   FILE *file_orders = OpenFile(f_orders, "a+" );

    STR_ORDER_TOTAL order;
    char *line_read = (char*) malloc(sizeof(char)*L_read_user);
    fgets (line_read, L_read_user, file_orders);

    printf("\n Lista de PEDIDOS.TXT: \n");
    while(!feof(file_orders))
    {
        parcear_orders(line_read, &order);
        printf("Email: %s  Usuario: %s  Cantidad: %i  TOTAL: %0.2f \n", order.email, order.name, order.quantity, order.value_final);
        fgets (line_read, L_read_user, file_orders);
    }
    printf("\n");
    fclose(file_orders);

}

void parcear_orders(char line_read[L_read_user], STR_ORDER_TOTAL *order){

    char *token = strtok (line_read, " ");
    strncpy(order->email, token, L_string_limit);

    token = strtok (NULL, " ");
    memset(order->name,'\0', L_string_limit);
    strncpy(order->name, token, L_string_limit);

    token = strtok (NULL, " ");
    order->quantity = atoi(token);

    token = strtok (NULL, " ");
    order->value_final = atof(token);
}