# Trabalho 1 - Estrutura de Dados
## Ana Júlia Caetano Martins
Matrícula: 20222bsi0091
### Passo-a-passo para executar o programa:

1. Abra um terminal ou prompt de comando no diretório onde os arquivos de código e o Makefile estão localizados.
2. No terminal, compile o programa.
3. Após a compilação bem-sucedida, você pode executar o programa que terá o nome "test_image" de acordo com o makefile.
4. O programa exibirá um menu interativo com opções para carregar uma imagem PPM, convertê-la para tons de cinza e escrever a imagem convertida em um arquivo. Siga as instruções no terminal para interagir com o programa e escolher as opções desejadas.

### Principais Decisões de Implementação:
- O programa permite que o usuário escolha o diretório e o nome do arquivo ao carregar e salvar a imagem.
- A função matrix_deallocation é usada para desalocar a memória alocada dinamicamente para a matriz de pixels, evitando vazamentos de memória.
- Uso de calloc para evitar problemas com "garbage" na memória heap.
- Impressões em inglês para evitar gramática sem acentos dependendo do compilador.
