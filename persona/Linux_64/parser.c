#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    Employee *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            pEmpleado = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

            if(pEmpleado != NULL)
            {
                if(!ll_add(pArrayListEmployee,pEmpleado))
                {
                    //printf("OK2");
                }
            }
        }
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *pEmpleado;

    if(pFile!=NULL){
        do{
            pEmpleado = employee_new();
            if(pEmpleado!=NULL && (fread(pEmpleado,sizeof(Employee),1,pFile)== 1))
            {
                ll_add(pArrayListEmployee,pEmpleado);
            }
            else
            {
               employee_delete(pEmpleado);
            }
        }while(feof(pFile));
     }
    return 1;
}
