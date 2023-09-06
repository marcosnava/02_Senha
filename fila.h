//
// Created by nava on 09/03/23.
//

#ifndef INC_02_SENHA_FILA_H
#define INC_02_SENHA_FILA_H

#include "utils.h"

// Constantes

enum{
    FL_TAMANHO = 10,
    FL_INICIO_DO_VETOR = 0
};

// Variáveis
extern int fila[FL_TAMANHO];
extern int fl_inicio;
extern int fl_fim;
extern BOOLEAN fl_vazia;

// Protótipos
BOOLEAN inserir(int valor);
BOOLEAN retirar(int *valor);
BOOLEAN existir(int valor);
BOOLEAN fimDoVetor(int quem);
BOOLEAN filaCheia();
BOOLEAN filaEsvaziou();

#endif //INC_02_SENHA_FILA_H
