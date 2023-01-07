#include "ordenacao.h"
#include <iostream>
#include <ctime>
using namespace std;

int *Sort::alocar(int *list, int lenght)
{
    list_ord = new int[lenght];
    aux_len = lenght;
    for (int i = 0; i < lenght; i++)
        list_ord[i] = list[i];

    return list_ord;
}
Sort::~Sort()
{
    delete list_ord;
}
Bubble::Bubble(int *list_, int lenght_)
{
    list = list_;
    lenght = lenght_;
    num_comp = 0;
}

void Bubble::interativo()
{
    bool ordenado = false;

    while (!ordenado)
    {
        ordenado = true;
        for (int i = 0; i < lenght - 1; i++)
        {
            num_comp++;
            if (list[i] > list[i + 1])
            {
                swap(list[i], list[i + 1]);
                ordenado = false;
            }
        }
        lenght--;
    }
}
void Bubble::interativo_op2()
{
    bool ordenado = false;

    while (!ordenado)
    {
        ordenado = true;
        for (int i = 0; i < lenght - 1; i++)
        {
            num_comp++;
            if (list[i] % 2 == 0 && list[i + 1] % 2 == 1)
            {
                num_comp++;
                swap(list[i], list[i + 1]);
                ordenado = false;
            }
            else if (list[i] > list[i + 1])
            {
                num_comp += 2;
                if (list[i] % 2 == 1 && list[i + 1] % 2 == 1)
                {
                    num_comp++;
                    swap(list[i], list[i + 1]);
                    ordenado = false;
                }
            }
            else
            {
                num_comp++;
                if (list[i] % 2 == 0 && list[i + 1] % 2 == 0)
                {
                    num_comp++;
                    swap(list[i], list[i + 1]);
                    ordenado = false;
                }
            }
        }
        lenght--;
    }
}

void Bubble::recursivo()
{
    bool ordenado = true;

    for (int i = 0; i < lenght - 1; i++)
    {
        num_comp++;
        if (list[i] > list[i + 1])
        {
            swap(list[i], list[i + 1]);
            ordenado = false;
        }
    }
    if (ordenado)
        return;

    --lenght;
    recursivo();
}
void Bubble::recursivo_op2()
{
    bool ordenado = true;

    for (int i = 0; i < lenght - 1; i++)
    {
        num_comp++;
        if (list[i] % 2 == 0 && list[i + 1] % 2 == 1)
        {
            num_comp++;
            swap(list[i], list[i + 1]);
            ordenado = false;
        }
        else if (list[i] > list[i + 1])
        {
            num_comp += 2;
            if (list[i] % 2 == 1 && list[i + 1] % 2 == 1)
            {
                num_comp++;
                swap(list[i], list[i + 1]);
                ordenado = false;
            }
        }
        else
        {
            num_comp++;
            if (list[i] % 2 == 0 && list[i + 1] % 2 == 0)
            {
                num_comp++;
                swap(list[i], list[i + 1]);
                ordenado = false;
            }
        }
    }
    if (ordenado)
        return;

    --lenght;
    recursivo_op2();
}
int *Bubble::ord_inter()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;
    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Bubble::ord_inter_op2()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;
    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Bubble::ord_recur()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    recursivo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;
    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Bubble::ord_recur_op2()
{
    int *aux = list;
    list = alocar(list, lenght);

    clock_t begin = clock();
    recursivo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;
    list = aux;
    lenght = aux_len;
    return list_ord;
}

Insetion::Insetion(int *list_, int lenght_)
{
    list = list_;
    lenght = lenght_;
    num_comp = 0;
}

void Insetion::inserir(int inicio)
{
    int key = list[inicio];
    int i = inicio - 1;

    while (i >= 0 && list[i] > key)
    {
        num_comp++;
        list[i + 1] = list[i];
        i--;
    }
    list[i + 1] = key;
}
void Insetion::inserir_par(int inicio)
{
    int key = list[inicio];
    int i = inicio - 1;
    while (i >= 0 && list[i] % 2 == 0 && list[i] < key)
    {
        num_comp += 2;
        list[i + 1] = list[i];
        i--;
    }
    list[i + 1] = key;
}

