#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define TotalMoves 9
#define TotalWins 212256
#define TotalLosses 104544
#define TotalTies 46080

int Display(int Board[3][3])
{
    int iTemp1;
    int iTemp2;
    int Value;
    char cTemp;

    for(iTemp1=0; iTemp1<3; iTemp1++)
    {
        for(iTemp2=0; iTemp2<3; iTemp2++)
        {
          Value=Board[iTemp1][iTemp2];
          if(Value==1)
          {
              cTemp='X';
          }
          else if(Value==0)
          {
              cTemp='O';
          }
          else if(Value==3)
          {
              cTemp='W';
          }
          else
          {
              cTemp='_';
          }
          printf("[ %c ]",cTemp );
        }
        printf("\t\t");
        for(iTemp2=0; iTemp2<3; iTemp2++)
        {
            printf("[ %d ]",((iTemp1)*3) + iTemp2 +1 );
        }
        printf("\n");

    }

}
int CheckMove(int Board[3][3], int MoveNo, int iCurrMove)
{
    //printf("Move Index: %d, %d\nCurrent Value: %d\n", (MoveVal/3), (MoveVal%3) , Board[(MoveVal/3)][(MoveVal%3)]);
    if(Board[(iCurrMove-1)/3][(iCurrMove-1)%3]==-1)
    {
        //printf("0\n");
        return(0);

    }
    else
    {
        //printf("1\n" );
        return(1);
    }
}
int CheckWin(int Board[3][3], int MoveNo)
{
    int iTemp1;
    int iTemp2;
    int iTemp3;
    int Flag;

    Flag=0;

    if(Board[0][0]==Board[1][1] && Board [1][1]==Board[2][2] && Board[0][0]!= -1)
    {
        printf("\n**Player %d Wins**\n", 2-MoveNo%2 );
        Board[0][0]=3;
        Board[1][1]=3;
        Board[2][2]=3;
        Flag=1;
        exit;
    }
    if(Board[0][2]==Board[1][1] && Board [1][1]==Board[2][0] && Board[2][0]!= -1)
    {
        printf("\n**Player %d Wins**\n", 2-MoveNo%2 );
        Board[2][0]=3;
        Board[1][1]=3;
        Board[0][2]=3;
        Flag=1;
        exit;
    }

    for(iTemp1=0; iTemp1<3; iTemp1++)
    {
        if(Board[iTemp1][0]==Board[iTemp1][1] && Board[iTemp1][0]==Board[iTemp1][2] && Board[iTemp1][2]!= -1)
        {
            //printf("\n**Player %d Wins**\n", 2-MoveNo%2 );
            Board[iTemp1][0]=3;
            Board[iTemp1][1]=3;
            Board[iTemp1][2]=3;
            Flag=1;
            break;
        }
        if(Board[0][iTemp1]==Board[1][iTemp1] && Board[0][iTemp1]==Board[2][iTemp1] && Board[2][iTemp1]!= -1)
        {
            //printf("\n**Player %d Wins**\n", 2-MoveNo%2 );
            Board[0][iTemp1]=3;
            Board[1][iTemp1]=3;
            Board[2][iTemp1]=3;
            Flag=1;
            break;
        }

    }

    //printf("%d\n", Flag );
    return(Flag);
}
void LoadArrays(int *TotalWinsArr, int *TotalLossesArr, int *TotalTiesArr, int LoadArrFlag)
{


    //printf("Addresses: Wins: %p, Losses: %p, Ties: %p\n", TotalWinsArr, TotalLossesArr, TotalLossesArr);

    //WinsArr=TotalWinsArr;
    //LossesArr=TotalLossesArr;
    //TiesArr=TotalTiesArr;

    FILE *WinsIn;
    FILE *LossesIn;
    FILE *TiesIn;

    int iTemp1;
    int iTemp2;
    //int iTemp3;
    //int Flag;

    char sTemp[10];
    //char cTemp1;
    //char cTemp2;

    WinsIn=fopen("Wins_Final.txt", "r");
    LossesIn=fopen("Losses_Final.txt", "r");
    TiesIn=fopen("Ties_Final.txt", "r");

    LoadArrFlag=0;
    //CHECKING WHETHER FILE INPUT POINTERS HAVE BEEN CORRECTLY ASSIGNED
    if (WinsIn==NULL)
    {
        //printf("Bad File Input for Wins\n");
        LoadArrFlag=1;
    }
    if (LossesIn==NULL)
    {
        //printf("Bad File Input for Losses\n");
        LoadArrFlag=1;
    }
    if (TiesIn==NULL)
    {
        LoadArrFlag=1;
        //printf("Bad File Input for Ties\n");
    }

    //CHECKING WHETHER ALL DYNAMICALLY ALLOCATED 2-D ARRAYS HAVE BEEN PROPERLY ALLOCATED

    //BRINGING IN INPUT FROM FILES AND MOVING IT TO DYNAMICALLY ALLOCATED ARRAYS
    //WINS
    for(iTemp1=0; iTemp1<TotalWins; iTemp1++)
    {
        fscanf(WinsIn, "%s", sTemp);
        //printf("%s\n",sTemp);
        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            *(TotalWinsArr + iTemp1*TotalMoves +iTemp2)=((int)sTemp[iTemp2])-48;
            //printf("%d", *(TotalWinsArr + iTemp1*TotalMoves +iTemp2) );
        }
        //printf("\n");
    }
    //printf("Wins Loaded\n");
    //LOSSES
    for(iTemp1=0; iTemp1<TotalLosses; iTemp1++)
    {
        fscanf(LossesIn, "%s", sTemp);
        //printf("%s\n",sTemp);
        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            *(TotalLossesArr + iTemp1*TotalMoves +iTemp2)=((int)sTemp[iTemp2])-48;
            //printf("%d", *(TotalLossesArr + iTemp1*TotalMoves +iTemp2) );
        }
        //printf("\n");
    }
    //printf("Losses Loaded\n");
    //TIES
    for(iTemp1=0; iTemp1<TotalTies; iTemp1++)
    {
        fscanf(TiesIn, "%s", sTemp);
        //printf("%s\n",sTemp);
        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            *(TotalTiesArr + iTemp1*TotalMoves +iTemp2)=((int)sTemp[iTemp2])-48;
            //printf("%d", *(TotalTiesArr + iTemp1*TotalMoves +iTemp2) );
        }
        //printf("\n");
    }
    //printf("Ties Loaded\n");
    //ARRAYS LOADED
    //printf("Addresses: Wins: %p, Losses: %p, Ties: %p\n", TotalWinsArr,TotalLossesArr, TotalTiesArr );
    //printf("Flag: %d\n",LoadArrFlag );
}
int MoveToTemp(int *CurrArr, int *TempArr, int iSize)
{
    int iTemp1;
    int iTemp2;
    for(iTemp1=0; iTemp1<iSize; iTemp1++)
    {

        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            *(TempArr + iTemp1*TotalMoves + iTemp2)= *(CurrArr + iTemp1*TotalMoves +iTemp2);
            //printf("%d", *(TotalTiesArr + iTemp1*TotalMoves +iTemp2) );
        }
        //printf("\n");
    }
}
int PrintArr(int *CurrArr, int ArrSize)
{
    int iTemp1;
    int iTemp2;

    for(iTemp1=0; iTemp1<ArrSize; iTemp1++)
    {
        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            printf("%d", *(CurrArr + iTemp1*TotalMoves +iTemp2) );
        }
        printf("\n");
    }
    return(0);
}
void PlayerMove(int Board[3][3], int iMoveNo, int Moves[])
{
    int iCurrMove;
    int Flag;

    printf("Your Move: ");
    scanf("%d", &iCurrMove);
    Flag=CheckMove(Board, iMoveNo, iCurrMove);
    if(Flag==0)
    {
        Board[(iCurrMove-1)/3][(iCurrMove-1)%3]=0;
        Moves[iMoveNo-1]=iCurrMove;
    }
    else
    {
        printf("Invalid Move.\n");
        PlayerMove(Board, iMoveNo, Moves);
    }
}
int FindCPUMovePlayingFirst(int *CurrWinsArr, int *CurrLossesArr, int *CurrTiesArr, int iMoveNo, int Moves[], int CurrWinsCount, int CurrLossesCount, int CurrTiesCount)
{
    int iTemp1;
    int iTemp2;
    int iCurrMove;
    int MoveVals[9]={0, 0, 0, 0, 0, 0 , 0, 0, 0};
    char cTemp1;
    int BestMove;
    int MostWins;
    for(iTemp1=0; iTemp1<CurrWinsCount; iTemp1++)
    {

        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            iCurrMove= *(CurrWinsArr + iTemp1*TotalMoves + iTemp2);
            //printf("%d", iCurrMove);
            //MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+1.5;
        }

        iCurrMove=*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo-1);
        MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+5;
        //printf("\n");
        //printf("%d\n",*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo-1));
    }
    //cTemp1=getchar();
    for(iTemp1=0; iTemp1<CurrLossesCount; iTemp1++)
    {

        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            iCurrMove= *(CurrLossesArr + iTemp1*TotalMoves + iTemp2);
            //printf("%d", iCurrMove);
            //MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]-2;
        }

        iCurrMove=*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo-1);
        MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+1;
        //printf("\n");
        //printf("%d\n",*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo-1));
    }
    //cTemp1=getchar();
    for(iTemp1=0; iTemp1<CurrTiesCount; iTemp1++)
    {

        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            iCurrMove= *(CurrTiesArr + iTemp1*TotalMoves + iTemp2);
            //printf("%d", iCurrMove);
            //MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+0.5;
        }

        iCurrMove=*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo-1);
        MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+3;
        //printf("\n");
        //printf("%d\n",*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo-1));
    }
    //cTemp1=getchar();
    MostWins=MoveVals[0];
    BestMove=1;
    for(iTemp1=0; iTemp1<9; iTemp1++)
    {
        //printf("%d: %d\n", iTemp1+1, MoveVals[iTemp1]);
        if(MoveVals[iTemp1]>MostWins)
        {
            MostWins=MoveVals[iTemp1];
            BestMove=iTemp1+1;
        }
    }
    //printf("BestMove: %d\n", BestMove);
    return(BestMove);
}
int FindCPUMovePlayingSecond(int *CurrWinsArr, int *CurrLossesArr, int *CurrTiesArr, int iMoveNo, int Moves[], int CurrWinsCount, int CurrLossesCount, int CurrTiesCount)
{
    int iTemp1;
    int iTemp2;
    int iCurrMove;
    int MoveVals[9]={0, 0, 0, 0, 0, 0 , 0, 0, 0};
    char cTemp1;
    int BestMove;
    int MostWins;
    for(iTemp1=0; iTemp1<CurrWinsCount; iTemp1++)
    {

        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            iCurrMove= *(CurrWinsArr + iTemp1*TotalMoves + iTemp2);
            //printf("%d", iCurrMove);
            //MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+1.5;
        }

        iCurrMove=*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo-1);
        MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+1;
        //printf("\n");
        //printf("%d\n",*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo-1));
    }
    //cTemp1=getchar();
    for(iTemp1=0; iTemp1<CurrLossesCount; iTemp1++)
    {

        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            iCurrMove= *(CurrLossesArr + iTemp1*TotalMoves + iTemp2);
            //printf("%d", iCurrMove);
            //MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]-2;
        }

        iCurrMove=*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo-1);
        MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+4;
        //printf("\n");
        //printf("%d\n",*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo-1));
    }
    //cTemp1=getchar();
    for(iTemp1=0; iTemp1<CurrTiesCount; iTemp1++)
    {

        for(iTemp2=0; iTemp2<TotalMoves; iTemp2++)
        {
            iCurrMove= *(CurrTiesArr + iTemp1*TotalMoves + iTemp2);
            //printf("%d", iCurrMove);
            //MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+0.5;
        }

        iCurrMove=*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo-1);
        MoveVals[iCurrMove-1]=MoveVals[iCurrMove-1]+3;
        //printf("\n");
        //printf("%d\n",*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo-1));
    }
    //cTemp1=getchar();
    MostWins=MoveVals[0];
    BestMove=1;
    for(iTemp1=0; iTemp1<9; iTemp1++)
    {
        //printf("%d: %d\n", iTemp1+1, MoveVals[iTemp1]);
        if(MoveVals[iTemp1]>MostWins)
        {
            MostWins=MoveVals[iTemp1];
            BestMove=iTemp1+1;
        }
    }

    //printf("BestMove: %d\n", BestMove);
    return(BestMove);
}
int main()
{
    int LoadArrFlag;
    int CurrLoadFlag;
    int iMoveNo;
    int iCurrMove;
    int MoveFlag;
    int TossVal;

    int *TotalWinsArr;
    int *TotalLossesArr;
    int *TotalTiesArr;

    int *CurrWinsArr;
    int *CurrLossesArr;
    int *CurrTiesArr;

    int *TempWinsArr;
    int *TempLossesArr;
    int *TempTiesArr;

    int Board[3][3]={-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int Moves[9]={0, 0, 0, 0, 0, 0, 0, 0, 0};

    int CurrWinsCount;
    int CurrLossesCount;
    int CurrTiesCount;

    int TempWinsCount;
    int TempLossesCount;
    int TempTiesCount;

    int iTemp1;
    int iTemp2;
    int iTemp3;
    int iTemp4;

    int WinFlag;

    char cTemp1;

    LoadArrFlag=0;
    TotalWinsArr= (int*)malloc(TotalWins * TotalMoves * sizeof(int));
    TotalLossesArr= (int*)malloc(TotalLosses * TotalMoves * sizeof(int));
    TotalTiesArr= (int*)malloc(TotalTies * TotalMoves *sizeof(int));

    if (TotalWinsArr==NULL)
    {
        LoadArrFlag=2;
        //printf("Bad Array Allocation for Wins\n");
    }
    if (TotalLossesArr==NULL)
    {
        LoadArrFlag=2;
        //printf("Bad Array Allocation for Losses\n");
    }
    if (TotalTiesArr==NULL)
    {
        LoadArrFlag=2;
        //printf("Bad Array Allocation for Ties\n");
    }
    LoadArrays(TotalWinsArr, TotalLossesArr, TotalTiesArr, LoadArrFlag);
    //printf("LoadArrFlag: %d\n",LoadArrFlag );
    //printf("Addresses: Wins: %p, Losses: %p, Ties: %p\n", TotalWinsArr, TotalLossesArr, TotalTiesArr);

    if(LoadArrFlag==2)
    {
        printf("There has been a Dynamic Memory Allocation Error.\n");
        exit(2);
    }
    else if(LoadArrFlag==1)
    {
        printf("There has been a File Input Error. Please check whether the required files are availible in the folder\n");
        exit(1);
    }
    else if(LoadArrFlag!=0 && LoadArrFlag!=1 && LoadArrFlag!=2)
    {
        printf("Unknown Error Occured. Please Try Again.\n");
        exit(-1);
    }
    else
    {
        /*
        PrintArr(TotalWinsArr, TotalWins);
        cTemp1=getchar();
        PrintArr(TotalLossesArr, TotalLosses);
        cTemp1=getchar();
        PrintArr(TotalTiesArr, TotalTies);
        */

        printf("Please Make Your Move According to the Legend\n" );
        printf("[ 1 ][ 2 ][ 3 ]\n[ 4 ][ 5 ][ 6 ]\n[ 7 ][ 8 ][ 9 ]\n\n" );
        //Display(Board);

        CurrWinsCount=TotalWins;
        CurrLossesCount=TotalLosses;
        CurrTiesCount=TotalTies;

        CurrWinsArr= (int*)malloc(CurrWinsCount * TotalMoves * sizeof(int));
        CurrLossesArr= (int*)malloc(CurrLossesCount * TotalMoves * sizeof(int));
        CurrTiesArr= (int*)malloc(CurrTiesCount * TotalMoves *sizeof(int));

        MoveToTemp(TotalWinsArr, CurrWinsArr, TotalWins);
        MoveToTemp(TotalLossesArr, CurrLossesArr, TotalLosses);
        MoveToTemp(TotalTiesArr, CurrTiesArr, TotalTies);

        srand(time(0));
        printf("Toss. Call Heads or Tails(H/T): ");
        scanf("%c", &cTemp1);
        iTemp1=rand();
        iTemp1=iTemp1%2;
        if(cTemp1=='H' || cTemp1=='h')
        {
            iTemp2=0;
        }
        else if(cTemp1=='T' || cTemp1=='t')
        {
            iTemp2=1;
        }
        else
        {
            printf("Invalid Toss Input. Try Again.\n");
            exit(9);
        }
        if(iTemp1==iTemp2)
        {
            printf("You have won the Toss. Please Play First.\n");
            Display(Board);
            printf("\n");
            for(iMoveNo=1; iMoveNo<10; iMoveNo++)
            {
                CurrLoadFlag=0;
                /*
                PrintArr(CurrWinsArr, CurrWinsCount);
                cTemp1=getchar();
                PrintArr(CurrLossesArr, CurrLossesCount);
                cTemp1=getchar();
                PrintArr(CurrTiesArr, CurrTiesCount);
                cTemp1=getchar();
                */
                if (CurrWinsArr==NULL || CurrLossesArr==NULL || CurrTiesArr==NULL)
                {
                    CurrLoadFlag=2;
                    //printf("Bad Array Allocation for Wins\n");
                }
                if(iMoveNo%2==0)
                {
                    iCurrMove=FindCPUMovePlayingSecond(CurrWinsArr, CurrLossesArr, CurrTiesArr, iMoveNo, Moves, CurrWinsCount, CurrLossesCount, CurrTiesCount);
                    //printf("iCurrMove: %d\n", iCurrMove);
                    MoveFlag=CheckMove(Board, iMoveNo, iCurrMove);
                    if(MoveFlag==0)
                    {
                        Board[(iCurrMove-1)/3][(iCurrMove-1)%3]=1;
                        Moves[iMoveNo-1]=iCurrMove;
                    }
                    Display(Board);
                    printf("CPU's Move: %d\n", Moves[iMoveNo-1]);
                    WinFlag=CheckWin(Board, iMoveNo);
                    if(WinFlag==1)
                    {
                        printf("\n\n");
                        Display(Board);
                        printf("\n***RESULT: The code Wins.***\n");
                        iMoveNo=10;
                        exit(1);
                    }
                }
                else
                {
                    //Player's Moves
                    PlayerMove(Board, iMoveNo, Moves);
                    Display(Board);
                    WinFlag=CheckWin(Board, iMoveNo);
                    if(WinFlag==1)
                    {
                        printf("\n\n");
                        Display(Board);
                        printf("\n***RESULT: You Win. Congratulations!***\n");
                        iMoveNo=10;
                        exit(2);
                    }
                }

                printf("\n");

                iCurrMove=Moves[iMoveNo-1];
                TempWinsCount=0;
                TempLossesCount=0;
                TempTiesCount=0;

                for(iTemp1=0; iTemp1<CurrWinsCount; iTemp1++)
                {
                    iTemp3=*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        //printf("%d %d\n", iTemp3, iCurrMove);
                        TempWinsCount++;
                    }

                }
                //printf("%d\n",TempWinsCount );
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<CurrLossesCount; iTemp1++)
                {
                    iTemp3=*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        //printf("%d %d\n", iTemp3, iCurrMove);
                        TempLossesCount++;
                    }

                }
                //printf("%d\n",TempLossesCount );
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<CurrTiesCount; iTemp1++)
                {
                    iTemp3=*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        //printf("%d %d\n", iTemp3, iCurrMove);
                        TempTiesCount++;
                    }

                }
                //printf("%d\n",TempTiesCount );
                //cTemp1=getchar();

                TempWinsArr= (int*)malloc(TempWinsCount * TotalMoves * sizeof(int));
                TempLossesArr= (int*)malloc(TempLossesCount * TotalMoves * sizeof(int));
                TempTiesArr= (int*)malloc(TempTiesCount * TotalMoves *sizeof(int));

                if(TempWinsArr==NULL || TempLossesArr==NULL || TempTiesArr==NULL)
                {
                    printf("Temp Array Alloc Error.\n");
                    exit(5);
                }

                iTemp4=0;
                for(iTemp1=0; iTemp1<CurrWinsCount; iTemp1++)
                {
                    iTemp3=*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        for(iTemp2=0; iTemp2<9; iTemp2++)
                        {
                            *(TempWinsArr + iTemp4*TotalMoves + iTemp2)= *(CurrWinsArr + iTemp1*TotalMoves +iTemp2);
                        }
                        iTemp4++;
                    }
                }
                //PrintArr(TempWinsArr, TempWinsCount);
                //cTemp1=getchar();


                iTemp4=0;
                for(iTemp1=0; iTemp1<CurrLossesCount; iTemp1++)
                {
                    iTemp3=*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        for(iTemp2=0; iTemp2<9; iTemp2++)
                        {
                            *(TempLossesArr + iTemp4*TotalMoves + iTemp2)= *(CurrLossesArr + iTemp1*TotalMoves +iTemp2);
                        }
                        iTemp4++;
                    }
                }
                //PrintArr(TempLossesArr, TempLossesCount);
                //cTemp1=getchar();

                iTemp4=0;
                for(iTemp1=0; iTemp1<CurrTiesCount; iTemp1++)
                {
                    iTemp3=*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        for(iTemp2=0; iTemp2<9; iTemp2++)
                        {
                            *(TempTiesArr + iTemp4*TotalMoves + iTemp2)= *(CurrTiesArr + iTemp1*TotalMoves +iTemp2);
                        }
                        iTemp4++;
                    }
                }
                //PrintArr(TempTiesArr, TempTiesCount);
                //cTemp1=getchar();

                //printf("Ran Upto Here\n");
                //cTemp1=getchar();
                free(CurrWinsArr);
                free(CurrLossesArr);
                free(CurrTiesArr);

                CurrWinsCount=TempWinsCount;
                CurrLossesCount=TempLossesCount;
                CurrTiesCount=TempTiesCount;

                //printf("Ran Upto Here2\n");
                //cTemp1=getchar();

                CurrWinsArr= (int*)malloc(CurrWinsCount * TotalMoves * sizeof(int));
                CurrLossesArr= (int*)malloc(CurrLossesCount * TotalMoves * sizeof(int));
                CurrTiesArr= (int*)malloc(CurrTiesCount * TotalMoves *sizeof(int));

                //printf("Ran Upto Here3\n");
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<TempWinsCount; iTemp1++)
                {
                    for(iTemp2=0; iTemp2<9; iTemp2++)
                    {
                        *(CurrWinsArr + iTemp1*TotalMoves + iTemp2)= *(TempWinsArr + iTemp1*TotalMoves +iTemp2);
                    }
                }
                //PrintArr(CurrWinsArr, CurrWinsCount);
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<TempLossesCount; iTemp1++)
                {
                    for(iTemp2=0; iTemp2<9; iTemp2++)
                    {
                        *(CurrLossesArr + iTemp1*TotalMoves + iTemp2)= *(TempLossesArr + iTemp1*TotalMoves +iTemp2);
                    }
                }
                //PrintArr(CurrLossesArr, CurrLossesCount);
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<TempTiesCount; iTemp1++)
                {
                    for(iTemp2=0; iTemp2<9; iTemp2++)
                    {
                        *(CurrTiesArr + iTemp1*TotalMoves + iTemp2)= *(TempTiesArr + iTemp1*TotalMoves +iTemp2);
                    }
                }
                //PrintArr(CurrTiesArr, CurrTiesCount);
                //cTemp1=getchar();

                //printf("Ran Upto Here4\n");
                //cTemp1=getchar();

                free(TempWinsArr);
                free(TempLossesArr);
                free(TempTiesArr);

                //printf("Ran Upto Here5\n");
                //cTemp1=getchar();


            }
        }
        else
        {
            printf("CPU has won the Toss. CPU Plays First.\n");
            Display(Board);
            printf("\n");
            for(iMoveNo=1; iMoveNo<10; iMoveNo++)
            {
                CurrLoadFlag=0;
                /*
                PrintArr(CurrWinsArr, CurrWinsCount);
                cTemp1=getchar();
                PrintArr(CurrLossesArr, CurrLossesCount);
                cTemp1=getchar();
                PrintArr(CurrTiesArr, CurrTiesCount);
                cTemp1=getchar();
                */
                if (CurrWinsArr==NULL || CurrLossesArr==NULL || CurrTiesArr==NULL)
                {
                    CurrLoadFlag=2;
                    //printf("Bad Array Allocation for Wins\n");
                }
                if(iMoveNo%2==1)
                {
                    iCurrMove=FindCPUMovePlayingFirst(CurrWinsArr, CurrLossesArr, CurrTiesArr, iMoveNo, Moves, CurrWinsCount, CurrLossesCount, CurrTiesCount);
                    //printf("iCurrMove: %d\n", iCurrMove);
                    MoveFlag=CheckMove(Board, iMoveNo, iCurrMove);
                    if(MoveFlag==0)
                    {
                        Board[(iCurrMove-1)/3][(iCurrMove-1)%3]=1;
                        Moves[iMoveNo-1]=iCurrMove;
                    }
                    Display(Board);
                    printf("CPU's Move: %d\n", Moves[iMoveNo-1]);
                    WinFlag=CheckWin(Board, iMoveNo);
                    if(WinFlag==1)
                    {
                        printf("\n\n");
                        Display(Board);
                        printf("\n***RESULT: The code Wins.***\n");
                        iMoveNo=10;
                        exit(1);
                    }
                }
                else
                {
                    //Player's Moves
                    PlayerMove(Board, iMoveNo, Moves);
                    Display(Board);
                    WinFlag=CheckWin(Board, iMoveNo);
                    if(WinFlag==1)
                    {
                        printf("\n\n");
                        Display(Board);
                        printf("\n***RESULT: You Win. Congratulations!***\n");
                        iMoveNo=10;
                        exit(2);
                    }
                }

                printf("\n");

                iCurrMove=Moves[iMoveNo-1];
                TempWinsCount=0;
                TempLossesCount=0;
                TempTiesCount=0;

                for(iTemp1=0; iTemp1<CurrWinsCount; iTemp1++)
                {
                    iTemp3=*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        //printf("%d %d\n", iTemp3, iCurrMove);
                        TempWinsCount++;
                    }

                }
                //printf("%d\n",TempWinsCount );
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<CurrLossesCount; iTemp1++)
                {
                    iTemp3=*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        //printf("%d %d\n", iTemp3, iCurrMove);
                        TempLossesCount++;
                    }

                }
                //printf("%d\n",TempLossesCount );
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<CurrTiesCount; iTemp1++)
                {
                    iTemp3=*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        //printf("%d %d\n", iTemp3, iCurrMove);
                        TempTiesCount++;
                    }

                }
                //printf("%d\n",TempTiesCount );
                //cTemp1=getchar();

                TempWinsArr= (int*)malloc(TempWinsCount * TotalMoves * sizeof(int));
                TempLossesArr= (int*)malloc(TempLossesCount * TotalMoves * sizeof(int));
                TempTiesArr= (int*)malloc(TempTiesCount * TotalMoves *sizeof(int));

                if(TempWinsArr==NULL || TempLossesArr==NULL || TempTiesArr==NULL)
                {
                    printf("Temp Array Alloc Error.\n");
                    exit(5);
                }

                iTemp4=0;
                for(iTemp1=0; iTemp1<CurrWinsCount; iTemp1++)
                {
                    iTemp3=*(CurrWinsArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        for(iTemp2=0; iTemp2<9; iTemp2++)
                        {
                            *(TempWinsArr + iTemp4*TotalMoves + iTemp2)= *(CurrWinsArr + iTemp1*TotalMoves +iTemp2);
                        }
                        iTemp4++;
                    }
                }
                //PrintArr(TempWinsArr, TempWinsCount);
                //cTemp1=getchar();


                iTemp4=0;
                for(iTemp1=0; iTemp1<CurrLossesCount; iTemp1++)
                {
                    iTemp3=*(CurrLossesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        for(iTemp2=0; iTemp2<9; iTemp2++)
                        {
                            *(TempLossesArr + iTemp4*TotalMoves + iTemp2)= *(CurrLossesArr + iTemp1*TotalMoves +iTemp2);
                        }
                        iTemp4++;
                    }
                }
                //PrintArr(TempLossesArr, TempLossesCount);
                //cTemp1=getchar();

                iTemp4=0;
                for(iTemp1=0; iTemp1<CurrTiesCount; iTemp1++)
                {
                    iTemp3=*(CurrTiesArr + iTemp1*TotalMoves + iMoveNo -1);
                    //printf("\n%d\n", iTemp3);
                    if(iTemp3==iCurrMove)
                    {
                        for(iTemp2=0; iTemp2<9; iTemp2++)
                        {
                            *(TempTiesArr + iTemp4*TotalMoves + iTemp2)= *(CurrTiesArr + iTemp1*TotalMoves +iTemp2);
                        }
                        iTemp4++;
                    }
                }
                //PrintArr(TempTiesArr, TempTiesCount);
                //cTemp1=getchar();

                //printf("Ran Upto Here\n");
                //cTemp1=getchar();
                free(CurrWinsArr);
                free(CurrLossesArr);
                free(CurrTiesArr);

                CurrWinsCount=TempWinsCount;
                CurrLossesCount=TempLossesCount;
                CurrTiesCount=TempTiesCount;

                //printf("Ran Upto Here2\n");
                //cTemp1=getchar();

                CurrWinsArr= (int*)malloc(CurrWinsCount * TotalMoves * sizeof(int));
                CurrLossesArr= (int*)malloc(CurrLossesCount * TotalMoves * sizeof(int));
                CurrTiesArr= (int*)malloc(CurrTiesCount * TotalMoves *sizeof(int));

                //printf("Ran Upto Here3\n");
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<TempWinsCount; iTemp1++)
                {
                    for(iTemp2=0; iTemp2<9; iTemp2++)
                    {
                        *(CurrWinsArr + iTemp1*TotalMoves + iTemp2)= *(TempWinsArr + iTemp1*TotalMoves +iTemp2);
                    }
                }
                //PrintArr(CurrWinsArr, CurrWinsCount);
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<TempLossesCount; iTemp1++)
                {
                    for(iTemp2=0; iTemp2<9; iTemp2++)
                    {
                        *(CurrLossesArr + iTemp1*TotalMoves + iTemp2)= *(TempLossesArr + iTemp1*TotalMoves +iTemp2);
                    }
                }
                //PrintArr(CurrLossesArr, CurrLossesCount);
                //cTemp1=getchar();

                for(iTemp1=0; iTemp1<TempTiesCount; iTemp1++)
                {
                    for(iTemp2=0; iTemp2<9; iTemp2++)
                    {
                        *(CurrTiesArr + iTemp1*TotalMoves + iTemp2)= *(TempTiesArr + iTemp1*TotalMoves +iTemp2);
                    }
                }
                //PrintArr(CurrTiesArr, CurrTiesCount);
                //cTemp1=getchar();

                //printf("Ran Upto Here4\n");
                //cTemp1=getchar();

                free(TempWinsArr);
                free(TempLossesArr);
                free(TempTiesArr);

                //printf("Ran Upto Here5\n");
                //cTemp1=getchar();


            }
        }
        printf("\nRESULT: Game ends in a tie. Well Played\n");

            

    }

}
