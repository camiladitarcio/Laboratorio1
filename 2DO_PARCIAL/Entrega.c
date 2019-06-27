#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Entrega.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

static int cont=1000;

/** \brief Genera el ID empleado de manera correlativa
 *
 * \param void
* \return int cont - numero de ID
 *
 */
int entrega_generarId(void)
{
    cont++;
    return cont;
}

/** \brief Reserva un espacio de memoria para un nuevo empleado
 *
 * \param void
 * \return Devuelvo el espacio en memoria
 *
 */
Entrega* entrega_new(void)
{
    return (Entrega*) malloc(sizeof(Entrega));
}

/** \brief Genera un nuevo empleado a traves de parametros solamente del tipo CHAR*
 *
 * \param char* ID empleado
 * \param char* NOMBRE empleado
 * \param char* HORAS empleado
 * \param char* SUELDO empleado
 * \return puntero a espacio de memoria donde esta ubicado el nuevo empleado
 *
 */
Entrega* entrega_newParametros(char* idStr,char* tipoStr,char* cantStr,char* peso)
{
    Entrega* p = entrega_new();
    if(p!=NULL)
    {
        //printf("%s\n",idStr);
        if(entrega_setIdString(p,idStr)==-1 ||
        entrega_setTipo(p, tipoStr)==-1 ||
        entrega_setCantString(p,cantStr)==-1 ||
        entrega_setPesoString(p,peso)==-1)
        {
            entrega_delete(p);
        }
    }
    return p;
}

/** \brief Genera un nuevo empleado a traves de parametros del tipo CHAR* y del tipo INT
 *
 * \param int ID empleado
 * \param char* NOMBRE empleado
 * \param int HORAS empleado
 * \param int SUELDO empleado
 * \return puntero a espacio de memoria donde esta ubicado el nuevo empleado
 *
 */
Entrega* entrega_newParametrosInt(int idStr,char* tipoStr,int cantStr,int peso)
{
    Entrega* p = entrega_new();
    if(p!=NULL)
    {
       // printf("%s\n",idStr);
        if(entrega_setId(p,idStr)==-1 ||
        entrega_setTipo(p, tipoStr)==-1 ||
        entrega_setCant(p,cantStr)==-1 ||
        entrega_setPeso(p,peso)==-1)
        {
            entrega_delete(p);
        }

    }
    return p;
}

/** \brief Libera el espacio de memoria donde esta ubicado un empleado - lo elimina
 *
 * \param Empleado a borrar
 * \return void
 *
 */
void entrega_delete(Entrega* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Guarda ID de empleado del tipo INT
 *
 * \param puntero a empleado
 * \param int ID empleado
 * \return int (0) si logra guardar correctamente ID de empleado - (-1) ERROR
 */
int entrega_setId(Entrega* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


/** \brief Guarda ID de empleado del tipo CHAR*
 *
 * \param puntero a empleado
 * \param int ID empleado
 * \return int (0) si logra guardar correctamente ID de empleado - (-1) ERROR
 */
int entrega_setIdString(Entrega* this,char* id)
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

/** \brief Obtiene ID de empleado
 *
 * \param puntero a empleado
 * \param int donde se guardará ID de empleado
 * \return int (0) si logra devolver correctamente ID de empleado - (-1) ERROR
 */
int entrega_getId(Entrega* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


/** \brief Guarda SUELDO de empleado de tipo INT
 *
 * \param puntero a empleado
 * \param int SUELDO empleado
 * \return int (0) si logra guardar correctamente SUELDO de empleado - (-1) ERROR
 */
int entrega_setPeso(Entrega* this, int peso)
{
    int retorno = -1;
    if(this != NULL && peso >= 0)
    {
        this->peso = peso;
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda SUELDO de empleado de tipo CHAR*
 *
 * \param puntero a empleado
 * \param int SUELDO empleado
 * \return int (0) si logra guardar correctamente SUELDO de empleado - (-1) ERROR
 */
int entrega_setPesoString(Entrega* this,char* peso)
{
    int auxPeso;
    int retorno = -1;
    if(this != NULL && peso >= 0)
    {
        auxPeso=atoi(peso);
        this->peso = auxPeso;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene SUELDO de empleado
 *
 * \param puntero a empleado
 * \param int SUELDO empleado
 * \return int (0) si logra obtener correctamente SUELDO de empleado - (-1) ERROR
 */
int entrega_getPeso(Entrega* this, int* peso)
{
    int retorno = -1;
    if(this != NULL && peso != NULL)
    {
        *peso = this->peso;
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda NOMBRE de empleado
 *
 * \param puntero a empleado
 * \param char* NOMBRE empleado
 * \return int (0) si logra guardar correctamente SUELDO de empleado - (-1) ERROR
 */
int entrega_setTipo(Entrega* this, char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene NOMBRE de empleado
 *
 * \param puntero a empleado
 * \param char* NOMBRE empleado
 * \return int (0) si logra obtener correctamente SUELDO de empleado - (-1) ERROR
 */
int entrega_getTipo(Entrega* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}



/** \brief Guarda HORAS TRABAJADAS de empleado de tipo INT
 *
 * \param puntero a empleado
 * \param int HORAS TRABAJADAS empleado
 * \return int (0) si logra guardar correctamente HORAS TRABAJADAS de empleado - (-1) ERROR
 */
int entrega_setCant(Entrega* this, int cant)
{
    int retorno = -1;
    if(this != NULL && cant >= 0)
    {
        this->cant = cant;
        retorno = 0;
    }
    return retorno;
}


/** \brief Guarda HORAS TRABAJADAS de empleado de tipo CHAR*
 *
 * \param puntero a empleado
 * \param char* HORAS TRABAJADAS empleado
 * \return int (0) si logra guardar correctamente HORAS TRABAJADAS de empleado - (-1) ERROR
 */
int entrega_setCantString(Entrega* this,char* cant)
{
    int auxCant;
    int retorno = -1;
    if(this != NULL && cant >= 0)
    {
        auxCant=atoi(cant);
        this->cant = auxCant;
        retorno = 0;
    }
    return retorno;
}


/** \brief Obtiene HORAS TRABAJADAS de empleado de tipo INT
 *
 * \param puntero a empleado
 * \param int guarda HORAS TRABAJADAS empleado
 * \return int (0) si logra obtener correctamente HORAS TRABAJADAS de empleado - (-1) ERROR
 */
int entrega_getCant(Entrega* this,int* cant)
{

    int retorno = -1;
    if(this != NULL && cant >= 0)
    {
        *cant = this->cant;
        retorno = 0;
    }
    return retorno;
}


/** \brief Ordena empleado según su NOMBRE
 *
 * \param Tipo A
 * \param Tipo B
 * \return int (0) si no logra ordenar empleados - (1) Si logra ordenar de manera ascendente - (-1) si logra ordenar de manera descendente
 */
int entrega_criterioTipo(void* thisA,void* thisB)
{
    char tipoA[128];
    char tipoB[128];
    int ret = 0;

    entrega_getTipo((Entrega*)thisA,tipoA);
    entrega_getTipo((Entrega*)thisB,tipoB);

        if(strcmp(tipoA,tipoB)>0)
        {
            ret = 1;
        }
        else if(strcmp(tipoA,tipoB)<0)
        {
            ret = -1;
        }
    return ret;
}
