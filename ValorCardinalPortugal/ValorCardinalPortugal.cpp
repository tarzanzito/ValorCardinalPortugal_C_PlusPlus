
#include "ValorCardinalPortugal.h"

/* ********* */
/* constants */
/* ********* */

const string CARDINAL_UNIDADES[CARDINAL_MAX] = { "", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove" };
const string CARDINAL_DEZENAS[CARDINAL_MAX] = { "", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa" };
const string CARDINAL_DEZENAS_DEZ[CARDINAL_MAX] = { "dez", "onze", "doze", "treze", "catorze", "quinze", "desasseis", "desassete", "dezoito", "dezanove" };
const string CARDINAL_CENTENAS[CARDINAL_MAX] = { "", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos" };
const string CARDINAL_ZERO = "zero";
const string CARDINAL_UM = "um";
const string CARDINAL_UMA = "uma";
const string CARDINAL_DOIS = "dois";
const string CARDINAL_DUAS = "duas";
const string CARDINAL_CEM = "cem";

const string CARDINAL_GRUPOS_PLURAL[CARDINAL_GRUPOS_MAX] = { "", "mil", "milhões", "milhares de milhão", "biliões",
                                                               "dezenas de bilião", "centenas de bilião", "milhares de bilião", "dezenas de milhar de bilião",
                                                               "centenas de milhar de bilião", "triliões", "undifined"
};
const string CARDINAL_GRUPOS_SINGULAR[CARDINAL_GRUPOS_MAX] = { "", "mil", "milhão", "milhar de milhão", "bilião",
                                                                 "dezena de bilião", "centena de bilião", "milhar de bilião", "dezena de milhar de bilião",
                                                                 "centena de milhar de bilião", "trilião", "undified"
};
const bool CARDINAL_GRUPOS_MASCULINO[CARDINAL_GRUPOS_MAX] = { true, true, true, true, true, false, false, true, false, false, true, true };

const string FRASE_SUFIXO_AO = "ão";
const string FRASE_SUFIXO_OES = "ões";
const string FRASE_E = " e ";
const string FRASE_VIRGULA = ", ";
const string FRASE_DE = " de";
const string FRASE_NOME_INTEIROS_PLURAL = "euros";
const string FRASE_NOME_INTEIROS_SINGULAR = "euro";
const string FRASE_NOME_DECIMAIS_PLURAL = "centimos";
const string FRASE_NOME_DECIMAIS_SINGULAR = "centimo";
const string FRASE_MENOS = "menos ";
const string FRASE_TRUE = "T";
const string FRASE_ESPACO = " ";

/* ************** */
/* Implementation */
/* ************** */

string ValorCardinalPortugal::Converte(const string &valor, bool vazioSeZeroParteinteira, bool vazioSeZeroParteDecimail)
{
    string valorTrim = m_utilFunctions.trimString(valor);

    // validatição e formatação do impute
    if (!ValidaValor(valorTrim))
        return "ERRO: não é um valor valido: " + valor;

    string valorForm = FormataValor(valorTrim);

    // inicio
    bool negativo = ValorNegativo(valorForm);

    string valorInicial;
    if (negativo)
        valorInicial = valorForm.substr(1);
    else
        valorInicial = valorForm;

    //processa

    // separa parte inteira pare decimal
    vector<string> partes = DivideEmPartesInteiraDecimal(valorInicial);

    //separa por grupos de mil "???"
    vector<string> gruposInteiros = DivideEmGruposDeMil(partes[0]);
    vector<string> gruposDecimais = DivideEmGruposDeMil(partes[1]);

    //descodifica os grupos inteiros
    vector<string> gruposCardinaisInteiros;
    for (int x = 0; x < gruposInteiros.size(); x++)
        gruposCardinaisInteiros.push_back(DescodificaCardinal(gruposInteiros[x], (gruposInteiros.size() - x - 1)));

    //descodifica os groupos decimais
    vector<string> gruposCardinaisDecimais;
    for (int x = 0; x < gruposDecimais.size(); x++)
        gruposCardinaisDecimais.push_back( DescodificaCardinal(gruposDecimais[x], (gruposDecimais.size() - x - 1)));

    //junta todos os grupos
   // vector<string> grouposEmCardinal;
    string finalInteiros = JuntaTodosGruposDeMil(gruposCardinaisInteiros, vazioSeZeroParteinteira);
    string finalDecimais = JuntaTodosGruposDeMil(gruposCardinaisDecimais, vazioSeZeroParteDecimail);

    //caso: se valor = 0.0 mostra sempre "zero"
    if ((finalInteiros.length() == 0) && (finalDecimais.length() == 0))
        finalInteiros = CARDINAL_ZERO + " " + FRASE_NOME_INTEIROS_PLURAL;

    //caso: analiza se coloca "de" antes do qualificador
    if (finalInteiros.length() > 2)
    {
        string temp = finalInteiros.substr((finalInteiros.length() - 3), 3);
        if (temp == FRASE_SUFIXO_OES)
            finalInteiros += FRASE_DE;
        else
        {
            temp = finalInteiros.substr((finalInteiros.length() - 2), 2);
            if (temp == FRASE_SUFIXO_AO)
                finalInteiros += FRASE_DE;
        }
    }

    //obtem qualificadores
    string qualificadorInteiros = ObtemQualificadorParteInteira(partes[0], vazioSeZeroParteinteira);
    string qualificadoreDecimais = ObtemQualificadorParteDecimal(partes[1], vazioSeZeroParteDecimail);

    //caso: adiciona qualificador inteiros
    if (finalInteiros.length() > 0)
        finalInteiros += " " + qualificadorInteiros;

    //caso: adiciona qualificador decimais
    if (finalDecimais.length() > 0)
        finalDecimais += " " + qualificadoreDecimais;

    //case: adiciona " e " entre a frase inteiros & frase decimais
    string dual = "";
    if ((finalInteiros.length() > 0) && (finalDecimais.length() > 0))
        dual = FRASE_E;

    string resultdofinal = finalInteiros + dual + finalDecimais;
    if (negativo)
        resultdofinal = FRASE_MENOS + resultdofinal;

    return resultdofinal;
}

vector<string> ValorCardinalPortugal::DivideEmPartesInteiraDecimal(const string &valor)
{
    size_t pos = valor.find('.');
    size_t len = valor.length();

    vector<string> partes;
    partes.push_back(valor.substr(0, pos));
    partes.push_back(valor.substr(pos + 1, len - pos));

    return partes;
}

vector<string> ValorCardinalPortugal::DivideEmGruposDeMil(const string &valor)
{
    string temp = valor;
    vector<string> list;

    //extrai
    while (temp.length() > 3)
    {
        string str3 = temp.substr(temp.length() - 3); //3 ultimos
        list.push_back(str3);
        temp = temp.substr(0, temp.length() - 3);
    }

    list.push_back(m_utilFunctions.padleft(temp, '0', 3)); //garante comprimento = 3

    // reverte array
    size_t  grp = list.size();
    vector<string> grupos;
    for (size_t x = 0; x < grp; x++)
        grupos.push_back(list[grp - 1 - x]);

    return grupos;
}

string ValorCardinalPortugal::JuntaTodosGruposDeMil(const vector<string> &grouposEmCardinal, bool vazioSeZero)
{
    string resultado = "";
    int length = grouposEmCardinal.size();
    size_t pos;

    for (int x = 0; x < length; x++)
    {
        if (grouposEmCardinal[x].length() == 0)
            continue;

        // no ultimo elemento analisa se coloca  " e " no fim
        if ((x == (length - 1)) && (resultado.length() > 1))
        {
            pos = grouposEmCardinal[x].find(FRASE_E);
            if (pos == -1)
            {
                resultado = RemoveUltimasVirgulasEmExcesso(resultado);
                resultado += FRASE_E;
            }
        }

        resultado += grouposEmCardinal[x];
        resultado += FRASE_VIRGULA;
    }

    if ((resultado.length() == 0) && (!vazioSeZero))
        resultado = CARDINAL_ZERO;

    resultado = RemoveUltimasVirgulasEmExcesso(resultado);

    //caso: quantos " e " existem depois da ultima virgula? se zero substitui ultima ", " por " e " 
    pos = resultado.rfind(FRASE_VIRGULA);
    if (pos != string::npos)
    {
        string temp1 = resultado.substr(0, pos);
        string temp2 = resultado.substr(pos + FRASE_VIRGULA.length());
        pos = temp2.find(FRASE_E);
        if (pos == string::npos)
            resultado = temp1 + FRASE_E + temp2;
    }

    return resultado;
}

string ValorCardinalPortugal::RemoveUltimasVirgulasEmExcesso(const string &valor)
{
    if (valor.length() < 2)
        return valor;

    string resultado = valor;

    while (resultado.substr(resultado.length() - 2, 2).compare(FRASE_VIRGULA) == 0)
        resultado = resultado.substr(0, resultado.length() - 2);

    return resultado;
}

string ValorCardinalPortugal::DescodificaCardinal(const string &valor, int nivel)
{
    if (valor.compare("000") == 0)
        return "";

    string cardinalArray[3];
    short digitArray[3];

    for (int x = 0; x < 3; x++)
        digitArray[x] = atoi(valor.substr(x, 1).c_str());
    
    cardinalArray[0] = ObtemCentenas(digitArray[0], digitArray[1], digitArray[2]);
    cardinalArray[1] = ObtemDezenas(digitArray[1], digitArray[2]);
    cardinalArray[2] = ObtemUnidades(digitArray[2], digitArray[1]);

    string resultado = JuntaCentenasDezenasUnidades(cardinalArray[0], cardinalArray[1], cardinalArray[2]);

    resultado = AdicionaSufixoDeGrupoMil(resultado, nivel);

    return resultado;
}

string ValorCardinalPortugal::JuntaCentenasDezenasUnidades(const string &centena, const string &dezena, const string &unidade)
{
    string resultado = centena;

    if ((centena.length() > 0) && ((dezena.length() > 0) || (unidade.length() > 0)))
        resultado += FRASE_E;

    resultado += dezena;
    if ((dezena.length() > 0) && (unidade.length() > 0))
        resultado += FRASE_E;

    resultado += unidade;

    return resultado;
}

string ValorCardinalPortugal::ObtemUnidades(const short digito, const short dezena)
{
    if (dezena == 1)
        return "";

    return CARDINAL_UNIDADES[digito];
}

string ValorCardinalPortugal::ObtemDezenas(const short digito, const short unidade)
{
    if (digito == 1)
        return CARDINAL_DEZENAS_DEZ[unidade];

    return CARDINAL_DEZENAS[digito];
}

string ValorCardinalPortugal::ObtemCentenas(const short digito, const short dezena, const short unidade)
{
    if ((digito == 1) && (dezena == 0) && (unidade == 0))
        return CARDINAL_CEM; //Caso : Cem

    return CARDINAL_CENTENAS[digito];
}

string ValorCardinalPortugal::ObtemQualificadorParteDecimal(const string &valor, bool vazioSeZero)
{
    double valTemp = atof(valor.c_str());

    if (valTemp > 1)
        return FRASE_NOME_DECIMAIS_PLURAL;

    if (valTemp == 1)
        return FRASE_NOME_DECIMAIS_SINGULAR;

    if ((valTemp == 0) && (!vazioSeZero))
        return FRASE_NOME_DECIMAIS_PLURAL;

    return "";
}

string ValorCardinalPortugal::ObtemQualificadorParteInteira(const string &valor, bool vazioSeZero)
{
    double valTemp = atof(valor.c_str());

    if (valTemp > 1)
        return FRASE_NOME_INTEIROS_PLURAL;

    if (valTemp == 1)
        return FRASE_NOME_INTEIROS_SINGULAR;

    if ((valTemp == 0) && (!vazioSeZero))
        return FRASE_NOME_INTEIROS_PLURAL;

    return "";
}

string ValorCardinalPortugal::AdicionaSufixoDeGrupoMil(const string &valor, int nivel)
{
    string resultado = "";

    switch (nivel)
    {
    case 0: // xxx -unidades, dezenas, centenas
        resultado = valor;
        break;

    case 1: //xxx.000 - milhares
        if (valor.compare(CARDINAL_UM) == 0)
            resultado = CARDINAL_GRUPOS_SINGULAR[nivel]; //special : remove palavra "um" (um mil)
        else
            resultado = valor + " " + CARDINAL_GRUPOS_PLURAL[nivel];
        break;

    default:
        if (valor == CARDINAL_UM)
        {
            if (CARDINAL_GRUPOS_MASCULINO[nivel])
                resultado = CARDINAL_UM;
            else
                resultado = CARDINAL_UMA;

            resultado += " " + CARDINAL_GRUPOS_SINGULAR[nivel];
        }
        else
            if (valor == CARDINAL_DOIS)
            {
                if (CARDINAL_GRUPOS_MASCULINO[nivel])
                    resultado = CARDINAL_DOIS;
                else
                    resultado = CARDINAL_DUAS;

                resultado += " " + CARDINAL_GRUPOS_PLURAL[nivel];
            }
            else
                resultado = valor + " " + CARDINAL_GRUPOS_PLURAL[nivel];

        break;
    }

    return resultado;
}

bool ValorCardinalPortugal::ValidaValor(const string &valor)
{
    if (valor.length() == 0)
        return true;

    int pontos = 0;
    const char *array = valor.c_str();

    for (int x = 0; x < strlen(array); x++)
    {
        char chr = array[x];

        if (chr == '-')
        {
            if (x > 0)
                return false;
            else
                continue;
        }

        if (chr == '.')
        {
            pontos++;
            continue;
        }

        if (chr < 48 || chr > 57)
            return false;

    }
    if (pontos > 1)
        return false;

    return true;
}

string ValorCardinalPortugal::FormataValor(const string &valor)
{
    if (valor.length() == 0)
        return "0.00";

    string result = valor;

    size_t pos = valor.find('.');
    if (pos == string::npos)
        result += ".00";
    else
        if (pos == 0)
            result = "0" + result;

    pos = result.find('.');
    size_t rlen = result.length() - pos;
    if (rlen == 1)
        result += "00";
    else
        if (rlen == 2)
            result += "0";
        else
            result = result.substr(0, pos + 3);

    return m_utilFunctions.trimString(result);
}

bool ValorCardinalPortugal::ValorNegativo(const string &valor)
{
    return (valor.substr(0, 1).compare("-") == 0);
}

