#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

static int cont=1000;

int employee_generarId(void)
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
        //printf("%s\n",idStr);
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

int employee_criterioNombre(void* thisA,void* thisB)
{
    char nombreA[128];
    char nombreB[128];
    int ret = 0;

    employee_getNombre((Employee*)thisA,nombreA);
    employee_getNombre((Employee*)thisB,nombreB);

        if(strcmp(nombreA,nombreB)>0)
        {
            ret = 1;
        }
        else if(strcmp(nombreA,nombreB)<0)
        {
            ret = -1;
        }
    return ret;
}
