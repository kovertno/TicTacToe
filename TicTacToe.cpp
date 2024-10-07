#include <iostream>
#include <ctime>

void draw_board(char *spaces);
void playerMove(char *spaces, char player);
void cpuMove(char *spaces, char computer, size_t who);
bool winner(char *spaces, char player, char computer);
bool tie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';    

    size_t who;
    std::cout<<"How many people want to play? (1-2 players): ";

    tutaj:
        std::cin>>who;

    switch(who)
    {
        case 1:
            std::cout<<"\n1 player, let's begin\n\n"<<"PLAYER 1 - X\n\n";
            break;
        case 2:
            std::cout<<"\n2 players, let's begin\n\n"<<"PLAYER 1 - X\nPLAYER 2 - O\n\n";
            break;
        default:
            std::cout<<"\nIncorrect number of players, please re-enter: ";
            goto tutaj;
            break; 
    }

    for(int i = 0; i < 9; i++)
    {
        draw_board(spaces);
        int x = i%2;
        switch(x)
        {
            case 0:
                playerMove(spaces, player);
                break;
            case 1:
                cpuMove(spaces, computer, who);
                break;
        }
        if(winner(spaces, player, computer))
        {
            if(x == 0)
            {
                draw_board(spaces);
                std::cout << "PLAYER 1  WINS!\n";
                return 0;
            }
            else
            {
                draw_board(spaces);
                std::cout << "PLAYER 2  WINS!\n";
                return 0;
            }
        }

    }

    draw_board(spaces);
    std::cout<<"IT'S A TIE!\n";

    return 0;
}

void draw_board(char *spaces)
{
    std::cout<<"      |      |      "<<std::endl;
    std::cout<<"0  "<<spaces[0]<<"  |1  "<<spaces[1]<<"  |2  "<<spaces[2]<<"  "<<std::endl;
    std::cout<<"------|------|------"<<std::endl;
    std::cout<<"3  "<<spaces[3]<<"  |4  "<<spaces[4]<<"  |5  "<<spaces[5]<<"  "<<std::endl;
    std::cout<<"------|------|------"<<std::endl;
    std::cout<<"6  "<<spaces[6]<<"  |7  "<<spaces[7]<<"  |8  "<<spaces[8]<<"  "<<std::endl;
    std::cout<<"      |      |      "<<std::endl;
    std::cout<<"\n"; 

} 
void playerMove(char *spaces, char player)
{
    int move;
    std::cout<<"In which box do You want to place Your 'X' (0-8): ";
    std::cin>>move;
    if(spaces[move] == ' ')
        spaces[move] = player;
    else
    {
        while(spaces[move] != ' ')
        {
            std::cout<<"Place already taken, try again: ";
            std::cin>>move;
        }
        spaces[move] = player;
    }
}
void cpuMove(char *spaces, char computer, size_t who)
{
    if(who == 1)
    {
        srand(time(NULL));
        std::cout<<"Now it's CPU move:\n";
        int move = rand()%10;
        if(spaces[move] == ' ')
            spaces[move] = computer;
        else
        {
            while(spaces[move] != ' ')
            {
                move = rand()%10;
            }
            spaces[move] = computer;
        }
    }
    else if(who == 2)
    {
        int move;
        std::cout<<"In which box do You want to place Your 'O' (0-8): ";
        std::cin>>move;
        if(spaces[move] == ' ')
            spaces[move] = computer;
        else
        {
            while(spaces[move] != ' ')
            {
                std::cout<<"Place already taken, try again: ";
                std::cin>>move;
            }
            spaces[move] = computer;
        }
    }
}
bool winner(char *spaces, char player, char computer)
{
    bool isWin[8];
    isWin[0] = ((spaces[0] == player && spaces[1] == player && spaces[2] == player) || 
                (spaces[0] == computer && spaces[1] == computer && spaces[2] == computer)) ? true : false;
    isWin[1] = ((spaces[3] == player && spaces[4] == player && spaces[5] == player) ||
                (spaces[3] == computer && spaces[4] == computer && spaces[5] == computer)) ? true : false;
    isWin[2] = ((spaces[6] == player && spaces[7] == player && spaces[8] == player) ||
                (spaces[6] == computer && spaces[7] == computer && spaces[8] == computer)) ? true : false;
    isWin[3] = ((spaces[0] == player && spaces[3] == player && spaces[6] == player) || 
                (spaces[0] == computer && spaces[3] == computer && spaces[6] == computer)) ? true : false;
    isWin[4] = ((spaces[1] == player && spaces[4] == player && spaces[7] == player) ||
                (spaces[1] == computer && spaces[4] == computer && spaces[7] == computer)) ? true : false;
    isWin[5] = ((spaces[2] == player && spaces[5] == player && spaces[8] == player) ||
                (spaces[2] == computer && spaces[5] == computer && spaces[8] == computer)) ? true : false;
    isWin[6] = ((spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
                (spaces[0] == computer && spaces[4] == computer && spaces[8] == computer))  ? true : false;
    isWin[7] = ((spaces[2] == player && spaces[4] == player && spaces[6] == player) || 
                (spaces[2] == computer && spaces[4] == computer && spaces[6] == computer)) ? true : false;

    for(int i = 0; i < 8; i++)
    {
        if(isWin[i])
        {
            return true;
        }
    }

    return false;
}