#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int checkBureaucratGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return grade;
}

Bureaucrat::Bureaucrat() : name(""), grade(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(checkBureaucratGrade(grade))
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(checkBureaucratGrade(other.grade))
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	checkBureaucratGrade(other.grade);
	grade = other.grade;
	return *this;
}

std::string const &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::increment()
{
	checkBureaucratGrade(grade - 1);
	grade--;
}

void Bureaucrat::decrement()
{
	checkBureaucratGrade(grade + 1);
	grade++;
}

void Bureaucrat::signForm(Form& form)
{
	bool flag = true;
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << "<" << name << "> cannot sign <" << form.getName() 
			<< "> because " << e.what() << std::endl;
		flag = false;
	}
	if (flag)
		std::cout << "<" << name << "> signs <" << form.getName() << ">" << std::endl;
}

void Bureaucrat::executeForm(Form const &form)
{
	try{
		form.execute(*this);
		std::cout << "<" << name << "> executes <" << form.getName() << ">" << std::endl;
	}catch (std::exception &e) {
		std::cout << "<" << name << "> cannot execute <" << form.getName() 
			<< "> because " << e.what() << std::endl;
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Bureaucrat: Grade Too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Bureaucrat: Grade Too Low!";
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &bureaucrat)
{
	return (stream << "<" << bureaucrat.getName() << ">, bureaucrat grade <" << bureaucrat.getGrade() << ">" << std::endl);
}