#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct _tdatoD{
	int dato;
	struct _tdatoD *sig;
	struct _tdatoD *ant;
	}TdatoD;

typedef TdatoD *Tnodo;

typedef struct _templeadoD{
	long matricula;
	char appat[30];
	char apmat[30];
	char nombres[30];
	int edad, sexo;
	struct _templeadoD *sig;
	struct _templeadoD *ant;
	}TempleadoD;

typedef TempleadoD *TnodoempD;

int validanum (int ri, int rs, char *msge, char *msgeerror)
{
	char xnum[30];
	int num;
	do{
		puts (msge);
		fflush (stdin);
		gets(xnum);
		num = atoi(xnum);
		if (num < ri || num > rs)
	   	   {
	   			puts (msgeerror);
	   			system("pause");
	       }

	 }
    while (num < ri || num > rs);
	return num;
}

void Imprimir(Tnodo lista, int cont)
{
    Tnodo temp=NULL;
    int i;
    if(lista)
      {
        temp=lista;
        for(i=0; i<cont; i++)
           {
                servicio(temp);
                temp=temp->sig;
           }
        system("pause");
      }
     else
	  {
	  	printf("\n\nLa lista esta vacia\n\n");
	  	system("pause");
	  }
}

void agregarLD(TnodoD *listaD, TnodoD *nuevo)
{
	TnodoD temp=NULL;
	if(!*listaD)
	  {
	  	*listaD=*nuevo;
	  	*nuevo=NULL;
	  }
	else
	 {
	 	if((*nuevo)->sig < (*listaD)->dato)
	 	  {
	 	  	(*nuevo)->sig=*listaD;
	 	  	*listaD=*nuevo;
	 	  	*nuevo=NULL;
		  }
		 else
		  {
		  	temp=*listaD;
		  	while((temp->sig)->dato < *nuevo->dato)
		  	     {
		  	     	temp=temp->sig;
				 }
			(*nuevo)->sig=temp->sig;
			(*nuevo)->ant=temp;
			temp->sig=*nuevo;
			if(temp->sig)
			  {
			  	(*nuevo->sig)->ant=*nuevo;
			  }
		  }
	 }
}

void Liberar(Tnodoemp lista, int cont)
{
    Tnodoemp temp=NULL;
        int i;
        if(lista)
          {
            temp=lista;
            for(i=0; i<cont; i++)
               {
                    free(temp);
                    temp=temp->sig;
               }
            printf("Memoria liberada\n");
            system("pause");
          }
}

void Liberar2(Tnodo lista, int cont)
{
    Tnodo temp=NULL;
        int i;
        if(lista)
          {
            temp=lista;
            for(i=0; i<cont; i++)
               {
                    free(temp);
                    temp=temp->sig;
               }
            printf("Memoria liberada\n");
            system("pause");
          }
}

TnodoD gendatos (void)
{
	TnodoD temp=NULL;
	temp= (Tnodo)malloc(sizeof(Tdato));
	temp->dato= rand()%1000;
	temp->sig=NULL;
}

TnodoempD gendatosemp (void)
{
    TnodoempD temp=NULL;
    temp= (TnodoempD)malloc(sizeof(TempleadoD));
    int j, f, x, y, k, repe;
    long t;
    char nomh[15][20]= {"CARLOS","ROBERTO","OSCAR","SANTIAGO","SERGIO","XAVIER","ANTONIO","JOSE","ALAN","IVAN","ALFONSO","GIOVANNI", "JUAN","ELVER","ARMANDO"};
    char nomm[15][20]= {"MARIA", "PATRICIA", "KAREN", "KARLA", "MONSERRAT", "XIMENA","PAULINA","CAROLINA","MARTHA","PAOLA","KASANDRA","ROSA","GUADALUPE","VANESSA","GLORIA"};
    char app[15][20]= {"GARCIA", "ROSAS", "GALLARDO", "HERNANDEZ", "LOPEZ", "TORRES","ARAMBULA","VALDOVINOS","ARCE","GOMEZ","RUELAS","PUTIN","YAMAMOTO","YEPIZ","CASTILLO"};
    x= rand()%1000;
    if (x % 2 == 0)
       {
            temp->sexo= 0;
            strcpy(temp->appat, app[rand()%14]);
            strcpy(temp->apmat, app[rand()%14]);
            strcpy(temp->nombres, nomh[rand()%14]);
            y= rand()%1000;
            if (y % 2 == 0)
               {
                    strcat(temp->nombres, "_");
                    strcat(temp->nombres, nomh[rand()%14]);
               }
       }
      else
       {
            temp->sexo= 1;
            strcpy(temp->appat, app[rand()%14]);
            strcpy(temp->apmat, app[rand()%14]);
            strcpy(temp->nombres, nomm[rand()%14]);
            if (y % 2 == 0)
               {
                    strcat(temp->nombres, "_");
                    strcat(temp->nombres, nomm[rand()%14]);
               }
       }
    temp->edad= (rand()%20)+17;
    temp->matricula= (rand()%499)+349000;
    temp->sig=NULL;
}

TnodoempD EliminarEmp(TnodoempD *lista, int matricula)
{
	TnodoempD temp=NULL, nodo1=NULL, nodo2=NULL;
	if(*lista)
	  {
	  	temp=*lista;
	  	if(temp->matricula == matricula)
	  	  {
	  	  	nodo1=temp;
	  	  	nodo2=temp;
	  	  	*lista= temp->sig;
	  	  	nodo1->sig=NULL;
	  	  	nodo->ant=NULL;
		  }
		 else
		  {
		  	while(temp->sig && (temp->sig)->matricula < matricula)
		  	    {
		  	    	temp=temp->sig;
				}
			if(temp->sig && (temp->sig)->matricula == matricula)
			  {
			  	nodo1=temp->sig;
			  	nodo2=temp->ant;
			  	temp->sig=nodo->sig;
			  	temp->ant=nodo->ant;
			  	nodo->sig=NULL;
			  }
		  }
	  }
	return nodo;
}

void servicioemp (TnodoempD temp)
{
    char strsexo[15];
    if (temp->sexo == 0)
       {
            strcpy (strsexo,"MASCULINO");
       }
      else
       {
            if (temp->sexo == 1)
               {
                    strcpy (strsexo,"FEMENINO");
               }
       }
    printf("\n");
    printf("MATRICULA: %ld, NOMBRE: %s %s %s, SEXO: %s, EDAD: %d\n", temp->matricula, temp->appat, temp->apmat, temp->nombres, strsexo, temp->edad);
}

TnodoempD BuscarEmp(Tnodoemp lista, int matricula, int cont)
{
    Tnodoemp temp=NULL;
    int i;
    if(lista)
      {
        temp=lista;
        for(i=0 ; i<cont ; i++)
            {
                if(temp->matricula==matricula)
                  {
                    return temp;
                  }
                temp=temp->sig;
            }
      }
    temp=NULL;
    return temp;
}
