#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string AC, PC;

struct HEX 
{
    string END;
    string MEM;
};

vector<HEX> teste;
vector<HEX> Memory;

int endereco (string endereco)
{
    for (int i = 0; i < teste.size(); i++)
    {
        if (teste[i].END == endereco)
            return i;        
    }
    
}

void LDR()
{
}

//  EXECUÇÃO
int exe(int counter)
{
    for (int i = 0; i < teste.size(); i++)
    {
        switch (teste[i].MEM[0])
        {
        case '0':
            cout << "NOP\n";
            counter++;
            break;
        case '1':
        //LDR
            LDR();
            counter++;
            break;
        case '2':
        //STR
            counter++;
            break;
        case '3':
        //ADD
            counter++;
            break;
        case '4':
        //SUB
            counter++;
            break;
        case '5':
        //MUL
            counter++;
            break;
        case '6':
        //DIV
            counter++;
            break;
        case '7':
        //NOT
            counter++;
            break;
        case '8':
        //AND
            counter++;
            break;
        case '9':
        //OR
            counter++;
            break;
        case 'A':
        //XOR
            counter++;
            break;
        case 'B':
        //JMP
            counter++;
            break;
        case 'C':
        //JEQ
            counter++;
            break;
        case 'D':
        //JG
            counter++;
            break;
        case 'E':
        //JL
            counter++;
            break;
        case 'F':
        //HLT
            counter++;
            return counter;
        }
    }
    
}

void parse (string linha)
{
    string delim = " ";

    HEX Opcode;

    Opcode.END = linha.substr(0, linha.find(delim));
    Opcode.MEM = linha.substr(3);

    teste.push_back(Opcode);
}

int main (int argc, char *argv[])
{
    int counter = 0;

    string linha;

    ifstream Arquivo;

    Arquivo.open("entrada01.txt");

    if(Arquivo.is_open())
    {
        while (getline(Arquivo, linha))
        {
            parse(linha);
        }

        counter = exe(counter);

        //  SAÍDA
        cout << counter << "instructions executed" << endl;
        cout << '\n';
        cout << "Registers:" << endl;
        cout << "AC " << AC << endl;
        cout << "PC " << PC << endl;
        cout << '\n';
        cout << "Memory:" << endl;
        for (size_t i = 0; i < Memory.size(); i++)
        {
            cout << Memory[i].END << ' ' << Memory[i].MEM << endl;
        }
        
        
        Arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo";
    }
    
}