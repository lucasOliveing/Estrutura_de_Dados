#include <iostream>
using namespace std;

class List
{
    friend class Comunidade;
    class Node
    {
    public:
        string nome;
        List *part;
        Node *prox;
        Node *prev;

        Node(string nome_)
        {
            nome = nome_;
            part = new List();
            prox = NULL;
            prev = NULL;
        }
        ~Node()
        {
            delete part;
        }
};

private:
    Node *inicio;
    Node *fim;
    int size;

public:
    List();
    ~List();
    Node *find(string dado);
    Node *insert(string dado);
    bool erase(string dado);
    void print();
};

class Comunidade
{
private:
    List a;

public:
    int size();

    void incluirComunidade(string nomeComunidade, string nomeParticipante);
    void listarComunidade();
    void excluirComunidade(string nomeComunidade);
    void listarParticipantes(string nomeComunidade);
    void listarComunidadeParticipante(string nomeParticipante);
    void excluirParticipante(string nomeParticipante);
};
