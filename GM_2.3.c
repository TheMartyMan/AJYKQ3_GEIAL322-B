#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// K�sz�tette Garamszegi M�rton - AJYKQ3


int main()
{

    FILE *fp, *fpp;


    char ch;

    char nev1[50];
    char nev2[50] = "atmasolt.txt";


    printf("A fajl neve: ");
    scanf("%s", nev1);

    fp = fopen(nev1, "w");
    printf("Az uzenet: ");

    while( (ch = getchar()) != '#') {
        putc(ch, fp);
    }

    fclose(fp);

    int pos;


    if ((fp = fopen(nev1, "r")) == NULL)
    {
        printf("\nHiba a fajl megnyitasa soran!\n");
        return 0;
    }


    else
    {
        printf("\nFajl megnyitva masolasra\n ");
    }

    fpp = fopen(nev2, "w");
    fseek(fp, 0L, SEEK_END);
    pos = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    while (pos--)
    {
        ch = fgetc(fp);
        fputc(ch, fpp);
    }

    fclose(fp);
    fclose(fpp);
}
