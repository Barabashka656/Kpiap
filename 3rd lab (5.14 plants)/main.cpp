#include <iostream>

using namespace std;


class Plant
{
public:
    Plant()
    {

    }
    Plant(string name)
    {
        this->personal_name = name;
    }
    virtual void get_info()
    {
        cout << "\n /// info about Plant ///\n\n class \"Plant\"\n plant name \"" << this->personal_name <<
            "\"\n with \"" << this->lifestyle << "\" lifestyle\n";
    }
    ~Plant()
    {

    }
protected:
    string lifestyle = "attached";
    string personal_name;
};

class Cannabis_sativa : public  virtual Plant
{
public:
    Cannabis_sativa()
    {

    }
    Cannabis_sativa(string name) :Plant(name)
    {

    }
    void get_info() override
    {
        cout << "\n /// info about Plant ///\n\n class \"Cannabis sativa\"\n plant name \"" << this->personal_name <<
            "\"\n with \"" << this->lifestyle << "\" lifestyle\n";
        cout << " seed size \"" << this->seeds << "\"\n average plant height \"" << this->average_height << "\"\n";
    }
    ~Cannabis_sativa()
    {

    }
protected:
    string seeds = "little";
    int average_height = 400;
};

class Bruce_banner : public  Cannabis_sativa
{
public:

    Bruce_banner(string name) : Cannabis_sativa(name)
    {
        this->personal_name = name;
    }
    void get_info() override
    {
        cout << "\n /// info about Plant ///\n\n class \"Cannabis sativa\"\n plant variety \"Bruce banner\"\n plant name \"" << this->personal_name <<
            "\"\n with \"" << this->lifestyle << "\" lifestyle\n";
        cout << " seed size \"" << this->seeds << "\"\n average plant height \"" << this->average_height << "\"\n" << " THC content \"" <<
            this->thc << "%\n";
    }
    ~Bruce_banner()
    {

    }
protected:
    int thc = 28;
};

class Cannabis_indica : public virtual Plant
{
public:
    Cannabis_indica()
    {

    }
    Cannabis_indica(string name) : Plant(name)
    {

    }
    void get_info() override
    {
        cout << "\n /// info about Plant ///\n\n class \"Cannabis indica\"\n plant name \"" << this->personal_name <<
            "\"\n with \"" << this->lifestyle << "\" lifestyle\n";
        cout << " seed size \"" << this->seeds << "\"\n average plant height \"" << this->average_height << "\"\n";
    }
    ~Cannabis_indica()
    {

    }
protected:
    string seeds = "big";
    int average_height = 150;
};

class Critical_kush : public Cannabis_indica
{
public:

    Critical_kush(string name) : Cannabis_indica(name)
    {
        this->personal_name = name;
    }
    void get_info() override
    {
        cout << "\n /// info about Plant ///\n\n class \"Cannabis indica\"\n plant variety \"Critical kush\"\n plant name \"" << this->personal_name <<
            "\"\n with \"" << this->lifestyle << "\" lifestyle\n";
        cout << " seed size \"" << this->seeds << "\"\n average plant height \"" << this->average_height << "\"\n" << " THC content \"" <<
            this->thc << "%\"\n";
    }
    ~Critical_kush()
    {

    }
protected:
    int thc = 25;
};

class Marijuana : public Bruce_banner, public Critical_kush
{
public:
    Marijuana(string name) : Bruce_banner(name), Critical_kush(name)
    {

    }
    void get_info() override
    {
        cout << "\n /// info about Plant ///\n\n class \"Marijuana\"\n plant variety \"Bruce banner\"\n plant name \"" << this->personal_name <<
            "\"\n with \"" << this->lifestyle << "\" lifestyle\n";

        cout << endl;
        cout << " /// short term effects of using ///" << endl;

        for (int i = 0; i < 3; i++)
            cout << " 1. " << this->short_term_effects[i] << endl;

        cout << endl;
        cout << " /// long term effects of using ///" << endl;

        for (int i = 0; i < 3; i++)
            cout << " 1. " << this->long_term_effects[i] << endl;

    }
    ~Marijuana()
    {

    }
protected:
    string short_term_effects[3] = { "euphoria", "insomnia", "sensitization" };
    string  long_term_effects[3] = { "addiction", "tolerance", "psychosis" };

};

int main()
{
    Plant boris("my_boris");
    boris.get_info();

    Cannabis_sativa sativa("my_sativa");
    sativa.get_info();

    Cannabis_indica indica("my_indica");
    indica.get_info();

    Bruce_banner bruce("my_bruce");
    bruce.get_info();

    Critical_kush kush("my_kush");
    kush.get_info();

    Marijuana ganja("my_ganja");
    ganja.get_info();
}
