#include "pic_translator.h"

using namespace::polish_inverse;
using namespace::std;

unsigned int polish_inverse::pic_translator::get_input(uint8_t type, char code, std::stack<lexem>& store)
{
	if (type == 0 || type == 1)
		return 0;
	else if (get_rank(code, QUEUE) > get_rank(store.top().get_code(), STORE) && type == 2 && code != ';' && code != ')')
		return 1;
	else if (get_rank(code, QUEUE) <= get_rank(store.top().get_code(), STORE) && type == 2)
		return 2;
	else if (get_rank(code, QUEUE) > get_rank(store.top().get_code(), STORE) && type == 2 && code == ')')
		return 3;
	else if (get_rank(code, QUEUE) > get_rank(store.top().get_code(), STORE) && type == 2 && code == ';')
		return 4;
	else
		return -1;
}

int polish_inverse::pic_translator::get_rank(char symbol, pic_location location)
{
	if (location == QUEUE)
	{
		switch (symbol)
		{
		case '(': return 3;
		case ')': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case ';': return -1;
		default: return 100;
		}
	}
	else
	{
		switch (symbol)
		{
		case '(': return -1;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '@': return -2;
		default: return 100;
		}
	}
}

void polish_inverse::pic_translator::y1(lexem lexem_from_queue, std::vector<lexem>& pic, unsigned int& pointer)
{
	pic.push_back(lexem_from_queue);
	++pointer;
}

void polish_inverse::pic_translator::y2(lexem lexem_from_queue, std::stack<lexem>& store, unsigned int& pointer)
{
	store.push(lexem_from_queue);
	++pointer;
}

void polish_inverse::pic_translator::y3(std::vector<lexem>& pic, std::stack<lexem>& store)
{
	pic.push_back(store.top());
	store.pop();
}

void polish_inverse::pic_translator::y4(std::stack<lexem>& store, unsigned int& pointer)
{
	store.pop();
	++pointer;
}

void polish_inverse::pic_translator::y5(lexem lexem_from_queue, std::vector<lexem>& pic, unsigned int& pointer)
{
	y1(lexem_from_queue, pic, pointer);
}

polish_inverse::pic_translator::pic_translator(abstract_sm state_machine)
{
	_state_machine = state_machine;
}

std::vector<lexem> polish_inverse::pic_translator::run(std::vector<lexem> lexems)
{
	stack<lexem> store;
	vector<lexem> pic_lexems;
	unsigned int pointer = 0;

	store.push(lexem(0, '@'));

	while (pointer < lexems.size())
	{
		auto input = get_input(lexems[pointer].get_type(), lexems[pointer].get_code(), store);

		switch (_state_machine.get_out(input))
		{
			case 1:
				y1(lexems[pointer], pic_lexems, pointer);
				
				break;
			case 2:
				y2(lexems[pointer], store, pointer);

				break;
			case 3:
				y3(pic_lexems, store);

				break;
			case 4:
				y4(store, pointer);

				break;
			case 5:
				y5(lexems[pointer], pic_lexems, pointer);

				break;
		}

		_state_machine.next(input);
	}

	return pic_lexems;
}
