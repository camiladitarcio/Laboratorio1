#ifndef entrega_H_INCLUDED
#define entrega_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cant; //horas
    int peso; //sueld
}Entrega;

Entrega* entrega_new();
Entrega* entrega_newParametros(char* idStr,char* tipoStr,char* CantStr,char* peso);
Entrega* entrega_newParametrosInt(int idStr,char* tipoStr,int CantStr,int peso);
void entrega_delete(Entrega* this);
int entrega_criterioTipo(void* thisA,void* thisB);
int entrega_generarId(void);

int entrega_setId(Entrega* this,int id);
int entrega_setIdString(Entrega* this,char* id);
int entrega_getId(Entrega* this,int* id);

int entrega_setTipo(Entrega* this,char* tipo);
int entrega_getTipo(Entrega* this,char* tipo);

int entrega_setCant(Entrega* this,int Cant);
int entrega_setCantString(Entrega* this,char* Cant);
int entrega_getCant(Entrega* this,int* Cant);

int entrega_setPeso(Entrega* this,int peso);
int entrega_setPesoString(Entrega* this,char* peso);
int entrega_getPeso(Entrega* this,int* peso);

#endif // entrega_H_INCLUDED
