#include "funciones.h"


void printLineWithText(const char* text)
{
	char line1[80+1];
	memset(line1, '\0', 81);
	*line1='#';
	*(line1+79) = '#';

	strncat(line1+1, text, strlen(text));

	int i=0;
	while(i<80)
	{
		if(*(line1+i) == '\0')
		{
			*(line1+i) = ' ';
		}
		i++;
	}

	printf("%s\n", line1);
}

void printHastagLine()
{
	char line[80+1];
	memset(line, '\0', 81);
	memset(line, '#', 80);

	printf("%s\n", line);
}

void showMenu()
{
	printHastagLine();
	printLineWithText("");
	printLineWithText("    MENU DE OPCIONES :");
	printLineWithText("");
	printLineWithText("        1 - Inicailizar carga de archivo        5 - Listar Users.dat");
	printLineWithText("        2 - Realizar Logueo                     6 - Listar Pedidos.dat");
	printLineWithText("        3 - Registrar Nuevo Usuario             7 - Listar Rejected.txt");
	printLineWithText("        4 - Carga de Pedidos                    8 - Listar Pedidos.txt");
	printLineWithText("");
    printLineWithText("                            9 - Para finalizar");
	printLineWithText("");
	printHastagLine();
}

enum OPTIONS getOption()
{
	int option = INITIALIZE;
	char *op;
	scanf("%s", op);
	//scanf("%d", &option);
	option = atoi(op);
	printHastagLine();
	return option;
}