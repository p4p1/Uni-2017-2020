/*
** EPITECH PROJECT, 2017
** ex05.hpp
** File description:
** <..>
*/

#ifndef EX05_HPP_
#define EX05_HPP_

template<typename T>
class array {
	public:
		array(unsigned int n)
			: _n(n)
		{
			arr = new T[n];
		}
		array(const array &ar)
		{
			_n = ar.size();
			arr = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				arr[i] = ar[i];
		}
		~array()
		{
			delete[] arr;
		}
		int size() const
		{
			return _n;
		}
		T operator[](int i) const
		{
			return arr[i];
		}
		T & operator[](int i)
		{
			return arr[i];
		}
	private:
		T		*arr;
		unsigned int	_n;
};

#endif
