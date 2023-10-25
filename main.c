#include "image.c"

int main() {

    int opcao;
    Image* coloredPPM = NULL;
    Image* greyConverted = NULL;

    // Menu com loop.
    do {
        puts("\n---------------MENU---------------");
        puts("1. Load PPM image.");
        puts("2. Convert to greyscale.");
        puts("3. Write image.");
        puts("4. Exit program.");
        printf("Enter one of the numbers above: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
        
        // Menu primeira opção.
        case 1:
            char caminhoW[500];
            int opcaocaminhoW;
            // Escolha de diretório.
            puts("Type '1' to use the default directory.");
            puts("Type '2' to enter a different directory.");
            scanf("%d", &opcaocaminhoW);

            if (opcaocaminhoW == 1) {
                char nome_do_arquivoW[50];
                puts("The directory used will be the same as where the program is stored.");
                printf("Type the file name (with the extension): ");
                scanf("%s", nome_do_arquivoW);
                coloredPPM = load_from_ppm(nome_do_arquivoW);

                puts("\nFile loaded sucessfully.");
                
            } else if (opcaocaminhoW == 2) {
                puts("Type the directory:");
                scanf("%s", caminhoW);
                coloredPPM = load_from_ppm(caminhoW);

                puts("\nFile loaded sucessfully.");
            
            } else {
                puts("\n'1' or '2' only.");
            }

            //teste
            printf("%s\n", coloredPPM->tipo);


            break;

        // Menu segunda opção.
        case 2:
            if (coloredPPM == NULL) {
                puts("\nNo image loaded. Menu returning.");
            } else {
                greyConverted = create(coloredPPM->altura, coloredPPM->largura, "P2");
                greyConverted->valor_max = coloredPPM->valor_max;
                rgb_to_gray(coloredPPM, greyConverted);
                puts("\nConversion finished.");
            }

            //teste
            printf("%s\n", coloredPPM->tipo);
            printf("%s\n", greyConverted->tipo);

            break;

        // Menu terceira opção.
        case 3:
            //teste
            printf("%s\n", coloredPPM->tipo);
            printf("%s\n", greyConverted->tipo);
        
            char caminho[500];
            int opcaocaminho;
            // Escolha de diretório.
            puts("Type '1' to use the default directory.");
            puts("Type '2' to enter a different directory.");
            scanf("%d", &opcaocaminho);

            if (opcaocaminho == 1) {
                char nome_do_arquivo[50];
                puts("The directory used will be the same as where the program is stored.");
                printf("Type the file name (with the extension): ");
                scanf("%s", nome_do_arquivo);
                write_to_ppm(greyConverted, nome_do_arquivo);

                puts("\nFile written successfully.");
                
            } else if (opcaocaminho == 2) {
                puts("Type the directory:");
                scanf("%s", caminho);
                write_to_ppm(greyConverted, caminho);

                puts("\nFile written successfully.");
            
            } else {
                puts("\n'1' or '2' only.");
            }

            break;

        // Menu quarta opção.
        case 4:
            puts("\nProgram exited.\n");
            exit(EXIT_SUCCESS);
            
            break;
        
        // Caso um caractere que não seja de 1 até 4 seja digitado.
        default:
            puts("\nType a number amongst the options.");

            break;
        }
        
    } while (opcao != 4);


    return 0;
}