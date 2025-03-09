#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

// Global variable to hold the original puzzle.
// This array will be filled once and then used to check which cells are original.
int original[9][9];

void read_problem(int grid[9][9]);
bool isValid(int grid[9][9], int r, int c, int num);
bool solve_visualization(int grid[9][9], int r, int c);
void print_grid(int grid[9][9], int cur_r, int cur_c);
bool solve_directly(int grid[9][9], int r, int c);

int main(void)
{    
    mciSendString("open \"music.mp3\" type mpegvideo alias mymusic", NULL, 0, NULL);
    mciSendString("play mymusic repeat", NULL, 0, NULL);
    top4: 
    printf(" _     _  _______  ___      _______  _______  __   __  _______    _______  _______    _______  __   __  _______     _______  _______  __   __  _______  __  \n");
    printf("| | _ | ||       ||   |    |       ||       ||  |_|  ||       |  |       ||       |  |       ||  | |  ||       |   |       ||   _   ||  |_|  ||       ||  | \n");
    printf("| || || ||    ___||   |    |       ||   _   ||       ||    ___|  |_     _||   _   |  |_     _||  |_|  ||    ___|   |    ___||  |_|  ||       ||    ___||  | \n");
    printf("|       ||   |___ |   |    |       ||  | |  ||       ||   |___     |   |  |  | |  |    |   |  |       ||   |___    |   | __ |       ||       ||   |___ |  | \n");
    printf("|       ||    ___||   |___ |      _||  |_|  ||       ||    ___|    |   |  |  |_|  |    |   |  |       ||    ___|   |   ||  ||       ||       ||    ___||__| \n");
    printf("|   _   ||   |___ |       ||     |_ |       || ||_|| ||   |___     |   |  |       |    |   |  |   _   ||   |___    |   |_| ||   _   || ||_|| ||   |___  __  \n");
    printf("|__| |__||_______||_______||_______||_______||_|   |_||_______|    |___|  |_______|    |___|  |__| |__||_______|   |_______||__| |__||_|   |_||_______||__| \n");
    printf("\n\n\n*********PRESS 1 to START THE GAME!!!!***************\n");
    int c_3;
    scanf("%d",&c_3);
    if(c_3 == 1){
        system("cls");
      
    top5:
    // Header text (ASCII art)
    printf(" _______  __   __  ______   _______  ___   _  __   __    _______  _______  ___      __   __  _______  ______   \n");
    printf("|       ||  | |  ||      | |       ||   | | ||  | |  |  |       ||       ||   |    |  | |  ||       ||    _ |  \n");
    printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |  |  _____||   _   ||   |    |  |_|  ||    ___||   | ||  \n");
    printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |  | |_____ |  | |  ||   |    |       ||   |___ |   |_||_ \n");
    printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |  |_____  ||  |_|  ||   |___ |       ||    ___||    __  | \n");
    printf(" _____| ||       ||       ||       ||    _  ||       |   _____| ||       ||       | |     | |   |___ |   |  | | \n");
    printf("|_______||_______||______| |_______||___| |_||_______|  |_______||_______||_______|  |___|  |_______||___|  |_|\n\n\n\n");
    printf("______    __   __  ___      _______  _______  __   __   __  \n");
    printf("|    _ |  |  | |  ||   |    |       ||       ||  | |  | |  | \n");
    printf("|   | ||  |  | |  ||   |    |    ___||  _____||  | |  | |  | \n");
    printf("|   |_||_ |  |_|  ||   |    |   |___ | |_____ |  | |  | |  | \n");
    printf("|    __  ||       ||   |___ |    ___||_____  ||__| |__| |__| \n");
    printf("|   |  | ||       ||       ||   |___  _____| | __   __   __  \n");
    printf("|___|  |_||_______||_______||_______||_______||__| |__| |__| \n\n");

    printf("1. Grid Structure:\n");
printf("   - Sudoku consists of a 9x9 grid, divided into nine 3x3 subgrids.\n\n");

printf("2. Number Placement:\n");
printf("   - The goal is to fill the entire grid with numbers from 1 to 9.\n\n");

printf("3. Row Rule:\n");
printf("   - Each row must contain the numbers 1 to 9, without repetition.\n\n");

printf("4. Column Rule:\n");
printf("   - Each column must also contain the numbers 1 to 9, without repetition.\n\n");

printf("5. Subgrid (Box) Rule:\n");
printf("   - Each of the nine 3x3 subgrids must contain the numbers 1 to 9, without repetition.\n\n");

printf("6. Starting Clues:\n");
printf("   - Some numbers are pre-filled in the grid as clues.\n");
printf("   - These numbers cannot be changed.\n\n");

printf("7. Logical Deduction:\n");
printf("   - The puzzle is solved using logic; no guessing is required.\n\n");

printf("8. Uniqueness:\n");
printf("   - A valid Sudoku puzzle has only one unique solution.\n\n");
int c_4;
printf("********PRESS 1 TO CONTINUE************");
scanf("%d",&c_4);
if(c_4 == 1){
    int grid[9][9];
    int wait, i, j, choice;

    // Read the problem from file.
    read_problem(grid);

    // Copy the initial grid into the global 'original' array.
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            original[i][j] = grid[i][j];
        }
    }

    // Print the initial puzzle (without color coding).
top1:
    printf("\n\n************This is Your Problem*******************\n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if(grid[i][j] != 0)
                printf("\033[1;32m%d\033[0m ",grid[i][j]);
            
            else    
                printf("\033[1;31m%d\033[0m ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n*************Menu:************\n");
    printf("\n You have Following Choices:\n");
    printf("1) Try Yourself!!!! \n2) See Solution Directly \n3) See Visualization of Computer Solving the problem\n");
    printf("Enter a choice[1/2/3]: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        // Reprint header art for consistency
        printf(" _______  __   __  ______   _______  ___   _  __   __    _______  _______  ___      __   __  _______  ______   \n");
        printf("|       ||  | |  ||      | |       ||   | | ||  | |  |  |       ||       ||   |    |  | |  ||       ||    _ |  \n");
        printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |  |  _____||   _   ||   |    |  |_|  ||    ___||   | ||  \n");
        printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |  | |_____ |  | |  ||   |    |       ||   |___ |   |_||_ \n");
        printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |  |_____  ||  |_|  ||   |___ |       ||    ___||    __  | \n");
        printf(" _____| ||       ||       ||       ||    _  ||       |   _____| ||       ||       | |     | |   |___ |   |  | | \n");
        printf("|_______||_______||______| |_______||___| |_||_______|  |_______||_______||_______|  |___|  |_______||___|  |_|\n");
        printf("*****TRY DOING IT BY YOURSELF*******\n");
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        {
            int c_1;
            printf("\nPress 1 to Giveup and Return To Menu!! Or Press 2 to Exit!!: ");
            scanf("%d", &c_1);
            if (c_1 == 1)
                goto top1;
            else
            {
                system("cls");
                printf("\n THANKS FOR PLAYING!!!!\n PROJECT BY: PRASHIL LAMICHHANE, SUMIRAN SUBEDI, DHIRAJ KUNWAR, SAURAB ADHIKARI!!");
            }
        }
        break;
    case 2:
        system("cls");
        printf(" _______  __   __  ______   _______  ___   _  __   __    _______  _______  ___      __   __  _______  ______   \n");
        printf("|       ||  | |  ||      | |       ||   | | ||  | |  |  |       ||       ||   |    |  | |  ||       ||    _ |  \n");
        printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |  |  _____||   _   ||   |    |  |_|  ||    ___||   | ||  \n");
        printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |  | |_____ |  | |  ||   |    |       ||   |___ |   |_||_ \n");
        printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |  |_____  ||  |_|  ||   |___ |       ||    ___||    __  | \n");
        printf(" _____| ||       ||       ||       ||    _  ||       |   _____| ||       ||       | |     | |   |___ |   |  | | \n");
        printf("|_______||_______||______| |_______||___| |_||_______|  |_______||_______||_______|  |___|  |_______||___|  |_|\n");
        printf("*******YOUR SOLVED SODUKU IS************\n");
        if (solve_directly(grid, 0, 0))
        {
            for (i = 0; i < 9; i++)
            {
                for (j = 0; j < 9; j++)
                {
                   if(grid[i][j] != 0){
                    printf("\033[1;33m%d\033[0m",grid[i][j]);
                   }
                   else{
                    printf("\033[1;32m%d\033[0m",grid[i][j]);
                   }
                }
                printf("\n");
            }
        }
        printf("\n THANKS FOR PLAYING!!!!\n PROJECT BY: PRASHIL LAMICHHANE, SUMIRAN SUBEDI, DHIRAJ KUNWAR, SAURAB ADHIKARI!!");
        break;
    case 3:
        // For visualization, the current cell is highlighted in yellow.
        solve_visualization(grid, 0, 0);
        break;
    default:
        break;
    }

    // Pause before exiting.
    scanf("%d", &wait);
  
   


    }
    else{
        printf("\n\n******INVALID INPUT*******");
        goto top5;
    }

}
   
        
    
    else{
        printf("INVALID INPUT!!!!!");
        system("cls");
        goto top4;
    }
        
      return 0;
}

