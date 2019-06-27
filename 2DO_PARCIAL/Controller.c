#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entrega.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return (0) si logra abrir el archivo - (-1) ERROR
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEntrega)
{
    int ret = -1;
    FILE* pFile;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        parser_EntregaFromText(pFile,pArrayListEntrega);
        ret = 0;
    }
    fclose(pFile);
    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int 1
 *
 */
int controller_ListEntrega(LinkedList* pArrayListEntrega)
{
    FILE* file = fopen("data.csv","r");
    Entrega* pEntrega;
    int i;
    int len = ll_len(pArrayListEntrega);
    int auxId;
    char auxTipo[128];
    int auxCant;
    int auxPeso;

    if(pArrayListEntrega!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pEntrega = ll_get(pArrayListEntrega,i);
            entrega_getId(pEntrega,&auxId);
            entrega_getTipo(pEntrega,auxTipo);
            entrega_getCant(pEntrega,&auxCant);
            entrega_getPeso(pEntrega,&auxPeso);

            printf("%d , %s , %d , %d\n",auxId,auxTipo,auxCant,auxPeso);
        }
    }
    fclose(file);
    return 1;
}

/* ---------------------------------------------- */
int controller_calcularTotalEntregas(LinkedList* pArrayListEntrega, int* totalEntregas)
{
    int returnAux = -1;
    int size = ll_len(pArrayListEntrega);

    if(pArrayListEntrega!=NULL && size>0)
    {
        printf("%d",size);
    }
        *totalEntregas = size;
    return returnAux;
}

int controller_calcularMaximoBultosEntregados(LinkedList* pArrayListEntrega, int* maximo)
{
    int returnAux = -1;
    int i;
    int size = ll_len(pArrayListEntrega);
    int auxCant;
    int bufferMax = 0;
    Entrega* pEntrega;

    if(pArrayListEntrega!=NULL)
    {
        for(i=0;i<size;i++)
        {
            pEntrega = ll_get(pArrayListEntrega,i);
            entrega_getCant(pEntrega,&auxCant);
            if(auxCant>bufferMax)
            {
                bufferMax = auxCant;
            }

        }
           *maximo = bufferMax;
    }
    return returnAux;
}

int controller_PromedioEntregas(LinkedList* pArrayListEntrega, int* promedioEntregas)
{
    int returnAux = -1;
    int i;
    int size = ll_len(pArrayListEntrega);
    int acum = 0;
    int auxCant;
    Entrega* pEntrega;
    float promedio;

    if(pArrayListEntrega!=NULL)
    {
        for(i=0;i<size;i++)
        {
            pEntrega = ll_get(pArrayListEntrega,i);
            entrega_getCant(pEntrega,&auxCant);
            acum = acum+auxCant;
        }
            printf("%d",acum);
            if(acum>0)
            {
                returnAux = 0;
            }

            promedio = acum/3;
            *promedioEntregas = promedio;

    }
    return returnAux;
}


int controller_PromedioPeso(LinkedList* pArrayListEntrega, int* promedioPeso)
{
    int returnAux = -1;
    int i;
    int size = ll_len(pArrayListEntrega);
    int acum = 0;
    int auxPeso;
    Entrega* pEntrega;
    float promedio;

    if(pArrayListEntrega!=NULL)
    {
        for(i=0;i<size;i++)
        {
            pEntrega = ll_get(pArrayListEntrega,i);
            entrega_getPeso(pEntrega,&auxPeso);
            acum = acum+auxPeso;
        }
            printf("%d",acum);

            promedio = acum/3;
            *promedioPeso = promedio;

    }
    return returnAux;
}


int controller_calcularEntregasPorTipo(LinkedList* pArrayListEntrega, int* STD, int* EXP, int* ECO)
{
    int i;
    char bufferTipo[128];
    int size = ll_len(pArrayListEntrega);
    int acumSTD = 0;
    int acumEXP = 0;
    int acumECO = 0;
    Entrega* pEntrega;

    if(pArrayListEntrega!=NULL)
    {
        for(i=0;i<size;i++)
        {
            pEntrega = ll_get(pArrayListEntrega,i);
            if(pEntrega!=NULL)
            {

            entrega_getTipo(pEntrega,bufferTipo);
            if(strcmp(bufferTipo,"STD")==0)
            {
                acumSTD++;
            }
            else if(strcmp(bufferTipo,"EXP")==0)
            {
                acumEXP++;
            }
            else if(strcmp(bufferTipo,"ECO")==0)
            {
                acumECO++;
            }
        }
        }
            *STD = acumSTD;
            *EXP = acumEXP;
            *ECO = acumECO;
    }
    return 0;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int (0) si logra guardar cada empleado desde el archivo - (-1) ERROR
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEntrega)
{
    int totalEntregas;
    int STD;
    int EXP;
    int ECO;
    int maximo;
    int promedioE;
    int promedioP;

    controller_calcularTotalEntregas(pArrayListEntrega,&totalEntregas);
    controller_calcularMaximoBultosEntregados(pArrayListEntrega, &maximo);
    controller_calcularEntregasPorTipo(pArrayListEntrega, &STD, &EXP, &ECO);
    controller_PromedioEntregas(pArrayListEntrega, &promedioE);
    controller_PromedioPeso(pArrayListEntrega, &promedioP);
    FILE* file = fopen(path,"w+");

    if(file!=NULL)
    {
         fprintf(file,"total entregas: %d\n",totalEntregas);
         fprintf(file,"STD: %d, EXP: %d, ECO: %d\n", STD, EXP, ECO);
         fprintf(file,"maximo: %d\n",maximo);
         fprintf(file,"promedio entregas: %d\n",promedioE);
         fprintf(file,"promedio peso: %d\n",promedioP);
    }
    fclose(file);
    return 0;
}
