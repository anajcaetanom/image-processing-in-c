#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _imagem {
    char tipo[3];
    int altura;
    int largura;
    int valor_max;
    unsigned char ***matriz_de_pixels;
};


/**
* Criação de nova imagem.
*
* @param rows The number of rows (height) of the image.
* @param cols The number of columns (width) of the image.
* @param type The PPM type ("P2" for grayscale or "P3" for color).
* @return A pointer to the newly created image.
*/
Image* create(int rows, int cols, char type[]) {
    Image* nova_imagem = (Image*)calloc(1, sizeof(Image));

    // Mensagem de erro caso alocação falhe.
    if (nova_imagem == NULL) {
        fprintf(stderr, "\nERROR IN 'CREATE' FUNCTION\nAllocation of 'nova_imagem' failed.\n\n");
        exit(EXIT_FAILURE);
    } 
    // Atribuição à struct.
    strcpy(nova_imagem->tipo, type);
    nova_imagem->altura = rows;
    nova_imagem->largura = cols; 
    
    // Criação de imagem permitida apenas para tipos "P2" e "P3".
    if  ((strcmp (nova_imagem->tipo, "P3") != 0) && (strcmp (nova_imagem->tipo, "P2") != 0)) {
        fprintf(stderr, "\nERROR IN 'CREATE' FUNCTION\nInvalid type.\n\n");
        exit(EXIT_FAILURE);
    } 
    // Imagem em RGB (colorida)
    if (strcmp (nova_imagem->tipo, "P3") == 0) {

        nova_imagem->matriz_de_pixels = (unsigned char***)calloc(cols, sizeof(unsigned char**));

        for (int k = 0; k < cols; k++) {
            nova_imagem->matriz_de_pixels[k] = (unsigned char**)calloc(rows, sizeof(unsigned char*));
            for (int i = 0; i < rows; i++) {
                nova_imagem->matriz_de_pixels[k][i] = (unsigned char*)calloc(3, sizeof(unsigned char));
            }
        }
    }

    // Imagem em tons de cinza
    if (strcmp (nova_imagem->tipo, "P2") == 0) {    

        nova_imagem->matriz_de_pixels = (unsigned char***)calloc(cols, sizeof(unsigned char**));

        for (int k = 0; k < cols; k++) {
            nova_imagem->matriz_de_pixels[k] = (unsigned char**)calloc(rows, sizeof(unsigned char*));
            for (int i = 0; i < rows; i++) {
                nova_imagem->matriz_de_pixels[k][i] = (unsigned char*)calloc(1, sizeof(unsigned char));
            }
        }
    }
    
    // Mensagem de erro caso alocação dos pixels falhe.
    if (nova_imagem->matriz_de_pixels == NULL) {
        fprintf(stderr, "\nERROR IN 'CREATE' FUNCTION\nAllocation of 'matriz_de_pixels' failed.\n\n");
        exit(EXIT_FAILURE);
    }
    
    return nova_imagem;
}


