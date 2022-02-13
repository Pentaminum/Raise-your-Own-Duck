#include <iostream>
#include "User.h"

using std::cout;



int main()
{
    User u1;
    cout << "Welcome, Duck master!" << endl << endl;
    u1.Egg_creation();
    u1.Display_Status();
    while(1)
    {
        cout << "*********************************************************\n";
        u1.Display_Option();
        if(u1.Egg_Status_Change() == 1)
        {
            break;
        }
        u1.Display_Status();
    }
    cout << "Your Duck is now a baby!\n";

    u1.Baby_creation();
    u1.Baby_Display_Status();
    int survive = 0;
    while(1)
    {
        cout << "*********************************************************\n";
        u1.Display_Option();
        int a = u1.Baby_Status_change();
        if(a == -1)
        {
            cout << "GAME OVER\n";
            survive = 0;
            break;
        }
        else if(a == 1)
        {
            cout << "Your Duck is now an Adult!\n";
            survive = 1;
            break;
        }
        u1.Baby_Display_Status();
    }

    if(survive == 1)
    {
        u1.Adult_creation();
        u1.Adult_Display_Status();
    }
}