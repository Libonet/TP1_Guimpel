#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 30

void clearScreen(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void clsBuffer(){
    int c;
    while ( (c = getchar()) != '\n' && c != EOF){}
}

typedef struct{
    char *dni, *nombre, *telefono, *mail, *direccion;
    int edad;
} Contacto;


Contacto* ingresoContacto(){
    Contacto *ingreso = malloc(sizeof(Contacto)*1);
    char aux[51];
    int i;

    clearScreen();

    printf("Ingrese nombre: ");
    for(i=0; i<50 && (aux[i] = getchar())!='\n' ; i++){}
    aux[i]='\0';
    if(i==50)
        clsBuffer();
    ingreso->nombre = malloc(strlen(aux)+1);
    strcpy(ingreso->nombre, aux);

    printf("Ingrese dni: ");
    for(i=0; i<50 && (aux[i] = getchar())!='\n' ; i++){}
    aux[i]='\0';
    if(i==50)
        clsBuffer();
    ingreso->dni = malloc(strlen(aux)+1);
    strcpy(ingreso->dni, aux);

    printf("Ingrese telefono: ");
    for(i=0; i<50 && (aux[i] = getchar())!='\n' ; i++){}
    aux[i]='\0';
    if(i==50)
        clsBuffer();
    ingreso->telefono = malloc(strlen(aux)+1);
    strcpy(ingreso->telefono, aux);

    printf("Ingrese mail: ");
    for(i=0; i<50 && (aux[i] = getchar())!='\n' ; i++){}
    aux[i]='\0';
    if(i==50)
        clsBuffer();
    ingreso->mail = malloc(strlen(aux)+1);
    strcpy(ingreso->mail, aux);

    printf("Ingrese direccion: ");
    for(i=0; i<50 && (aux[i] = getchar())!='\n' ; i++){}
    aux[i]='\0';
    if(i==50)
        clsBuffer();
    ingreso->direccion = malloc(strlen(aux)+1);
    strcpy(ingreso->direccion, aux);

    printf("Ingrese edad: ");
    scanf("%d", &(ingreso->edad));
    clsBuffer();

    //printf("nombre: %s", (lista+*cantContactos) -> nombre);
    return ingreso;
}

void nuevoContacto(Contacto *ingreso, Contacto *lista, int cantContactos){
    *(lista+cantContactos) = *ingreso;
    free(ingreso);
}

//---------------------------------------------------------------

void imprimirContactos(Contacto *lista, int cantContactos){
    clearScreen();
    printf("Lista de todos los contactos:\n\n");
    for(int i=0; i<cantContactos; i++){
        if(lista->edad!=2425){
            printf("Contacto %d:\n\n", i+1);
            printf("Nombre: %s\n", (lista+i)->nombre);
            printf("Dni: %s\n", (lista+i)->dni);
            printf("Telefono: %s\n", (lista+i)->telefono);
            printf("Mail: %s\n", (lista+i)->mail);
            printf("Direccion: %s\n", (lista+i)->direccion);
            printf("Edad: %d\n\n", (lista+i)->edad);
        }
    }
}

//---------------------------------------------------------------

char ingresoChar(){
    char ingreso;
    clearScreen();
    printf("Ingrese la clave de busqueda: ");

    ingreso = getchar();
    clsBuffer();
    return ingreso;
}

void imprimirContactosLetra(char ingreso, Contacto *lista, int cantContactos){
    int found=0;
    char letra[2];

    letra[0] = ingreso;
    letra[1] = '\0';

    for(int i=0; i<cantContactos; i++){
        if(strncmp((lista+i)->nombre, letra, 1)==0 && (lista+i)->edad!=2425){
            found++;
            printf("Contacto %d:\n\n", i+1);
            printf("Nombre: %s\n", (lista+i)->nombre);
            printf("Dni: %s\n", (lista+i)->dni);
            printf("Telefono: %s\n", (lista+i)->telefono);
            printf("Mail: %s\n", (lista+i)->mail);
            printf("Direccion: %s\n", (lista+i)->direccion);
            printf("Edad: %d\n\n", (lista+i)->edad);
        }
    }
    if(found==0){
        printf("\nNo se ha encontrado un contacto con esa inicial\n\n");
    }
}

//---------------------------------------------------------------

char* ingresoContactosArray(){
    int i;
    char aux[51];
    char *clave;
    clearScreen();

    printf("Ingrese la clave de busqueda: ");
    for(i=0; i<50 && (aux[i] = getchar())!='\n' ; i++){}
    aux[i]='\0';
    if(i==50)
        clsBuffer();
    clave = malloc(strlen(aux)+1);
    strcpy(clave, aux);

    return clave;
}

void buscarContactosNombre(char *clave, Contacto *lista, int cantContactos){
    int found=0;

    for(int i=0; i<cantContactos; i++){
        if(strstr((lista+i)->nombre, clave)!=NULL && (lista+i)->edad!=2425){
            found++;
            printf("Contacto %d:\n\n", i+1);
            printf("Nombre: %s\n", (lista+i)->nombre);
            printf("Dni: %s\n", (lista+i)->dni);
            printf("Telefono: %s\n", (lista+i)->telefono);
            printf("Mail: %s\n", (lista+i)->mail);
            printf("Direccion: %s\n", (lista+i)->direccion);
            printf("Edad: %d\n\n", (lista+i)->edad);
        }
    }
    if(found==0){
        printf("\nNo se han encontrado contactos usando la clave: %s...\n\n", clave);
    }
    free(clave);
}

//---------------------------------------------------------------

void buscarContactosTelefono(char *clave, Contacto *lista, int cantContactos){
    int found=0;

    for(int i=0; i<cantContactos; i++){
        if(strstr((lista+i)->telefono, clave)!= NULL && (lista+i)->edad!=2425){
            found++;
            printf("Contacto %d:\n\n", i+1);
            printf("Nombre: %s\n", (lista+i)->nombre);
            printf("Dni: %s\n", (lista+i)->dni);
            printf("Telefono: %s\n", (lista+i)->telefono);
            printf("Mail: %s\n", (lista+i)->mail);
            printf("Direccion: %s\n", (lista+i)->direccion);
            printf("Edad: %d\n\n", (lista+i)->edad);
        }
    }
    if(found==0){
        printf("\nNo se han encontrado contactos usando la clave: %s...\n\n", clave);
    }
    free(clave);
}

//---------------------------------------------------------------

int eleccionEliminarContacto(char *clave, Contacto *lista, int cantContactos){
    int ingreso, i=0, x=0, found=0, posibilidades[TAM];

    for(i=0; i<cantContactos; i++){
        if(strstr((lista+i)->nombre, clave)!= NULL && (lista+i)->edad!=2425){
            found++;
            posibilidades[x]=i;
            x++;
        }
    }
    if(found==0){
        printf("\nNo se han encontrado contactos usando la clave: %s...\n\n", clave);
        printf("Presione 'enter' para continuar...");
        clsBuffer();
    }
    else if(found>0){
        printf("Elija el contacto a eliminar:\n\n");
        for(i=0; i<x; i++){
            printf("%d)\n", i);
            printf("Nombre: %s\n", (lista+posibilidades[i])->nombre);
            printf("Dni: %s\n", (lista+posibilidades[i])->dni);
            printf("Telefono: %s\n", (lista+posibilidades[i])->telefono);
            printf("Mail: %s\n", (lista+posibilidades[i])->mail);
            printf("Direccion: %s\n", (lista+posibilidades[i])->direccion);
            printf("Edad: %d\n\n", (lista+posibilidades[i])->edad);

        }
        printf("Eliminar: ");
        scanf("%d", &ingreso);
        clsBuffer();

    }
    free(clave);

    return posibilidades[ingreso];
}

void eliminarContactoNombre(int ingreso, Contacto *lista, int *cantContactos){

    *cantContactos -= 1;

    free((lista+ingreso)->nombre);
    free((lista+ingreso)->dni);
    free((lista+ingreso)->telefono);
    free((lista+ingreso)->mail);
    free((lista+ingreso)->direccion);
    (lista+ingreso)->edad = 2425;

    (lista+ingreso)->nombre = malloc(sizeof(*(lista+*cantContactos)->nombre));
    (lista+ingreso)->dni = malloc(sizeof(*(lista+*cantContactos)->dni));
    (lista+ingreso)->telefono = malloc(sizeof(*(lista+*cantContactos)->telefono));
    (lista+ingreso)->mail = malloc(sizeof(*(lista+*cantContactos)->mail));
    (lista+ingreso)->direccion = malloc(sizeof(*(lista+*cantContactos)->direccion));

    strcpy((lista+ingreso)->nombre, (lista+*cantContactos)->nombre);
    strcpy((lista+ingreso)->dni, (lista+*cantContactos)->dni);
    strcpy((lista+ingreso)->telefono, (lista+*cantContactos)->telefono);
    strcpy((lista+ingreso)->mail, (lista+*cantContactos)->mail);
    strcpy((lista+ingreso)->direccion, (lista+*cantContactos)->direccion);
    (lista+ingreso)->edad = (lista+(*cantContactos))->edad;

    free((lista+*cantContactos)->nombre);
    free((lista+*cantContactos)->dni);
    free((lista+*cantContactos)->telefono);
    free((lista+*cantContactos)->mail);
    free((lista+*cantContactos)->direccion);
    (lista+*cantContactos)->edad = 2425;

    printf("Contacto eliminado! Presione 'enter' para continuar...");
    clsBuffer();
}

//---------------------------------------------------------------

int ingresoModo(){
    int ingreso;
    printf("Confirmar que quiere borrar todos los contactos: (Y=1/N=0)");
    do{
        scanf("%d", &ingreso);
        if(ingreso!=0 && ingreso!=1){
            clsBuffer();
            printf("Ingrese una de las opciones...\n\n");
        }

    } while(ingreso!=0 && ingreso!=1);

    if(ingreso==1){
        return 1;
    }
    else{
        printf("Cancelando... Presione 'enter' para continuar");
        clsBuffer();
        return 2425;
    }
}

void eliminarTodosContactos(int modo, Contacto *lista, int cantContactos){
    clearScreen();
    if(modo==1){ //Borra todos los punteros de la lista sin preguntar
        for(int i=0; i<cantContactos; i++){
                free((lista+i)->nombre);
                free((lista+i)->dni);
                free((lista+i)->telefono);
                free((lista+i)->mail);
                free((lista+i)->direccion);

                (lista+i)->edad = 2425;
            }
    }
}

//---------------------------------------------------------------

void menu(Contacto *lista, int *cantContactos){
    int flag=0, ingreso;
    do{
        printf("Cantidad de contactos: %d\n\n", *cantContactos);
        printf("1- Ingrese un nuevo contacto\n"
               "2- Muestra los contactos\n"
               "3- Muestra lista de contactos con cierta inicial\n"
               "4- Muestra contactos por nombre\n"
               "5- Muestra contactos por telefono\n"
               "6- Elimina contactos por nombre\n"
               "7- Eliminar todos los contactos\n"
               "8- Salir\n");

        scanf("%d", &ingreso);
        clsBuffer();

        switch(ingreso){
            case 1:
                nuevoContacto(ingresoContacto(), lista, *cantContactos);
                *cantContactos += 1;
                printf("Presione 'enter' para continuar...");
                clsBuffer();
                break;
            case 2:
                imprimirContactos(lista, *cantContactos);
                printf("Presione 'enter' para continuar...");
                clsBuffer();
                break;
            case 3:
                imprimirContactosLetra(ingresoChar(), lista, *cantContactos);
                printf("Presione 'enter' para continuar...");
                clsBuffer();
                break;
            case 4:
                buscarContactosNombre(ingresoContactosArray(), lista, *cantContactos);
                printf("Presione 'enter' para continuar...");
                clsBuffer();
                break;
            case 5:
                buscarContactosTelefono(ingresoContactosArray(),lista, *cantContactos);
                printf("Presione 'enter' para continuar...");
                clsBuffer();
                break;
            case 6:
                eliminarContactoNombre(eleccionEliminarContacto(ingresoContactosArray(), lista, *cantContactos), lista, cantContactos);
                break;
            case 7:
                eliminarTodosContactos(ingresoModo(), lista, *cantContactos);
                *cantContactos = 0;
                break;
            case 8:
                flag=1;
                break;
            default:
                printf("Elija una opcion de las disponibles...");
                break;
        }
        clearScreen();
    } while(flag!=1);

}

int main()
{
    Contacto *lista;
    int cantContactos = 0; //cantidad de contactos
    int *cantCont = &cantContactos;
    lista = malloc(sizeof(Contacto)*TAM);

    menu(lista, cantCont);
    eliminarTodosContactos(1, lista, cantContactos);
    free(lista);
    return 0;
}
