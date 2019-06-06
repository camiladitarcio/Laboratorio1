#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
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
    int opcionMenu;
    LinkedList* listaEmpleados = ll_newLinkedList();
   
        do{
        utn_getSignedNumber("
        1)\nAbrir archivo modo texto
        2)\nAbrir archivo modo binario
        3)\nAgregar 
        4)\nModificar
        5)\nDar de baja
        6)\nListar
        7)\nOrdenar
        8)\nGuardar(modo texto)
        9)\nGuardar(modo binario)
       10)\nSalir","\n--ERROR--",
       1,10,3,&opcionMenu);
        switch(opcionMenu)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                 break;
            case 5:
                 break;
            case 6:
                 break;
            case 7:
                 break;
            case 8:
                 break;
            case 9:
                 break;
        }
    }while(opcionMenu!=10);

    return 0;
}
