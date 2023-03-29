#pragma once
#include <string>
using namespace std;

class card
{
    private:
        int num;
        string kind;

    public:
        card(int num, string kind){this->num = num; this->kind = kind;};
        card(){};

        int getNum () const
        {
            return 1;
        }

        string getKind () const
        {
            return "hearts";
        }
};
