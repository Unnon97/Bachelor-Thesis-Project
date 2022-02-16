#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;


class population
{
    public:
    string bitstring;
    int fitness;

    population() ()
    ~population()()

    population(string s, int f)
    {

    }
    int calcfitness(population present, population target)
    {
        int cnt = 0;
        int plen = strlen(present.bitstring);
        int tlen = strlen(target.bitstring);
        for(int i=0; i < strlen(present.bitstring); i++)
        {
           if(present.bitstring[i] == target.bitstring[i] )
                cnt++;
        }
    }
};

population people[10000];
population target()
string

int main()
{
    cout << "Hello world!" << endl;
    return 0;++
}
