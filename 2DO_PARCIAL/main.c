#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entrega.h"
#include "utn.h"

int main()
{
    LinkedList* listaEntrega = ll_newLinkedList();
    controller_loadFromText("data.csv",listaEntrega);
    controller_saveAsText("datacpy.csv", listaEntrega);
    return 0;
}
