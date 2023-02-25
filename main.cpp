#include <iostream>
using namespace std;

int b[9][9];

bool checkrowcol (int num, int row, int col)              //function to check if num is somewhere in the row or column
{
    int z=0;                                       //z=1 means number was found in row or column

    for(int i = 0; i < 9; i++)
    {
        int temp = b[row][i];
        if(temp == num)
        {
            z=1;
            break;
        }
        else
        {
            z=0;
        }
    }

    if(z == 0)
    {
        for(int i = 0; i < 9; i++)
        {
            int temp = b[i][col];
            if(temp == num)
            {
                z=1;
                break;
            }
            else
            {
                z=0;
            }
        }
    }

    if(z == 1)
    {
        return true;                //"true" means the same number is already in the same row or column, try next number
    }
    else
    {
        return false;              //"false" means number was not found anywhere in row or column, endter number into position.
    }
}


bool checkblock(int num, int row, int col)                //function to check whether num is already in the block
{
    if(row >= 0 && row < 3)
    {
        if(col >= 0 && col < 3)
        {
            for(int i = 0; i < 3; i++)                    //check block 1 for num
            {
                for(int j = 0; j < 3; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(col >= 3 && col < 6)
        {
            for(int i = 0; i < 3; i++)                    //check block 2 for num
            {
                for(int j = 3; j < 6; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(col >= 6 && col < 9)
        {
            for(int i = 0; i < 3; i++)                    //check block 3 for num
            {
                for(int j = 6; j < 9; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }

    if(row >= 3 && row < 6)
    {
        if(col >= 0 && col < 3)
        {
            for(int i = 3; i < 6; i++)                    //check block 4 for num
            {
                for(int j = 0; j < 3; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(col >= 3 && col < 6)
        {
            for(int i = 3; i < 6; i++)                    //check block 5 for num
            {
                for(int j = 3; j < 6; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(col >= 6 && col < 9)
        {
            for(int i = 3; i < 6; i++)                    //check block 6 for num
            {
                for(int j = 6; j < 9; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }

    if(row >= 6 && row < 9)
    {
        if(col >= 0 && col < 3)
        {
            for(int i = 6; i < 9; i++)                    //check block 7 for num
            {
                for(int j = 0; j < 3; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(col >= 3 && col < 6)
        {
            for(int i = 6; i < 9; i++)                    //check block 8 for num
            {
                for(int j = 3; j < 6; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(col >= 6 && col < 9)
        {
            for(int i = 6; i < 9; i++)                    //check block 9 for num
            {
                for(int j = 6; j < 9; j++)
                {
                    if(b[i][j] == num)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
}

int solve(int b[9][9])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
           if(b[i][j] == 0)                //check if spot is "open" (zero)
           {
              for(int k = 1; k < 9;)
              {
                 if(checkrowcol(k,i,j))
                 {
                     k = k+1;
                 }
                 else if(checkblock(k,i,j))
                 {
                     k = k+1;
                 }
                 else
                 {
                     b[i][j] = k;
                     break;
                 }

              }
           }
        }
    }

    return 0;                        //trek hier weg
}


void PrintBoard(int b[9][9])
{

    cout<< endl<< "board:";

    for(int i = 0; i < 9; i++)
    {
        if((i %3) == 0)
        {
            cout<< endl;
        }

        for(int j = 0; j < 9; j++)
        {
            cout<< b[i][j] << " ";

            if(((j+1) %3) == 0)
            {
                cout<< " ";
            }

            if(j == 8)
            {
                cout<< endl;
            }

        }

    }
    cout<<endl;
}


void PrintBlock(int x[3][3])
{
    //cout<< endl;
   // cout<< "BLOCK:" << endl;
    for(int i = 0; i < 3; i++)
    {
       for(int j = 0; j < 3; j++)
        {
         if((j %3) == 0)
           {
             cout<< endl;
           }
          cout<< x[i][j] << " ";
        }
    }
    cout<<endl<<endl;
}

int main()
{
    int b[9][9] = { {1,0,0,  2,0,0,  3,0,0},
                    {0,1,0,  0,2,0,  0,3,0},
                    {0,0,1,  0,0,2,  0,0,3},

                    {4,0,0,  5,0,0,  6,0,0},
                    {0,4,0,  0,5,0,  0,6,0},
                    {0,0,4,  0,0,5,  0,0,6},

                    {7,0,0,  8,0,0,  9,0,0},
                    {0,7,0,  0,8,0,  0,9,0},
                    {0,0,7,  0,0,8,  0,0,9}, };

    PrintBoard(b);

//----------------------------------------- Blocks definition
    int one[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            one[i][j] = b[i][j];
        }
    }
//------------------------------------------
    int two[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 3; j < 6; j++)
        {
            two[i][j-3] = b[i][j];
        }
    }
//------------------------------------------
       int three[3][3];

       for(int i = 0; i < 3; i++)
       {
           for(int j = 6; j < 9; j++)
           {
               three[i][j-6] = b[i][j];
           }
       }
//------------------------------------------
          int four[3][3];

          for(int i = 3; i < 6; i++)
          {
              for(int j = 0; j < 3; j++)
              {
                  four[i-3][j] = b[i][j];
              }
          }
//------------------------------------------
      int five[3][3];

      for(int i = 3; i < 6; i++)
         {
           for(int j = 3; j < 6; j++)
              {
                five[i-3][j-3] = b[i][j];
               }
         }
//------------------------------------------
        int six[3][3];

          for(int i = 3; i < 6; i++)
            {
                 for(int j = 6; j < 9; j++)
                 {
                      six[i-3][j-6] = b[i][j];
                    }
                }
//------------------------------------------
   int seven[3][3];

   for(int i = 6; i < 9; i++)
     {
       for(int j = 0; j < 3; j++)
          {
             seven[i-6][j] = b[i][j];
          }
     }
//------------------------------------------
     int eight[3][3];

     for(int i = 6; i < 9; i++)
       {
         for(int j = 3; j < 6; j++)
            {
               eight[i-6][j-3] = b[i][j];
            }
       }
//------------------------------------------
       int nine[3][3];

       for(int i = 6; i < 9; i++)
         {
           for(int j = 6; j < 9; j++)
              {
                 nine[i-6][j-6] = b[i][j];
              }
         }

        cout<< "Block one:";
        PrintBlock(one);
        cout<< "Block two:";
        PrintBlock(two);
        cout<< "Block three:";
        PrintBlock(three);
        cout<< "Block four:";
        PrintBlock(four);
        cout<< "Block five:";
        PrintBlock(five);
        cout<< "Block six:";
        PrintBlock(six);
        cout<< "Block seven:";
        PrintBlock(seven);
        cout<< "Block eight:";
        PrintBlock(eight);
        cout<< "Block nine:";
        PrintBlock(nine);

        solve(b);

        cout<< "COPLETED BOARD:"<< endl;
        PrintBoard(b);


    return 0;
}
