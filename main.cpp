#include <iostream>
#include <cstdlib>
#include<conio.h>

using namespace std;

bool gameOver;
const int width =20;
const int height =20;
int x,y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int ntail;
enum eDirection {STOP=0, LEFT, Right , UP , DOWN};
eDirection dir;


void Setup(){
gameOver =false;
dir = STOP;
x= width /2;
y= height /2;

fruitX =rand()%height;
fruitY= rand()%width;
score = 0;
}


void Draw()
{
system("cls");

for (int i = 0;i< width +2; i++)
    cout<<"#";
    cout<<endl;

    for (int i = 0;i< height ; i++)
    {
        for (int j = 0; j< width ; j++)
        {

if(j == 0)
    cout << "#";
    if (i == y && j == x)
        cout <<"G";
    else if (i== fruitX && j== fruitY)
        cout <<"*";
    else
     cout << " ";
  if (j == width - 1)
         cout << "#";
        }
cout<<endl;
    }

for (int i = 0;i< width+2 ; i++)
cout<<"#";

cout<<endl;
cout << "score " << score<<endl;
cout << "position x  " <<fruitX<<endl;
cout << "position Y " <<fruitY<<endl;
cout << "position Gx  " <<x<<endl;
cout << "position GY " <<y<<endl;

}



void Input()
{
if (_kbhit())
{
    switch(_getch())
    {
        case 'q' :
        dir = LEFT;
        break;
        case 'd' :
        dir=Right;
        break;
        case 'z' :
        dir = UP;
        break;
        case 's' :
        dir = DOWN;
        break;
        case 'x' :
        gameOver=true;
        break;
    }
}

}


void Logic()
{
    switch(dir)
    {
    case STOP:
        x=x;
        y=y;
         break;
        case LEFT :
        x--;
        break;
        case Right :
        x++;
     break;
        case UP :
        y--;
        break;
        case DOWN :
y++;
        break;
    }
    if (x > width || x< 0 || y > height || y<0)
    {

        gameOver =true;
    }

      if (x == fruitY && y == fruitX)
    {
    score+=10;
    fruitX =rand()% width;
    fruitY =rand()% height;
    }

}
int main()
{
    Setup();
    while(!gameOver){

        Draw();

        Input();

        Logic();

//Sleep(10);





    }
cout <<endl;
cout<<"Game Over !";
    return 0;
}
