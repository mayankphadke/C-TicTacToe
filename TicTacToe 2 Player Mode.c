//#include "GameDisplayH.h"
#include <stdio.h>
#include <stdlib.h>

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
              cTemp=' ';
          }
          printf("[ %c ]",cTemp );
        }
        printf("\n");

    }

}


int CheckMove(int Board[3][3], int MoveNo, int MoveVal)
{
    //printf("Move Index: %d, %d\nCurrent Value: %d\n", (MoveVal/3), (MoveVal%3) , Board[(MoveVal/3)][(MoveVal%3)]);

    if(Board[(MoveVal-1)/3][(MoveVal-1)%3]==-1)
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


void MakeMove(int Board[3][3], int MoveNo)
{
    int MoveVal;
    int Flag;

    if(MoveNo%2==1)
    {
        printf("Player 1's Move (X) : " );
        scanf("%d", &MoveVal);
        Flag=CheckMove(Board, MoveNo, MoveVal);
        if(Flag==0)
        {
            Board[(MoveVal-1)/3][(MoveVal-1)%3]=1;
        }
        else
        {
            printf("Invalid Move, Please try again\n" );
            MakeMove(Board, MoveNo);
        }
    }
    else
    {
        printf("Player 2's Move (O) : " );
        scanf("%d", &MoveVal);
        Flag=CheckMove(Board, MoveNo, MoveVal);
        if(Flag==0)
        {
            Board[(MoveVal-1)/3][(MoveVal-1)%3]=0;
        }
        else
        {
            printf("Invalid Move, Please try again\n" );
            MakeMove(Board, MoveNo);
        }
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
            printf("\n**Player %d Wins**\n", 2-MoveNo%2 );
            Board[iTemp1][0]=3;
            Board[iTemp1][1]=3;
            Board[iTemp1][2]=3;
            Flag=1;
            break;
        }
        if(Board[0][iTemp1]==Board[1][iTemp1] && Board[0][iTemp1]==Board[2][iTemp1] && Board[2][iTemp1]!= -1)
        {
            printf("\n**Player %d Wins**\n", 2-MoveNo%2 );
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


int main()
{
    int Board[3][3]={-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int MoveNo;
    int PlayerNo;
    int MoveVal;
    int WinVal;

    printf("Please Make Your Move According to the Legend\n" );
    printf("[ 1 ][ 2 ][ 3 ]\n[ 4 ][ 5 ][ 6 ]\n[ 7 ][ 8 ][ 9 ]\n\n" );

    Display(Board);
    for(MoveNo=1; MoveNo<=9; MoveNo++)
    {
        MakeMove(Board, MoveNo);
        Display(Board);
        WinVal=CheckWin(Board, MoveNo);
        if(WinVal==1)
        {
          printf("\n" );
            Display(Board);
            //printf("Player %d Wins\n", 2-MoveNo%2 );
            exit(1);
        }
    }
    printf("Game Ends in a Tie\n");
}
