#include<stdlib.h>
#include<stdio.h>

void input_from_user(char **arr);
void driver_code_for_player(char **arr, int pos1, int pos2, int move);
int winner_check(char **arr,int move);
void print_array(char **arr);

int main()
{
    char **arr=(char **)malloc(3*sizeof(char*)); //no of rows
    for(int i=0;i<3;i++)
    {
        arr[i]=(char*)malloc(3*sizeof(char));// no of columns
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]='\0';
        }
    }
    int flag=0;
    input_from_user(arr);
    return 0;
}

void input_from_user(char **arr)
{
    int pos1; int pos2; int pos3; int pos4; int flag=0;
    int i=0; 
    while(i<9 && flag==0)
    {
        if(i%2==0)
        {
            printf("Enter the position player 1(0 based indexing)\n");
            scanf("%d%d",&pos1,&pos2);
            driver_code_for_player(arr,pos1,pos2,1);
        }
        else
        {
            printf("Enter the position player 2(0 based indexing)\n");
            scanf("%d%d",&pos3,&pos4);
            driver_code_for_player(arr,pos3,pos4,2);
        }
        print_array(arr);
        if(i>=4)
        {
            int w=winner_check(arr,(i%2)+1);

            if(w==1)
            {
                flag=1;
                printf("Player 1 wins\n");
            }
            else if(w==2)
            {
                flag=1;
                printf("Player 2 wins\n");
            }
        }
        ++i;
    }
    if(flag==0)
        printf("Draw\n");
}

void driver_code_for_player(char **arr, int pos1, int pos2, int move)
{
    char m;
    if(move==1)
        m='o';
    else
        m='x';
    if(arr[pos1][pos2]=='\0')
    {
        arr[pos1][pos2]=m;
    }
    else
    {
        while(arr[pos1][pos2]!='\0')
        {
            printf("Enter a different position\n");
            scanf("%d%d",&pos1,&pos2);
        }
        arr[pos1][pos2]=m;
    }
}

int winner_check(char **arr, int move)
{
    char m;
    if(move==1)
        m='o';
    else
        m='x';
    for(int i=0;i<3;++i)
    {
        if(arr[i][0]==m && arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2])
            return move;
        
        else if(arr[0][i]==m && arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i])
            return move;
    }
    
    if(arr[0][2]==m && arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0])
        return move;
    
    if(arr[0][0]==m && arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2])
        return move;
    
    return 3;
}

// void print_array(char **arr)
// {
//     printf("\n");
//     for(int i=0;i<3;i++)
//     {
//         for(int j=0;j<3;j++)
//         {
//             if(arr[i][j]!='\0')
//                 printf(" %c |",arr[i][j]);
//             else
//                 printf("___|");
//         }
//         printf("\n");
//     }
// }

void print_array(char **arr)
{
    printf("\n");
    printf("Player 1 (o)  -  Player 2 (x)\n");

    printf("     |     |     \n");
    if(arr[0][0]!='\0' && arr[0][1]!='\0' && arr[0][2]!='\0')
        printf("  %c  |  %c  |  %c \n", arr[0][0], arr[0][1], arr[0][2]);
    else
        printf("  %c   |  %c   |  %c \n", arr[0][0], arr[0][1], arr[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c   |  %c   |  %c \n", arr[1][0], arr[1][1], arr[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c   |  %c   |  %c \n", arr[2][0], arr[2][1], arr[2][2]);

    printf("     |     |     \n\n");
    }