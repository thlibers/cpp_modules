#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	// try{
	// 	Bureaucrat Bureaucrat("thlibers", 0);
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	Bureaucrat Bureaucrat("ytennah", 1);
	// 	std::cout << Bureaucrat << "\n";
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// try{
	// 	Bureaucrat Bureaucrat("nclavel", 3);
	// 	std::cout << Bureaucrat << "\n";
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << '\n';
	// }
	
	// try{
	// 	Bureaucrat Bureaucrat("nithomas", 10);
	// 	std::cout << Bureaucrat << "\n";
	// 	Bureaucrat.Increment();
	// 	std::cout << Bureaucrat << "\n";
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }

	// try{
	// 	Bureaucrat Bureaucrat("hkeromn", 13);
	// 	std::cout << Bureaucrat << "\n";
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }

	// try{
	// 	Bureaucrat Bureaucrat("yderridj", 99);
	// 	std::cout << Bureaucrat << "\n";
	// 	Bureaucrat.Decrement();
	// 	std::cout << Bureaucrat << "\n";
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }

	// try{
	// 	Bureaucrat Bureaucrat("sbonneau", 150);
	// 	std::cout << Bureaucrat << "\n";
	// 	Bureaucrat.Decrement();
	// 	std::cout << Bureaucrat << "\n";
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }

	// try{
	// 	Bureaucrat Bureaucrat("jhauvill", 10000);
	// }
	// catch(const std::exception &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }

	try{
		Form form1("Contract 1", 42, 24);
		Form form2("Contract 2", 5, 1);
		Bureaucrat Bureaucrat1("jhauvill", 100);
		Bureaucrat Bureaucrat2("thlibers", 1);
		std::cout << form1 << '\n';
		Bureaucrat1.signForm(form1);
		Bureaucrat2.signForm(form1);
		std::cout << form1 << '\n';
		std::cout << form2 << '\n';
		Bureaucrat1.signForm(form2);
		Bureaucrat2.signForm(form2);
		std::cout << form2 << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}
