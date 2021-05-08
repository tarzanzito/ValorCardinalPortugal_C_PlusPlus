
#include "Tests.h"

void Tests::ExecuteAll()
{
    cout << "Tests Begin..." << endl;

    test_strcopy();
    test_substring();
    test_indexof();
    test_leftpad();
    test_strltrim();
    test_strrtrim();
    test_strtrim();
    test_strupper();

    test_validaValor();
    test_formataValor();
    test_valorNegativo();

    test_adicionaSufixoDeGrupoMil();
    test_obtemQualificadorParteDecimal();
    test_obtemQualificadorParteInteira();
    test_obtemCentenas();
    test_obtemDezenas();
    test_obtemUnidades();
    test_juntaCentenasDezenasUnidades();
    test_descodificaCardinal();
    test_removeUltimasVirgulasEmExcesso();
    test_juntaTodosGruposDeMil(); 
    test_divideEmGruposDeMil();
    test_divideEmPartesInteiraDecimal();
    
    test_converte();

    cout << "Tests End..." << endl;
}

void Tests::test_strcopy()
{
    UtilFunctions utils;

    cout << "testing function: strcopy" << endl;
    string input = "AABBCCDDEEFF";
    string result = m_utilFunctions.strcopy(input);
    if (result.compare("AABBCCDDEEFF") != 0)
        cout << "ERROR testing function: strcopy (0)" << endl;
}

void Tests::test_leftpad()
{
    cout << "testing function: leftpad" << endl;
    string input = "123";
    string result = m_utilFunctions.padleft(input, 'A', 10);
    if (result.compare("AAAAAAA123") != 0)
        cout << "ERROR testing function: leftpad (0)" << endl;

    string result1 = m_utilFunctions.padleft(input, 'A', 3);
    if (result1.compare("123") != 0)
        cout << "ERROR testing function: leftpad (1)" << endl;
}

void Tests::test_substring()
{
    cout << "testing function: substring" << endl;
    string input = "123456789";
    string result = m_utilFunctions.substring(input, 5, 7);
    if (result.compare("67") != 0)
        cout << "ERROR testing function: substring" << endl;
}

void Tests::test_indexof()
{
    cout << "testing function: indexof" << endl;
    size_t pos = m_utilFunctions.indexof("alfabetazulu", "beta");
    if (pos != 4)
        cout << "ERROR testing function: indexof" << endl;
}

void Tests::test_strltrim()
{
    cout << "testing function: strltrim" << endl;
    string result = m_utilFunctions.leftTrim("   alfabetazulu");
    if (result.compare("alfabetazulu") != 0)
        cout << "ERROR testing function: strltrim (0)" << endl;

    string result1 = m_utilFunctions.leftTrim("");
    if (result1.compare("") != 0)
        cout << "ERROR testing function: strltrim (1)" << endl;

    string result2 = m_utilFunctions.leftTrim("   ");
    if (result2.compare("") != 0)
        cout << "ERROR testing function: strltrim (2)" << endl;
}

void Tests::test_strrtrim()
{
    cout << "testing function: strrtrim" << endl;
    string result = m_utilFunctions.rightTrim("alfabetazulu   ");
    if (result.compare("alfabetazulu") != 0)
        cout << "ERROR testing function: strrtrim (0)" << endl;

    string result1 = m_utilFunctions.rightTrim("");
    if (result1.compare("") != 0)
        cout << "ERROR testing function: strrtrim (1)" << endl;

    string result2 = m_utilFunctions.rightTrim("   ");
    if (result2.compare("") != 0)
        cout << "ERROR testing function: strrtrim (2)" << endl;
}

void Tests::test_strtrim()
{
    cout << "testing function: strtrim" << endl;
    string result = m_utilFunctions.trimString("   alfabetazulu   ");
    if (result.compare("alfabetazulu") != 0)
        cout << "ERROR testing function: strtrim (0)" << endl;

    string result1 = m_utilFunctions.trimString("");
    if (result1.compare("") != 0)
        cout << "ERROR testing function: strtrim (1)" << endl;

    string result2 = m_utilFunctions.trimString("   ");
    if (result2.compare("") != 0)
        cout << "ERROR testing function: strtrim (2)" << endl;
}

void Tests::test_strupper()
{
    cout << "testing function: strupper" << endl;
    string result = m_utilFunctions.strupper("alfa12345zulu");
    if (result.compare("ALFA12345ZULU") != 0)
        cout << "ERROR testing function: strupper (0)" << endl;
}

