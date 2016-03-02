#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class zwierze
{
protected:
    int8_t masa;

public:
    virtual void daj_glos() = 0;

    void ustaw_mase(int8_t masa)
    {
        this -> masa = masa;
    }

    zwierze()
    {
        ustaw_mase(0);
    }
};

class koza : public zwierze
{
public:
    virtual void daj_glos()
    {
        cout << "meee!" << endl;
    }

   void ustaw_mase(int8_t masa)
    {
        zwierze::ustaw_mase(masa%50);
        cout << masa << endl;
    }
};

class gnu : public zwierze
{
    virtual void daj_glos()
    {
        cout << "gnuuu!!!" << endl;
    }

    void ustaw_mase(int8_t masa)
    {
        zwierze::ustaw_mase(masa%75);
        cout << masa << endl;
    }
};

class zebra : public zwierze
{
    virtual void daj_glos()
    {
        cout << "zebr zebr" << endl;
    }

    void ustaw_mase(int8_t masa)
    {
        zwierze::ustaw_mase(masa%120);
        cout << masa << endl;
    }
};

class forfiter : public zwierze
{
    virtual void daj_glos()
    {
        cout << "szwagier!" << endl;
    }

    void ustaw_mase(uint8_t masa)
    {
        zwierze::ustaw_mase(masa%30);
        cout << masa << endl;
    }
};

int main()
{
    vector <int8_t> zwierz;
    zwierze *z;
    srand(time(NULL));

    int8_t masa = rand();

    z = new koza;

    z -> daj_glos();
    z -> ustaw_mase(masa);
    delete z;
    //for(int i = 0; i < 10; i++)
    //{

    //}

    return 0;
}
