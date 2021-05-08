
#include "Main.h"


int main(int argc, char* argv[])
{
	const string VERSION = "1.0.9";

	#ifdef TEST
		Tests tests;
		tests.ExecuteAll();
		return 0;
	#endif

	bool vazioSeZeroParteinteira = false;
	bool vazioSeZeroParteDecimal = false;

	UtilFunctions m_utilFunctions;
	ValorCardinalPortugal m_valorCardinalPortugal;

	if (argc >= 3)
	{
		string temp = m_utilFunctions.strupper(argv[2]);
		vazioSeZeroParteinteira = (temp.compare("TRUE") == 0);
	}

	if (argc >= 4)
	{
		string temp = m_utilFunctions.strupper(argv[3]);
		vazioSeZeroParteDecimal = (temp.compare("TRUE") == 0);
	}

	if (argc >= 2)
	{
		string result = m_valorCardinalPortugal.Converte(argv[1], vazioSeZeroParteinteira, vazioSeZeroParteDecimal);
		cout << "[" + result + "]" << endl;
		return 0;
	}

	cout << endl << "ValorCardinalPortugal (Version: " << VERSION << ")" << endl;
	cout << "======================================" << endl << endl;

	string valor;
	cout << "Introduza valor '#0.00': ";
	cin >> valor; // str; 

	cout << "Processa :[" << valor << "]" << endl;

	string result = m_valorCardinalPortugal.Converte(valor, vazioSeZeroParteinteira, vazioSeZeroParteDecimal);
	cout << endl << "Resultado:[" << result << "]" << endl;

	return 0;
}
