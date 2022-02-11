#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>

using namespace std;

int arr[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}};

void display()
{
    cout << "\n\t\t\t    Welcome To the 2048 Game\n" << endl;
    cout << "Rules Of The Game " << endl;
    cout << "\'W\' To Move Up" << endl;
    cout << "\'S\' To Move Down" << endl;
    cout << "\'A\' To Move Left" << endl;
    cout << "\'D\' To Move Right" << endl;
    cout << "\'Q\' To Quit the game" << endl;
    cout << "\'R\' To Restart\n" << endl;
    cout << "\t----------------------------------------------------------------";
    for (int i = 0; i < 8; i++)
    {
        cout << "\n\t|               ||              ||              ||              |\n\t";
        for (int j = 0; j < 4; j++)
        {
            if (i % 2 == 0)
            {
                if (arr[i / 2][j] == 0)
                {
                    cout << "|\t \t|";
                }
                else
                {
                    cout << "|\t" << arr[i / 2][j] << " \t|";
                }
            }
            else
            {
                cout << "----------------";
            }
        }
    }
}

void add()
{
    srand(time(0));
    int x, y, in;
    while (true)
    {
        x = rand() % 4;
        y = rand() % 4;
        in = rand() % 2;
        if (arr[x][y] == 0)
        {
            if (in == 0)
            {
                arr[x][y] = 2;
                break;
            }
            else if (in == 1)
            {
                arr[x][y] = 4;
                break;
            }
        }
    }
}

void restart()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = 0;
        }
    }
    add();
    add();
}

bool up()
{
    bool done = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[j][i] == 0)
            {
                for (int k = j + 1; k < 4; k++)
                {
                    if (arr[k][i] != 0)
                    {
                        arr[j][i] = arr[k][i];
                        arr[k][i] = 0;
                        j--;
                        done = true;
                        break;
                    }
                }
            }
            else
            {
                for (int k = j + 1; k < 4; k++)
                {
                    if (arr[k][i] != 0)
                    {
                        if (arr[j][i] == arr[k][i])
                        {
                            arr[j][i] += arr[k][i];
                            arr[k][i] = 0;
                            done = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return done;
}

bool down()
{
    bool done = false;
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            if (arr[j][i] == 0)
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (arr[k][i] != 0)
                    {
                        arr[j][i] = arr[k][i];
                        arr[k][i] = 0;
                        j++;
                        done = true;
                        break;
                    }
                }
            }
            else
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (arr[k][i] != 0)
                    {
                        if (arr[j][i] == arr[k][i])
                        {
                            arr[j][i] += arr[k][i];
                            arr[k][i] = 0;
                            done = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return done;
}

bool left()
{
    bool done = false;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (arr[j][i] == 0)
            {
                for (int k = i + 1; k < 4; k++)
                {
                    if (arr[j][k] != 0)
                    {
                        arr[j][i] = arr[j][k];
                        arr[j][k] = 0;
                        i--;
                        done = true;
                        break;
                    }
                }
            }
            else
            {
                for (int k = i + 1; k < 4; k++)
                {
                    if (arr[j][k] != 0)
                    {
                        if (arr[j][i] == arr[j][k])
                        {
                            arr[j][i] += arr[j][k];
                            arr[j][k] = 0;
                            done = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return done;
}

bool right()
{
    bool done = false;
    for (int j = 3; j >= 0; j--)
    {
        for (int i = 3; i >= 0; i--)
        {
            if (arr[j][i] == 0)
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (arr[j][k] != 0)
                    {
                        arr[j][i] = arr[j][k];
                        arr[j][k] = 0;
                        i++;
                        done = true;
                        break;
                    }
                }
            }
            else
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (arr[j][k] != 0)
                    {
                        if (arr[j][i] == arr[j][k])
                        {
                            arr[j][i] += arr[j][k];
                            arr[j][k] = 0;
                            done = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    return done;
}

bool gameover()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                return true;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i + 1][j] == arr[i][j] || arr[i][j + 1] == arr[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    char input, quit = 'N', go, re;
    bool chk = false, first = true;
    restart();
    do
    {
        system("cls");
        if (chk)
        {
            add();
        }
        else if (first)
        {
            cout << "\t\t\t\t  Hello There!!" << endl;
        }
        else
        {
            cout << "\t\t\t\t  Invalid Move" << endl;
        }
        display();
        cout << endl;
        input = getch();
        first = false;
        if (input == 'w' || input == 'W')
        {
            chk = up();
        }
        else if (input == 's' || input == 'S')
        {
            chk = down();
        }
        else if (input == 'a' || input == 'A')
        {
            chk = left();
        }
        else if (input == 'd' || input == 'D')
        {
            chk = right();
        }
        else if (input == 'r' || input == 'R')
        {
            cout << "Do You Want To Restart (Y/N) : ";
            re = getch();
            if (re == 'Y' || re == 'y')
            {
                restart();
                re = 'n';
                chk = false;
                first = true;
            }
        }
        else if (input == 'q' || input == 'Q')
        {
            cout << "Do You Want To Quit (Y/N) : ";
            quit = getch();
            chk = false;
        }
        else
        {
            cout << "invalid choice" << endl;
        }
        if (!gameover())
        {
            cout << "\t\t\t\t Game Over!!" << endl;
            cout << "Do You Want To : " << endl;
            cout << "\'R\' Restart" << endl;
            cout << "\'Q\' Quit" << endl;
            go = getch();
            if (go == 'R' || go == 'r')
            {
                cout << "Do You Want To Restart (Y/N) : ";
                re = getch();
                if (re == 'Y' || re == 'y')
                {
                    restart();
                    re = 'n';
                    chk = false;
                    first = true;
                }
            }
            else if (go == 'Q' || go == 'q')
            {
                cout << "Do You Want To Quit (Y/N) : ";
                quit = getch();
                chk = false;
            }
        }
    } while (quit == 'N' || quit == 'n');
    return 0;
}
