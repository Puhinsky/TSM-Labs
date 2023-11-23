#include "translator.h"

using namespace::polish_inverse;
using namespace::std;

unsigned int translator::get_input(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z')
		return 0;
	else if (symbol >= '0' && symbol <= '9')
		return 1;
	else if (symbol == '=')
		return 2;
	else if (symbol == '(')
		return 3;
	else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 4;
	else if (symbol == ')')
		return 5;
	else if (symbol == ';')
		return 6;
	else
		return -1;
}

void polish_inverse::translator::y1(char symbol)
{
	_id += symbol;
}

void polish_inverse::translator::y2()
{
	_id_map.insert({ _id, (unsigned int)_id_map.size() });
	_id = "";
}

void polish_inverse::translator::y3(vector<lexem>& lexems, char symbol)
{
	lexems.push_back(lexem(2, int(symbol)));
}

void polish_inverse::translator::y4(char symbol)
{
	y1(symbol);
}

void polish_inverse::translator::y5(vector<lexem>& lexems, char symbol)
{
	lexems.push_back(lexem(1, _id_map.find(_id)->second));
	lexems.push_back(lexem(2, int(symbol)));
	_id = "";
}

void polish_inverse::translator::y6(vector<lexem>& lexems, char symbol)
{
	y5(lexems, symbol);
}

void polish_inverse::translator::y7(vector<lexem>& lexems, char symbol)
{
	lexems.push_back(lexem(0, atoi(_id.c_str())));
	lexems.push_back(lexem(2, int(symbol)));
	_id = "";
}

void polish_inverse::translator::y8(vector<lexem>& lexems, char symbol)
{
	y7(lexems, symbol);
}

void polish_inverse::translator::y9(vector<lexem>& lexems, char symbol)
{
	y3(lexems, symbol);
}

translator::translator(pi::abstract_sm state_machine, std::string expression_file_path)
{
	_state_machine = state_machine;
	_expression_file_path = expression_file_path;
}

std::vector<pi::lexem> polish_inverse::translator::run()
{
	ifstream is(_expression_file_path);
	string line;
	vector<lexem> lexems;

	while (getline(is, line))
	{
		for (auto symbol : line)
		{
			auto input = get_input(symbol);

			switch (_state_machine.get_out(input))
			{
				case 1:
					y1(symbol);

					break;
				case 2:
					y2();

					break;
				case 3:
					y3(lexems, symbol);

					break;
				case 4:
					y4(symbol);

					break;
				case 5:
					y5(lexems, symbol);

					break;
				case 6:
					y6(lexems, symbol);

					break;
				case 7:
					y7(lexems, symbol);

					break;
				case 8:
					y8(lexems, symbol);

					break;
				case 9:
					y9(lexems, symbol);

					break;
			}

			_state_machine.next(input);
		}
	}

	is.close();

	return lexems;
}

std::map<std::string, unsigned int> polish_inverse::translator::get_id_map()
{
	return _id_map;
}
