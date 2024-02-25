// AbiLehrerZuteilung.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void nextSchueler(int counter);


int schuelerZahl = 64;
int schueler[64][2] =
{ { 1,20 },
    { 2,4 },
    { 3,1 },
    { 4,20 },
    { 1,3 },
    { 5,8 },
    { 2,1 },
    { 5,6 },
    { 2,20 },
    { 3,8 },
    { 6,5 },
    { 2,1 },
    { 4,1 },
    { 1,8 },
    { 7,2 },
    { 8,4 },
    { 9,7 },
    { 5,7 },
    { 10,28 },
    { 7,2 },
    { 7,10 },
    { 10,28 },
    { 11,10 },
    { 7,28 },
    { 10,22 },
    { 2,11 },
    { 7,10 },
    { 10,28 },
    { 2,9 },
    { 12,27 },
    { 11,2 },
    { 7,9 },
    { 7,10 },
    { 2,4 },
    { 13,2 },
    { 2,10 },
    { 10,28 },
    { 14,16 },
    { 15,5 },
    { 3,24 },
    { 14,19 },
    { 16,20 },
    { 17,19 },
    { 18,14 },
    { 14,20 },
    { 16,19 },
    { 17,19 },
    { 19,14 },
    { 18,14 },
    { 19,17 },
    { 18,19 },
    { 17,18 },
    { 14,18 },
    { 17,19 },
    { 5,20 },
    { 1,11 },
    { 19,5 },
    { 1,5 },
    { 1,20 },
    { 1,25 },
    { 8,26 },
    { 19,1 },
    { 19,8 },
    { 19,26 } };
int aktAuswahl[64];
int bestAuswahl[64];
char way[64];
char bestWay[64];
char bestWaySum = 64;
char sumNow = 0;

char sevenCounter = 0;

unsigned long long cnt = 0;
int lehrerCnt[28];

int main()
{
    for (int i = 0; i < 28; i++)
    {
        lehrerCnt[i] = 0;
    }
    cout << "Start" << endl;
    nextSchueler(0);
    for (int i = 0; i < 64; i++)
    {
        cout << i + 1 << ": " << bestWay[i] << endl;
    }

}

void nextSchueler(int counter)
{
    if (counter >= schuelerZahl-1)
    {
        if (sumNow < bestWaySum)
        {
            for (int i = 0; i < 64; i++)
            {
                way[i]=bestWay[i];
            }
        }
    }
    else
    {
        auto start = high_resolution_clock::now();
        int teach = schueler[counter][0];
        if (lehrerCnt[teach] < 4)
        {
            if (teach != 5)
            {
                lehrerCnt[teach]++;
                way[counter] = 0;
                aktAuswahl[counter] = teach;
                nextSchueler(counter + 1);
                lehrerCnt[teach]--;
            }
        }
        teach = schueler[counter][1];
        if (lehrerCnt[teach] < 4)
        {
            if (teach != 5)
            {
                sumNow++;
                lehrerCnt[teach]++;
                way[counter] = 1;
                aktAuswahl[counter] = teach;
                nextSchueler(counter + 1);
                lehrerCnt[teach]--;
                sumNow--;
            }
        }
        if (counter == 7)
        {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            sevenCounter++;
            cout << sevenCounter << "/128 (" << duration.count()/1000000 <<"s)" << endl;
        }
    }
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
