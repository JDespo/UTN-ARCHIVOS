#include "funciones.h"

void login (){

    STR_USER *user = (STR_USER*) malloc(sizeof(STR_USER));
    STR_USER *user_aux = (STR_USER*) malloc(sizeof(STR_USER));

    printf("ingrese su correo: ");
    scanf("%s", user_aux->email);
    printf("ingrese su contrasena: ");
    scanf("%s", user_aux->password);

    if (serch_email( user_aux->email, user, search_email) != -1)
    {
        if(strcmp( user_aux->password, user->password ) == 0)
        {
            printf("\n Logueo exitoso:  \n\t\tUsuario : %s  \n \t\tEmail\t: %s \n",  user->name,  user->email);
        }
        else
        {
            printf("\n ALguno de los datos ingresados fueron incorrectos ");
        }
    }
    else
    {
        printf("\n ALguno de los datos ingresados fueron incorrectos ");
    }
    
}

int serch_email( const char *search_aux, STR_USER *user, int option_search)
{
    FILE *pFile = OpenFile( f_users_b, "ab+" );
    int lower = 0;
    int medium = 0;
    int higher = recor_quantity( pFile );

    fseek( pFile, 0, SEEK_SET );

    while ( lower <= higher )
    {
        medium = ( higher + lower ) /2 ;
        fseek( pFile, medium * sizeof( STR_USER ), SEEK_SET );
        fread( user, sizeof( STR_USER ), 1, pFile );

        if(strcmp( search_aux, user->email ) == 0)
        { return medium; }

        if( strcmp(search_aux, user->email )== -1 )
        { higher = medium - 1; }

        if( strcmp( search_aux, user->email )== 1 )
        { lower = medium + 1; }  
    }

    fclose(pFile);
    if( option_search == search_lower)
    {
        return lower;
    }
    return -1;
}

int search_user(const char *search_aux, STR_USER *user)
{
    FILE *pFile = OpenFile( f_users_b, "ab+" );
    fseek( pFile, 0, SEEK_SET );

    fread( user, sizeof( STR_USER ), 1, pFile );

    while(!feof(pFile))
    {
        if(strcmp( search_aux, user->name ) == 0)
        { return 1; }
        fread( user, sizeof( STR_USER ), 1, pFile );
    }
    fclose(pFile);
    return -1;
}
