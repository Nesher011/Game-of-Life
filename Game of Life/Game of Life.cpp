#include <iostream>
#include <Windows.h>
#include <time.h>
#include <WinUser.h>

#define xSize 40
#define ySize 40

void printGrid(bool grid[xSize][ySize])
{
    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            if (grid[i][j])
                std::cout << 'x';
            else
                std::cout << ' ';
        }
        std::cout << '\n';
    }
}
void changeGrid(bool grid[xSize][ySize], bool nextGrid[xSize][ySize])
{
    static int neighbourNumber{ 0 };
    for (int i = 0; i < ySize; i++)
    {
        for (int j = 0; j < xSize; j++)
        {
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if(grid[i+k][j+l]&&i+k!=xSize&&j+l!=ySize&&i+k>=0&&j+l>=0&& !(k == 0 && l == 0))
                        neighbourNumber++;
                }
                
            }
            if (!grid[i][j] && neighbourNumber == 3)
            {
                nextGrid[i][j] = true;
                neighbourNumber = 0;
            }
            else if ((neighbourNumber == 3 || neighbourNumber == 2) && grid[i][j])
            {
                nextGrid[i][j] = true;
                neighbourNumber = 0;
            }
            else
            {
                nextGrid[i][j] = false;
                neighbourNumber = 0;
            }
        }
    }
}

void replaceArray(bool grid[xSize][ySize], bool nextGrid[xSize][ySize])
{
    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

void fillArrayv2(bool grid[xSize][ySize])
{
    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            grid[i][j] = false;
        }
    }
    int x{ 0 }, y{ 0 };
    while (true)
    {
        std::cout << "type in coordinates you want to set to true(x y), if you want to finish, type '-1 -1': ";
        std::cin >> x >> y;
        if (x == -1)
            break;
        grid[x-1][y-1] = true;
        std::cout << '\n';

    }
}

void fillArrayv3(bool grid[xSize][ySize])
{
    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            grid[i][j] = rand()%2;
        }
    }
}


int main()
{
    SetCursorPos(0, 0);
    srand(time(NULL));
    //static bool firstGrid[xSize][ySize] = {};
    static bool firstGrid[xSize][ySize] = {};
    static bool nextGrid[xSize][ySize] = {};
    int chooseCase;
    std::cout << "1. Type in coordinates i want to set to true\n";
    std::cout << "2. Have some fun with random 40x40 array\n";
    std::cin >> chooseCase;
    system("cls");
    switch (chooseCase)
    {
    case 1:
        fillArrayv2(firstGrid);
        break;
    case 2:
        fillArrayv3(firstGrid);
        break;
    default:
        return 0;
    }    
    while (true)
    {
        system("cls");
        printGrid(firstGrid);
        changeGrid(firstGrid, nextGrid);
        replaceArray(firstGrid, nextGrid);
        //printGrid(nextGrid);
        //replaceArray(firstGrid, nextGrid);
        //printGrid(firstGrid);
        Sleep(500);
        //system("pause");
    }
}
