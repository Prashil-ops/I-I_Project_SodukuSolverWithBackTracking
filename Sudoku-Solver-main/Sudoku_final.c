#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include<conio.h>
// Global variable to hold the original puzzle.
// This array will be filled once and then used to check which cells are original.
int original[9][9];

void read_problem(int grid[9][9]);
bool isValid(int grid[9][9], int r, int c, int num);
bool solve_visualization(int grid[9][9], int r, int c);
void print_grid(int grid[9][9]);
bool solve_directly(int grid[9][9],int r,int c);
int main(void)
{

    printf(" _______  __   __  ______   _______  ___   _  __   __    _______  _______  ___      __   __  _______  ______   \n");
    printf("|       ||  | |  ||      | |       ||   | | ||  | |  |  |       ||       ||   |    |  | |  ||       ||    _ |  \n");
    printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |  |  _____||   _   ||   |    |  |_|  ||    ___||   | ||  \n");
    printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |  | |_____ |  | |  ||   |    |       ||   |___ |   |_||_ \n");
    printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |  |_____  ||  |_|  ||   |___ |       ||    ___||    __  | \n");
    printf(" _____| ||       ||       ||       ||    _  ||       |   _____| ||       ||       | |     | |   |___ |   |  | | \n");
    printf("|_______||_______||______| |_______||___| |_||_______|  |_______||_______||_______|  |___|  |_______||___|  |_|\n");
    int grid[9][9];
    int wait, i, j,choice;
    // menu
   
    // switch
    //     scanf("%d", &wait);

    // Read the problem from the file.
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
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n*************Menu:************\n");
    printf("\n You have Following Choiices:\n");
    printf("1) Try Yourself!!!! \n 2) See Solution Directly \n 3)See Visualization of Computer Solving the problem\n");
    printf("Enter a choice[1/2/3]: ");
    scanf("%d",&choice);
    switch (choice){
        case 1:
        system("cls");
        printf(" _______  __   __  ______   _______  ___   _  __   __    _______  _______  ___      __   __  _______  ______   \n");
    printf("|       ||  | |  ||      | |       ||   | | ||  | |  |  |       ||       ||   |    |  | |  ||       ||    _ |  \n");
    printf("|  _____||  | |  ||  _    ||   _   ||   |_| ||  | |  |  |  _____||   _   ||   |    |  |_|  ||    ___||   | ||  \n");
    printf("| |_____ |  |_|  || | |   ||  | |  ||      _||  |_|  |  | |_____ |  | |  ||   |    |       ||   |___ |   |_||_ \n");
    printf("|_____  ||       || |_|   ||  |_|  ||     |_ |       |  |_____  ||  |_|  ||   |___ |       ||    ___||    __  | \n");
    printf(" _____| ||       ||       ||       ||    _  ||       |   _____| ||       ||       | |     | |   |___ |   |  | | \n");
    printf("|_______||_______||______| |_______||___| |_||_______|  |_______||_______||_______|  |___|  |_______||___|  |_|\n");
        printf("*****TRY DOING IT BY YOURSELF*******\n");
        for(i = 0;i<9;i++){
            for(j = 0;j <9; j++){
                 printf("%d ",grid[i][j]);
             }
             printf("\n");
         }
         int c_1;
         printf("\nPress 1 to Giveup and Return To Menu!! Or Press 2 to Exit!!: ");
         scanf("%d",&c_1);
         if(c_1 == 1) goto top1;
         else{
            system("cls");
            printf("\n THANKS FOR PLAYING!!!!\n PROJECT BY: PRASHIL LAMICHHANE, SUMIRAN SUBEDI, DHIRAJ KUNWAR, SAURAB ADHIKARI!!");
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
        if(solve_directly(grid,0,0)){
            for(i = 0;i<9;i++){
               for(j = 0;j <9; j++){
                    printf("%d ",grid[i][j]);
                }
                printf("\n");
            }
        } printf("\n THANKS FOR PLAYING!!!!\n PROJECT BY: PRASHIL LAMICHHANE, SUMIRAN SUBEDI, DHIRAJ KUNWAR, SAURAB ADHIKARI!!");
        break;
        case 3:
            solve_visualization(grid,0,0);
        default:
            break;
        
    }

    // Solve the puzzle while visualizing the backtracking steps.
    

    // Pause before exiting.
    scanf("%d", &wait);
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

void print_grid(int grid[9][9])
{
    int i, j;
    // Clear the screen and move the cursor to the top using ANSI escape codes.
    system("cls");

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            // If the cell was part of the original puzzle, print it in green;
            // otherwise, print it in red.
            if (original[i][j] != 0)
            {
                // system("color 4");
                printf("\033[1;32m%d\033[0m ", grid[i][j]);
            } // Green for original cells
            else
            {
                // system("color 2");
                printf("\033[1;31m%d\033[0m ", grid[i][j]);
            } // Red for solver-filled cells
            // system("color 7");
            // Optional: add vertical dividers after each 3-cell block.
            if ((j + 1) % 3 == 0 && j != 8)
                printf("| ");
        }
        printf("\n");
        // Optional: add horizontal dividers after each 3-row block.
        if ((i + 1) % 3 == 0 && i != 8)
            printf("---------------------\n");
    }
    Sleep(500); // Pause briefly to allow visualization of the step.
}

bool isValid(int grid[9][9], int r, int c, int num)
{
    int i, j;
    // Check if num is in the same row.
    for (i = 0; i < 9; i++)
    {
        if (grid[r][i] == num)
            return false;
    }

    // Check if num is in the same column.
    for (i = 0; i < 9; i++)
    {
        if (grid[i][c] == num)
            return false;
    }

    // Check if num is in the same 3x3 subgrid.
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
        return true; // Reached the end of the grid successfully.
    if (c == 9)
        return solve_visualization(grid, r + 1, 0); // Move to the next row.
    if (grid[r][c] != 0)
        return solve_visualization(grid, r, c + 1); // Skip pre-filled cells.

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(grid, r, c, num))
        {
            grid[r][c] = num;
            print_grid(grid); // Visualize after each assignment.

            if (solve_visualization(grid, r, c + 1))
                return true;

            grid[r][c] = 0;   // Backtracking step.
            print_grid(grid); // Visualize after backtracking.
        }
    }
    return false; // Trigger backtracking.
}
bool solve_directly(int grid[9][9], int r, int c) {
    if (r == 9) return true;  // If we reach row 9, solution found
    if (c == 9) return solve_directly(grid, r + 1, 0);  // Move to next row
    if (grid[r][c] != 0) return solve_directly(grid, r, c + 1);  // Skip non-empty cells

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, r, c, num)) {
            grid[r][c] = num;
            if (solve_directly(grid, r, c + 1)) {
                return true;
            }
            grid[r][c] = 0;  // Backtrack
        }
    }
    return false;  // No solution found for this path
}

