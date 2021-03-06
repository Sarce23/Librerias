#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define RI 1
#define RS 4
#define TRUE 1
#define FALSE 0
#define N 100
#define tam 30
#define a 97
#define z 122
#define A 65
#define Z 90
#define ENTER 13
#define ESP 32

typedef struct _tdato{
	int dato;
	struct _tdato *sig;
}Tdato;

typedef Tdato *Tnodo;

int validanum(int Ri, int Rs, char *msn, char *msnError);
char *ValidaChar (char *msg, char *msgError, int n);
int ValidaNum (int ri, int rs, char *msg, char *msgError, int n);
int Llenasinrepetir(int V[], int n, int V2[]);
void LlenaVec(int V[], int n);
int Secuencial(int V2[], int j, int V);
int SecuencialO(int Valum[],int n, int matri);
int busqbinaria(const int arreglo[], int n, int clave);
void Burbuja(int Valum[], int n);
void servicio(Tnodo temp);


int validanum(int Ri, int Rs, char *msn, char *msnError)
{
	int opc;
	char opcion[10];
	do{
		puts(msn);
		fflush(stdin);
		gets(opcion);
		opc= atoi(opcion);
		if( opc < Ri || opc > Rs)
		  {
		  	puts(msnError);
		  }
	}while(opc < Ri || opc > Rs);
	return opc;
}

int ValidaNum (int ri, int rs, char *msg, char *msgError, int n)
{
	int i=0, num=0, k;
	unsigned int reg;
	char numero[20];
	
	do{
		puts(msg);
		for(k=0; k < n; k++)
		{
			num=getch();
			if(num >= 48 && num <= 57)
			{
				printf("%c", num);
				numero[i++] = num;
			}
			else
			{
				k--;
			}
		}
		reg = atoi(numero);
		if( reg < ri || reg > rs )
		{
			printf("\n");
			puts(msgError);
			i=0;
			reg=0;
		}
		
		}while( reg < ri || reg > rs );
		printf("\n");
		
		return reg;
}


int Llenasinrepetir(int V[], int n, int V2[])
{
    int i,j=0;
    for(i=0; i < n ; i++)
    {
             if(Secuencial(V2, j, V[i]) == -1)
             {
                           V2[j] = V[i];
                           j++;
             }
    }
    return j;
}

void LlenaVec(int V[], int n)
{
	int i;
	for(i=0; i < n; i++)
	{
		V[i]= (rand()%10) + 11;
	}
	printf("\nVector Llenado\n");
	system("pause");
}


int Secuencial(int V2[], int j, int V)
{
    int i;
    for(i=0; i < j; i++)
    {
             if( V == V2[i] )
             {
                 return i;
             }
    }
    return -1;
}

int SecuencialO(int Valum[],int n, int matri)//busqueda
{
	int i;
	for(i=0; i < n && matri >= Valum[i]; i++)
	{
		if( matri == Valum[i])
		  {
		  	return i;
		  }
	}
	return -1;
}

int busqbinaria(const int arreglo[], int n, int clave)//busqueda
{
	int Iarriba = n-1;
	int Iabajo = 0;
	int Icentro;
	while (Iabajo <= Iarriba)
	{
		Icentro = (Iarriba + Iabajo)/2;
		if (arreglo[Icentro] == clave)
			return Icentro;
		else
			if (clave < arreglo[Icentro])
				Iarriba=Icentro-1;
			else
				Iabajo=Icentro+1;
	}
	return -1;
}

void Burbuja(int Valum[], int n)//ordenar
{
	int i,j;
	int aux;

	for(i=0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			if(Valum[i] < Valum[j])
			  {
			  	aux	= Valum[i];
				Valum[i] = Valum[j];
				Valum[j] = aux;
			  }
		}
	}
}

void servicio(Tnodo temp)
{
	printf("\n%d \n\n",temp->dato);
	system("PAUSE");
}




