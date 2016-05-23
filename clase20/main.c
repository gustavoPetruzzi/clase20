#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nombre[32];
    int edad;
}ePersona;
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);


int main()
{

    ePersona * miPersona;
    int auxInt;
    ePersona arrayPersonas[2];
    int i;
    for(i=0;i<2;i++)
    {
        miPersona = (ePersona*) malloc(sizeof(ePersona));
        do
        {
            auxInt = getInt(&(miPersona->edad), "Ingrese una edad: ", "Error: maximo 99 años", 0, 100);
        }while(auxInt!=0);

        do
        {
            auxInt = getName((miPersona->nombre), "Ingrese un nombre: ", "Error: maximo 30 caracteres", 0, 31);
        }while(auxInt!=0);

        arrayPersonas[i] = *miPersona;
    }
        for(i=0;i<2;i++)
        {
            printf("Nombre: %s\t\tEdad:%d\n", arrayPersonas[i].nombre, arrayPersonas[i].edad);
        }


    return 0;
}








int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxInt;
    int flag = -1;
    int resp;
    printf("%s", message);
    fflush(stdin);          // Se pone bandera por si nos olvidamos un return
    resp = scanf("%d", &auxInt);
    if(resp == 1)
    {
        if(auxInt > lowLimit && auxInt < hiLimit)
        {
            *input = auxInt;
            flag = 0;

        }
    }

    if(flag == -1)
    {
        printf("%s", eMessage);
    }

    return flag;
}







int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    int flagName = 1;
    int i;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%s", auxChar);
    if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
    {
        for(i= 0; i< strlen(auxChar); i ++)
        {
            auxChar[i] = tolower(auxChar[i]);
            if(auxChar[i] < 'a' || auxChar[i] >'z')
            {
                flagName = 0;
                break;
            }
        }
    }
    else
    {
        flagName = 0;
    }
    if(flagName)
    {
        auxChar[0] = toupper(auxChar[0]);
        strcpy(input, auxChar);
        return 0;
    }

    system("cls");
    printf("%s", eMessage);
    return -1;
}
