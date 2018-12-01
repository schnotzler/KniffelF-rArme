#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Settings                                             Default values:
const char playerCount  = 1;    //Anzahl der Spieler                1
const char throwCount   = 3;    //Anzahl der Züge pro Runde - Würfe 3
const char roundCount   = 1;    //Anzahl der Runden                 1
const char diceCount    = 5;    //Anzahl der Würfel max.10          5
const char diceSides    = 6;    //n - Seitige Würfel                6

//Methods given
void initD6()
{
    srand((unsigned)time(NULL));
}
int D6()
{
    return ((rand() % diceSides) + 1);
}
//Methods written
unsigned short takeTurn()
{
    char dice[diceCount];
    char dLock[diceCount];
    for(char z=0; z<diceCount; z++)
    {
        dice[z]=0;
        dLock[z]=0;
    }
    char locked = 0;
    for(char z=0; z<throwCount-1; z++)//Throws 1 - 2ndLast
    {
        if(locked<diceCount)
        {
            printf("\n\t\tThrow %hhi\n\t\t",z+1);
            for(char i=0; i<diceCount; i++)
            {
                if(dLock[i]==0)
                {
                    dice[i]=D6();
                    printf("%hhi ",dice[i]);
                }
            }
            printf("\n\t\t");

            char input[diceCount-locked];
            switch(diceCount-locked)//Only read as many diceLockValues as there were rolled
            {
            case 1:
                scanf("%hhi",&input[0]);
                break;
            case 2:
                scanf("%hhi,%hhi",&input[0],&input[1]);
                break;
            case 3:
                scanf("%hhi,%hhi,%hhi",&input[0],&input[1],&input[2]);
                break;
            case 4:
                scanf("%hhi,%hhi,%hhi,%hhi",&input[0],&input[1],&input[2],&input[3]);
                break;
            case 5:
                scanf("%hhi,%hhi,%hhi,%hhi,%hhi",&input[0],&input[1],&input[2],&input[3],&input[4]);
                break;
            default:
                scanf("%hhi,%hhi,%hhi,%hhi,%hhi,%hhi",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5]);
                break;
            case 7:
                scanf("%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5],&input[6]);
                break;
            case 8:
                scanf("%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5],&input[6],&input[7]);
                break;
            case 9:
                scanf("%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5],&input[6],&input[7],&input[8]);
                break;
            case 10:
                scanf("%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi,%hhi",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5],&input[6],&input[7],&input[8],&input[9]);
                break;
            }
            char inc=0;
            for(char i=0; i<diceCount; i++)
            {
                if(dLock[i]==0)
                {
                    if(input[inc]==1)
                    {
                        dLock[i]=1;
                        locked++;
                    }
                    inc++;
                }
            }
            printf("\t\t");
            for(char i=0; i<diceCount; i++)
            {
                printf("%c ",input[i]);
            }
            /*//Debug Shows which dice are locked
            printf("Lock %hhi\t\t",locked);
            for(char i=0;i<diceCount;i++)
            {
                printf("%hhi ",dLock[i]);
            }*/
        }
    }

    if(locked<diceCount)//Last Throw process only when dices left unlocked
    {
        printf("\n\t\tThrow %hhi\n\t\t",throwCount);//Last Throw Info
        for(char i=0; i<diceCount; i++)//Last Throw
        {
            if(dLock[i]==0)
            {
                dice[i]=D6();
                printf("%hhi ",dice[i]);
            }
        }
    }

    short result = 0;
    printf("\nFinal Values:\n\t\t");
    for(char z=0; z<diceCount; z++)
    {
        printf("%hhi ",dice[z]);
        result=result+dice[z];
    }
    printf("=> %hhi Pts.\n",result);
    return result;
}

int main()
{
    initD6();
    unsigned short playerScore[playerCount];
    for(unsigned char z = 0; z<playerCount; z++)
    {
        playerScore[z]=0;
    }
    printf("\n\t\t\t - - - KNIFFEL FUER ARME - - -\n\nSettings:\n\t-%hhi players\n\t-%hhi dice\n\t-%hhi sided dice\n\t-%hhi rounds a.k.a. turns per player\n\t-%hhi dice throws per turn\n\nHow to select Dices after throwing:\n\t2 6 3 5 1\n\t0,1,0,1,0\nSelect by typing '1'discard with any other number e.g. '0'.\nSeperate your selections by ',' .\n\n",
           playerCount,diceCount,diceSides,roundCount,throwCount);
    for(unsigned char z=0; z<roundCount; z++)
    {
        printf("Round %hhu:",z+1);
        for(unsigned char p = 0; p<playerCount; p++)
        {
            printf("\n\tPlayer %hhu:\t%hu Pts.\n",p+1,playerScore[p]);
            playerScore[p]=(playerScore[p]+takeTurn());
            printf("\t\t=>Score: %hu Pts\n",playerScore[p]);
        }
    }
    printf("\n\n\t- - - GAME RESULTS - - -");
    for(char z=0; z<playerCount; z++)
    {
        printf("\nPlayer \t%hhi: %hu \tPts.",z+1,playerScore[z]);
    }
    printf("\n\n");
    return 0;
}

