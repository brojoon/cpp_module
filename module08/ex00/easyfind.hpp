#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &con, int value)
{
	return (std::find(con.begin(), con.end(), value));
}

#endif