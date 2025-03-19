#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_board(char board[][5]){
    printf("  ");
    for(int i = 0; i < 5 ; i++){
        printf("%d", i+1);
    }
    printf("\n");
    for(int i = 0; i < 5 ; i++){
        printf("%d ", i+1);
        for(int j = 0; j < 5 ; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void put_ship(int x, int y, char player_board[][5]){
    x--;
    y--;
    player_board[y][x] = 'A';
}

int attack_ship(int x, int y, char player_board[][5], char fakeboard[][5]){
    x--;
    y--;
    if(player_board[y][x] == 'A'){
        player_board[y][x] = 'X';
        fakeboard[y][x] = 'X'; //if a ship was hit
        return 1;
    }
    else{
        fakeboard[y][x] = '#'; //no ship was hit
        return 0;
    }
    
}

void play(char board_player1[][5], char board_player2[][5],char fakeboard1[][5],char fakeboard2[][5]){
    int x, y;
    system("clear");
    printf("Player 1's turn(attack)\n");
    print_board(fakeboard2);
    printf("(x y): \n");
    scanf("%d %d", &x, &y);
    // attack_ship(x, y, board_player2, fakeboard2);
    if(attack_ship(x, y, board_player2, fakeboard2) == 1){
        print_board(fakeboard2);
        play(board_player1, board_player2, fakeboard1, fakeboard2);
    }
    else{
        print_board(fakeboard2);
    }
}



int main(void){
    char board_player1[5][5];
    char board_player2[5][5];
    char fakeboard1[5][5];
    char fakeboard2[5][5];
    int x,y;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 ; j++){
            board_player1[i][j] = 'O';
            board_player2[i][j] = 'O';
            fakeboard1[i][j] = 'O';
            fakeboard2[i][j] = 'O';
        }
    }
    int player1_points = 0, player2_points = 0;

    // for(int i = 0 ; i < 5 ; i++){
    //     system("cls");
    //     printf("Player 1 place your ships(5)\n");
    //     print_board(board_player1);
    //     printf("(x y): \n");
    //     scanf("%d %d", &x, &y);
    //     put_ship(x, y, board_player1);
    // }

    for(int i = 0 ; i < 5 ; i++){
        system("clear");
        printf("Player 2 place your ships(5)\n");
        print_board(board_player2);
        printf("(x y): \n");
        scanf("%d %d", &x, &y);
        put_ship(x, y, board_player2);
    }

    play(board_player1, board_player2, fakeboard1, fakeboard2);
    return 0;
}