void Insetion::interativo()
{
    interativo(0);
}
void Insetion::interativo(int inicio)
{
    for (int j = inicio + 1; j < lenght; j++)
        inserir(j);
}

void Insetion::interativo_op2()
{
    interativo_op2(0);
}
void Insetion::interativo_op2(int inicio) // DESCRICAO - 2 etapas
{
    int j = 1;
    while (j < lenght)
    {
        num_comp++;
        if (list[j] % 2 == 1 && list[j - 1] % 2 == 0)
        {
            num_comp++;
            swap(list[j], list[j - 1]);
            j = j - 1;
        }
        else if (list[j] % 2 == 1)
        {
            num_comp++;
            inserir(j++);
        }
        else
            inserir_par(j++);
    }
}
void Insetion::recursivo()
{
    recursivo(0);
}
void Insetion::recursivo(int inicio)
{
    if (inicio >= lenght - 1)
        return;

    inserir(++inicio);
    recursivo(inicio);
}
void Insetion::recursivo_op2()
{
    recursivo_op2(0);
}
void Insetion::recursivo_op2(int inicio)
{
    if (inicio + 1 >= lenght)
        return;

    num_comp += 2;
    if (list[inicio + 1] % 2 == 1 && list[inicio] % 2 == 0)
    {
        num_comp++;
        swap(list[inicio + 1], list[inicio]);
        recursivo_op2(--inicio);
    }
    if (list[inicio + 1] % 2 == 1)
        inserir(inicio + 1);
    else
        inserir_par(inicio + 1);

    recursivo_op2(++inicio);
}
int *Insetion::ord_inter()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;
    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Insetion::ord_inter_op2()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Insetion::ord_recur()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    recursivo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Insetion::ord_recur_op2()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    recursivo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}

Selection::Selection(int *list_, int lenght_)
{
    list = list_;
    lenght = lenght_;
    num_comp = 0;
}
int Selection::select(int i)
{
    for (int j = i + 1; j < lenght; j++)
    {
        num_comp++;
        if (list[j] < list[i])
            i = j;
    }
    return i;
}
void Selection::interativo()
{
    for (int i = 0; i < lenght - 1; i++)
        swap(list[i], list[select(i)]);
}
void Selection::recursivo()
{
    if (inicio >= lenght - 1)
        return;
    swap(list[inicio++], list[select(inicio)]);
    recursivo();
}

void Selection::interativo_op2()
{

    int indexMin;
    for (int i = 0; i < lenght - 1; i++)
    {
        int aux = select(i);
        num_comp++;
        if (list[aux] % 2 == 0)
        {
            swap(list[--lenght], list[aux]);
            i--;
        }
        else
            swap(list[i], list[aux]);
    }
}

void Selection::recursivo_op2() /// DIficuldades: nao conseguir alterar o valor de lenght para as prox interacao recursiva
{                               // assim, impossibilitar usar a funcao select(), pois sempre vai percorrer o vetor ate o fim.

    if (inicio >= lenght - 1)
        return;

    int aux = inicio;
    for (int i = inicio + 1; i < lenght; i++)
    {
        num_comp++;
        if (list[aux] > list[i])
            aux = i;
    }
    num_comp++;
    if (list[aux] % 2 == 0)
        swap(list[aux], list[--lenght]);
    else
        swap(list[inicio++], list[aux]);

    recursivo_op2();
}

int *Selection::ord_inter()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Selection::ord_inter_op2()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Selection::ord_recur()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    recursivo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Selection::ord_recur_op2()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    recursivo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}

