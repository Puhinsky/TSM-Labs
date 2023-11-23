#pragma once
#include "abstract_sm.h"
#include "lexem.h"
#include <map>

namespace pi = polish_inverse;

namespace polish_inverse
{
	class translator
	{
	private:
		pi::abstract_sm _state_machine;
		std::string _expression_file_path;
		std::string _id;
		std::map<std::string, unsigned int> _id_map;

		unsigned int get_input(char symbol);
		void y1(char symbol);
		void y2();
		void y3(std::vector<lexem>& lexems, char symbol);
		void y4(char symbol);
		void y5(std::vector<lexem>& lexems, char symbol);
		void y6(std::vector<lexem>& lexems, char symbol);
		void y7(std::vector<lexem>& lexems, char symbol);
		void y8(std::vector<lexem>& lexems, char symbol);
		void y9(std::vector<lexem>& lexems, char symbol);
	public:
		translator(pi::abstract_sm state_machine, std::string expression_file_path);
		std::vector<pi::lexem> run();
		std::map<std::string, unsigned int> get_id_map();
	};
}

