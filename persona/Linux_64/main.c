#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int optionMenu;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

        utn_getSignedInt("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
                        "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
                        "3. Alta de empleado\n"
                        "4. Modificar datos de empleado\n"
                        "5. Baja de empleado\n"
                        "6. Listar empleados\n"
                        "7. Ordenar empleados\n"
                        "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
                        "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
                        "10. Salir\n","--ERROR--\n",0,3,0,11,2,&optionMenu);
        switch(optionMenu)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                //ordenar empleados
                break;
            case 8:
                controller_saveAsText("a.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("abin.csv",listaEmpleados);
                break;
        }
    }while(optionMenu != 10);
    return 0;
}