Quick::Quick(int *list_, int lenght_)
{
    list = list_;
    lenght = lenght_;
    i = new Index[924370];
    num_comp = 0;
}
Quick::~Quick()
{
    delete i;
}
int Quick::_partition(int inicio, int fim)
{
    int pivot = fim--;
    while (inicio < fim)
    {
        num_comp++;
        if (list[fim] > list[pivot])
        {
            num_comp++;
            if (list[fim] > list[inicio])
                swap(list[fim], list[inicio]);
            inicio++;
        }
        else
            fim--;
    }
    num_comp++;
    if (list[inicio] < list[pivot])
        swap(list[inicio], list[pivot]);
    return inicio;
}
void Quick::_interativo()
{
    _interativo(0, lenght);
}
void Quick::_interativo(int inicio, int lenght)
{
    int inter_atual = 0;
    int inter_final = 0;

    i[0].inicio = inicio;
    i[0].fim = lenght - 1;

    while (inter_atual <= inter_final)
    {

        if (i[inter_atual].inicio < i[inter_atual].fim)
        {

            i[inter_atual].pivot = _partition(i[inter_atual].inicio, i[inter_atual].fim);

            inter_final++;
            i[inter_final].inicio = i[inter_atual].inicio;
            i[inter_final].fim = i[inter_atual].pivot - 1;

            inter_final++;
            i[inter_final].inicio = i[inter_atual].pivot + 1;
            i[inter_final].fim = i[inter_atual].fim;
        }
        inter_atual++;
    }
}

int Quick::partition(int inicio, int fim)
{
    int index = inicio;

    while (inicio < fim)
    {
        num_comp++;
        if (list[inicio] < list[fim])
            swap(list[inicio], list[index++]);

        inicio++;
    }
    swap(list[fim], list[index]);
    return index;
}

void Quick::interativo()
{
    interativo(0, lenght);
}
void Quick::interativo(int inicio, int lenght)
{
    int inter_atual = 0;
    int inter_final = 0;

    i[0].inicio = inicio;
    i[0].fim = lenght - 1;

    while (inter_atual <= inter_final)
    {

        if (i[inter_atual].inicio < i[inter_atual].fim)
        {

            i[inter_atual].pivot = partition(i[inter_atual].inicio, i[inter_atual].fim);

            inter_final++;
            i[inter_final].inicio = i[inter_atual].inicio;
            i[inter_final].fim = i[inter_atual].pivot - 1;

            inter_final++;
            i[inter_final].inicio = i[inter_atual].pivot + 1;
            i[inter_final].fim = i[inter_atual].fim;
        }
        inter_atual++;
    }
}

int Quick::partition_impar_par()
{
    int index = 0;
    int inicio = 0;

    while (inicio < lenght)
    {
        num_comp++;
        if (list[inicio] % 2 == 1)
            swap(list[inicio], list[index++]);

        inicio++;
    }
    return index;
}

void Quick::interativo_op2()
{
    int p = partition_impar_par();
    interativo(0, p);
    _interativo(p, lenght);
}

void Quick::recursivo()
{
    recursivo(0, lenght - 1);
}
void Quick::recursivo(int inicio, int fim)
{
    if (inicio >= fim)
        return;

    int p = partition(inicio, fim);
    recursivo(inicio, p - 1);
    recursivo(p + 1, fim);
}
void Quick::_recursivo(int inicio, int fim)
{
    if (inicio >= fim)
        return;
    int p = _partition(inicio, fim);
    _recursivo(inicio, p - 1);
    _recursivo(p + 1, fim);
}

void Quick::recursivo_op2()
{
    int p = partition_impar_par();
    recursivo(0, p - 1);
    _recursivo(p, lenght - 1);
}
int *Quick::ord_inter()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;
    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Quick::ord_inter_op2()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    interativo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Quick::ord_recur()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    recursivo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Quick::ord_recur_op2()
{
    int *aux = list;
    list = alocar(list, lenght);
    clock_t begin = clock();
    recursivo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}

Merge::Merge(int list[], int lenght)
{
    this->list = list;
    this->lenght = lenght - 1;
    num_comp = 0;
}

int Merge::partition_impar_par()
{
    int index = 0;
    int inicio = 0;

    while (inicio < lenght)
    {
        num_comp++;
        if (list[inicio] % 2 == 1)
            swap(list[inicio], list[index++]);

        inicio++;
    }
    return index;
}

