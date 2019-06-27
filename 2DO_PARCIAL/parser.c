#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entrega.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int (0) si logra leer correctamente los datos de archivo - (-1) ERROR
 *
 */
int parser_EntregaFromText(FILE* pFile , LinkedList* pArrayListEntrega)
{
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCant[4096];
    char bufferPeso[4096];
    Entrega *pEntrega;
    int ret = -1;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTipo,bufferCant,bufferPeso);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTipo,bufferCant,bufferPeso);

            pEntrega = entrega_newParametros(bufferId,bufferTipo,bufferCant,bufferPeso);

            if(pEntrega != NULL)
            {
                ll_add(pArrayListEntrega,pEntrega);
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntrega LinkedList*
 * \return int (0) si logra leer correctamente los datos de archivo - (-1) ERROR
 *
 */
int parser_EntregaFromBinary(FILE* pFile , LinkedList* pArrayListEntrega)
{
    int ret = -1;
    Entrega *pEntrega;
    int bufferInt;
    int maxId=-1;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pEntrega = entrega_new();
            if(pEntrega!=NULL && fread(pEntrega,sizeof(Entrega),1,pFile) && ll_add(pArrayListEntrega,pEntrega)==0)
            {
                entrega_getId(pEntrega,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId = bufferInt;
                }
                ret = 0;
            }
            else
            {
                entrega_delete(pEntrega);
            }
        }
    }
    return ret;
}
