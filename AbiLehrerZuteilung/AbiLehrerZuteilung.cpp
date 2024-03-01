#include <iostream>
#include <math.h>
using namespace std;
void nextSchueler(int counter);
void printProgress(int counter);


int schuelerZahl = 65;
int schueler[65][2] =
{ 
    {1,20},{2,4},{3,1},{4,20},{1,3},{5,8},{2,1},{5,1},{2,20},{3,8},{1,5},{2,1},{4,1},{1,8},{7,2},{8,4},{9,7},{5,7},{10,28},{7,2},{7,2},{7,10},{10,28},{11,10},{7,28},{10,22},{2,11},{7,10},{10,28},{2,9},{12,27},{11,2},{7,9},{7,10},{2,4},{11,2},{2,10},{10,28},{14,16},{15,5},{3,24},{14,19},{16,20},{17,19},{18,14},{14,20},{16,19},{17,19},{19,14},{18,14},{19,17},{18,19},{17,18},{14,18},{17,19},{5,20},{1,11},{19,5},{1,5},{1,20},{1,25},{8,26},{19,1},{19,8},{19,26}
};

int way[65];
int bestWay[65];

int bestWaySum = 100;
int sumNow = 0;


long long sevenCounter = 0;
long aCnt = 0;

unsigned long long cnt = 0;
int lehrerCnt[28];

int main()
{
    for (int i = 0; i < 28; i++)
    {
        lehrerCnt[i] = 0;
    }
    for (int i = 0; i < 65; i++)
    {
        way[i] = 0;
        bestWay[i] = 0;
    }

    bestWaySum = 100;
    nextSchueler(0);
    for (int i = 0; i < 65; i++)
    {
        if(bestWay[i] + 1==2)cout << i + 1 << ": " << bestWay[i]+1 << endl;
    }
    cout << cnt << " Berechnungen!" << endl;
    cout << aCnt << " kleinere Berechnungen!" << endl;
}

void nextSchueler(int counter)
{
    if (counter >= schuelerZahl)
    {
        cnt++;
        
        if (sumNow <= bestWaySum)
        {

            aCnt++;
            bestWaySum = sumNow;
            for (int i = 0; i < 65; i++)
            {
                bestWay[i] = way[i];
            }
        }
        

    }
    else
    {
        int teach = schueler[counter][0];
        if (lehrerCnt[teach] < 4)
        {
            if (teach != 5)
            {
                lehrerCnt[teach]++;
                way[counter] = 0;
                nextSchueler(counter + 1);
                lehrerCnt[teach]--;
            }
            else if (counter < 7)printProgress(counter);
        }
        else if(counter<7)printProgress(counter);

        teach = schueler[counter][1];
        if (lehrerCnt[teach] < 4)
        {
            if (teach != 5)
            {
                sumNow++;
                lehrerCnt[teach]++;
                way[counter] = 1;
                nextSchueler(counter + 1);
                lehrerCnt[teach]--;
                sumNow--;
            }
            else if (counter < 7)printProgress(counter);
        }
        else if (counter < 7)printProgress(counter);

        if (counter == 7)printProgress(counter);
    }
}

void printProgress(int counter)
{
    if (counter != 7)sevenCounter += pow(2, (6 - counter));
    else sevenCounter++;
    cout << sevenCounter << " / 128" << endl;
}