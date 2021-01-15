#include <iostream>
#include <Windows.h>

#define xSize 8
#define ySize 8

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

void fillArray(bool grid[xSize][ySize])
{
    static bool arrayFiller{ 0 };
    std::cout << "Fill an array[5][5]\n";
    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            std::cout << "Array[" << i + 1 << "][" << j + 1 << "] = ";
            std::cin >> grid[i][j];
            std::cout << '\n';
        }
    }
}

void fillArrayv2(bool grid[xSize][ySize])
{
    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            grid[i][j] = false;;
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


int main()
{
    //static bool firstGrid[xSize][ySize] = {};
    static bool firstGrid[xSize][ySize] = { false, false, false, true, true, false, false, false,
                                            false, false, true, false, false, true, false, false,
                                            false, true, false, false, false, false, true, false,
                                            true, false, false, false, false, false, false, true,
                                            true, false, false, false, false, false, false, true,
                                            false, true, false, false, false, false, true, false,
                                            false, false, true, false, false, true, false, false,
                                            false, false, false, true, true, false, false, false};
    static bool nextGrid[xSize][ySize] = {};
    //fillArray(firstGrid);
    //fillArrayv2(firstGrid);
    
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
