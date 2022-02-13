#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

using std::cout;
using std::cin;
using std::string;
using std::endl;


class Duck
{
    public:
        Duck();
        void Drawing();
        void Circle();
        void Baby_circle();
        void Adult_circle();

        string getName();
        void setName();

        bool getMale();
        void setMale();

        int Mood();
        int Full();

        void setMood(int x);
        void setFull(int x);
        void setExp(int x);
        void setStg(string x);

        string getMood();
        string getFull();
        string getStg();
        int getExp();

    private:
        string name;
        bool male;

        int mood;
        int full;
        int exp;
        string stg;
        char drawing[15][30];

};

Duck::Duck()
{
    this->name = "";
    this->male = true;
    this->mood = 5;
    this->full = 5;
    this->exp = 0;
    this->stg = "EGG"; 
}

void Duck::setMood(int x)
{
    this->mood = x;
}

void Duck::setFull(int x)
{
    this->full = x;
}

void Duck::setExp(int x)
{
    this->exp = x;
}

void Duck::setStg(string x)
{
    this->stg = x;
}

void Duck::setName()
{
    cout << NC "Name Your Duck: ";
    cin >> this->name;
}

void Duck::setMale()
{
    while(1)
    {
        cout << NC "Choose its gender(type M or F): ";
        string gender;
        cin >> gender;
        if(gender.compare("M") == 0)
        {
            this->male = true;
            break;
        }
        else if(gender.compare("F") == 0)
        {
            this->male = false;
            break;
        }
        else
        {
            cout << NC "That is not a gender QUACK QUACK!\n";
        }
    }
}

string Duck::getName()
{
    return this->name;
}

bool Duck::getMale()
{
    return this->male;
}

void Duck::Drawing()
{
    for(int col=0; col<15  ; col++)
    {
        for(int row = 0; row<30 ; row++)
        {
            cout << this->drawing[col][row];
        }
        cout << endl;
    }
}

void Duck::Circle()
{
    for(int col=0; col<15; col++)
    {
        for(int row = 0; row<30 ; row++)
        {
            this->drawing[col][row] = ' ';
        }
    }
    for(int i=10;i<20;i++)
    {
        this->drawing[0][i] = '0';
        this->drawing[14][i] = '0';
    }
    for(int i=1;i<5;i++)
    {
        this->drawing[1][10-i] = '0';
        this->drawing[1][19+i] = '0';
        this->drawing[13][10-i] = '0';
        this->drawing[13][19+i] = '0';
    }
    for(int i=0;i<2;i++)
    {
        this->drawing[2][5-i] = '0';
        this->drawing[2][24+i] = '0';
        this->drawing[12][5-i] = '0';
        this->drawing[12][24+i] = '0';
    }

    for(int i=0;i<2;i++)
    {
        this->drawing[3][2+i] = '0';
        this->drawing[3][26+i] = '0';
        this->drawing[11][2+i] = '0';
        this->drawing[11][26+i] = '0';
    }

    this->drawing[4][1] = '0';
    this->drawing[4][28] = '0';
    this->drawing[10][1] = '0';
    this->drawing[10][28] = '0';

    for(int i=0;i<5;i++)
    {
        this->drawing[5+i][0] = '0';
        this->drawing[5+i][29] = '0';
    }
}

void Duck::Baby_circle()
{
    for(int i=5;i<7;i++)
    {
        this->drawing[i][10-i+5] = '0';
        this->drawing[i][9-i+5] = '0';
        this->drawing[i][20+i-5] = '0';
        this->drawing[i][21+i-5] = '0';
    }

        this->drawing[8][14] = '/';
        this->drawing[12][14] = '\\';
        this->drawing[8][15] = '\\';
        this->drawing[12][15] = '/';

        this->drawing[9][12] = '/';
        this->drawing[9][17] = '\\';
        this->drawing[11][12] = '\\';
        this->drawing[11][17] = '/';

    for(int i=0;i<8;i++)
    {
        this->drawing[10][11+i] = '-';
    }
}

void Duck::Adult_circle()
{
    for(int i=5;i<7;i++)
    {
        this->drawing[i][10-i+5] = '0';
        this->drawing[i][9-i+5] = '0';
        this->drawing[i][20+i-5] = '0';
        this->drawing[i][21+i-5] = '0';
    }
    
    this->drawing[7][14] = '/';
    this->drawing[13][14] = '\\';
    this->drawing[7][15] = '\\';
    this->drawing[13][15] = '/';

    this->drawing[8][12] = '/';
    this->drawing[12][12] = '\\';
    this->drawing[8][17] = '\\';
    this->drawing[12][17] = '/';

    this->drawing[9][10] = '/';
    this->drawing[9][19] = '\\';
    this->drawing[11][10] = '\\';
    this->drawing[11][19] = '/';

    for(int i=0;i<12;i++)
    {
        this->drawing[10][9+i] = '-';
    }

    for(int i=0;i<3;i++)
    {
        this->drawing[2+i][10+i*2] = '\\';
        this->drawing[2+i][20-i*2] = '/';
    }

}

string Duck::getStg()
{
    return this->stg;
}

string Duck::getMood()
{
    string duck_mood = "          ";
    for(int i=0;i<this->mood;i++)
    {
        duck_mood[i] = '*';
    }
    return duck_mood;
}

string Duck::getFull()
{
    string duck_full = "          ";
    for(int i=0;i<this->full;i++)
    {
        duck_full[i] = '*';
    }
    return duck_full;
}

int Duck::getExp()
{
    return this->exp;
}

int Duck::Mood()
{
    return this->mood;
}

int Duck::Full()
{
    return this->full;
}