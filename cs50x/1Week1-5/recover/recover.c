#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s IMAGE\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    uint8_t *buffer = malloc(512);
    if (buffer == NULL)
    {
        fclose(f);
        printf("Memory error\n");
        return 1;
    }

    int count = 0;
    FILE *img = NULL;

    while (fread(buffer, 1, 512, f) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(f);
                free(buffer);
                printf("Error creating output file\n");
                return 1;
            }
            count++;
        }

        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    free(buffer);
    fclose(f);

    return 0;
}
