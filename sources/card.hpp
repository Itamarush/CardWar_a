#pragma once
#include <string>
using namespace std;

namespace ariel
{
    class card
    {
        private:
            int num;
            int kind;

        public:
            card(int num, int kind){this->num = num; this->kind = kind;};
            string toString();
            card(){};

            int getNum () const
            {
                return this->num;
            }

            int getKind () const
            {
                return this->kind;
            }

            void setNum(int num)
            {
                this->num = num;
            };
            void setKind(int num)
            {
                this->kind = kind;
            };
    };
};
