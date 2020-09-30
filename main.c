#include "funciones.h"

int main()
{
    showMenu();
    printf("\n\t\t\tIngrese opcion: ");
	enum OPTIONS option = getOption();

	while(option != END_PROGRAM){

		switch(option){
			case INITIALIZE:
				read_users();
				system("pause");
				system("cls");
				break;
			case LOGIN:
				login();
				system("pause");
				system("cls");
				break;
			case REGISTER_USER:
				register_user();
				//rename_file();
				system("pause");
				system("cls");
				break;
			case ORDERS:
                read_orders();
				system("pause");
				system("cls");
				break;
			case READ_DATA:
				read_user_dat();
				system("pause");
				 system("cls");
				break;
			case READ_FILE_ORDERS:
				 read_orders_dat();
				 system("pause");
				 system("cls");
				break;
			case READ_FILE_REJECTED:
				read_rejected();
				system("pause");
				system("cls");
				break;
			case READ_FILE_ORDERS_TXT:
				 read_orders_txt();
				 system("pause");
				 system("cls");
				break;
			default:
				printf("\n	Opcion no valida	\n\n");
				break;
		}

		showMenu();
		printf("\n\t\t\tIngrese opcion: ");
		option = getOption();
    }
    return 0;
}
