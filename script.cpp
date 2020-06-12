#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct HEX 
{
    string END;
    string MEM;
};

vector<string> conjunto;

vector<HEX> teste;

void execucao(HEX OpCode)
{

}

HEX instrucao(string linha)
{
    string delim = " ";

    HEX OpCode;

    OpCode.END = linha.substr(0, linha.find(delim));

    OpCode.MEM = linha.substr(3);

    teste.push_back(OpCode);

    return OpCode;
}

int main (int argc, char *argv[])
{
    string argumento = argv[0];

    string linha;

    ifstream Arquivo;

    Arquivo.open("entrada01.txt");

    if(Arquivo.is_open())
    {
        int indice = 0;

        while (getline(Arquivo, linha))
        {

            // cout << linha << '\n';

            instrucao(linha);

            indice++;
        }

        for (int i = 0; i < teste.size(); i++)
        {
            cout << teste[i].END << " " << teste[i].MEM << endl;
        }
        
        
        Arquivo.close();
    }
    else
        cout << "Não foi possível abrir o arquivo\n";
    
}

