#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <cctype>
#include "libreria.h"

/*
Comision 1k3

Mieres Gerhardt, Sebastian Segundo; Legajo:60456; DNI:94260315
Brizuela, Santiago; Legajo:60459; DNI:45961674
Yurcovich de Armas, Ernesto; Legajo:60324; DNI:45126914
*/


int Menu()
{
	int opcion = 0;
	printf("Cocina comunitaria munecas II\n");
	printf("=============================");
	printf("\n1- Crear usuario");
	printf("\n2- Iniciar Sesion");
	printf("\n3- Listado de personas");
	printf("\n4- Cargar persona");
	printf("\n5- Baja de persona");
	printf("\n6- Listado de productos");
	printf("\n7- Cargar productos");
	printf("\n8- Baja de productos");
	printf("\n9- Activar persona");	
	printf("\n10-Activar producto");
	printf("\n11-Asistencia");
	printf("\n12-Gastos");
	printf("\n13-Buscar persona");	
	printf("\n14-Buscar productos");
	printf("\n15-Modificar producto");
	printf("\n0- Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &opcion);
	return opcion;
}




int main()
{
	int opc = 0;
	int funcion=0;
	
	
	personas per = { 0 };
	productos pro = { 0 };
	
	FILE *archU; //Archivo con ususarios
	FILE *archP; //Archivo con productos
	FILE *archG; //Archivo con personas
	

	bool resultadoBaja = false;//PERSONAS

	int codigoTarget = 0, codigoTarget2 =0;
	int dni=0;
	
	int codigo=0;
	int codigoP = 0, codigoP2=0;	//PRODUCTOS

	bool resultadoBaja1 = false;
	
	
	bool resultadoModificacion = false;
	
	
	archU = fopen("usuarios.dat", "r+b");
	if(archU == NULL)
	{
		archU = fopen("usuarios.dat", "w+b");
		if(archU == NULL)
		{
			printf("ERROR");
			exit(1);
		}
	}
	
	archP = fopen("Productos.dat", "r+b");
	if(archP == NULL)
	{
		archP = fopen("Productos.dat", "w+b");
		if(archP == NULL)
		{
			printf("ERROR");
			exit(1);
		}
	}
	
	archG = fopen("Personas.dat", "r+b");
	if(archG == NULL)
	{
		archG = fopen("Personas.dat", "w+b");
		if(archG == NULL)
		{
			printf("ERROR");
			exit(1);
		}
	}
	
	
	srand(time(NULL));
	
	
	do
	{
		system("cls");
		opc = Menu();
		system("cls");
		
		switch ( opc )
		{
			
			case 1: {
					system("cls");
					printf("registrar usuario");
					printf("\n\n");
					registrarusuario(archU);
					system("pause");
					
						break;
					}
			case 2: {
					system("cls");
					printf("iniciar sesion");
					printf("\n\n");
					iniciarsesion(archU);
					printf("\n\n");
					system("pause");
						
						break;
					}
			case 3: {
			        system("cls");
					printf("Listado de personas:");
					printf("\n\n");
					ordenar1(archG,per);
					listado1(archG ,per);
					system("pause");
						break;
					}
					
			case 4: {
					system("cls");
					printf("Cargar persona:");
					printf("\n\n");
					carga1(archG , per);
					system("pause");	
						break;
					}
			case 5: {
			        printf("Baja Logica\n\n");
						
						printf("DNI: ");
						scanf("%d", &codigoTarget);
						
						resultadoBaja = borrado1(archG, codigoTarget);
						
						if ( resultadoBaja == true )
						{
							printf("\nLa persona %d se elimino exitosamente...\n", codigoTarget);
						}
						else
						{
							printf("\nNo se encontro la persona %d\n", codigoTarget);
						}
						
						break;
					}
			case 6: {
				    system("cls");
					printf("Listado de productos:");
					printf("\n\n");
					ordenar2(archP,pro);	
					listado2(archP , pro);
						break;
					}
			case 7: {
					system("cls");
					printf("Cargar productos:");
					printf("\n\n");
					carga2(archP, pro);
					system("pause");	
						
						break;
					}
			case 8: {
					system("cls");
					printf("Borrar producto:");
					printf("\nCodigo: ");
						scanf("%d", &codigoP);
						
						resultadoBaja1 = borrado2(archP, codigoP,pro);
						
						if ( resultadoBaja1 == true )
						{
							printf("\nEl producto %d se elimino exitosamente...\n", codigoP);
						}
						else
						{
							printf("\nNo se encontro el producto %d\n", codigoP);
						}
					system("pause");	
						
						break;
					}
			case 9:
			{
				system("cls");
					printf("Activar persona");
					printf("\n\n");
					printf("DNI: ");
						scanf("%d", &codigoTarget2);
						
						resultadoBaja = alta1(archG, codigoTarget2);
						
						if ( resultadoBaja == true )
						{
							printf("\nLa persona %d se activo correctamente...\n", codigoTarget2);
						}
						else
						{
							printf("\nNo se encontro la persona %d\n", codigoTarget2);
						}
					printf("\n\n");
					system("pause");
				break;
			}
			case 10:{
				system("cls");
					printf("Activar producto");
					printf("\n\n");
					printf("\nCodigo: ");
						scanf("%d", &codigoP2);
						
						resultadoBaja1 = alta2(archP, codigoP2,pro);
						
						if ( resultadoBaja1 == true )
						{
							printf("\nEl producto %d se activo correctamente...\n", codigoP2);
						}
						else
						{
							printf("\nNo se encontro el producto %d\n", codigoP2);
						}
					printf("\n\n");
					system("pause");
				break;
			}
			case 11:{
				system("cls");
					printf("Asistencia");
					printf("\n\n");
					funcion=asistencia(archG,per);
					printf("\n\n");
					system("pause");
				
				break;
			}
			case 12:{
				system("cls");
					printf("Gastos");
					printf("\n\n");
					gastos(archP,pro,funcion);
					printf("\n\n");
					system("pause");
				break;
			}
			case 13:{
				system("cls");
					printf("BUSCAR PERSONA");
					printf("\nDNI:");
					scanf("%d",&dni);
					printf("\n\n");
					mostrar(archG,dni,per);
					printf("\n\n");
					system("pause");
				break;
				
			}
			case 14:{
				system("cls");
					printf("BUSCAR PRODUCTO");
					printf("\nCodigo:");
					scanf("%d",&codigo);
					printf("\n\n");
					mostrarp(archP,codigo,pro);
					printf("\n\n");
					system("pause");
				break;
				
			}
			case 15:{
				system("cls");
					printf("MODIFICAR PRODUCTO");
					printf("\n\n");
					modificarProducto(archP,pro);
					printf("\n\n");
					system("pause");
				break;
				
			}
			case 0: {
						printf("Salir\n");
						break;
					}
					
			default: {
						printf("Opcion incorrecta");
						break;
					}


		} // switch
		
		printf("\n\n");
		system("pause");
		
	} 
	while ( opc != 0 );
	fclose(archU);
	fclose(archG);
	fclose(archP);
}


