#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char apellido[50];
    float promedio;
    char materia[50];
} Alumno;

void leerXML() {
    FILE *archivo = fopen("alumnos.xml", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo XML\n");
        return;
    }

    int cantidad = 0;
    char linea[200];

    while (fgets(linea, sizeof(linea), archivo)) {
        if (strstr(linea, "<cantidad>")) {
            sscanf(linea, " <cantidad>%d</cantidad>", &cantidad);
            break;
        }
    }

    Alumno *alumnos = (Alumno *) malloc(cantidad * sizeof(Alumno));
    if (alumnos == NULL) {
        printf("Error al reservar memoria\n");
        fclose(archivo);
        return;
    }

    int i = -1;
    while (fgets(linea, sizeof(linea), archivo)) {
        if (strstr(linea, "<Alumno>")) {
            i++;
        } else if (strstr(linea, "<Nombre>")) {
            sscanf(linea, " <Nombre>%[^<]", alumnos[i].nombre);
        } else if (strstr(linea, "<Apellido>")) {
            sscanf(linea, " <Apellido>%[^<]", alumnos[i].apellido);
        } else if (strstr(linea, "<Promedio>")) {
            sscanf(linea, " <Promedio>%f", &alumnos[i].promedio);
        } else if (strstr(linea, "<Materia>")) {
            sscanf(linea, " <Materia>%[^<]", alumnos[i].materia);
        }
    }

    fclose(archivo);

    printf("\n--- Alumnos (XML) ---\n");
    for (int j = 0; j < cantidad; j++) {
        printf("Alumno %d: %s %s - Promedio: %.2f - Materia: %s\n",
               j + 1, alumnos[j].nombre, alumnos[j].apellido,
               alumnos[j].promedio, alumnos[j].materia);
    }

    free(alumnos);
}

void leerJSON() {
    

FILE *archivo = fopen("alumnos.json", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo JSON\n");
        return;
    }

    int cantidad = 0;
    char linea[200];

    // Buscamos la cantidad de alumnos
    while (fgets(linea, sizeof(linea), archivo)) {
        if (strstr(linea, "\"cantidad\"")) {
            sscanf(linea, " \"cantidad\": %d", &cantidad);
            break;
        }
    }

    Alumno *alumnos = (Alumno *) malloc(cantidad * sizeof(Alumno));
    if (alumnos == NULL) {
        printf("Error al reservar memoria\n");
        fclose(archivo);
        return;
    }

    int i = -1;
    while (fgets(linea, sizeof(linea), archivo)) {
        if (strstr(linea, "{")) {
            i++; // nuevo alumno
        } else if (strstr(linea, "\"Nombre\"")) {
            sscanf(linea, " \"Nombre\": \"%[^\"]", alumnos[i].nombre);
        } else if (strstr(linea, "\"Apellido\"")) {
            sscanf(linea, " \"Apellido\": \"%[^\"]", alumnos[i].apellido);
        } else if (strstr(linea, "\"Promedio\"")) {
            sscanf(linea, " \"Promedio\": %f", &alumnos[i].promedio);
        } else if (strstr(linea, "\"Materia\"")) {
            sscanf(linea, " \"Materia\": \"%[^\"]", alumnos[i].materia);
        }

        if (i >= cantidad) break; // seguridad, no seguir de más
    }

    fclose(archivo);

    printf("\n--- Alumnos (JSON) ---\n");
    for (int j = 0; j < cantidad; j++) {
        printf("Alumno %d: %s %s - Promedio: %.2f - Materia: %s\n",
               j + 1, alumnos[j].nombre, alumnos[j].apellido,
               alumnos[j].promedio, alumnos[j].materia);
    }

    free(alumnos);
    
}

void leerCSV() {
    FILE *archivo = fopen("alumnos.csv", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo CSV\n");
        return;
    }

    char linea[200];
    int cantidad = 0;

    // Primera pasada: contamos cuántas líneas hay (menos la de títulos)
    fgets(linea, sizeof(linea), archivo); // saltamos la línea de títulos
    while (fgets(linea, sizeof(linea), archivo)) {
        cantidad++;
    }

    // Volvemos al principio del archivo para leer los datos
    rewind(archivo);
    fgets(linea, sizeof(linea), archivo); // saltamos la línea de títulos otra vez

    Alumno *alumnos = (Alumno *) malloc(cantidad * sizeof(Alumno));
    if (alumnos == NULL) {
        printf("Error al reservar memoria\n");
        fclose(archivo);
        return;
    }

    int i = 0;
    while (fgets(linea, sizeof(linea), archivo)) {
        sscanf(linea, " %[^,],%[^,],%f,%[^\n]",
               alumnos[i].nombre, alumnos[i].apellido,
               &alumnos[i].promedio, alumnos[i].materia);
        i++;
    }

    fclose(archivo);

    printf("\n--- Alumnos (CSV) ---\n");
    for (int j = 0; j < cantidad; j++) {
        printf("Alumno %d: %s %s - Promedio: %.2f - Materia: %s\n",
               j + 1, alumnos[j].nombre, alumnos[j].apellido,
               alumnos[j].promedio, alumnos[j].materia);
    }

    free(alumnos);
}

int main() {
    int opcion;

    printf("Menu:\n");
    printf("1. Leer archivo XML\n");
    printf("2. Leer archivo JSON\n");
    printf("3. Leer archivo CSV\n");
    printf("Elegir una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        leerXML();
    } else if (opcion == 2) {
        leerJSON();
    } else if (opcion == 3) {
        leerCSV();
    } else {
        printf("Opcion invalida\n");
    }

    return 0;
}