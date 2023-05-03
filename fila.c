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
BOOLEAN inserir(int valor)
{
    if(fl_vazia)
    {
        fila[fl_fim] = valor;
        fl_fim++;
        if(fl_fim == FL_TAMANHO)
        {
            fl_fim = 0;
        }
        fl_vazia = FALSE;
    }
    else
    {
        if(fl_inicio != fl_fim)
        {
            fila[fl_fim] = valor;
            fl_fim++;
            if(fl_fim == FL_TAMANHO)
            {
                fl_fim = 0;
            }
        }
        else
        {
            return FALSE;
        }
    }
    return TRUE;
}

BOOLEAN retirar(int *valor)
{
    if(!fl_vazia)
    {
        *valor = fila[fl_inicio];
        fl_inicio++;
        if(fl_inicio == FL_TAMANHO)
        {
            fl_inicio = 0;
        }
        if(fl_inicio == fl_fim)
        {
            fl_vazia = TRUE;
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
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
            if (i == FL_TAMANHO) {
                i = 0;
            }
        } while (i != fl_fim);
    }
    return FALSE;
}