///////////

void Tests::test_validaValor()
{
    cout << "testing function: ValidaValor" << endl;

    bool ok = m_valorCardinal.ValidaValor("123456.89");
    if (!ok)
        cout << "ERROR testing function: ValidaValor (0)" << endl;

    ok = m_valorCardinal.ValidaValor("123.456.89");
    if (ok)
        cout << "ERROR testing function: ValidaValor (1)" << endl;
}

void Tests::test_formataValor()
{
    cout << "testing function: FormataValor" << endl;

    string result = m_valorCardinal.FormataValor("123.89");
    if (result.compare("123.89") != 0)
        cout << "ERROR testing function: FormataValor (0)" << endl;

    string result1 = m_valorCardinal.FormataValor("123.8");
    if (result1.compare("123.80") != 0)
        cout << "ERROR testing function: FormataValor (1)" << endl;

    string result2 = m_valorCardinal.FormataValor("123.");
    if (result2.compare("123.00") != 0)
        cout << "ERROR testing function: FormataValor (2)" << endl;

    string result3 = m_valorCardinal.FormataValor(".");
    if (result3.compare("0.00") != 0)
        cout << "ERROR testing function: FormataValor (3)" << endl;

    string result4 = m_valorCardinal.FormataValor("0.");
    if (result4.compare("0.00") != 0)
        cout << "ERROR testing function: FormataValor (4)" << endl;

    string result5 = m_valorCardinal.FormataValor("");
    if (result5.compare("0.00") != 0)
        cout << "ERROR testing function: FormataValor (5)" << endl;

    string result6 = m_valorCardinal.FormataValor("123");
    if (result6.compare("123.00") != 0)
        cout << "ERROR testing function: FormataValor (6)" << endl;
}

void Tests::test_valorNegativo()
{
    cout << "testing function: ValorNegativo" << endl;
    bool negativo = m_valorCardinal.ValorNegativo("-123456.89");
    if (!negativo)
        cout << "ERROR testing function: ValorNegativo (1)" << endl;

    negativo = m_valorCardinal.ValorNegativo("123456.89");
    if (negativo)
        cout << "ERROR testing function: ValorNegativo (3)" << endl;
}

///////

void Tests::test_adicionaSufixoDeGrupoMil()
{
    cout << "testing function: AdicionaSufixoDeGrupoMil" << endl;
    string input = "oito";
    string result = m_valorCardinal.AdicionaSufixoDeGrupoMil(input, 2);
    if (result.compare("oito milhões") != 0)
        cout << "ERROR testing function: AdicionaSufixoDeGrupoMil" << endl;
}

void Tests::test_obtemQualificadorParteDecimal()
{
    cout << "testing function: ObtemQualificadorParteDecimal" << endl;
    string input = "123";
    string result = m_valorCardinal.ObtemQualificadorParteDecimal(input, false);
    if (result.compare("centimos") != 0)
        cout << "ERROR testing function: ObtemQualificadorParteDecimal" << endl;
}

void Tests::test_obtemQualificadorParteInteira()
{
    cout << "testing function: ObtemQualificadorParteInteira" << endl;
    string input = "123";
    string result = m_valorCardinal.ObtemQualificadorParteInteira(input, false);
    if (result.compare("euros") != 0)
        cout << "ERROR testing function: ObtemQualificadorParteInteira" << endl;
}

void Tests::test_obtemCentenas()
{
    cout << "testing function: ObtemCentenas" << endl;
    string result = m_valorCardinal.ObtemCentenas(2, 1, 3);
    if (result.compare("duzentos") != 0)
        cout << "ERROR testing function: ObtemCentenas (1)" << endl;

    result = m_valorCardinal.ObtemCentenas(1, 0, 0);  //new
    if (result.compare("cem") != 0) //new
        cout << "ERROR testing function: ObtemCentenas (2)" << endl; //new
}

void Tests::test_obtemDezenas()
{
    cout << "testing function: ObtemDezenas" << endl;
    string result = m_valorCardinal.ObtemDezenas(1, 2);
    if (result.compare("doze") != 0)
        cout << "ERROR testing function: ObtemDezenas (1)" << endl;

    result = m_valorCardinal.ObtemDezenas(2, 1); //new
    if (result.compare("vinte") != 0) //new
        cout << "ERROR testing function: ObtemDezenas (2)" << endl; //new
}

