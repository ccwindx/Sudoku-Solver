#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;


/* a two dimensional array contains board information */
int arr[9][9];
  
/* solve sudoku method */
bool sudoku(int arr[9][9]);

/* find empty grid on the table */
bool findEmptyGrid(int arr[9][9] , int  &r, int &c);

/* if checrow and checkcol and checksquare are all true */
bool isSafe(int arr[9][9], int r , int c, int num); 

/* check the row */
bool checkRow(int arr[9][9], int r, int c, int num);

/* check the column */
bool checkCol(int arr[9][9], int r, int c, int num);

/* check the square */
bool checkSquare(int arr[9][9], int r, int c, int num);

/* print the grid to the screen */
void printGrid(int arr[9][9]);

int main()
{
  std::ifstream in("list");

  if (!in.is_open())
  {
    std::cout << "Cannot open the file" << std::endl;
    exit(1);
  }
  
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      in >> arr[i][j];
    }
  }

  if (sudoku(arr))
    printGrid(arr);

  else
    std::cout << "There is no solution" << std::endl;

  return 0;
}

bool sudoku(int arr[9][9])
{
  int r, c;
  if (!findEmptyGrid(arr, r, c))
  {
    return true;
  }

  for (int num = 1; num < 10; num++)
  {
    if (isSafe(arr, r, c, num))
    {
      arr[r][c] = num;

      if (sudoku(arr))
        return true;

      arr[r][c] = 0;
    }
  }
  return false;
}

/* find the next empty grid 
 * @param arr[9][9] the puzzle board
 * @param &r pass by reference of row 
 * @param &c pass by reference of column
 * @return true if find empty grid on the board, false if not 
 */
bool findEmptyGrid(int arr[9][9], int &r, int &c)
{
  for (r = 0; r < 9; r++)
  {
    for (c = 0; c < 9; c++)
    {
      if (arr[r][c] == 0)
        return true;
    }
  }
  return false;
}

bool isSafe(int arr[9][9], int r, int c, int num)
{
  if (checkRow(arr, r, c, num) && checkCol(arr, r, c, num) && checkSquare(arr, r, c, num))
    return true;
  else
    return false;
}

bool checkRow(int arr[9][9], int r, int c, int num)
{
  for (int i = 0; i < 9; i++)
  {
    if (arr[r][i] == num)
      return false;
  }
  return true;
}

bool checkCol(int arr[9][9], int r, int c, int num)
{
  for (int i = 0; i < 9; i++)
  {
    if (arr[i][c] == num)
      return false;
  }
  return true;
}

bool checkSquare(int arr[9][9], int r, int c, int num)
{
  int startRow = r - r % 3;
  int startCol = c - c % 3;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arr[startRow + i][startCol + j] == num)
        return false;
    }
  }
  return true;
}


void printGrid(int arr[9][9])
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
