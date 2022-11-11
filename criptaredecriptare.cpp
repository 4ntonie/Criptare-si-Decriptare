#include <iostream>
#include <cstring>
using namespace std;

char text[100]="acesta este un text ce trebuie sa fie codificat text text";
char criptat[100];


void cripteaza(char text[], char cheie[]) {
    int nr_litere_in_cheie = strlen(cheie);
    int v[strlen(cheie)];
    for (int i = 0; i < strlen(cheie); i++)
        v[i] = cheie[i] - 'a';

    char criptat[strlen(text)];
    int i = 0;
    while (text[i]) {
        if (text[i] != ' ') {
            criptat[i] = text[i] + v[i % nr_litere_in_cheie];
            if (criptat[i] > 'z') criptat[i] -= 26;

        } else criptat[i] = ' ';
        i++;
    }
    criptat[i] = 0;
    for (int i = 0; i < strlen(text); i++)
        text[i] = criptat[i];
}


void decripteaza(char text[], char cheie[]) {
    int nr_litere_in_cheie = strlen(cheie);
    int v[strlen(cheie)];
    for (int i = 0; i < strlen(cheie); i++)
        v[i] = cheie[i] - 'a';

    char criptat[strlen(text)];
    int i = 0;
    while (text[i]) {
        if (text[i] != ' ') {
            criptat[i] = text[i] - v[i % nr_litere_in_cheie];
            if (criptat[i] < 'a') criptat[i] += 26;
        } else criptat[i] = ' ';
        i++;
    }
    criptat[i] = 0;
    for (int i = 0; i < strlen(text); i++)
        text[i] = criptat[i];
}

int main() {
    strcpy(criptat, text);
    cout << criptat << endl;
    cripteaza(criptat, "abecedar");
    cout << criptat << endl;
    decripteaza(criptat, "abecedar");
    cout << criptat << endl;
    return 0;
}