void Tests::test_obtemUnidades()
{
    cout << "testing function: ObtemUnidades" << endl;
    string result = m_valorCardinal.ObtemUnidades(8, 2);
    if (result.compare("oito") != 0)
        cout << "ERROR testing function: ObtemUnidades (1)" << endl;

   result = m_valorCardinal.ObtemUnidades(8, 1); //new
    if (result.compare("") != 0) //new
        cout << "ERROR testing function: ObtemUnidades (2)" << endl; //new

}

void Tests::test_juntaCentenasDezenasUnidades()
{
    cout << "testing function: JuntaCentenasDezenasUnidades" << endl;
    string result = m_valorCardinal.JuntaCentenasDezenasUnidades("oitocentos", "setenta", "seis");
    if (result.compare("oitocentos e setenta e seis") != 0)
        cout << "ERROR testing function: JuntaCentenasDezenasUnidades" << endl;
}

void Tests::test_descodificaCardinal()
{
    cout << "testing function: DescodificaCardinal" << endl;
    string result = m_valorCardinal.DescodificaCardinal("123", 2);
    if (result.compare("cento e vinte e três milhões") != 0)
        cout << "ERROR testing function: DescodificaCardinal" << endl;
}

void Tests::test_removeUltimasVirgulasEmExcesso()
{
    cout << "testing function: RemoveUltimasVirgulasEmExcesso" << endl;
    string result = m_valorCardinal.RemoveUltimasVirgulasEmExcesso("123456789, , , ");
    if (result.compare("123456789") != 0)
        cout << "ERROR testing function: RemoveUltimasVirgulasEmExcesso" << endl;
}

void Tests::test_juntaTodosGruposDeMil()
{
    cout << "testing function: JuntaTodosGruposDeMil" << endl;

    vector<string> phrases = { "alfa", "beta", "zulu" };
    string result = m_valorCardinal.JuntaTodosGruposDeMil(phrases, false);
    if (result.compare("alfa, beta e zulu") != 0)
        cout << "ERROR testing function: JuntaTodosGruposDeMil (1)" << endl;

    vector<string> phrases2 = { "alfa", "beta", "" };
    string result2 = m_valorCardinal.JuntaTodosGruposDeMil(phrases2, false);
    if (result2.compare("alfa e beta") != 0)
        cout << "ERROR testing function: JuntaTodosGruposDeMil (2)" << endl;

}

void Tests::test_divideEmGruposDeMil()
{
    cout << "testing function: DivideEmGruposDeMil" << endl;

    vector<string> result = m_valorCardinal.DivideEmGruposDeMil("123456789012345");
    int sizegrp = result.size();

    if (sizegrp != 5)
        cout << "ERROR testing function: DivideEmGruposDeMil (n)" << endl;

    string g0 = result[0];
    string g1 = result[1];
    string g2 = result[2];
    string g3 = result[3];
    string g4 = result[4];
    if (g0.compare("123") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (0)" << endl;
    if (g1.compare("456") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (1)" << endl;
    if (g2.compare("789") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (2)" << endl;
    if (g3.compare("012") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (3)" << endl;
    if (g4.compare("345") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (4)" << endl;

    vector<string> result2 = m_valorCardinal.DivideEmGruposDeMil("1234567890123");
    string g4a = result2[0];
    if (g4a.compare("001") != 0)
        cout << "ERROR testing function: DivideEmGruposDeMil (4a)" << endl;
}

void Tests::test_divideEmPartesInteiraDecimal()
{
    cout << "testing function: DivideEmPartesInteiraDecimal" << endl;

    vector<string> result = m_valorCardinal.DivideEmPartesInteiraDecimal("1234567.89");
    string p10 = result[0];
    string p11 = result[1];
    if (p10.compare("1234567") != 0)
        cout << "ERROR testing function: DivideEmPartesInteiraDecimal (0)" << endl;
    if (p11.compare("89") != 0)
        cout << "ERROR testing function: DivideEmPartesInteiraDecimal (1)" << endl;
}

void Tests::test_converte(void)
{
    cout << "testing function: Converte" << endl;
    string input = "123456789.87";
    string result = m_valorCardinal.Converte(input, false, false);
    if (result.compare("cento e vinte e três milhões, quatrocentos e cinquenta e seis mil, setecentos e oitenta e nove euros e oitenta e sete centimos") != 0)
        cout << "ERROR testing function: Converte (0)" << endl;
}
