#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main (int argc, char *argv[])
{
    //Inicialização das variáveis
    int AC = 0,     //Acumulador
        end = 0,    //Registrador de endereço de memória
        RDM = 0,    //Registrador de dados de memória
        MEM[256],   //Memória inicial
        Memory[256],//Memória final
        PC = 0,     //Program Counter
        counter = 0,//Contador de instruções
        END = 0,    //Endereço 
        Cont = 0,   //Conteúdo 
        RI = 0;     //Registrador de instruções

    FILE *Arquivo;

    for (size_t i = 0; i < 256; i++)
    {
        MEM[i] = 0;
        Memory[i] = 0;
    }

    //Validação da entrada
    if (argc != 2)
    {
        cout << "Parametros invalidos\n";
        return 1;
    }

    //Validação do arquivo
    if (Arquivo == NULL)
    {
        cout << "Arquivo invalido\n";
        return 1;
    }

    Arquivo = fopen(argv[1], "r");
    
    cout << "Input file: " << argv[1] << endl << endl;

    //Adiciona o conteúdo do arquivo para duas listas
    while (!feof(Arquivo))
    {
        fscanf(Arquivo, "%x %x", &END, &Cont);

        Memory[END] = Cont;

        MEM[END] = Cont;
    }
    fclose(Arquivo);

    while (1)
    {
        //Atualização da próxima instrução
        end = PC;
        RDM = MEM[end];
        RI = RDM;

        switch (RI)
        {
        case 0x00:
        //NOP
            cout << "NOP\n";
            PC++;
            counter++;
            continue;
        
        case 0x10:
        //LDR
            RDM = MEM[end+1];
            printf("LDR %x ; ", RDM); 
            printf("AC <- MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC = RDM;
            PC += 2;
            counter++;
            continue;
        case 0x20:
        //STR
            RDM = MEM[end+1];
            printf("STR %x ; ", RDM); 
            printf("MEM[%x] <- AC\n", RDM);
            end = RDM;
            RDM = MEM[end];
            MEM[end] = AC;
            PC += 2;
            counter++;
            continue;
        case 0x30:
        //ADD
            RDM = MEM[end+1];
            printf("ADD %x ; ", RDM); 
            printf("AC <- AC + MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC  = AC + MEM[end];
            PC += 2;
            counter++;
            continue;
        case 0x40:
        //SUB
            RDM = MEM[end+1];
            printf("SUB %x ; ", RDM); 
            printf("AC <- AC - MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC  = AC - MEM[end];
            PC += 2;
            counter++;
            continue;
        case 0x50:
        //MUL
            RDM = MEM[end+1];
            printf("MUL %x ; ", RDM); 
            printf("AC <- AC * MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC  = AC * MEM[end];
            PC += 2;
            counter++;
            continue;
        case 0x60:
        //DIV
            RDM = MEM[end+1];
            printf("DIV %x ; ", RDM); 
            printf("AC <- AC / MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC  = AC / MEM[end];
            PC += 2;
            counter++;
            continue;
        case 0x70:
        //NOT
            RDM = MEM[end+1];
            printf("NOT ; "); 
            printf("AC <- !AC\n");
            end = RDM;
            RDM = MEM[end];
            AC  = !AC;
            PC ++;
            counter ++;
            continue;
        case 0x80:
        //AND
            RDM = MEM[end+1];
            printf("AND %x ; ", RDM); 
            printf("AC <- AC & MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC  = AC & MEM[end];
            PC += 2;
            counter++;
            continue;
        case 0x90:
        //OR
            RDM = MEM[end+1];
            printf("OR %x ; ", RDM); 
            printf("AC <- AC | MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC  = AC | MEM[end];
            PC += 2;
            counter++;
            continue;
        case 0xA0:
        //XOR
            RDM = MEM[end+1];
            printf("XOR %x ; ", RDM); 
            printf("AC <- AC ^ MEM[%x]\n", RDM);
            end = RDM;
            RDM = MEM[end];
            AC  = AC ^ MEM[end];
            PC += 2;
            counter++;
            continue;
        case 0xB0:
        //JMP
            RDM = MEM[end+1];
            printf("JMP %x ; ", RDM);
            printf("PC <- %x\n", RDM);
            end = RDM;
            RDM = MEM[end+1];
            PC = RDM;
            PC += 2;
            counter ++;
            continue;
        case 0xC0:
        //JEQ
            if (AC == 0)
            {
                RDM = MEM[end+1];
                printf("JEQ %x ; ", RDM);
                printf("se (AC == 0) entao PC <- %x\n", RDM);
                end = RDM;
                RDM = MEM[end+1];
                PC = RDM;
                PC += 2;
                counter ++;
                continue;
            }
        case 0xD0:
        //JG
            if (AC > 0)
            {
                RDM = MEM[end+1];
                printf("JG %x ; ", RDM);
                printf("se (AC > 0) entao PC <- %x\n", RDM);
                end = RDM;
                RDM = MEM[end+1];
                PC = RDM;
                PC += 2;
                counter ++;
                continue;
            }
        case 0xE0:
        //JL
            if (AC < 0)
            {
                RDM = MEM[end+1];
                printf("JL %x ; ", RDM);
                printf("se (AC < 0) entao PC <- %x\n", RDM);
                end = RDM;
                RDM = MEM[end+1];
                PC = RDM;
                PC += 2;
                counter ++;
                continue;
            }
        case 0xF0:
        //HLT
            printf("HLT\n\n");
            PC ++;
            counter ++;
            break;
        }

    }

    //  SAÍDA
    printf("%d instructions executed\n\n", counter);

    printf("Registers:\n");
    printf("AC %02x\n", AC);
    printf("PC %02x\n\n", PC);

    printf("Memory:\n");
    for(int i=128; i < 255; i++)
    {
        if(Memory[i] != MEM[i])
        {
            printf("%02x %02x\n",i, MEM[i]);
        }
    }
}