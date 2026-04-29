#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int byte_to_unicode(int c)
{
    if (c >= 0xC0 && c <= 0xFF)
        return (int)(0x0410 + (c - 0xC0));
    return c;
}

int main()
{
    char input_name[256];
    char output_name[256];
    FILE* fin;
    FILE* fout;
    int ch, u;

    /* Ask for input filename */
    printf("Enter input file name: ");
    scanf("%255s", input_name);

    /* Build output filename by adding "_unicode" before the extension */
    char* dot = strrchr(input_name, '.');
    if (dot != NULL)
    {
        /* e.g. "hello.txt" -> "hello_unicode.txt" */
        int base_len = dot - input_name;
        strncpy(output_name, input_name, base_len);
        output_name[base_len] = '\0';
        strcat(output_name, "_unicode");
        strcat(output_name, dot);
    }
    else
    {
        /* No extension: just append "_unicode" */
        strcpy(output_name, input_name);
        strcat(output_name, "_unicode");
    }

    fin = fopen(input_name, "rb");
    if (fin == NULL)
    {
        printf("Error: cannot open %s\n", input_name);
        return 1;
    }

    fout = fopen(output_name, "wb");
    if (fout == NULL)
    {
        printf("Error: cannot create %s\n", output_name);
        fclose(fin);
        return 1;
    }

    /* Write BOM */
    fwrite("\xFF\xFE", 1, 2, fout);

    /* Convert byte by byte */
    while ((ch = fgetc(fin)) != EOF)
    {
        u = byte_to_unicode(ch);
        fputc(u & 0xFF, fout);
        fputc((u >> 8) & 0xFF, fout);
    }

    fclose(fin);
    fclose(fout);

    printf("Done! Saved as: %s\n", output_name);
    return 0;
}