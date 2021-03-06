#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
	int random_num = rand() % 3;
	switch (random_num)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base & p)
{
	identify_from_pointer(&p);
}

int main(void)
{
	srand(time(NULL));
	Base *base = generate();
    Base &ref = *base;
    identify_from_pointer(base);
    identify_from_reference(ref);
	delete base;
	return 0;
}