void read_problem(int grid[9][9])
{
    srand(time(0));
    int rand_problem_no = (rand() % 50); // Generate a random number between 0 and 49.
    int i, j;
    FILE *file;
    file = fopen("sudoku.txt", "r");
    char line[15]; // Temporary string to store each line.

    if (file)
    {
        // Skip lines before the randomly chosen problem.
        for (i = 0; i < rand_problem_no * 10 + 1; i++)
        {
            fgets(line, sizeof(line), file);
        }
        // Read the 9 lines of the problem.
        for (i = 0; i < 9; i++)
        {
            fgets(line, sizeof(line), file);
            for (j = 0; j < 9; j++)
            {
                grid[i][j] = line[j] - '0';
            }
        }
        fclose(file);
    }
    else
    {
        printf("Error: could not open sudoku.txt\n");
        exit(EXIT_FAILURE);
    }
}

void print_grid(int grid[9][9], int cur_r, int cur_c)
{
    int i, j;
    system("cls"); // Clear the screen

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (i == cur_r && j == cur_c)
            {
                // Highlight current cell in yellow
                printf("\033[1;33m%d\033[0m ", grid[i][j]);
            }
            else if (original[i][j] != 0)
            {
                // Original puzzle numbers in green
                printf("\033[1;32m%d\033[0m ", grid[i][j]);
            }
            else
            {
                // Solver-filled numbers in red
                printf("\033[1;31m%d\033[0m ", grid[i][j]);
            }

            
        }
        printf("\n");
        
    }
    Sleep(500); // Pause for visualization
}

