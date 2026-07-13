#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define MAX_ARCHIVOS 200
#define MAX_NOMBRE 260

int tieneExtensionValida(const char *nombre) {
    const char *punto = strrchr(nombre, '.');
    if (!punto) return 0;
    char ext[10];
    strncpy(ext, punto + 1, 9);
    ext[9] = '\0';
    for (int i = 0; ext[i]; i++) ext[i] = tolower(ext[i]);
    if (strcmp(ext, "png") == 0) return 1;
    if (strcmp(ext, "jpg") == 0) return 1;
    if (strcmp(ext, "jpeg") == 0) return 1;
    if (strcmp(ext, "bmp") == 0) return 1;
    return 0;
}

int listarArchivos(const char *carpeta, char lista[][MAX_NOMBRE]) {
    DIR *d = opendir(carpeta);
    if (!d) {
        printf("No se pudo abrir la carpeta: %s\n", carpeta);
        return -1;
    }
    struct dirent *entrada;
    int total = 0;
    while ((entrada = readdir(d)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0)
            continue;
        if (tieneExtensionValida(entrada->d_name) && total < MAX_ARCHIVOS) {
            strncpy(lista[total], entrada->d_name, MAX_NOMBRE - 1);
            lista[total][MAX_NOMBRE - 1] = '\0';
            total++;
        }
    }
    closedir(d);
    return total;
}

void obtenerExtension(const char *nombre, char *extDestino) {
    const char *punto = strrchr(nombre, '.');
    strcpy(extDestino, punto + 1);
    for (int i = 0; extDestino[i]; i++) extDestino[i] = tolower(extDestino[i]);
}

int convertirAGrises(const char *rutaEntrada, const char *rutaSalida, const char *ext) {
    int ancho, alto, canales;
    unsigned char *datos = stbi_load(rutaEntrada, &ancho, &alto, &canales, 0);
    if (!datos) {
        printf("Error al leer la imagen.\n");
        return 0;
    }

    for (int i = 0; i < ancho * alto; i++) {
        unsigned char *pixel = datos + i * canales;
        unsigned char r = pixel[0];
        unsigned char g = (canales >= 2) ? pixel[1] : r;
        unsigned char b = (canales >= 3) ? pixel[2] : r;
        unsigned char gris = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
        pixel[0] = gris;
        if (canales >= 2) pixel[1] = gris;
        if (canales >= 3) pixel[2] = gris;
    }

    int resultado = 0;
    if (strcmp(ext, "png") == 0) {
        resultado = stbi_write_png(rutaSalida, ancho, alto, canales, datos, ancho * canales);
    } else if (strcmp(ext, "bmp") == 0) {
        resultado = stbi_write_bmp(rutaSalida, ancho, alto, canales, datos);
    } else if (strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0) {
        resultado = stbi_write_jpg(rutaSalida, ancho, alto, canales, datos, 95);
    }

    stbi_image_free(datos);
    return resultado;
}

int main(int argc, char *argv[]) {
    char carpeta[300];
    if (argc >= 2) {
        strncpy(carpeta, argv[1], sizeof(carpeta) - 1);
        carpeta[sizeof(carpeta) - 1] = '\0';
    } else {
        strcpy(carpeta, ".");
    }

    char lista[MAX_ARCHIVOS][MAX_NOMBRE];
    int total = listarArchivos(carpeta, lista);
    if (total <= 0) {
        printf("No se encontraron imagenes png, jpg o bmp en la carpeta.\n");
        return 1;
    }

    printf("Imagenes encontradas en \"%s\":\n", carpeta);
    for (int i = 0; i < total; i++) {
        printf("%d. %s\n", i + 1, lista[i]);
    }

    int opcion;
    printf("\nSeleccione el numero de la imagen a convertir: ");
    if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > total) {
        printf("Opcion invalida.\n");
        return 1;
    }

    char *nombreArchivo = lista[opcion - 1];
    char rutaEntrada[600];
    snprintf(rutaEntrada, sizeof(rutaEntrada), "%s/%s", carpeta, nombreArchivo);

    char ext[10];
    obtenerExtension(nombreArchivo, ext);

    char nombreBase[MAX_NOMBRE];
    strncpy(nombreBase, nombreArchivo, MAX_NOMBRE - 1);
    nombreBase[MAX_NOMBRE - 1] = '\0';
    char *puntoBase = strrchr(nombreBase, '.');
    if (puntoBase) *puntoBase = '\0';

    char rutaSalida[700];
    snprintf(rutaSalida, sizeof(rutaSalida), "%s/%s_bn.%s", carpeta, nombreBase, ext);

    if (convertirAGrises(rutaEntrada, rutaSalida, ext)) {
        printf("Conversion exitosa. Archivo guardado en: %s\n", rutaSalida);
    } else {
        printf("No se pudo convertir la imagen.\n");
        return 1;
    }

    return 0;
}