/**
* Carrega imagem de um arquivo PPM.
*
* @param filename The name of the PPM file to load.
* @return A pointer to the loaded image.
*/
Image* load_from_ppm(const char* filename) {
    int numero;
    char tipo[3];
    int largura, altura, valor_max;

    // Abrindo arquivo.
    FILE *arquivoPPMcolor = fopen(filename, "r");

    // Mensagem de erro caso abertura do arquivo falhe.
    if (arquivoPPMcolor == NULL) {
        fprintf(stderr, "\nERROR IN 'LOAD' FUNCTION\nCouldn't load PPM file.\n\n");
        exit(EXIT_FAILURE);
    } 
    
    // Adquirindo as informações necessárias do arquivo.
    fscanf(arquivoPPMcolor, "%s", tipo);
    fscanf(arquivoPPMcolor, "%d %d", &largura, &altura);
    fscanf(arquivoPPMcolor, "%d", &valor_max);

    // Criação da imagem.
    Image *imagemPPMcolor = create(altura, largura, tipo);

    // Atribuição
    imagemPPMcolor->altura = altura;
    imagemPPMcolor->largura = largura;
    strcpy(imagemPPMcolor->tipo, tipo);
    imagemPPMcolor->valor_max = valor_max;

    // Preenchimento da imagem.
    if (strcmp (imagemPPMcolor->tipo, "P3") == 0) {
        for (int k = 0; k < largura; k++) {
            for (int i = 0; i < altura; i++) {
                for (int j = 0; j < 3; j++) {
                    fscanf(arquivoPPMcolor, "%d", &numero);
                    imagemPPMcolor->matriz_de_pixels[k][i][j] = (unsigned char)numero;
                }
            }
        }
    } else {
        fprintf(stderr, "\nERROR IN 'LOAD' FUNCTION\nPPM file is not 'P3' type.\n\n"); // Mensagem de erro caso PPM não seja do arquivo específicado.
        exit(EXIT_FAILURE);
    }

    // Mensagem de erro caso preenchimento da imagem falhe.
    if (imagemPPMcolor == NULL) {
        fprintf(stderr, "\nERROR IN 'LOAD' FUNCTION\nCouldn't create PPM image.\n\n");
        exit(EXIT_FAILURE);
    }

    fclose(arquivoPPMcolor);

    return imagemPPMcolor;
}


/**
* Converts an RGB image to grayscale.
*
* @param image_rgb The input RGB image to convert.
* @param image_gray The output grayscale image where the result is stored.
*/
void rgb_to_gray(Image* image_rgb, Image* image_gray) {

    // Escrevendo a matriz em tons de cinza.
    for (int k = 0; k < image_gray->largura; k++) {
        for (int i = 0; i < image_gray->altura; i++) {
            image_gray->matriz_de_pixels[k][i][0] = 
            0.299 * image_rgb->matriz_de_pixels[k][i][0] + 
            0.587 * image_rgb->matriz_de_pixels[k][i][1] + 
            0.114 * image_rgb->matriz_de_pixels[k][i][2];
        }
    }
}


/**
* Writes an P2 image to a PPM file.
*
* @param image The image to write to the file.
* @param filename The name of the PPM file to write.
*/
void write_to_ppm(Image* image, const char* filename){

    // Abertura ou criação de arquivo para escrita.
    FILE *write_image = fopen(filename, "w");

    // Mensagem de erro caso abertura ou criação do arquivo falhe.
    if (write_image == NULL) {
        fprintf(stderr, "\nERROR IN 'WRITE' FUNCTION\nCouldn't create file for writing.\n\n");
        exit(EXIT_FAILURE);
    } 

    fprintf(write_image, "%s\n", image->tipo);
    fprintf(write_image, "%d %d\n", image->largura, image->altura);
    fprintf(write_image, "%d\n", image->valor_max);

    for (int k = 0; k < image->largura; k++){
        for (int i = 0; i < image->altura; i++) {
            fprintf(write_image, "%hhu", image->matriz_de_pixels[k][i][0]);
            fprintf(write_image, " ");
        }
        fprintf(write_image,"\n");
    }
    
    // Mensagem de erro caso o processo de escrita do arquivo falhe.
    if (write_image == NULL) {
        fprintf(stderr, "\nERROR IN 'WRITE' FUNCTION\nCouldn't write in file.\n\n");
        exit(EXIT_FAILURE);
    } 

}


////// Função de desalocação ///////

void matrix_deallocation(Image* image) {

        for (int k = 0; k < image->largura; k++) {
            for (int i = 0; i < image->altura; i++) {
                free(image->matriz_de_pixels[k][i]);
            }
            free(image->matriz_de_pixels[k]);
        }
        free(image->matriz_de_pixels);
        image->matriz_de_pixels = NULL;

}

