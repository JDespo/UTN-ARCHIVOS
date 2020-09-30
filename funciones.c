#include "funciones.h"

void read_users()
{
    FILE *file_user = OpenFile(f_users, "r+" );
    FILE *file_rejected = OpenFile(f_rejected, "a+" );
    FILE *file_users_b = OpenFile(f_users_b, "ab+" );

    STR_USER user;

    char *line_read = (char*) malloc(sizeof(char)*L_read_user);
    fgets (line_read, L_read_user, file_user);

    while(!feof(file_user))
    {
        parcear(line_read, &user);

        if (check_List (&user) == true){
            //Cumple los requisitos -> guardar en el archivo USER.DAT
            fwrite(&user, sizeof(STR_USER), 1, file_users_b);
        }
        else{
            // NO cumple los requisitos -> guardar archivo en REJECTED.TXT 
             fprintf(file_rejected,"%s;%s;%s;\n", user.name, user.email, user.password);
        }
        fgets (line_read, L_read_user, file_user);
    }
    
    fclose(file_user);
    fclose(file_rejected);
    fclose(file_users_b);
}

void parcear(const char *line_read, STR_USER *user){

    char *line_strtok = (char*) malloc(sizeof(char)*L_read_user);
    strcpy(line_strtok, line_read);

    char *token = strtok (line_strtok, ";");
    memset(user->name,'\0', L_string_limit);
    strncpy(user->name, token, L_string_limit);

    token = strtok (NULL, ";");
    memset(user->email,'\0', L_string_limit);
    strncpy(user->email, token, L_string_limit);

    token = strtok (NULL, ";");
    memset(user->password,'\0', L_string_limit);
    strncpy(user->password, token, L_string_limit);
    return;
}

bool check_List(STR_USER *user)
{
    int check = 0;
    // Nombre maximo 15
    if (strlen(user->name) <= L_max_limit)
    {  check += 1; }

    //Email max15 && que contenga @
    check += check_email(user->email);

    //Contraseña minimo 8 &&  formado por numeros y letras
    check += check_Password(user->password);

    if(check == 3)
    { return true; }

    return false;
}

bool check_email(char *email) 
{
    char *key = "@";
 
    if( strlen(email) <= L_max_limit)
    {
        if ( strpbrk(email, key) != NULL)
        {  return true; }
    }

    return false;
}

int check_Password(char *password)
{
    int valorAscci;
    bool flag_number = false;
    bool flag_letters = false;

    int strlength = strlen(password);

    if (strlength >= 8){
    
        for ( int i = 0; i < strlength; i++ )
        { 
            valorAscci = *(password+i);
           //           48 <=> 57 ( Numeros )          //        65 <=> 90 ( A - Z )             //           97 <=> 122  ( a - z )
            if ((valorAscci >= 48 && valorAscci <= 57) || (valorAscci >= 65 && valorAscci <= 90) || (valorAscci >= 97 && valorAscci <= 122)) 
            {   
                if(valorAscci <= 57)
                {
                    flag_number = true;
                }
                else
                {
                    flag_letters = true;
                }
            }
            else 
            { 
                return false;
            }
        }
        if ( flag_number == true && flag_letters == true)
        {
           return true;
        }
    }
    return false;
}


