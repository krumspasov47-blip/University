#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    /* Ex 1
    char ch;
    printf("Symbol:");
    scanf("%c", &ch);

    printf("%c%c%c%c%c%c%c%c%c%c\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);
    printf("%c        %c\n", ch, ch);
    printf("%c        %c\n", ch, ch);
    printf("%c        %c\n", ch, ch);
    printf("%c%c%c%c%c%c%c%c%c%c\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);
    */

    /* Ex 2
    float inches;
    printf("Inches:");
    scanf("%f", &inches);
    
    printf("mm: %.2f\n", inches * 25.4);
    printf("cm: %.2f\n", inches * 2.54);
    printf("dm: %.2f\n", inches * 0.254);
    printf("m: %.2f\n", inches * 0.0254);
    */

    /*Ex 3
    float c;
    printf("Celcius:");
    scanf("%f", &c);

    printf("Fahrenheit: %.2f", c * 9 / 5 + 32);
    */

    /* Ex 4
    float degrees;
    float pi = 3.14;
    printf("Degrees:");
    scanf("%f", &degrees);
    
    printf("Radians: %.2f", degrees * pi / 180);
    */

    /* Ex 5
    float leva;
    printf("Leva:");
    scanf("%f", &leva);

    printf("USD: %.2f\n", leva / 1.80);
    printf("EUR: %.2f\n", leva / 1.95);
    printf("GBP: %.2f\n", leva / 2.20);
    */

    /* Ex 6
    float a, b, h;
    printf("Data:");
    scanf("%f %f %f", &a, &b, &h);

    printf("%.2f\n", (a + b) * h / 2);
    */

    /* Ex 7
    float x1, y1, x2, y2;
    printf("Coordiantes:");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    double width = x1 - x2;
    double height = y1 - y2;

    printf("%.2f\n", width * height);
    */

    /* Ex 8
    float x1, y1, x2, y2, x3, y3;
    printf("Coordiantes:");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

    double area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;

    printf("%.2f\n", area);
    */

    /* Ex 9
    float w, h;
    printf("Width and height:");
    scanf("%f %f", &w, &h);

    int rows = (int)((h * 100) / 120);
    int cols = (int)(((w * 100) - 100) / 70);

    int total = rows * cols - 3;

    printf("%d\n", total);
    */

    /* Ex 10
    float vegPrice, fruitPrice;
    int vegKg, fruitKg;
    printf("Prices and kg:");
    scanf("%f %f %d %d", &vegPrice, &fruitPrice, &vegKg, &fruitKg);

    float leva = vegPrice * vegKg + fruitPrice * fruitKg;

    printf("%.2f\n", leva / 1.95);
    */

    return 0;
}
