//-new
//-newparametres
//delete
//set/get
//amb
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"

static int cont=0;
static int generarID(void)
{
    cont++;
    return cont;
}

void Per_inicializarIdInicial(int val)
{
    val=cont;
}

Persona* per_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* per_newParametros(int id, char* nombre, char* apellido, int edad)
{
    Persona* p = per_new();
    if(p!=NULL)
    {
        Per_setNombre(p, nombre);
        Per_setApellido(p, apellido);
        Per_setEdad(p, edad);
    }
    return 0;
}

int Per_inicializar(Persona* array[], int size)
{
    int i;
    int ret = -1;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {

            array[i] = NULL;
        }
    ret = 0;
    }
    return ret;
}

int Per_buscarLibre(Persona* array[], int size, int* posicion)
{
    int i;
    int ret = -1;
    if(array!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i]==NULL)
            {
                *posicion = i;
                ret = 0;
                break;
            }
        }
    }
    return ret;
}

int Per_alta(Persona* array[], int size)
{
    int posLibre;
    char auxNombre[40];
    char auxApellido[40];
    int auxEdad;
    int auxId;

    if(array!=NULL && size>0)
    {
        Per_buscarLibre(array,size,&posLibre);
        auxId = generarID();
        utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxNombre);
        utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxApellido);
        utn_getSignedInt("\nIngrese edad:","\nERROR",1,4,1,99,2,&auxEdad);
        per_newParametros(auxId,auxNombre,auxApellido,auxEdad);
    }
    return 0;
}

int Per_buscarID(Persona* array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i]->id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


int Per_modificar(Persona* array[], int size)
{
    int ret = -1;
    int i;
    int idBuscado;
    int pos;
    int opcionMenu;
    char auxNombre[40];
    char auxApellido[40];
    int auxEdad;
    Persona* pAux;

    if(array!=NULL && size>0)
    {
        utn_getSignedInt("\nIngrese edad:","\nERROR",1,3,1,size,2,&idBuscado);
        Per_buscarID(array,size,idBuscado,&pos);
        for(i=0;i<size;i++)
        {
            if(array[i]->id==idBuscado)
            {
                utn_getSignedInt("\nMODIFICAR: 1(nombre) 2(apellido) 3(edad) 4(salir)","\nERROR",1,4,1,4,2,&opcionMenu);
                do{
                switch(opcionMenu)
                    {
                    case 1:
                    utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxNombre);
                    Per_getNombre(pAux,auxNombre);
                    break;

                    case 2:
                    utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxApellido);
                    Per_getApellido(pAux,auxApellido);
                    break;

                    case 3:
                    utn_getSignedInt("\nIngrese edad:","\nERROR",1,4,1,99,2,&auxEdad);
                    Per_getEdad(pAux,&auxEdad);
                    break;

                    default:
                    printf("No es una opcion valida");
                    }
                }while(opcionMenu!=4);
                ret = 0;
            }
            else
            {
                printf("\nNo se ha encontrado ese ID");
            }
        }
    }
    return ret;
}

int Per_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Per_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Per_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Per_setEdad(Persona* this, int edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 0)
    {
        this->edad = edad;
        retorno = 0;
    }
    return retorno;
}

int Per_getEdad(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->edad;
        retorno = 0;
    }
    return retorno;
}

int Per_setNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Per_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int Per_setApellido(Persona* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int Per_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int Per_listar(Persona* array[],int size)
{
    int i;

    if(array!=NULL&&size>0)
    {
        for(i=0;i<size;i++)
        {
            printf("\nNombre: %s\tApellido: %s\tEdad: %d",array[i]->nombre,array[i]->apellido,array[i]->edad);
        }
    }

    return 0;
}

int Per_parser(Persona* array[], int size, char* fileName)
{
    char aux[512];
    char auxId[512];
    char auxNombre[512];
    char auxApellido[512];
    char auxEdad[512];
    int r;
    int index=-1;

    Persona* pPersona;
    FILE* file;
    file = fopen(fileName,"r"); // o tambien: FILE* file = fopen(fileName,"r");

    if(file!=NULL)
    {
        fscanf(file,"%[^\n]\n",aux); //saltea linea
        //fgets(aux,512,file) //saltea linea
        do
        {
            r = fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxEdad);
            if(r==4)
            {
                pPersona=per_newParametros(auxId,auxNombre,auxApellido,auxEdad); // todas cadenas // devuelve direccion de puntero
                if(pPersona!=NULL)
                {
                        array[index] = pPersona;
                        index++;
                }//printf("%s %s %s %s\n",auxId,auxNombre,auxApellido,auxEdad);
            }// }while(feof(file)==0)
        }while(!feof(file));
    }
    fclose(file);
    return index;
}
