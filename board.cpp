
#include<iostream>
#include<stdexcept>
#include"Board.h"
using namespace std;

Board::Board()
{
    for(int i = 0; i<10; ++i)
        
    {
        for(int j = 0 ; j < 10; ++j)
        {
            score[i][j] = ' ';
        }
    
    }
    
}

void Board :: addShip(char type, int x1, int y1, int x2, int y2)
{
    static int n = 0;
    if(n < 10)
     {
       Ship *p = Ship::makeShip(type,x1,y1,x2,y2);
        shipList.push_back(p);
     }
    n++;
    
}

void Board :: print(void)
{
    char horizontal_ch[10];
    horizontal_ch[0] = 'a';
    horizontal_ch[1] = 'b';
    horizontal_ch[2] = 'c';
    horizontal_ch[3] = 'd';
    horizontal_ch[4] = 'e';
    horizontal_ch[5] = 'f';
    horizontal_ch[6] = 'g';
    horizontal_ch[7] = 'h';
    horizontal_ch[8] = 'i';
    horizontal_ch[9] = 'j';
    
    int verticle_num[10];
    horizontal_ch[0] = 'a';
    
    cout << "   ";
    
    for (int i = 0; i < 10; i++)
    {
        cout <<  horizontal_ch[i] << " ";
        
    }
    
    cout << endl;
    cout << "  +-------------------+" <<endl;
    
    for (int i = 0; i <10 ; i++)
    {
        verticle_num[i] = i;
        cout <<" "<<  verticle_num[i] << "|";
        
        for (int j = 0; j <9; j++)
        {
            cout << score[i][j]<< " ";
        }
        
        cout << score[i][9];
        cout << "|"<<endl;
    }
    
    cout << "  +-------------------+"<<endl;
    
  
    
    
}
void Board ::hit (char c, int i)
{
    if (((c >='a') && (c < 'k')) && (i >= 0 && i < 10))
          
    {
        char horizontal[10];
        horizontal[0] = 'a';
        horizontal[1] = 'b';
        horizontal[2] = 'c';
        horizontal[3] = 'd';
        horizontal[4] = 'e';
        horizontal[5] = 'f';
        horizontal[6] = 'g';
        horizontal[7] = 'h';
        horizontal[8] = 'i';
        horizontal[9] = 'j';
       
        for (int j = 0; j< 10; ++j)
        {
            if (c == horizontal[j])
            {
                if (shipAt(j,i))
                {
                    if (score[i][j]!= '*' && score[i][j] != 'x')
                    {
                        score[i][j] = '*';
                                
                        shipAt(j,i)-> decreaseLevel();
                                
                        if(shipAt(j ,i)->level() == 0 )
                        {
                            cout << shipAt(j ,i)-> name() << " sunk" << endl;
                        }
                    }
                }
                        
                else
                {
                    if(score[i][j] != 'x' && score[i][j]!= '*')
                        score[i][j] = 'x';
                }
                    
            }
        }
    }
    
    else
          throw invalid_argument("invalid input");
}

    
    int Board::level(void)
    {
        int sum_level = 0;
        
        for(int i = 0; i < 10; i++)
        {
            sum_level += (shipList [i]->level());
        }
 
        return sum_level;
    }
    
    
    
    Ship *Board:: shipAt(int x, int y)
    {
        for(int i = 0; i < 10 ; i++)
        {
            if (shipList[i]->includes(x,y))
                return shipList[i];
        }
        return NULL;
    }




