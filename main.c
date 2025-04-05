//Write your code in this file
/*Varje elev har ett namn och 13 provresultat.
Namnet är ett engelskt förnamn (max 10 tecken långt) och består endast av bokstäver a-z (ej specialtecken eller siffror).
Poängen är heltal mellan 0 och 10 (inklusive 0 och 10). "Så jag slipper växla fönster hela tiden"*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_STUDENTS 5
#define NUM_TESTS 13

struct Student {
    char name[15];
    int scores[NUM_TESTS];
    float average;
};

//Funktion för att räkna medelvärde
float beräkna_medel(int scores[], int antal) {
    int sum = 0;
    for (int i = 0; i < antal; i++) {
        sum += scores[i];
    }
    return (float)sum / antal;
}

//Funktion för att skriva ut namn med stor första bokstav
void skriv_ut_namn(char name[]) {
    char namn_kapital[15];
    strcpy(namn_kapital, name);
    namn_kapital[0] = toupper(namn_kapital[0]);
    printf("%s\n", namn_kapital);
}

int main() {
    struct Student klass[NUM_STUDENTS];

    //Inläsning
    for (int i = 0; i < NUM_STUDENTS; i++) {
        scanf("%s", klass[i].name);
        for (int j = 0; j < NUM_TESTS; j++) {
            scanf("%d", &klass[i].scores[j]);
        }
        klass[i].average = beräkna_medel(klass[i].scores, NUM_TESTS);
    }

    //Hitta elev med högst medelpoäng
    int index_högst = 0;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (klass[i].average > klass[index_högst].average) {
            index_högst = i;
        }
    }

    //Beräkna klassens totala medel
    float klass_medel = 0.0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        klass_medel += klass[i].average;
    }
    klass_medel /= NUM_STUDENTS;

    
    skriv_ut_namn(klass[index_högst].name);

    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (klass[i].average <klass_medel) {
            skriv_ut_namn(klass[i].name);
        }
    }

    return 0;
}

