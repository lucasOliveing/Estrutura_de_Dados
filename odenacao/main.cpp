#include "ordenacao.h"
#include <iostream>
using namespace std;

int main()
{
    int tam;
    int op;
    cout << "\nDigite a Operacao:\n1-Interativa.\n2-Interativo Op2.\n3-Recursivo.\n4-Recursivo Op2.\n";
    cin >> op;
    cout << "Digite o tamanho do vetor: ";
    cin >> tam;
    
    
    Sort *s[5];
    int *list = new int[tam];

    for (int i = 0; i < tam; i++)
        list[i] = rand() % 100;

    s[0] = new Insetion(list, tam);
    s[1] = new Selection(list, tam);
    s[2] = new Bubble(list, tam);
    s[3] = new Quick(list, tam);
    s[4] = new Merge(list, tam);

    int *saida[5];

    for (int i = 0; i < 5; i++)
    {
        if (op == 1)
        {
            saida[i] = s[i]->ord_inter();
        }
        else if (op == 2)
        {
            saida[i] = s[i]->ord_inter_op2();
        }
        else if (op == 3)
        {
            saida[i] = s[i]->ord_recur();
        }
        else if (op == 4)
        {
            saida[i] = s[i]->ord_recur_op2();
        }
        else
        {
            cout << "Operacao nao selecionada";
            abort();
        }
        cout << "Ordenacao por ";
        switch (i)
        {
        case 0:
            cout << "Insetio:\n";
            break;
        case 1:
            cout << "Selection:\n";
            break;
        case 2:
            cout << "Bubble: \n";
            break;
        case 3:
            cout << "Quick: \n";
            break;
        case 4:
            cout << "Merge: \n";
            break;
        default:
            break;
        }

        for (int k = 0; k < tam; k++)
        {
            cout << list[k] << " ";
        }
        cout << "\nSaida: [";
        for (int j = 0; j < tam - 1; j++)
        {
            cout << saida[i][j] << ", ";
        }
        cout << saida[i][tam - 1] << "]\n";
        cout << "Comparacoes: " << s[i]->comparacoes << " | Tempo: " << s[i]->exec_temp << " s\n";

        cout << "\n\n";
    }
    cout << "Dados:\n";
    for(int i=0; i< 5;i++){
        switch (i)
        {
        case 0:
            cout << "Insetio:   " << s[i]->comparacoes << " comparacoes, -> " << s[i]->exec_temp << " s\n";
            break;
        case 1:
            cout << "Selection: "<< s[i]->comparacoes << " comparacoes, -> " << s[i]->exec_temp << " s\n";
            break;
        case 2:
            cout << "Bubble:    "<< s[i]->comparacoes << " comparacoes, -> " << s[i]->exec_temp << " s\n";
            break;
        case 3:
            cout << "Quick:     "<< s[i]->comparacoes << " comparacoes, -> " << s[i]->exec_temp << " s\n";
            break;
        case 4:
            cout << "Merge:     "<< s[i]->comparacoes << " comparacoes, -> " << s[i]->exec_temp << " s\n";
            break;
        default:
            break;
        }
    }

    delete list;
}