//	Coronado Obregón Carlos Alejandro - 170038
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "lista.h" // Llamada a header lista.h

#define pr printf
#define sc scanf
#define sys system

void gotoxy(int x1,int y1);

main(){ // Funcion principal
	int tecla=0,i,j,x=26,y=3;
	nodo *cab=NULL;
	sys("color f0");
	while(tecla!=27 || tecla!=13){ // Menu con teclado
		gotoxy(x,y-1);
		pr("     "); // Borra la posicion anterior de la flecha
		gotoxy(x,y);
		pr("<<--"); // Flecha/selección
		gotoxy(x,y+1);
		pr("     "); // Borra la posicion anterior de la flecha
		
		// Menu/Interfaz
		gotoxy(3,1);
		pr("Menu: (Listas dobles)");
		gotoxy(3,3);
		pr("1. Inserta inicio");
		gotoxy(3,4);
		pr("2. Inserta final");
		gotoxy(3,5);
		pr("3. Inserta ordenada");
		gotoxy(3,6);
		pr("4. Elimina inicio");
		gotoxy(3,7);
		pr("5. Elimina final");
		gotoxy(3,8);
		pr("6. Elimina especifico");
		gotoxy(3,9);
		pr("7. Recorre lista");
		gotoxy(3,10);
		pr("8. Recorre lista");
		gotoxy(3,11);
		pr("9. Busqueda");
		gotoxy(3,12);
		pr("10. Salir");
		
		tecla=getch();
		switch(tecla){
			case 72: // Arriba
				if(y>3){
					y--;
				}else{
					y=12;
					gotoxy(x,3);
					pr("     ");
				}
				break;
			case 80: // Abajo
				if(y<12){
					y++;
				}else{
					y=3; 
					gotoxy(x,12);
					pr("     ");
				}
				break;	
		}
		
		if(tecla==13){ // Solo si tecla = enter
			// Seleccion de la funcion dentro del menu
			sys("cls");
			switch(y){
				case 3:
					inserta_inicio(&cab);
					pr("\n\t"); sys("pause");
					break;
				case 4:
					inserta_final(&cab);
					pr("\n\t"); sys("pause");
					break;
				case 5:
					inserta_orde(&cab);
					pr("\n\t"); sys("pause");
					break;
				case 6: 
					elimina_ini(&cab);
					pr("\n\t"); sys("pause");
					break;
				case 7:
					elimina_final(&cab);
					pr("\n\t"); sys("pause");
					break;
				case 8:
					elimina_espec(&cab);
					pr("\n\t"); sys("pause");
					break;
				case 9:
					modifica(&cab);
					pr("\n\t"); sys("pause");
					break;
				case 10:
					recorre_lista(cab);
					pr("\n\t"); sys("pause");
					break;
				case 11:
					busqueda(cab);
					pr("\n\t"); sys("pause");
					break;
				case 12:
					// Pantalla de carga para salir (estetico)
					for(i=0;i<3;i++){ 
						system("cls");
						pr("\n\tSaliendo");
						for(j=0;j<3;j++){
							Sleep(135);
							pr(".");
						}
					}
					exit(0); // Función para forzar cierre
					break;
			}
			sys("cls");
		}
	}
}

void gotoxy(int x1,int y1){ // Funcion que otorga una pocicion x,y en algun punto de la pantalla
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x1;  
    dwPos.Y= y1;  
	SetConsoleCursorPosition(hcon,dwPos);  
}