bool isValid(int grid[9][9], int r, int c, int num)
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        if (grid[r][i] == num)
            return false;
    }
    for (i = 0; i < 9; i++)
    {
        if (grid[i][c] == num)
            return false;
    }
    int startRow = r - r % 3, startCol = c - c % 3;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

bool solve_visualization(int grid[9][9], int r, int c)
{
    if (r == 9)
        return true;
    if (c == 9)
        return solve_visualization(grid, r + 1, 0);
    if (grid[r][c] != 0)
        return solve_visualization(grid, r, c + 1);

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(grid, r, c, num))
        {
            grid[r][c] = num;
            print_grid(grid, r, c); // Visualize current assignment

            if (solve_visualization(grid, r, c + 1))
                return true;

            grid[r][c] = 0; // Backtrack
            print_grid(grid, r, c);
        }
    }
    return false;
}

bool solve_directly(int grid[9][9], int r, int c)
{
    if (r == 9)
        return true;
    if (c == 9)
        return solve_directly(grid, r + 1, 0);
    if (grid[r][c] != 0)
        return solve_directly(grid, r, c + 1);

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(grid, r, c, num))
        {
            grid[r][c] = num;
            if (solve_directly(grid, r, c + 1))
                return true;
            grid[r][c] = 0;
        }
    }
    return false;
}
