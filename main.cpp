#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class zwierze{
public:
    virtual ~zwierze();
    virtual void daj_glos() = 0;
};

class fabryka{
private:
    vector <kreatoryZwierzy> kreatory;

public:
    void nowy_gatunek(zwierzeKreator* kreator) {kreatory.push_back(kreator);}

    zwierze *tworz() {
        uint32_t index  = rand() % (kreatory.size());
        return kreatory.at(index) -> tworz();
    }

    ~fabryka(){
        for( uint32_t j = 0; j< kreatory.size(); j++)
            delete kreatory.at(j);

        kreatory.clear();

    }
};
class zwierzeKreator{
public:
    virtual zwierze* tworz() = 0;
};

class gnu : public zwierze{
    public:
    virtual void daj_glos() { cout << "gnuuu!!!" << endl; }
};

class gnuKreator: public zwierzeKreator{
protected:
   void ustaw_mase(int8_t masa) { }

public:
    virtual zwierze* tworz() { return new gnu(); }
};

class zebra : public zwierze{
    public:
    virtual void daj_glos() { cout << "zebr zebr" << endl; }

    virtual ~zebra();
};

class zebraKreator : public zwierzeKreator{
protected:
    void ustaw_mase(uint8_t masa) { }

public:
    virtual zwierze* tworz() {return new zebra(); }
};

int main()
{
    vector <zwierzeKreator*> z;
    //zwierze *z;
    srand(time(NULL));

    //int8_t masa = rand();

    for( int i=0; i<10; i++ ){
        if( rand() % 2 )
            z.push_back(new gnuKreator());
        else
            z.push_back(new zebraKreator());


        z.at(i) -> daj_glos;
    }
    //git desktop app test
    return 0;
}
