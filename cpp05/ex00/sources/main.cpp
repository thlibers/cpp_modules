#include "../includes/Bureaucrat.hpp"

int main(void)
{
	try{
		Bureaucrat Bureaucrat("thlibers", 0);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat Bureaucrat("ytennah", 1);
		std::cout << Bureaucrat << "\n";
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try{
		Bureaucrat Bureaucrat("nclavel", 3);
		std::cout << Bureaucrat << "\n";
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
	
	try{
		Bureaucrat Bureaucrat("nithomas", 10);
		std::cout << Bureaucrat << "\n";
		Bureaucrat.Increment();
		std::cout << Bureaucrat << "\n";
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try{
		Bureaucrat Bureaucrat("hkeromn", 13);
		std::cout << Bureaucrat << "\n";
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try{
		Bureaucrat Bureaucrat("yderridj", 99);
		std::cout << Bureaucrat << "\n";
		Bureaucrat.Decrement();
		std::cout << Bureaucrat << "\n";
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try{
		Bureaucrat Bureaucrat("sbonneau", 150);
		std::cout << Bureaucrat << "\n";
		Bureaucrat.Decrement();
		std::cout << Bureaucrat << "\n";
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try{
		Bureaucrat Bureaucrat("jhauvill", 10000);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	return 0;
}
