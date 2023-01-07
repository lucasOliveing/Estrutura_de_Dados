#include "class.h"

List::List()
{
    inicio = NULL;
    fim = NULL;
    size = 0;
}

List::~List()
{
    Node *i;
    while (inicio != NULL)
    {
        i = inicio;
        inicio = inicio->prox;
        delete i;
    }
}

List::Node *List::find(string dado)
{
    Node *i = inicio;
    while (i != NULL)
    {
        if (i->nome == dado)
        {
            return i;
        }
        i = i->prox;
    }
    return NULL;
}

List::Node *List::insert(string dado)
{
    Node *novo = new Node(dado);
    if (inicio == NULL)
    {
        inicio = novo;
        fim = novo;
        size++;
        return fim;
    }
    else
    {
        Node *aux = find(dado);
        if (aux == NULL)
        {
            Node *i = inicio;

            while (i != NULL && i->nome < dado)
                i = i->prox;

            if (i == NULL)
            {

                fim->prox = novo;
                novo->prev = fim;
                fim = novo;
                size++;
                return fim;
            }

            if(i->prev == NULL){
                i->prev = novo;
                novo->prox = i;
                novo->prev = NULL;
                inicio = novo;
                return inicio;
            }

            i->prev->prox = novo;
            i->prev = novo;
            novo->prev = i->prev;
            novo->prox = i;
            return novo;
        }
        else
        {
            return NULL;
        }
    }
}

bool List::erase(string dado)
{
    Node *i = find(dado);
    if (i != NULL)
    {
        if (size == 1)
        {
            inicio = NULL;
            fim = NULL;
            size--;
            delete i;
            return true;
        }
        else if (i->prev == NULL)
        {
            i->prox->prev = NULL;
            inicio = i->prox;
            size--;
            delete i;
            return true;
        }
        else if (i->prox == NULL)
        {
            i->prev->prox = NULL;
            fim = i->prev;
            size--;
            delete i;
            return true;
        }
        else
        {
            i->prev->prox = i->prox;
            i->prox->prev = i->prev;
            size--;
            delete i;
            return true;
        }
    }
    return false;
}

void List::print()
{
    Node *aux = inicio;
    while (aux != NULL)
    {
        cout << "-> " << aux->nome << endl;
        aux = aux->prox;
    }
}

//////////FUNCOES DA CLASSE COMUNIDADE///////////////////////
void Comunidade::incluirComunidade(string nomeComunidade, string nomeParticipante)
    {   
        List::Node *aux = a.insert(nomeComunidade);
        if (aux != NULL)
            cout << "<comunidade criada>>\n";
        else{
            cout << "<<comunidade encontrada>>\n";
            aux = a.find(nomeComunidade);
        }

        if (aux->part->insert(nomeParticipante) != NULL){
            cout << "<<participante inserido>>\n";
            aux->part->size++;
        }else
            cout << "<<participante ja inserido>>\n";
    }
    int Comunidade::size()
    {
        return a.size;
    }
    void Comunidade::listarComunidade()
    {
        if (a.size > 0)
            a.print();
        else
            cout << "<<sem comunidades>>\n";
    }

    void Comunidade::excluirComunidade(string nomeComunidade)
    {
        if (a.erase(nomeComunidade))
            cout << "Comunidade removida << " << nomeComunidade << " >>\n";
        else    
            cout << "<<comunidade nao encontrada>>\n";
    }

    void Comunidade::listarParticipantes(string nomeComunidade)
    {
        List::Node *aux = a.find(nomeComunidade);
        if (aux != NULL)
        {
            cout << "Participante(s)::\n";
            aux->part->print();
        }
        else
            cout << "<<comunidade nao encontrada>>\n";
    }

    void Comunidade::listarComunidadeParticipante(string nomeParticipante)
    {
        int ope = 0;
        List::Node *i = a.inicio;
        List::Node *aux;
        while (i != NULL)
        {
            aux = i->part->find(nomeParticipante);
            if (aux != NULL)
            {
                if (ope == 0)
                    ope = 1;
                if (ope == 1)
                {
                    cout << "Comunidade(s)::\n";
                    ope = 2;
                }
                cout << "-> " << i->nome << endl;
            }
            i = i->prox;
        }

        if (ope == 0)
            cout << "<<participante nao encontrado>>\n";
    }

    void Comunidade::excluirParticipante(string nomeParticipante)
    {
        int ope = 0;
        List::Node *i = a.inicio;
        List::Node *aux;

        while (i != NULL)
        {

            aux = i->part->find(nomeParticipante);
            if (aux != NULL) 
            {
                ope = 1;
                cout << "participante removido da comunidade << " << i->nome << " >>\n";
                i->part->erase(nomeParticipante);
                i->part->size--;
                if (i->part->size <= 0)
                {
                    cout << "<<comunidade removida>>\n";
                    a.erase(i->nome);
                }
            }
            i = i->prox;
        }
        if (ope == 0)
            cout << "<<participante nao encontrado>>\n";
    }