#include "Duck.h"

class User
{
    public:
        User();
        void Egg_creation();
        void Baby_creation();
        void Duck_creation();
        void Adult_creation();
        void Display_Status();
        void Display_Option();

        void Baby_Display_Status();
        void Adult_Display_Status();

        int Egg_Status_Change();
        int Baby_Status_change();
        void Duck_Status_Change();

    private:
        Duck* d1;
        int choice;
};


User::User()
{
    this->d1 = new Duck(); 
}

void User::Egg_creation()
{
    d1->setName();
    d1->setMale();

    cout << "Your Duck is born!\n";
}

void User::Baby_creation()
{
    d1->setMood(3);
    d1->setFull(3);
    d1->setExp(0);
    d1->setStg("BABY");
}

void User::Adult_creation()
{
    d1->setMood(5);
    d1->setFull(3);
    d1->setExp(0);
    d1->setStg("ADULT");
}

void User::Display_Option()
{
    cout << "\nWhat would you like to do to " << d1->getName() << "?\n";
    cout << "1. Feed it.\n2. Play with it.\n3. Leave it alone.\n";
    int option;
    cin >> option;
    cout << endl << endl;
    this->choice = option;
}

void User::Display_Status()
{
    d1->Circle();
    d1->Drawing();
    
    cout << "STAGE: " << d1->getStg() << " | ";
    cout << "EXP: " << d1->getExp() << " %" << " until next stage!" << endl;
    if(d1->getMale())
    {
        cout << "Name: " << d1->getName() << " | ";
    }
    else
    {
        cout << "Name: " << d1->getName() << " | ";
    }

    cout << "Mood: ";
    for(int i=0; i<10 ;i++)
    {
        if(d1->getMood()[i] == '*')
        {
            cout << CYN << "*";
        }
        else
        {
            cout << NC << "*";
        }
    }
    cout << NC << " | ";

    cout << "Fullness: ";
    for(int i=0; i<10;i++)
    {
        if(d1->getFull()[i] == '*')
        {
            cout << CYN << "*";
        }
        else
        {
            cout << NC << "*";
        }
    }
    cout << NC << " |\n";
}

int User::Egg_Status_Change()
{
    int mood;
    int exp;
    while(1)
    {
        int m = 0;
        int e = 20;
        switch(this->choice)
        {
            case 1:
                cout << "Nothing happened...\n";
                m = 1;
                break;
            case 2:
                cout << CYN << "Mood increased!" << NC << endl;
                mood = d1->Mood() + 1;
                d1->setMood(mood);
                exp = d1->getExp() + 20;
                d1->setExp(exp);
                m = 1;
                break;
            case 3:
                cout << CYN << "Mood significantly increased!" << NC << endl;
                mood = d1->Mood() + 3;
                d1->setMood(mood);
                exp = d1->getExp() + 60;
                d1->setExp(exp);
                m = 1;
                break;
            default:
                cout << "Invalid choice.\n";
                m = 1;
                break;
        }
        if(m==1)
        {
            break;
        }
    }
    if(d1->getExp() >= 100)
    {
        cout << GRN << "Your Egg is fetching!!" << NC << endl;
        d1->setStg("Baby");
        return 1;
    }
    return 0;
}

void User::Baby_Display_Status()
{
    d1->Circle();
    d1->Baby_circle();
    d1->Drawing();

    cout << "STAGE: " << d1->getStg() << " | ";
    cout << "EXP: " << d1->getExp() << " %" << " until next stage!" << endl;
    if(d1->getMale())
    {
        cout << "Name: " << d1->getName() << " | ";
    }
    else
    {
        cout << "Name: " << d1->getName() << " | ";
    }

    cout << "Mood: ";
    for(int i=0; i<10 ;i++)
    {
        if(d1->getMood()[i] == '*')
        {
            cout << CYN << "*";
        }
        else
        {
            cout << NC << "*";
        }
    }
    cout << NC << " | ";

    cout << "Fullness: ";
    for(int i=0; i<10;i++)
    {
        if(d1->getFull()[i] == '*')
        {
            cout << CYN << "*";
        }
        else
        {
            cout << NC << "*";
        }
    }
    cout << NC << " |\n";
}

int User::Baby_Status_change()
{
    int mood;
    int full;
    int exp;
    int cond = 0;
    while(cond == 0)
    {
        int e = 20;
        switch(this->choice)
        {
            case 1:
                cout << CYN << "Fullness and mood increased!" << NC << endl;

                mood = d1->Mood() + 1;
                d1->setMood(mood);

                full = d1->Full() + 2;
                d1->setFull(full);

                exp = d1->getExp() + 10;
                d1->setExp(exp);
                cond = 1;
                break;

            case 2:
                cout << "Mood increased and Fullness decreased!\n";

                mood = d1->Mood() + 3;
                d1->setMood(mood);

                full = d1->Full() - 1;
                d1->setFull(full);

                exp = d1->getExp() + 20;
                d1->setExp(exp);

                cond = 1;
                break;

            case 3:
                cout << RED << "Mood decreased!" << NC << endl;

                mood = d1->Mood() - 1;
                d1->setMood(mood);

                cond = 1;
                break;

            default:
                cout << "Invalid choice.\n";
                cond = 1;
                break;
        }
    }
    if(d1->Full() <= 0)
    {
        cout << RED << "Your Baby Duck died in hunger..." << NC << endl;
        d1->setStg("Death");
    }
    else if(d1->Full() >= 10)
    {
        cout << RED << "You fed your Baby Duck too much..." << NC << endl;
        d1->setStg("Death");
    }

    else if(d1->Mood() <= 0)
    {
        cout << RED << "Your Baby Duck died in lonliness..." << NC << endl;
        d1->setStg("Death");
    }

    else if(d1->Mood() >= 10)
    {
        cout << CYN << "Your Baby Duck is happy!!" << NC << endl;
        int exp = d1->getExp();
        d1->setExp(exp + 30);
        d1->setMood(3);
    }

    if(d1->getExp() >= 100)
    {
        cout << GRN << "Your Baby Duck is growing!!" << NC << endl;
        d1->setStg("Adult");
        d1->setExp(0);
        return 1;
    }

    if(d1->getStg() == "Death")
    {
        return -1;
    }
    return 0;
}

void User::Adult_Display_Status()
{
    d1->Circle();
    d1->Adult_circle();
    d1->Drawing();

    cout << CYN << "Congratulations, You have fully grown your duck, " << d1->getName() << "!!" << endl;
}