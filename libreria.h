//#ifndef LIBRERIA_H
//#define LIBRERIA_H

const int usu=10;
const int cont=32;

struct guardar_usuario
{
	char nombre_de_usuario[usu], contrasena[cont];
};

struct personas{
	char nya[50]; //Nombre y Apellido
	int dni;
	int presente;
	bool borrado;
};


struct productos{
	char nombre[50];
	int cod; //codigo
	int cantidad;
	float precio;
	bool rp; //reponer stock
	bool borrado; //Ya no se tendra en cuenta este producto
};



//1.1
bool mmu(char nombre[usu]) // min y max para usuario
{
	int i, l, p;
	p = strlen(nombre);
	l = 0;
	for (i = 0; i < p; i++)
	{
		l = l + 1;
	}
	if (l >= 6 && l <= 10)
	{
		return true;
	}
	return false;
}

//1.2
bool uu(FILE* archivo, char nombre[usu])// unico usuario
{
	guardar_usuario usuario;
	fseek(archivo, 0, SEEK_SET);
	fread(&usuario, sizeof(usuario), 1, archivo);
	while (!feof(archivo))
	{
		if (strcmp(nombre, usuario.nombre_de_usuario) == 0)
		{
			return false;
		}
		fread(&usuario, sizeof(usuario), 1, archivo);
	}
	return true;
}

