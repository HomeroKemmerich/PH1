#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (int argc, char *argv[])
{
    string linha;

    ifstream Arquivo;

    Arquivo.open("entrada01.txt");

    if(Arquivo.is_open())
    {
        while (getline(Arquivo, linha))
        {
            cout << linha << '\n'; 
        }
        
        Arquivo.close();
    }
    else
        cout << "Não foi possível abrir o arquivo";
    
}