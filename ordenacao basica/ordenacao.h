
class Sort
{
private:
public:
    int *list_ord;
    int aux_len;
    int comparacoes;
    double exec_temp;
    int *alocar(int *list, int lenght);
    ~Sort();
    virtual int *ord_inter() = 0;
    virtual int *ord_inter_op2() = 0;
    virtual int *ord_recur() = 0;
    virtual int *ord_recur_op2() = 0;
};
class Bubble : public Sort
{

private:
    int *list;
    int lenght;
    int num_comp;

public:
    Bubble(int *list_, int lenght_);
    void interativo();
    void interativo_op2();

    void recursivo();
    void recursivo_op2();
    virtual int *ord_inter();
    virtual int *ord_inter_op2();
    virtual int *ord_recur();
    virtual int *ord_recur_op2();
};

class Insetion : public Sort
{
private:
    int *list;
    int lenght;
    int num_comp;

public:
    Insetion(int *list_, int lenght_);

    void inserir(int inicio);
    void inserir_par(int inicio);

    void interativo();
    void interativo(int inicio);

    void interativo_op2();
    void interativo_op2(int inicio);
    void recursivo();
    void recursivo(int inicio);
    void recursivo_op2();
    void recursivo_op2(int inicio);
    virtual int *ord_inter();
    virtual int *ord_inter_op2();
    virtual int *ord_recur();
    virtual int *ord_recur_op2();
};

class Selection : public Sort
{
private:
    int *list;
    int lenght;
    int inicio = 0;
    int num_comp;

public:
    Selection(int *list_, int lenght_);
    int select(int i);
    void interativo();
    void recursivo();

    void interativo_op2();

    void recursivo_op2();

    virtual int *ord_inter();
    virtual int *ord_inter_op2();
    virtual int *ord_recur();
    virtual int *ord_recur_op2();
};

struct Index
{
    int inicio;
    int fim;
    int pivot;
};

class Quick : public Sort
{
private:
    int *list;
    int lenght;
    Index *i;
    int num_comp;

public:
    Quick(int *list_, int lenght_);
    ~Quick();
    int _partition(int inicio, int fim);
    void _interativo();
    void _interativo(int inicio, int lenght);

    int partition(int inicio, int fim);

    void interativo();
    void interativo(int inicio, int lenght);

    int partition_impar_par();

    void interativo_op2();

    void recursivo();
    void recursivo(int inicio, int fim);
    void _recursivo(int inicio, int fim);

    void recursivo_op2();
    virtual int *ord_inter();
    virtual int *ord_inter_op2();
    virtual int *ord_recur();
    virtual int *ord_recur_op2();
};

class Merge : public Sort
{
private:
    int *list;
    int lenght;
    int num_comp;

public:
    Merge(int list[], int lenght);

    int partition_impar_par();

    void _merge(int inicio, int meio, int fim);
    void merge(int inicio, int meio, int fim);
    void interativo();
    void interativo(int start, int lenght);

    void _interativo(int start, int lenght);

    void interativo_op2();

    void recursivo(int inicio, int fim);
    void recursivo();

    void _recursivo(int inicio, int fim);
    void recursivo_op2();
    virtual int *ord_inter();
    virtual int *ord_inter_op2();
    virtual int *ord_recur();
    virtual int *ord_recur_op2();
};
