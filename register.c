#include "funciones.h"


void register_user()
{
    STR_USER *user = (STR_USER*) malloc(sizeof(STR_USER));
    STR_USER *user_aux = (STR_USER*) malloc(sizeof(STR_USER));
    
    int flag = 0;
    printf("\nREGISTRACION DE NUEVO USUARIO: \n");
    printf("\ningrese su Nombre: ");
    scanf("%s", user_aux->name);
    printf("\ningrese  correo: ");
    scanf("%s", user_aux->email);
    printf("\ningrese contrasena: ");
    scanf("%s", user_aux->password);

    int pos =-1;

    if( check_List(user_aux) == 1 )
    {
        if ((serch_email( user_aux->email, user, search_email) == -1) && ((search_user( user_aux->name, user) == -1))) 
        {   // Devuelve la posicion inferior para luego guardar ordenado  //BUSQUEDA SECUENCIAL
            pos = (serch_email( user_aux->email, user, search_lower));

            funcion_aux( pos, user_aux);
        }
    }
    else
    {
        printf("\nNo cumple con los parametros requeridos\n");
    }

}

void funcion_aux(int pos, STR_USER *user_aux)
{
    FILE *pFile = OpenFile(f_users_b, "ab+" );
    int cant_user = recor_quantity(pFile);
        
    if(pos > cant_user)
    {//La Pos indica que se guardara en la ultima posicion
        fseek( pFile, 0, SEEK_END );
        fwrite(user_aux, sizeof(STR_USER), 1, pFile);
        fclose(pFile);
    }
    else
    {
        FILE *pFile2 = OpenFile(f_users_aux_b, "ab+" );
        STR_USER *user_vec = (STR_USER*) malloc(sizeof(STR_USER));
        fseek( pFile, 0, SEEK_SET );
        fread(user_vec, sizeof(STR_USER), 1, pFile);
        int i = 0;

        while(!feof(pFile))
        {
            if (i == pos )
            { fwrite(user_aux, sizeof(STR_USER), 1, pFile2); }

            fwrite(user_vec, sizeof(STR_USER), 1, pFile2);
            fread(user_vec, sizeof(STR_USER), 1, pFile);
            i++;
        }

        printf("\nSe registro correctamente\n");
        fclose(pFile);
        fclose(pFile2);
        file_remove(f_users_b);
        file_rename(f_users_aux_b, f_users_b);
    }
}