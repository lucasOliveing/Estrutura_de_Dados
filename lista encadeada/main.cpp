#include "class.h"
void print(string);

int main()
{
    Comunidade *comunidades = new Comunidade;
    string ope;
    string comun;
    string part;

    print("0");
    while (1)
    {

        cout << "Operacao:: ";
        getline(cin, ope, '\n');
        if (ope == "exit" || ope == "sair")
            return 0;
        else if (ope == "0")
        {
            system("cls");
            print("0");
        }
        else if (ope == "1")
        {

            system("cls");
            print("1");
            cout << "Digite o nome da Comunidade: ";
            getline(cin, comun, '\n');
            cout << "Digite o nome do Participante: ";
            getline(cin, part, '\n');
            system("cls");
            print("1");
            cout << "Comunidade: " <<comun << ", Participante: "<< part << endl;
            comunidades->incluirComunidade(comun, part);
        }
        else if (comunidades->size() == 0)
        {
            system("cls");
            print("0");
            cout << "<<sem comunidade>>\n";
        }
        else if (ope == "2")
        {
            system("cls");
            print("2");
            cout << "Lista de Comunidades:: \n";
            comunidades->listarComunidade();
        }
        else if (ope == "3")
        {
            system("cls");
            print("3");
            cout << "Digite o nome da Comunidade a ser excluida: ";
            getline(cin, comun, '\n');
            comunidades->excluirComunidade(comun);
        }
        else if (ope == "4")
        {
            system("cls");
            print("4");

            cout << "Digite o nome da Comunidade: ";
            getline(cin, part, '\n');
            system("cls");
            print("4");
            cout << "Comunidade << " << part << " >>\n";
            comunidades->listarParticipantes(part);
        }
        else if (ope == "5")
        {
            system("cls");
            print("5");
            cout << "Digite o nome do Participante: ";
            getline(cin, part, '\n');
            comunidades->listarComunidadeParticipante(part);
        }
        else if (ope == "6")
        {
            system("cls");
            print("6");

            cout << "Digite o nome do Participante: ";
            getline(cin, part, '\n');
            comunidades->excluirParticipante(part);
        }
    }
}

void print(string ope)
{
    if (ope == "0")
    {
        cout << "Digite << exit >> para sair\n";
        cout << "\n:::Operacoes::: \n1: incluir comunidade\n2: listar comunidades\n3: excluir comunidade\n4: listar participantes\n5: listar comunidades do participante\n6: excluir participante\n\n";
    }
    else if (ope == "1")
    {
        cout << "Digite << exit >> para sair\n";
        cout << "\nOperacao:: 1 - incluir comunidade\n1: << incluir comunidade >>\n2: listar comunidades\n3: excluir comunidade\n4: listar participantes\n5: listar comunidades do participante\n6: excluir participante\n\n";
    }
    else if (ope == "2")
    {
        cout << "Digite << exit >> para sair\n";
        cout << "\nOperacao:: 2 - listar comunidades\n1: incluir comunidade\n2: << listar comunidades >>\n3: excluir comunidade\n4: listar participantes\n5: listar comunidades do participante\n6: excluir participante\n\n";
    }
    else if (ope == "3")
    {
        cout << "Digite << exit >> para sair\n";
        cout << "\nOperacao:: 3 -> excluir comunidade\n1: incluir comunidade\n2: listar comunidades\n3: << excluir comunidade >>\n4: listar participantes\n5: listar comunidades do participante\n6: excluir participante\n\n";
    }
    else if (ope == "4")
    {
        cout << "Digite << exit >> para sair\n";
        cout << "\nOperacao:: 4 -> listar participantes\n1: incluir comunidade\n2: listar comunidades\n3: excluir comunidade\n4: << listar participantes >>\n5: listar comunidades do participante\n6: excluir participante\n\n";
    }
    else if (ope == "5")
    {
        cout << "Digite << exit >> para sair\n";
        cout << "\nOperacao:: 5 -> listar comunidades do participante\n1: incluir comunidade\n2: listar comunidades\n3: excluir comunidade\n4: listar participantes\n5: << listar comunidades do participante >>\n6: excluir participante\n\n";
    }
    if (ope == "6")
    {
        cout << "Digite << exit >> para sair\n";
        cout << "\nOperacao:: 6 -> excluir participante\n1: incluir comunidade\n2: listar comunidades\n3: excluir comunidade\n4: listar participantes\n5: listar comunidades do participante\n6: << excluir participante >>\n\n";
    }
}