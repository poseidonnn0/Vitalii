#include <iostream>
#include <CodeGenerator.hpp>



int main()
{
	setlocale(LC_ALL, "Rus");

	std::shared_ptr<programmLanguage::CodeGenerator> programmCode = programmLanguage::codeProgramm(programmLanguage::PHP);

	std::cout << "\n====================\nPHP\n====================\n";
	std::cout << programmCode->CG() << std::endl;
	//
	programmCode = programmLanguage::codeProgramm(programmLanguage::JAVA);

	std::cout << "\n====================\nJAVA\n====================\n";
	std::cout << programmCode->CG() << std::endl;
	//
	programmCode = programmLanguage::codeProgramm(programmLanguage::C_PLUS_PLUS);

	std::cout << "\n====================\nC_PLUS_PLUS\n====================\n";
	std::cout << programmCode->CG() << std::endl;
	//
	programmCode = programmLanguage::codeProgramm(programmLanguage::C_SHARP);

	std::cout << "\n====================\nC_SHARP\n====================\n";
	std::cout << programmCode->CG() << std::endl;

	/*programmCode = programmLanguage::codeProgramm(programmLanguage::JS); // Проверка на работоспособность исключения
	std::cout << "\n====================\nJS\n====================\n";
	std::cout << programmCode->CG() << std::endl;*/

	return 0;
}
