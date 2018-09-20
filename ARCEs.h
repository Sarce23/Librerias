#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

typedef struct _tdato{
	int numero;
	struct _tdato *sig;
}Tdato;

typedef Tdato *Tnodo;


void Servicio( Tnodo temp);
Tnodo GenDatos(Tnodo tope);
Tnodo GenDatos();

void PUSH( Tnodo *cola, Tnodo *ultimo, Tnodo *nuevo);
Tnodo POP( Tnodo *cola, Tnodo *ultimo);


void Servicio( Tnodo temp)
{
	printf("\n\tNUMERO: %li", temp->numero);
}

Tnodo GenDatos(Tnodo tope)
{	
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	
	if(tope)
	{
		temp->numero = tope->numero + 1;
		temp->sig = NULL;
	}
	else
	{
		temp->numero = 1;
		temp->sig = NULL;
	}
	
	return temp;
}

void PUSH( Tnodo *cola, Tnodo *ultimo, Tnodo *nuevo)
{
	if(!*cola)
	{
		*cola = *nuevo;
	}
	else
	{
		(*ultimo)->sig = *nuevo;
	}
	*ultimo = *nuevo;
	printf("\n\n\t cliente con %d movimientos \n", (*nuevo)->numero);
	*nuevo = NULL;
}


Tnodo POP( Tnodo *cola, Tnodo *ultimo)
{
	Tnodo temp = NULL;
	
	if(*cola)
	{
          temp = *cola;         
		*cola = ((*cola)->sig);
		temp->sig = NULL;
		if(temp == *ultimo)
		{
			*ultimo = NULL;
		}
	}
	if(temp)
	{
               printf("\n\n\tse ha atendido a un cliente, con un numero de movimientos de: %d\n", temp->numero);
     }
	return temp;
}

Tnodo GenDatos()
{
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	
	temp->numero = rand()%10;
	temp->sig = NULL;
	
	return temp;
}
