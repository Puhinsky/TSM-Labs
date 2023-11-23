#pragma once
#include "abstract_sm.h"
#include "lexem.h"
#include "pic_location.h"
#include <stack>

namespace polish_inverse
{
	class pic_translator
	{
	private:
		abstract_sm _state_machine;

		unsigned int get_input(uint8_t type, char code, std::stack<lexem>& store);
		int get_rank(char symbol, pic_location location);
		void y1(lexem lexem_from_queue, std::vector<lexem>& pic, unsigned int& pointer);
		void y2(lexem lexem_from_queue, std::stack<lexem>& store, unsigned int& pointer);
		void y3(std::vector<lexem>& pic, std::stack<lexem>& store);
		void y4(std::stack<lexem>& store, unsigned int& pointer);
		void y5(lexem lexem_from_queue, std::vector<lexem>& pic, unsigned int& pointer);
	public:
		pic_translator(abstract_sm state_machine);
		std::vector<lexem> run(std::vector<lexem> lexems);
	};
}
