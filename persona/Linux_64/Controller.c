#include <stdio.h>
#include <stdlib.h>
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
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee); // pasa a la memoria
        ret = 0;
    }
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
            auxId = employee_generarID();
            utn_getName("\nIngrese nombre:","\nERROR",1,40,2,auxNombre);
            utn_getSignedInt("\nIngrese hr trabajadas:","\nERROR",0,6,1,24,2,&auxHorasTrabajadas);
            utn_getSignedInt("\nIngrese sueldo:","\nERROR",1,4,1,35000,2,&auxSueldo);

            employee_newParametrosInt(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            ret = 0;
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
    return 1;
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
    return 1;
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
    return 1;
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
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    Employee* pEmpleado; //acá guardo data de empleado -id nombre sueldo horas-
    FILE* file = fopen("a.csv","w+");

    if(file!=NULL)
    {
        len = ll_len(pArrayListEmployee);
        fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<len;i++)
        {
         //   printf("%d",i);
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&auxId);
            employee_getNombre(pEmpleado,auxNombre);
            employee_getHorasTrabajadas(pEmpleado,&auxHoras);
            employee_getSueldo(pEmpleado,&auxSueldo);


            fprintf(file,"%d , %s , %d , %d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
            fclose(file);
    }
    return 1;
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
