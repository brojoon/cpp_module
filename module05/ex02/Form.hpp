#ifndef Form_hpp
#define Form_hpp

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	std::string target;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
public:
	Form();
	Form(std::string name, std::string target, int gradeToSign, int gradeToExecute);
	virtual ~Form();
	Form(const Form&);

	Form &operator=(const Form&);

	std::string const &getName() const;
	std::string const &getTarget() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat&);
	virtual void execute(Bureaucrat const & executor) const;

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

	class AlreadySignedException : public std::exception
	{
	public:
		 virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		 virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream&, Form&);

#endif