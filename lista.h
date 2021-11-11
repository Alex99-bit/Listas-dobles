#define pr printf
#define sc scanf

// Las listas sirven como pilas o colas dependiendo de como se trabajen 

typedef struct{ 
	int d;
}dato;

typedef struct nodo{ // Estructura nodo, con anidacion a estructura dato
	dato info;
	nodo*sig; // Nodo sigiente
	nodo*ant; // Nodo anterior (no se encuentran en listas sencillas)
};

// Prototipos de funcion
void inserta_inicio(nodo **cab);
void inserta_final(nodo **cab);
void inserta_orde(nodo **cab);
void recorre_lista(nodo *cab);
int elimina_ini(nodo **cab);
void elimina_final(nodo **cab);
void elimina_espec(nodo **cab);
void modifica(nodo **cab);
void busqueda(nodo *cab);
nodo* inicializa_nodo(dato info);

// Funcion que apila los nuevos datos
void inserta_inicio(nodo **cab){
	char resp='s';
	 //Nodo auxiliar
	dato info;
	nodo *aux;
	do{ 	
 		pr("Dato:");
 		sc("%d",&info.d);
		aux=inicializa_nodo(info);
		aux->sig=*cab;
		if(*cab!=NULL){
			*cab=aux->ant;
		}
		*cab=aux;
		pr("Otro dato:");
		fflush(stdin);
 		sc("%c",&resp);
	}while(resp=='s');
}

// Funcion que inserta al final de la lista un dato
void inserta_final(nodo **cab){
	nodo *nuevo=NULL, *ultimo;
	dato info;
	pr("\nIngresa Dato:	");
	sc("%d",&info.d);
	nuevo=inicializa_nodo(info);
	if(*cab==NULL){
		*cab=nuevo;
	}
	else{
		ultimo=*cab;
		while(ultimo->sig!=NULL){
			ultimo=ultimo->sig;
		}
		ultimo->sig=nuevo;
		nuevo->ant=ultimo;
	}
}

// Funcion que inserta los datos de una lista de forma ordenada
void inserta_orde(nodo **cab){
	nodo *nuevo, *anterior, *actual;
	dato info;
	pr("\nIngresa dato:	");
	sc("%d",&info.d);
	nuevo=inicializa_nodo(info);
	actual=*cab;
	anterior=*cab;
	while(actual!=NULL && actual->info.d < nuevo->info.d){
		anterior=actual;
		actual=actual->sig;
	}
	if(anterior==NULL || anterior ==actual){
		nuevo->sig=anterior;
		if(anterior!=NULL){
			anterior->ant=nuevo;
		}
		*cab=nuevo;
	}
	else{
		nuevo->sig=actual;
		anterior->sig=nuevo;
		nuevo->ant=anterior;
		if(actual!=NULL){
			actual->ant=nuevo;
		}
	}
}

// Recorre la lista y muestra sus datos
void recorre_lista(nodo *cab){
	nodo *aux=NULL;
	if(cab!=NULL){
		aux=cab;
		while(aux->sig!=NULL){
			pr("%d",aux->info.d);
			aux=aux->sig;
		}
		while(aux!=NULL){
			pr("%d",aux->info.d);
			aux=aux->ant;
		}
	}	
}

// Inicializa el nodo, retorna el valor de nodo nuevo
nodo* inicializa_nodo(dato info){
	nodo *nuevo;
	nuevo=(nodo*)malloc(sizeof(nodo));
	nuevo->info=info;
	nuevo->sig=NULL;
	return nuevo;
}

// Funcion que elimina el primer dato de la lista
int elimina_ini( nodo **cab){
	nodo *aux=NULL;
	if(*cab==NULL){
		return 0;
	}
	else{
	aux=*cab;
	*cab=aux->sig;
	if(*cab!=NULL){
		*cab=aux->ant=NULL;
	}
	free(aux);
	return 1;
	}
}

// Funcion que elimina el ultimo dato de la lista
void elimina_final(nodo **cab){
	nodo *ultimo, *ante;
	dato info;
	if(*cab!=NULL){
		ultimo=*cab;
		ante=*cab;
		while(ultimo->sig!=NULL){
			ante==ultimo;
			ultimo=ultimo->sig;
		}
	if(ante==ultimo){
		*cab=NULL;
	}
	else{
		ante->sig=NULL;
	}
	free(ultimo);
	}
}

// Funcion que elimina un dato especifico
void elimina_espec(nodo **cab){
	int find=0, cve;
	nodo *ultimo, *anterior, *aux, *actual;
	dato info;
	if(*cab==NULL){
		pr("LISTA VACIA");
	}
	else{
		pr("DATO:	");
		sc("%d",cve);
		find=0;
		anterior=*cab;
		ultimo=*cab;
		while(ultimo!=NULL && find==0){
			if(ultimo->info.d==cve && find==0){
				find=1;
			}
			else{
				anterior=ultimo;
				ultimo=ultimo->sig;
			}
		}
		if(find==1){
			if(ultimo==anterior){
				*cab=(*cab)->sig;
				if(*cab!=NULL){
					*cab=aux->ant=NULL;
				}
			}
			else{
				aux=actual->sig;
				anterior->sig=aux;
				if(aux!=NULL){
					aux->ant=anterior;
				}
			}
			free(ultimo);
			pr("\n%d Eliminado");
		}
	}
}

// Modifica un dato especifico (cambia el valor de dicho dato)
void modifica(nodo **cab){
	int cve=0, find=0;
	nodo *aux;
	if(*cab==NULL){
		pr("\nLISTA VACIA");
	}
	else{
		pr("Dato a modificar:	");
		sc("%d",&cve);
		find=0;
		aux=*cab;
		while(aux!=NULL && find==0){
			if(aux->info.d==cve){
				find=1;
				pr("\nIngresa el nuevo valor:	");
				sc("%d",&aux->info.d);
				pr("\ndato modificado:	%d",aux->info.d);
			}
			else{
				aux=aux->sig;
			}
		}
	}
}

// Busca un dato en especifico
void busqueda(nodo *cab){
	int cve, find=0;
	nodo *ultimo;
	pr("\n\tIngresa el valor a buscar:	");
	sc("%d",&cve);
	find=0;
	for(ultimo=cab;ultimo!=NULL && find==0;ultimo=ultimo->sig){
		if(ultimo->info.d==cve){
			find=1;
		}
	}
	if(find==1){
		pr("\n\tElemento encontrado");
	}
	else{
		pr("\n\tElemento no encontrado");
	}	
}






