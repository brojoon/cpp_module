#ifndef Bureaucrat_hpp
#define Bureaucrat_hpp

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	virtual ~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &other);

	std::string const &getName() const;
	int getGrade() const;

	void increment();
	void decrement();

	class GradeTooHighException : public std::exception
	{
	public:
		 virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		 virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &bureaucrat);

#endif