#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"

static int cont=0;
static int generarID(void)
{
    cont++;
    return cont;
}

void employee_inicializarIdInicial(int val)
{
    val=cont;
}

Employee* per_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* p = per_new();
    if(p!=NULL)
    {
        employee_setIdString(p,*idStr);
        employee_setNombre(p, nombreStr);
        employee_setHorasTrabajadasString(p, *horasTrabajadasStr);
        employee_setSueldoString(p, *sueldo);
    }
    return 0;
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

/*
int employee_alta(Employee* array[], int size)
{
    int posLibre;
    char auxNombre[40];
    int auxHorasTrabajadas[40];
    int auxSueldo;
    int auxId;

    if(array!=NULL && size>0)
    {
        Employee_buscarLibre(array,size,&posLibre);
        auxId = generarID();
        utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxNombre);
        utn_getName("\nIngrese hr trabajadas:","\nERROR",0,25,2,&auxHorasTrabajadas);
        utn_getSignedInt("\nIngrese sueldo:","\nERROR",1,4,1,35000,2,&auxSueldo);
        employee_newParametros(auxId,auxNombre,&auxHorasTrabajadas,&auxSueldo);
    }
    return 0;
}
*/

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

/*
int employee_modificar(Employee* array[], int size)
{
    int ret = -1;
    int i;
    int idBuscado;
    int pos;
    int opcionMenu;
    char auxNombre[40];
    char auxApellido[40];
    int auxEdad;
    Employee* pAux;

    if(array!=NULL && size>0)
    {
        utn_getSignedInt("\nIngrese edad:","\nERROR",1,3,1,size,2,&idBuscado);
        Employee_buscarID(array,size,idBuscado,&pos);
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
                    Employee_getNombre(pAux,auxNombre);
                    break;

                    case 2:
                    utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxApellido);
                    Employee_getApellido(pAux,auxApellido);
                    break;

                    case 3:
                    utn_getSignedInt("\nIngrese edad:","\nERROR",1,4,1,99,2,&auxEdad);
                    Employee_getEdad(pAux,&auxEdad);
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
*/
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

int employee_setIdString(Employee* this,char id)
{
    char auxId;
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        strcpy(auxId,id);
        atoi(auxId);
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

int employee_setSueldoString(Employee* this,char sueldo)
{
    int auxSueldo;
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        auxSueldo=atoi(sueldo);
        this->id = auxSueldo;
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

int employee_setHorasTrabajadasString(Employee* this,char horasTrabajadas)
{
    int auxHorasTrabajadas;
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        auxHorasTrabajadas=atoi(horasTrabajadas);
        this->id = auxHorasTrabajadas;
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


