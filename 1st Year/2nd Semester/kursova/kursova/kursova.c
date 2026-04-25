#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned short byte_to_unicode(unsigned short c)
{
    /* Кирилицата в Windows-1251 започва от 0xC0 (192)
     * и отговаря точно на Unicode блока за кирилица от 0x0410 */
    if (c >= 0xC0 && c <= 0xFF)
        return (unsigned short)(0x0410 + (c - 0xC0));

    /* Всички ASCII символи (0-127) имат същия номер в Unicode */
    return c;
}

int main(void)
{
    FILE* fin;
    FILE* fout;
    int ch;
    unsigned short unicode_num;
    unsigned char  bom[2];

    /* Отваряме входния файл за четене в двоичен режим */
    fin = fopen("input.txt", "rb");
    if (fin == NULL)
    {
        printf("Грешка: не може да се отвори input.txt\n");
        return 1;
    }

    /* Създаваме изходния файл за писане в двоичен режим */
    fout = fopen("output_unicode.txt", "wb");
    if (fout == NULL)
    {
        printf("Грешка: не може да се създаде output_unicode.txt\n");
        fclose(fin);
        return 1;
    }

    fwrite("\xFF\xFE", 1, 2, fout);

    /* Четем входния файл байт по байт до края му */
    while ((ch = fgetc(fin)) != EOF)
    {
        /* Преобразуваме байта в Unicode номер */
        unicode_num = byte_to_unicode((unsigned short)ch);

        /* Записваме Unicode номера като 2 байта (UTF-16 LE формат):*/
        /* първо записваме десния (low) байт, после левия (high) байт */
        fputc(unicode_num & 0xFF, fout);  /* low byte  */
        fputc((unicode_num >> 8) & 0xFF, fout);  /* high byte */
    }

    fclose(fin);
    fclose(fout);

    printf("Готово! Файлът е записан като output_unicode.txt\n");

    return 0;
}