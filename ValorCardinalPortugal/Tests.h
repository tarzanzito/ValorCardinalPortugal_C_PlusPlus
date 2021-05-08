#pragma once

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

using namespace std;

#include <iostream>
#include "ValorCardinalPortugal.h"
#include "UtilFunctions.h"

class Tests
{
private:
	UtilFunctions m_utilFunctions;
	ValorCardinalPortugal m_valorCardinal;

private:
	void test_strcopy();
	void test_substring();
	void test_indexof();
	void test_leftpad();
	void test_strtrim();
	void test_strltrim();
	void test_strrtrim();
	void test_strupper();

	void test_validaValor();
	void test_formataValor();
	void test_valorNegativo();

	void test_adicionaSufixoDeGrupoMil();
	void test_obtemQualificadorParteDecimal();
	void test_obtemQualificadorParteInteira();
	void test_obtemCentenas();
	void test_obtemDezenas();
	void test_obtemUnidades();
	void test_juntaCentenasDezenasUnidades();
	void test_descodificaCardinal();
	void test_removeUltimasVirgulasEmExcesso();
	void test_juntaTodosGruposDeMil();
	void test_divideEmGruposDeMil();
	void test_divideEmPartesInteiraDecimal();
	void test_converte();

public:
	void ExecuteAll();
};
#endif // TESTS_H_INCLUDED

