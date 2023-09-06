//
// Created by nava on 09/03/23.
//

#include "fila.h"

// Variáveis
int fila[FL_TAMANHO];
int fl_inicio = 0;
int fl_fim = 0;
BOOLEAN fl_vazia = TRUE;

// Funções
BOOLEAN fimDoVetor(int quem)
{
    return quem == FL_TAMANHO;
}

BOOLEAN filaCheia()
{
    return fl_inicio == fl_fim;
}

BOOLEAN filaEsvaziou()
{
    return fl_inicio == fl_fim;
}

BOOLEAN inserir(int valor)
{
    if(fl_vazia)
    {
        fila[fl_fim] = valor;
        fl_fim++;
        if(fimDoVetor(fl_fim))
        {
            fl_fim = FL_INICIO_DO_VETOR;
        }
        fl_vazia = FALSE;
    }
    else
    {
        if(filaCheia())
        {
            return FALSE;
        }
        fila[fl_fim] = valor;
        fl_fim++;
        if(fimDoVetor(fl_fim))
        {
            fl_fim = FL_INICIO_DO_VETOR;
        }
    }
    return TRUE;
}

BOOLEAN retirar(int *valor)
{
    if(fl_vazia)
    {
        return FALSE;
    }
    *valor = fila[fl_inicio];
    fl_inicio++;
    if(fimDoVetor(fl_inicio))
    {
        fl_inicio = FL_INICIO_DO_VETOR;
    }
    if(filaEsvaziou())
    {
        fl_vazia = TRUE;
    }

    return TRUE;
}

BOOLEAN existir(int valor)
{
    if(!fl_vazia) {
        int i = fl_inicio;
        do {
            if(fila[i] == valor)
            {
                return TRUE;
            }
            i++;
            if (fimDoVetor(i)) {
                i = FL_INICIO_DO_VETOR;
            }
        } while (i != fl_fim);
    }
    return FALSE;
}