void Merge::_merge(int inicio, int meio, int fim)
{
    int *vet_aux = new int[(fim - inicio) + 1];
    int right = inicio;
    int left = meio + 1;
    int k = 0;

    while (right <= meio && left <= fim)
    {
        num_comp++;
        if (list[right] > list[left])
        {
            vet_aux[k++] = list[right++];
        }
        else if (list[right] < list[left])
        {
            num_comp++;
            vet_aux[k++] = list[left++];
        }
        else
        {
            num_comp++;
            vet_aux[k++] = list[right++];
            vet_aux[k++] = list[left++];
        }
    }

    while (right <= meio)
        vet_aux[k++] = list[right++];

    while (left < fim)
        vet_aux[k++] = list[left++];

    for (int i = 0, j = inicio; i < k; i++)
    {
        list[j++] = vet_aux[i];
    }
    delete vet_aux;
}
void Merge::merge(int inicio, int meio, int fim)
{
    int *vet_aux = new int[(fim - inicio) + 1];
    int right = inicio;
    int left = meio + 1;
    int k = 0;

    while (right <= meio && left <= fim)
    {
        num_comp++;
        if (list[right] > list[left])
        {
            vet_aux[k++] = list[left++];
        }
        else if (list[right] < list[left])
        {
            num_comp++;
            vet_aux[k++] = list[right++];
        }
        else
        {
            num_comp++;
            vet_aux[k++] = list[right++];
            vet_aux[k++] = list[left++];
        }
    }

    while (right <= meio)
        vet_aux[k++] = list[right++];

    while (left < fim)
        vet_aux[k++] = list[left++];

    for (int i = 0, j = inicio; i < k; i++)
    {
        list[j++] = vet_aux[i];
    }
    delete vet_aux;
}
void Merge::interativo()
{
    interativo(0, lenght);
}
void Merge::interativo(int start, int lenght)
{
    int inicio;
    int fim;
    int bloco = 1;

    while (bloco <= lenght)
    {
        inicio = start;

        while (inicio + bloco <= lenght)
        {
            fim = inicio + 2 * bloco - 1;
            if (fim > lenght)
                fim = lenght;
            merge(inicio, inicio + bloco - 1, fim);
            inicio = inicio + 2 * bloco;
        }
        bloco = 2 * bloco;
    }
}

void Merge::_interativo(int start, int lenght)
{
    int inicio;
    // cout << "Start: " << inicio << "\n";
    int fim;
    int bloco = 1;

    while (bloco <= lenght)
    {
        inicio = start;

        while (inicio + bloco <= lenght)
        {
            fim = inicio + 2 * bloco - 1;
            if (fim > lenght)
                fim = lenght;
            _merge(inicio, inicio + bloco - 1, fim);
            inicio = inicio + 2 * bloco;
        }
        bloco = 2 * bloco;
    }
}

void Merge::interativo_op2()
{
    int p = partition_impar_par();
    interativo(0, p - 1);
    _interativo(p, lenght);
}

void Merge::recursivo(int inicio, int fim)
{
    if (fim <= inicio)
        return;

    int meio = (inicio + fim) / 2; // Dividir
    // Conquistar
    recursivo(inicio, meio);
    recursivo(meio + 1, fim);
    // Combinar
    merge(inicio, meio, fim);
}
void Merge::recursivo()
{
    recursivo(0, lenght);
}

void Merge::_recursivo(int inicio, int fim)
{
    if (fim <= inicio)
        return;

    int meio = (inicio + fim) / 2; // Dividir
    // Conquistar
    _recursivo(inicio, meio);
    _recursivo(meio + 1, fim);
    // Combinar
    _merge(inicio, meio, fim);
}
void Merge::recursivo_op2()
{
    int p = partition_impar_par();
    recursivo(0, p - 1);
    _recursivo(p, lenght);
}
int *Merge::ord_inter()
{
    int *aux = list;
    list = alocar(list, lenght + 1);
    clock_t begin = clock();
    interativo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;
    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Merge::ord_inter_op2()
{
    int *aux = list;
    list = alocar(list, lenght + 1);
    clock_t begin = clock();
    interativo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Merge::ord_recur()
{
    int *aux = list;
    list = alocar(list, lenght + 1);
    clock_t begin = clock();
    recursivo();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}
int *Merge::ord_recur_op2()
{
    int *aux = list;
    list = alocar(list, lenght + 1);
    clock_t begin = clock();
    recursivo_op2();
    clock_t end = clock();
    exec_temp = double(end - begin) / CLOCKS_PER_SEC;
    comparacoes = num_comp;
    num_comp = 0;

    list = aux;
    lenght = aux_len;
    return list_ord;
}