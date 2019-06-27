int controller_loadFromText(char* path , LinkedList* pArrayListEntrega);
int controller_ListEntrega(LinkedList* pArrayListEntrega);
int controller_calcularTotalEntregas(LinkedList* pArrayListEntrega, int* totalEntregas);
int controller_ListEntrega(LinkedList* pArrayListEntrega);
int controller_calcularEntregasPorTipo(LinkedList* pArrayListEntrega, int* STD, int* EXP, int* ECO);
int controller_PromedioPeso(LinkedList* pArrayListEntrega, int* promedioPeso);
int controller_PromedioEntregas(LinkedList* pArrayListEntrega, int* promedioEntregas);
int controller_saveAsText(char* path, LinkedList* pArrayListEntrega);
int controller_calcularMaximoBultosEntregados(LinkedList* pArrayListEntrega, int* maximo);


