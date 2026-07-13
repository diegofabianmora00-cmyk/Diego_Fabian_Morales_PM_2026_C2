#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_NOMBRE 260
#define TAM_FIRMA 12

void obtenerExtension(const char *nombre, char *extDestino) {
    const char *punto = strrchr(nombre, '.');
    if (!punto) {
        extDestino[0] = '\0';
        return;
    }
    strcpy(extDestino, punto + 1);
    for (int i = 0; extDestino[i]; i++) extDestino[i] = tolower(extDestino[i]);
}

int compararFirma(unsigned char *bytes, const unsigned char *firma, int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (bytes[i] != firma[i]) return 0;
    }
    return 1;
}

int esTextoPlano(unsigned char *bytes, int leidos) {
    for (int i = 0; i < leidos; i++) {
        unsigned char c = bytes[i];
        if (c == 0) return 0;
        if (c < 9) return 0;
    }
    return 1;
}

int contenidoValido(const char *ext, unsigned char *bytes, int leidos) {
    unsigned char firmaPNG[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
    unsigned char firmaJPG[3] = {0xFF, 0xD8, 0xFF};
    unsigned char firmaBMP[2] = {0x42, 0x4D};
    unsigned char firmaGIF87[6] = {'G', 'I', 'F', '8', '7', 'a'};
    unsigned char firmaGIF89[6] = {'G', 'I', 'F', '8', '9', 'a'};
    unsigned char firmaPDF[5] = {0x25, 0x50, 0x44, 0x46, 0x2D};
    unsigned char firmaZIP[4] = {0x50, 0x4B, 0x03, 0x04};
    unsigned char firmaEXE[2] = {0x4D, 0x5A};
    unsigned char firmaRAR[6] = {0x52, 0x61, 0x72, 0x21, 0x1A, 0x07};
    unsigned char firma7Z[6] = {0x37, 0x7A, 0xBC, 0xAF, 0x27, 0x1C};

    if (strcmp(ext, "png") == 0) {
        return leidos >= 8 && compararFirma(bytes, firmaPNG, 8);
    }
    if (strcmp(ext, "jpg") == 0 || strcmp(ext, "jpeg") == 0) {
        return leidos >= 3 && compararFirma(bytes, firmaJPG, 3);
    }
    if (strcmp(ext, "bmp") == 0) {
        return leidos >= 2 && compararFirma(bytes, firmaBMP, 2);
    }
    if (strcmp(ext, "gif") == 0) {
        return leidos >= 6 && (compararFirma(bytes, firmaGIF87, 6) || compararFirma(bytes, firmaGIF89, 6));
    }
    if (strcmp(ext, "pdf") == 0) {
        return leidos >= 5 && compararFirma(bytes, firmaPDF, 5);
    }
    if (strcmp(ext, "zip") == 0 || strcmp(ext, "docx") == 0 || strcmp(ext, "xlsx") == 0 || strcmp(ext, "pptx") == 0) {
        return leidos >= 4 && compararFirma(bytes, firmaZIP, 4);
    }
    if (strcmp(ext, "exe") == 0) {
        return leidos >= 2 && compararFirma(bytes, firmaEXE, 2);
    }
    if (strcmp(ext, "rar") == 0) {
        return leidos >= 6 && compararFirma(bytes, firmaRAR, 6);
    }
    if (strcmp(ext, "7z") == 0) {
        return leidos >= 6 && compararFirma(bytes, firma7Z, 6);
    }
    if (strcmp(ext, "txt") == 0 || strcmp(ext, "csv") == 0) {
        return esTextoPlano(bytes, leidos);
    }
    return -1;
}

void analizarArchivo(const char *carpeta, const char *nombre) {
    char ruta[600];
    snprintf(ruta, sizeof(ruta), "%s/%s", carpeta, nombre);

    FILE *f = fopen(ruta, "rb");
    if (!f) {
        printf("%-30s No se pudo abrir el archivo\n", nombre);
        return;
    }

    unsigned char bytes[TAM_FIRMA];
    int leidos = (int)fread(bytes, 1, TAM_FIRMA, f);
    fclose(f);

    char ext[10];
    obtenerExtension(nombre, ext);

    if (ext[0] == '\0') {
        printf("%-30s (sin extension)      No se puede verificar\n", nombre);
        return;
    }

    int resultado = contenidoValido(ext, bytes, leidos);

    if (resultado == 1) {
        printf("%-30s .%-6s Contenido VALIDO\n", nombre, ext);
    } else if (resultado == 0) {
        printf("%-30s .%-6s Contenido INVALIDO (no coincide con la extension)\n", nombre, ext);
    } else {
        printf("%-30s .%-6s Extension no soportada por el verificador\n", nombre, ext);
    }
}

int main(int argc, char *argv[]) {
    char carpeta[300];
    if (argc >= 2) {
        strncpy(carpeta, argv[1], sizeof(carpeta) - 1);
        carpeta[sizeof(carpeta) - 1] = '\0';
    } else {
        strcpy(carpeta, ".");
    }

    DIR *d = opendir(carpeta);
    if (!d) {
        printf("No se pudo abrir la carpeta: %s\n", carpeta);
        return 1;
    }

    struct dirent *entrada;
    int total = 0;
    printf("%-30s %-8s %s\n", "Archivo", "Ext", "Resultado");
    printf("--------------------------------------------------------------\n");
    while ((entrada = readdir(d)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0)
            continue;
        analizarArchivo(carpeta, entrada->d_name);
        total++;
    }
    closedir(d);

    if (total == 0) {
        printf("La carpeta esta vacia.\n");
    }

    return 0;
}
