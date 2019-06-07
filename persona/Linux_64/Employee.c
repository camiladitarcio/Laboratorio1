#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

static int cont=1000;

int employee_generarID(void)
{
    cont++;
    return cont;
}

void employee_inicializarIdInicial(int val)
{
    val=cont;
}

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* p = employee_new();
    if(p!=NULL)
    {
       // printf("%s\n",idStr);
        if(employee_setIdString(p,idStr)==-1 ||
        employee_setNombre(p, nombreStr)==-1 ||
        employee_setHorasTrabajadasString(p,horasTrabajadasStr)==-1 ||
        employee_setSueldoString(p,sueldo)==-1)
        {
            employee_delete(p);
        }

    }
    return p;
}

Employee* employee_newParametrosInt(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldo)
{
    Employee* p = employee_new();
    if(p!=NULL)
    {
       // printf("%s\n",idStr);
        if(employee_setId(p,idStr)==-1 ||
        employee_setNombre(p, nombreStr)==-1 ||
        employee_setHorasTrabajadas(p,horasTrabajadasStr)==-1 ||
        employee_setSueldo(p,sueldo)==-1)
        {
            employee_delete(p);
        }

    }
    return p;
}

int employee_inicializar(Employee* array[], int size)
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

int employee_buscarLibre(Employee* array[], int size, int* posicion)
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

int employee_buscarID(Employee* array[], int size, int valorBuscado, int* posicion)
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
// VALIDAR SETS CON UTN IS_VALIDNUMBER O IS_VALIDSTRING
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setIdString(Employee* this,char* id)
{
    int auxId;
    int retorno = -1;
    if(this != NULL && isValidNumber(id))
    {
        auxId = atoi(id);
       // printf("%d\n",auxId);
        this->id = auxId;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoString(Employee* this,char* sueldo)
{
    int auxSueldo;
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        auxSueldo=atoi(sueldo);
        this->sueldo = auxSueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasString(Employee* this,char* horasTrabajadas)
{
    int auxHorasTrabajadas;
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        auxHorasTrabajadas=atoi(horasTrabajadas);
        this->horasTrabajadas = auxHorasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {

        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}



int employee_listar(Employee* array[],int size)
{
    int i;

    if(array!=NULL&&size>0)
    {
        for(i=0;i<size;i++)
        {
            printf("\nNombre: %s\tHoras Trabajadas: %d\tSueldo: %d",array[i]->nombre,array[i]->horasTrabajadas,array[i]->sueldo);
        }
    }

    return 0;
}

int employee_parser(LinkedList* pArrayListEmployeesonas, int size, char* fileName)
{
    char aux[512];
    char auxId[512];
    char auxNombre[512];
    char auxHorasTrabajadas[512];
    char auxSueldo[512];
    int r;
    int index=-1;

    Employee* pEmployee;
    FILE* file;
    file = fopen(fileName,"r"); // o tambien: FILE* file = fopen(fileName,"r");

    if(file!=NULL)
    {
        fscanf(file,"%[^\n]\n",aux); //saltea linea
        //fgets(aux,512,file) //saltea linea
        do
        {
            r = fscanf(file,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            if(r==4)
            {
                pEmployee=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo); // todas cadenas // devuelve direccion de puntero
                if(pEmployee!=NULL)
                {
                        index++;
                }//printf("%s %s %s %s\n",auxId,auxNombre,auxApellido,auxEdad);
            }// }while(feof(file)==0)
        }while(!feof(file));
    }
    fclose(file);
    return index;
}