//1.3
bool cm(char nombre[usu])//comienzo minuscula
{
	if (nombre[0] >= 'a' && nombre[0] <= 'z')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//1.4
bool may(char nombre[usu])// tener mayusculas
{
	int i, mayu, p;
	p = strlen(nombre);
	mayu = 0;
	for (i = 0; i < p; i++)
	{
		if (nombre[i] >= 'A' && nombre[i] <= 'Z')
		{
			mayu = mayu + 1;
		}
	}
	if (mayu >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//1.5
bool maxdig(char nombre[usu])// maximo de digitos
{
	int i, dig, p;
	p = strlen(nombre);
	dig = 0;
	for (i = 0; i < p; i++)
	{
		if (nombre[i] >= '0' && nombre[i] <= '9')
		{
			dig = dig + 1;
		}
	}
	if (dig <= 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//1.6
bool mmn(char contrasena[cont])//mmn mayuscula, minuscula y numero
{
	int i, min, may, num, p;
	p = strlen(contrasena);
	min = 0;
	may = 0;
	num = 0;
	for (i = 0; i < p; i++)
	{
		if (contrasena[i] >= '0' && contrasena[i] <= '9')
		{
			num = num + 1;
		}
		if (contrasena[i] >= 'A' && contrasena[i] <= 'Z')
		{
			may = may + 1;
		}
		if (contrasena[i] >= 'a' && contrasena[i] <= 'z')
		{
			min = min + 1;
		}
	}
	if (may >= 1 && min >= 1 && num >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//1.7
bool sa(char contrasena[cont])//sa soloalfanumerico
{
	int i, l, p;
	p = strlen(contrasena);
	l = 0;
	for (i = 0; i < p; i++)
	{
		if (contrasena[i] >= '0' && contrasena[i] <= '9' || contrasena[i] >= 'A' && contrasena[i] <= 'Z' || contrasena[i] >= 'a' && contrasena[i] <= 'z')
		{
			l = l + 1;
		}
	}
	if (p == l)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//1.8
bool mmc(char contrasena[cont])//mmc minymaxparacontrasena
{
	int i, l, p;
	p = strlen(contrasena);
	l = 0;
	for (i = 0; i < p; i++)
	{
		l = l + 1;
	}
	if (l >= 6 && l <= 32)
	{
		return true;
	}
	return false;
}

//1.9
bool nnc(char contrasena[cont])//nnc nonumericosconsecutivos
{
	int i, l, p;
	p = strlen(contrasena);
	l = 0;
	for (i = 0; i < p; i++)
	{
		if (contrasena[i] >= '0' && contrasena[i] <= '9')
		{
			l = l + 1;
		}
		else
		{
			l = 0;
		}
	}
	if (l <= 3)
	{
		return true;
	}
	{
		return false;
	}
}

//1.10
bool mayuscula(char c1, char c2)
{
	if (c1 >= 'A' && c1 <= 'Z')
	{
		c1 = tolower(c1);
	}
	if (c2 >= 'A' && c2 <= 'Z')
	{
		c2 = tolower(c2);
	}
	return (c1 + 1 == c2);
}

//1.11
bool nac(char contrasena[cont])// no alfabeticamente consecutiva
{
	int i, p;
	p = strlen(contrasena);

	for (i = 0; i < p - 1; i++)
	{
		if ((mayuscula(contrasena[i], contrasena[i + 1])) == true)
		{
			return false;
		}
	}
	return true;
}

//1.12
void registrarusuario(FILE* archivo)
{
	int i, b, longitud1, longitud2;
	char nombre[11], contrasena[33];
	guardar_usuario usuario;
	fseek(archivo, 0, SEEK_END);
	do
	{
		b = 0;
		printf("condiciones del usuario");
		printf("\n ==============");
		printf("\n 1. tener entre 6 y 10 caracteres");
		printf("\n 2. Ser unico para cada usuario registrado.");
		printf("\n 3. Comenzar con una letra minuscula.");
		printf("\n 4. Tener al menos 2 letras mayusculas.");
		printf("\n 5. Tener como maximo 3 digitos.");
		printf("\n\n");
		printf("usuario: ");
		fflush(stdin);
		fgets(nombre, sizeof(nombre), stdin);
		longitud1 = strlen(nombre);
		if (longitud1 > 0 && nombre[longitud1 - 1] == '\n')
		{
			nombre[longitud1 - 1] = '\0';
		}
		printf("\n\n");
		printf("condiciones de la contrasena");
		printf("\n ==============");
		printf("\n 1. Debera contener al menos una letra mayuscula, una letra minuscula y un numero.");
		printf("\n 2. No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.");
		printf("\n 3. Debera tener entre 6 y 32 caracteres.");
		printf("\n 4. No debe tener mas de 3 caracteres numericos consecutivos.");
		printf("\n 5. No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas (ascendentemente).");
		printf("\n    Este criterio es valido tanto para letras mayusculas, minusculas o combinacion de ambas.");
		printf("\n\n");
		printf("contrasena: ");
		fflush(stdin);
		fgets(contrasena, sizeof(contrasena), stdin);
		longitud2 = strlen(contrasena);
		if (longitud2 > 0 && contrasena[longitud2 - 1] == '\n')
		{
			contrasena[longitud2 - 1] = '\0';
		}

		if (!mmu(nombre))
		{
			printf("\nEL nombre de usuario debera contener entre 6 y 10 caracteres.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!uu(archivo, nombre))
		{
			printf("\nEl nombre de usuario ya esta en uso.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!cm(nombre))
		{
			printf("\nEl nombre debe comenzar con una letra minuscula.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!may(nombre))
		{
			printf("\nEl nombre debe tener al menos 2 letras mayusculas.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!maxdig(nombre))
		{
			printf("\nEl nombre no puede tener mas de 3 digitos.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!mmn(contrasena))
		{
			printf("\nLa contrasena debe contener al menos una mayuscula, una minuscula y un numero.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!sa(contrasena))
		{
			printf("\nLa contrasena debe ser solo alfanumerica.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!mmc(contrasena))
		{
			printf("\nLa contrasena debe tener entre 6 y 32 caracteres.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!nnc(contrasena))
		{
			printf("\nLa contrasena no debe tener mas de 3 numeros consecutivos.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if (!nac(contrasena))
		{
			printf("\nLa contrasena no debe tener letras consecutivas alfabeticamente.\n");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		if (mmu(nombre) == true && uu(archivo, nombre) == true && cm(nombre) == true && may(nombre) == true && maxdig(nombre) == true)
		{
			if (mmn(contrasena) == true && sa(contrasena) == true && mmc(contrasena) == true && nnc(contrasena) == true && nac(contrasena) == true)
			{
				strcpy(usuario.nombre_de_usuario, nombre);
				strcpy(usuario.contrasena, contrasena);
				fwrite(&usuario, sizeof(usuario), 1, archivo);
				b = 1;
			}
		}
	} while (b == 0);
	return;
}


void iniciarsesion(FILE* archivo)
{
	guardar_usuario usuario;
	char nombre[50], contrasena[50];
	int longitud;

	printf("Ingrese su usuario y contrasena");

	printf("\nUsuario: ");
	_flushall();
	fgets(nombre, sizeof(nombre), stdin);
	// Eliminar salto de línea del usuario
	longitud = strlen(nombre);
	if (longitud > 0 && nombre[longitud - 1] == '\n') {
		nombre[longitud - 1] = '\0';
	}

	printf("\nContrasena: ");
	_flushall();
	fgets(contrasena, sizeof(contrasena), stdin);
	// Eliminar salto de línea de la contraseña
	longitud = strlen(contrasena);
	if (longitud > 0 && contrasena[longitud - 1] == '\n') {
		contrasena[longitud - 1] = '\0';
	}

	fseek(archivo, 0, SEEK_SET);

	// Leer registro por registro hasta terminar el archivo
	while (fread(&usuario, sizeof(usuario), 1, archivo) == 1)
	{
		if (strcmp(nombre, usuario.nombre_de_usuario) == 0 && strcmp(contrasena, usuario.contrasena) == 0)
		{
			printf("\nSe inicio sesion correctamente");
			return; // Si coincide, sale de la función exitosamente
		}
	}

	// Si el bucle termina sin haber salido por el 'return', los datos no están
	printf("\nEl usuario y/o la contrasena son incorrecta/s");
}

//15
void modificarProducto(FILE* archP, productos pro)
{
	int codigoBuscado;
	bool encontrado = false;

	archP = fopen("Productos.dat", "rb+");
	if (archP == NULL) {
		printf("Error al abrir el archivo de productos.\n");
		return;
	}

	printf("Ingrese el codigo del producto a modificar: ");
	scanf("%d", &codigoBuscado);

	// Leer secuencialmente hasta el final
	while (fread(&pro, sizeof(productos), 1, archP)) {
		if (pro.cod == codigoBuscado && !pro.borrado) {
			encontrado = true;

			printf("Producto encontrado:\n");
			printf("Codigo: %d\nNombre: %s\nCantidad: %d\nPrecio: %.2f\n",
				pro.cod, pro.nombre, pro.cantidad, pro.precio);

			// Pedir nuevos datos
			printf("Ingrese el nuevo nombre: ");
			scanf(" %[^\n]", pro.nombre);
			printf("Ingrese la nueva cantidad: ");
			scanf("%d", &pro.cantidad);
			printf("Ingrese el nuevo precio: ");
			scanf("%f", &pro.precio);

			// Retroceder el puntero y sobrescribir
			fseek(archP, (long)-sizeof(productos), SEEK_CUR);
			fwrite(&pro, sizeof(productos), 1, archP);
			fflush(archP);
			break; // Terminar la busqueda
		}
	}

	if (!encontrado) {
		printf("Producto activo con codigo %d no encontrado.\n", codigoBuscado);
	}
	else {
		printf("Producto modificado exitosamente.\n");
	}

	fclose(archP);
}

void carga1(FILE* archG, personas per) {
	int n = 0, longitud;

	archG = fopen("Personas.dat", "rb+");
	if (archG == NULL) {
		archG = fopen("Personas.dat", "wb+");
		if (archG == NULL) {
			exit(1);
		}
	}
	fseek(archG, 0, SEEK_END);

	printf("Cuantas personas desea cargar? ");
	scanf("%d", &n);
	printf("\n===================================================\n");
	for (int i = 0; i < n; i++) {
		printf("Nombre y apellido: ");
		_flushall();
		fgets(per.nya, sizeof(per.nya), stdin);

		// Eliminar el salto de línea
		longitud = strlen(per.nya);
		if (longitud > 0 && per.nya[longitud - 1] == '\n') {
			per.nya[longitud - 1] = '\0';
		}

		printf("DNI: ");
		scanf("%d", &per.dni);
		per.borrado = false;
		printf("===================================================\n");
		fwrite(&per, sizeof(personas), 1, archG);
	}
	fclose(archG);
}



void carga2(FILE* archP, productos pro) {
	int n = 0, longitud;

	archP = fopen("Productos.dat", "rb+");
	if (archP == NULL) {
		archP = fopen("Productos.dat", "wb+");
		if (archP == NULL) {
			exit(1);
		}
	}
	fseek(archP, 0, SEEK_END);

	printf("Cuantos productos desea cargar? ");
	scanf("%d", &n);
	printf("\n===================================================\n");
	for (int i = 0; i < n; i++) {
		printf("Nombre: ");
		_flushall();
		fgets(pro.nombre, sizeof(pro.nombre), stdin);

		// Eliminar el salto de línea
		longitud = strlen(pro.nombre);
		if (longitud > 0 && pro.nombre[longitud - 1] == '\n') {
			pro.nombre[longitud - 1] = '\0';
		}

		printf("Codigo: ");
		scanf("%d", &pro.cod);
		printf("Unidades: ");
		scanf("%d", &pro.cantidad);
		printf("Precio(unidad/kg): ");
		scanf("%f", &pro.precio);
		pro.rp = false;
		pro.borrado = false;
		printf("===================================================\n");
		fwrite(&pro, sizeof(productos), 1, archP);
	}
	fclose(archP);
}



void listado1(FILE *archG, personas per) // Listado de personas
{
    archG = fopen("Personas.dat", "r+b");
    if (archG == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    while (fread(&per, sizeof(personas), 1, archG) == 1)
    {
        printf("\nNombre y apellido: %s", per.nya);
        printf("\nDNI: %d", per.dni);
        if (per.borrado == true)
        {
            printf("\nEstado: BORRADO");
        }
        else
        {
            printf("\nEstado: ACTIVO");
        }
        printf("\n\n");
    }
}

void listado2(FILE *archP, productos pro)
{
    // Rebobinar el archivo
    fseek(archP, 0, SEEK_SET);

    // Mientras la lectura sea exitosa
    while (fread(&pro, sizeof(productos), 1, archP) == 1)
    {
        // Procesar el dato actual
        printf("\nNombre: %s", pro.nombre);
        printf("\nCodigo: %d", pro.cod);
        printf("\nStock:  %d", pro.cantidad);
        printf("\nPrecio por unidad/kg: %.2f",pro.precio);
        if (pro.borrado == true)
        {
            printf("\nEstado: BORRADO");
        }
        else
        {
            printf("\nEstado: ACTIVO");
        }
        printf("\n\n");
    }
}



void ordenar1(FILE* archG, personas per)
{
	personas p1, p2;
	int n, i, j;

	archG = fopen("Personas.dat", "rb+");
	if (archG == NULL) {
		printf("Error al abrir archivo Personas.dat.\n");
		return;
	}

	// Calcular la cantidad total de registros en el archivo
	fseek(archG, 0, SEEK_END);
	n = ftell(archG) / sizeof(personas);

	// Ordenamiento de burbuja directamente en el archivo
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			// Posicionarse y leer dos registros adyacentes
			fseek(archG, j * sizeof(personas), SEEK_SET);
			fread(&p1, sizeof(personas), 1, archG);
			fread(&p2, sizeof(personas), 1, archG);

			// Comparar alfabeticamente
			if (strcmp(p1.nya, p2.nya) > 0) {
				// Retroceder y escribir invertidos
				fseek(archG, j * sizeof(personas), SEEK_SET);
				fwrite(&p2, sizeof(personas), 1, archG);
				fwrite(&p1, sizeof(personas), 1, archG);
			}
		}
	}

	fclose(archG);
	printf("Personas ordenadas correctamente.\n");
}

void ordenar2(FILE* archP, productos pro)
{
	productos p1, p2;
	int n, i, j;

	archP = fopen("Productos.dat", "rb+");
	if (archP == NULL) {
		printf("Error al abrir archivo Productos.dat.\n");
		return;
	}

	// Calcular la cantidad total de registros en el archivo
	fseek(archP, 0, SEEK_END);
	n = ftell(archP) / sizeof(productos);

	// Ordenamiento de burbuja directamente en el archivo
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			fseek(archP, j * sizeof(productos), SEEK_SET);
			fread(&p1, sizeof(productos), 1, archP);
			fread(&p2, sizeof(productos), 1, archP);

			if (strcmp(p1.nombre, p2.nombre) > 0) {
				fseek(archP, j * sizeof(productos), SEEK_SET);
				fwrite(&p2, sizeof(productos), 1, archP);
				fwrite(&p1, sizeof(productos), 1, archP);
			}
		}
	}

	fclose(archP);
	printf("Productos ordenados correctamente.\n");
}



int asistencia(FILE *archG, personas per)
{
	int contador=0, a=0;
	
	/*fseek(archG,0,SEEK_SET);
	fread(&per, sizeof(personas), 1, archG);*/
	
	archG = fopen("Personas.dat", "rb");
    if (archG == NULL) 
	{
        printf("Error al abrir el archivo");
        return contador;
    }
	printf("si esta presente indicar con 1, ausente con 0:\n");

	
	while (fread(&per, sizeof(personas), 1, archG))
	{
		if(per.borrado == false)
		{
		printf("%s:",per.nya);
		scanf("%d",&a);
		contador=contador+a;

		}	
		
	}
	
	printf("Hay %d personas presentes hoy.",contador);
	
	fclose(archG);
	return contador;
	
}

bool borrado1(FILE *archG, int codigoABuscar) 
{
    if (archG == NULL) {
        printf("Error: archivo no disponible.\n");
        return false;
    }

    personas per;
    bool encontrado = false;

    // Rebobinar archivo al inicio
    fseek(archG, 0, SEEK_SET);

    // Leer cada registro
    while (fread(&per, sizeof(personas), 1, archG)) {
        // Verificar si coincide el DNI y no está ya borrado
        if (per.dni == codigoABuscar && !per.borrado) {
            per.borrado = true; // Marcar como borrado lógico

            // Retroceder puntero para reescribir el registro
            fseek(archG,(long) -sizeof(personas), SEEK_CUR);
            fwrite(&per, sizeof(personas), 1, archG);
            fflush(archG); // Asegurar que los cambios se escriban
            encontrado = true;
            break; // Salir del bucle, ya que se encontró el registro
        }
    }

    return encontrado;
}

bool borrado2(FILE *archP, int codigoP, productos pro) {
    if (archP == NULL) {
        printf("Error: archivo no disponible.\n");
        return false;
    }

    bool encontrado = false;

    // Rebobinar archivo al inicio
    fseek(archP, 0, SEEK_SET);

    // Leer cada registro
    while (fread(&pro, sizeof(productos), 1, archP)) {
        // Verificar si coincide el código y no está ya borrado
        if (pro.cod == codigoP && !pro.borrado) {
            pro.borrado = true; // Marcar como borrado lógico

            // Retroceder puntero para reescribir el registro
            fseek(archP,(long) -sizeof(productos), SEEK_CUR);
            fwrite(&pro, sizeof(productos), 1, archP);
            fflush(archP); // Asegurar que los cambios se escriban
            encontrado = true;
            break; // Salir del bucle, ya que se encontró el registro
        }
    }

    return encontrado;
}
void mostrar(FILE *archG, int dni, personas per)
{	
    archG = fopen("Personas.dat", "rb");
    if (archG == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    while (fread(&per, sizeof(personas), 1, archG) == 1)
    {
        if (per.dni == dni)
        {
            printf("Nombre: %s\n", per.nya);
            printf("DNI: %d\n", per.dni);
            if (per.borrado == true)
            {
                printf("Estado: Inactivo\n");
            }
            else
            {
                printf("Estado: Activo\n");
            }
        }
    }

    fclose(archG);	
}

void mostrarp(FILE *archP, int codigo, productos pro)
{	
    archP = fopen("Productos.dat", "rb");
    if (archP == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    while (fread(&pro, sizeof(productos), 1, archP) == 1)
    {
        if (pro.cod == codigo)
        {
            printf("Nombre: %s\n", pro.nombre);
            printf("Codigo: %d\n", pro.cod);
            printf("Unidades: %d\n",pro.cantidad);
            printf("Precio por kg/unidad: %.2f \n",pro.precio);
            if (pro.borrado == true)
            {
                printf("Estado: Inactivo\n");
            }
            else
            {
                printf("Estado: Activo\n");
            }
        }
    }

    fclose(archP);	
}
bool alta1(FILE *archG, int codigoABuscar) 
{
    if (archG == NULL) {
        printf("Error: archivo no disponible.\n");
        return false;
    }

    personas per;
    bool encontrado = false;

    // Rebobinar archivo al inicio
    fseek(archG, 0, SEEK_SET);

    while (fread(&per, sizeof(personas), 1, archG) == 1) {
        if (per.dni == codigoABuscar) { // Verificar coincidencia de DNI
            if (!per.borrado) {
                printf("El registro ya está activo.\n");
                return true; // Ya activo, no es necesario reactivarlo
            }

            per.borrado = false; // Reactivar el registro
            fseek(archG, (long)-sizeof(personas), SEEK_CUR);
            fwrite(&per, sizeof(personas), 1, archG);
            fflush(archG); // Asegurar que se escriban los cambios
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un registro con el DNI %d.\n", codigoABuscar);
    }

    return encontrado;
}

bool alta2(FILE *archP, int codigoP, productos pro) 
{
    if (archP == NULL) {
        printf("Error: archivo no disponible.\n");
        return false;
    }

    bool encontrado = false;

    // Rebobinar archivo al inicio
    fseek(archP, 0, SEEK_SET);

    while (fread(&pro, sizeof(productos), 1, archP) == 1) {
        if (pro.cod == codigoP) { // Verificar coincidencia de código
            if (!pro.borrado) {
                printf("El registro ya está activo.\n");
                return true; // Ya activo, no es necesario reactivarlo
            }

            pro.borrado = false; // Reactivar el registro
            fseek(archP, (long)-sizeof(productos), SEEK_CUR);
            fwrite(&pro, sizeof(productos), 1, archP);
            fflush(archP); // Asegurar que se escriban los cambios
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un registro con el código %d.\n", codigoP);
    }

    return encontrado;
}


void gastos(FILE *archP, productos pro, int funcion)
{
	float gastosT =0, sumador=0,contador=0,gastosp=0;
	
	
	archP = fopen("Productos.dat", "rb");
    if (archP == NULL) 
	{
        printf("Error al abrir el archivo");
        return;
    }	
    
    while(fread(&pro, sizeof(productos), 1, archP))
    {
    	if(pro.borrado == false)
    	{
    		printf("\nCuantas unidades/kg consumieron de %s: ",pro.nombre);
    		scanf("%f",&contador);
    		
    		sumador= contador*pro.precio;
    		
    		gastosT=gastosT+sumador;
		}
	}
    
    printf("\nEn total se gastaron $%.2f",gastosT);
    
    gastosp=gastosT/funcion;
    
    printf("\nSe promedia un gasto de $%.2f por persona.",gastosp);
    
	fclose(archP);
}