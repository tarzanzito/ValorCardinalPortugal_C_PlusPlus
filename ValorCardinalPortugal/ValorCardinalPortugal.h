#pragma once

#ifndef VALORCARDINALPORTUGALCALL_H_INCLUDED
#define VALORCARDINALPORTUGALCALL_H_INCLUDED

using namespace std;

#include <string>
#include <vector> 
#include "UtilFunctions.h"

/* macros */

#define GRUPO_CDU_ARRAY_MAX 32
#define CARDINAL_MAX 10
#define CARDINAL_GRUPOS_MAX 12
#define RESULTADO_FINAL_SIZE 8192
#define VALOR_SIZE_MAX 96
#define RESULTADO_GRUPO_SIZE 4096
#define CDU_SIZE_MAX 32
#define PALAVRA_UNIDADES_MAX 12
#define PALAVRA_DEZENAS_MAX 12
#define PALAVRA_CENTENAS_MAX 12
#define QUALIFICADOR_INTEIRO_MAX 6
#define QUALIFICADOR_DECIMAL_MAX 10
#define CARDINAL_GRUPOS_PRASE_MAX 128


class ValorCardinalPortugal
{
	friend class Tests;

public:
	UtilFunctions m_utilFunctions;

public:
	string Converte(const string& valor, bool vazioSeZeroParteinteira = false, bool vazioSeZeroParteDecimail = false);

private:
	vector<string> DivideEmPartesInteiraDecimal(const string& valor);
	vector<string> DivideEmGruposDeMil(const string& valor);
	string JuntaTodosGruposDeMil(const vector<string>& grouposEmCardinal, bool vazioSeZero);
	string RemoveUltimasVirgulasEmExcesso(const string& valor);
	string DescodificaCardinal(const string& valor, int nivel);
	string JuntaCentenasDezenasUnidades(const string& centena, const string& dezena, const string& unidade);
	string ObtemUnidades(const short digito, const short dezena);
	string ObtemDezenas(const short digito, const short unidade);
	string ObtemCentenas(const short digito, const short dezena, const short unidade);
	string ObtemQualificadorParteDecimal(const string& valor, bool vazioSeZero);
	string ObtemQualificadorParteInteira(const string& valor, bool vazioSeZero);
	string AdicionaSufixoDeGrupoMil(const string& valor, int nivel);
	bool ValidaValor(const string& valor);
	string FormataValor(const string& valor);
	bool ValorNegativo(const string& valor);
};

#endif // VALORCARDINALPORTUGALCALL_H_INCLUDED

