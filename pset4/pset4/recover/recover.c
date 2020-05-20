#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define block_size 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    FILE *file = NULL;
    file = fopen(argv[1], "r"); //Abrir memoria
    if (file==NULL){
        fprintf(stderr, "Problem opening memory card\n");
        return 1;
    }
    BYTE buffer[block_size];
    int imageCount = 0;
    FILE *img = NULL;
    char filename[8]; //es de 8 bytes 000.jpg=7caracter nulo
    while (true)
    {
        size_t read = fread(buffer, sizeof(BYTE), block_size, file);

        // Exite while loop if End Of File "file"
        if (read == 0 && feof(file))
        {
            break;
        }
        bool isjpg = (buffer [0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0);
        //If jpeg file detected close the previous one and increase image counter
        if (isjpg && img != NULL)
        {
            fclose(img);
            imageCount++;
        }
        //if jpeg file detected create the jpg file
        if (isjpg)
        {
            sprintf(filename, "%03i.jpg", imageCount);
            img = fopen(filename, "w");
        }
        if (img != NULL)
        {
            //writint into the recently created jpg file
            fwrite(buffer, sizeof(BYTE),block_size,img);
        }
    }
    fclose(img);
    fclose(file);
}
