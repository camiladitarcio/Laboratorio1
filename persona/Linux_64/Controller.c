#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int len;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee); // pasa a la memoria
        ret = 0;
    }
    len = ll_len(pArrayListEmployee);
    printf("\nlen: %d",len);
    fclose(pFile);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* file;
    file = fopen(path,"rb");

    if(file!=NULL)
    {
        ret = parser_EmployeeFromBinary(file,pArrayListEmployee);
    }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxNombre[40];
    int auxHorasTrabajadas;
    int auxSueldo;
    int auxId;
    int ret = -1;
    Employee* pEmpleado;

    if(pArrayListEmployee!=NULL)
    {
            pEmpleado = employee_new();
            if(pEmpleado!=NULL)
            {
                auxId = employee_generarId();
                if(!utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxNombre) &&
                   !utn_getSignedInt("\nIngrese hr trabajadas:","\nERROR",0,6,1,24,2,&auxHorasTrabajadas) &&
                   !utn_getSignedInt("\nIngrese sueldo:","\nERROR",1,6,1,35000,2,&auxSueldo))
                    {
                            if( !employee_setId(pEmpleado,auxId) &&
                                !employee_setNombre(pEmpleado,auxNombre) &&
                                !employee_setHorasTrabajadas(pEmpleado,auxHorasTrabajadas) &&
                                !employee_setSueldo(pEmpleado,auxSueldo))
                                {
                                    ll_add(pArrayListEmployee,pEmpleado);
                                    printf("Se ha agregado un empleado");
                                    ret = 0;
                                }
                                else
                                {
                                    employee_delete(pEmpleado);
                                    printf("No se ha podido agregar el empleado");
                                }
                    }
            }
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int ret = -1;
    int len;
    int id;
    int option;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        utn_getSignedInt("Ingrese ID de empleado que quiera modificar:\n","--ERROR--\n",1,6,0,len,2,&id);
        id=id-1; // me toma un id de mas (ingreso 2, modifica 3)
        pEmpleado = ll_get(pArrayListEmployee,id);

        if(pEmpleado!=NULL)
        {
            do
            {
                utn_getSignedInt("Ingrese el parametro que desea modificar:\n 1)NOMBRE - 2)HORAS TRABAJADAS - 3)SUELDO - 4)SALIR\n","--ERROR--\n",1,3,1,4,2,&option);
                switch(option)
                {
                case 1:
                    if(!utn_getName("Ingrese nuevo nombre:\n","--ERROR--\n",1,128,2,auxNombre))
                    {
                        strncpy(pEmpleado->nombre,auxNombre,sizeof(auxNombre));
                        printf("Se ha modificado el nombre del empleado %d",id);
                        ret = 0;
                    }
                    break;
                case 2:
                    utn_getSignedInt("Ingrese nuevas Horas Trabajadas:\n","--ERROR--\n",0,5,0,1000,2,&auxHorasTrabajadas);
                    pEmpleado->horasTrabajadas = auxHorasTrabajadas;
                    break;
                case 3:
                    utn_getSignedInt("Ingrese nuevo sueldo:\n","--ERROR--\n",0,6,0,35000,2,&auxSueldo);
                    pEmpleado->sueldo = auxSueldo;
                    break;
                }
            }while(option!=4);
        }
        else
        {
            printf("No se ha encontrado empleado con ese ID");
        }
    }
    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int i;
    int ret=-1;
    int len;
    int id;
    int auxId;

    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        if(!utn_getSignedInt("\nIngrese ID de empleado que desee modificar:\n","\n--ERROR--",0,6,0,len,2,&auxId))
            printf("\n%d",auxId);
        {
            for(i=0;i<len;i++)
            {
                pEmpleado = ll_get(pArrayListEmployee,i);
                if(pEmpleado!=NULL)
                {
                    employee_getId(pEmpleado,&id);
                    if(id==auxId)
                    {
                        ll_remove(pArrayListEmployee,i);
                        ret = 0;
                        printf("\nSe ha eliminado un empleado\n");
                    }
                    else
                    {
                        printf("\nNo se ha encontrado empleado con ese ID");
                    }
                }

             }
        }
    }
    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    FILE* file = fopen("data.csv","r");
    Employee* pEmpleado;
    int i;
    int len = ll_len(pArrayListEmployee);
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee!=NULL)
    {
        for(i=0;i<len;i++)
        {
         //   printf("%d",i);
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&auxId);
            employee_getNombre(pEmpleado,auxNombre);
            employee_getHorasTrabajadas(pEmpleado,&auxHorasTrabajadas);
            employee_getSueldo(pEmpleado,&auxSueldo);

            printf("%d , %s , %d , %d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        }
    }
    fclose(file);
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_criterioNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) //acá guardo direccion de memoria de empleado
{
    int len;
    int i;
    int ret = -1;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    Employee* pEmpleado; //acá guardo data de empleado -id nombre sueldo horas-
    FILE* file = fopen(path,"w+");

    if(file!=NULL)
    {
        len = ll_len(pArrayListEmployee);
        fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<len;i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            if(pEmpleado!=NULL)
            {
                if(!employee_getId(pEmpleado,&auxId) &&
                !employee_getNombre(pEmpleado,auxNombre) &&
                !employee_getHorasTrabajadas(pEmpleado,&auxHoras) &&
                !employee_getSueldo(pEmpleado,&auxSueldo))
                {
                    fprintf(file,"%d , %s , %d , %d\n",auxId,auxNombre,auxHoras,auxSueldo);
                    ret = 0;
                }
            }
        }
        fclose(file);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    return 1;
}


/*
    no usamos mas arrays, a partir de ahora se ubica en una posicion a traves de una funcion:
    ll_get ll_add ll_set etc
*/
