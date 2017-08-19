// Programmer : Yao Chen    
// This program is part of the object-oriented implementation of the battleship board game

#include<iostream>
#include<stdexcept>
#include"Ship.h"
using namespace std;

int Ship::getX(int i)const
{
    int x;
    
    
    for(int j = 0; j< size(); j++)
    {
        if (j == i)
        {
            
            if(x1 == x2)
                return x1;
            else if (x2>x1)
                x = x1+j;
            else
                x = x2+j;
            return x;
        }
    }
    return 0;
}

int Ship::getY(int i)const
{
    int y;
   
    for(int j = 0; j< size(); j++)
    {
        if (j == i)
        {
            
            if(y1 == y2)
                return y1;
            else if (y2>y1)
                y = y1+j;
            else
                y = y2+j;
            return y;
        }
    }

    return 0;
  
}


void Ship::print(void)const
{
    cout << name() << " from "<< "("<< x1<< ","<< y1 << ") to ("<< x2 <<"," <<y2<< ")"<<endl;
}

bool Ship::includes(int x, int y)
{
    if (x1 == x2 && x == x1 )
    {
        if (y2>y1)
        {
           if(y<= y2 && y>= y1)
               
               return true;
        }
        
        if(y1>y2)
        {
            if(y<=y1 && y>= y2)
                
                return true;
        }
    }
    
    else if(y1 == y2 && y == y1 )
    {
        if (x2>x1 && x<= x2 && x>= x1)
        
                return true;
        
        if (x1>x2 && x<= x1 && x>= x2)
        
                return true;
        
    }
        return false;
    
}

int Ship::level(void)const
{
    return lev;
}


void Ship::decreaseLevel(void)
{
    
    if (lev > 0)
        lev -= 1;

}

void Ship::setPos( int a1, int b1, int a2, int b2 )
{
    x1 = a1;
    x2 = a2;
    y1 = b1;
    y2 = b2;
    
    if (!checkConfig(a1,b1,a2,b2))
        throw invalid_argument("invalid configuration");
    
}


bool Ship::checkConfig(int x1, int y1, int x2, int y2)
{
    if (x1<= 10 && x2<=10 && y1<=10 && y2<=10)
    {
        if(x1 ==x2 && abs(y2-y1)== size()-1)
            return true;
        
        else if (y1 == y2 && abs(x2-x1) == size()-1)
            return true;
        
        else
            return false;
    }
    
    else
        return false;
}

////////////////////
//AircraftCarrier////
///////////////////

AircraftCarrier::AircraftCarrier(int x1, int y1, int x2, int y2)
{
    setPos(x1,y1,x2,y2);
    lev = size();

}


const char* AircraftCarrier::name(void) const
{
    const char *p="AircraftCarrier";
    
    return p;
}

int AircraftCarrier:: size(void)const
{
    int AircraftCarrier_size = 5;
    
    return AircraftCarrier_size;
}

/////////////////
//BattleShip
/////////////

BattleShip::BattleShip(int x1, int y1, int x2, int y2)
{
    setPos(x1,y1,x2,y2);
    lev = size();

}

 const char* BattleShip:: name(void)const
{
    
    const char *p ="BattleShip";
    
    
    return p;
}

int BattleShip:: size(void)const
{

    int BattleShip_size = 4;
    
    return BattleShip_size;
}

//////////////
//Cruiser
/////////////

Cruiser::Cruiser(int x1, int y1, int x2, int y2)
{
    setPos(x1,y1,x2,y2);
    lev = size();

}

 const char* Cruiser:: name(void)const
{
   
    const char *p="Cruiser";
    
    return p;
}

int Cruiser:: size(void)const
{
    int Cruiser_size = 3;
   
    return Cruiser_size;
}

////////////////
//Destroyer
///////////////

Destroyer::Destroyer(int x1, int y1, int x2, int y2)
{
    setPos(x1,y1,x2,y2);
    lev = size();
}

const char* Destroyer:: name(void) const
{
    const  char *p="Destroyer";

    return p;
}

int Destroyer:: size(void) const
{
    int Destroyer_size = 2;
  
    return Destroyer_size;
}


Ship *Ship::makeShip(char ch,int x1, int y1, int x2, int y2)
{
    if (ch == 'A') return  new AircraftCarrier(x1,y1,x2,y2);
    
    else if (ch == 'B') return  new BattleShip(x1,y1,x2,y2);
    
    else if (ch == 'C') return  new Cruiser(x1,y1,x2,y2);
    
    else if (ch == 'D') return new Destroyer(x1,y1,x2,y2);
    
    else
    {
        throw invalid_argument("invalid configuration");
    }
    return NULL;
    
}



