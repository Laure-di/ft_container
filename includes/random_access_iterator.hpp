#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"

namespace ft
{
	template<class T>
		class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
		{
			/*
			 ** @Source : https://en.cppreference.com/w/cpp/iterator/iterator_traits
			 */
			private:
				typedef ft::iterator<ft::random_access_iterator_tag, T>		_traits;

			public:
				typedef typename	_traits::value_type					value_type;
				typedef typename	_traits::difference_type			difference_type;
				typedef	typename	_traits::pointer					pointer;
				typedef typename	_traits::reference					reference;
				typedef	typename	_traits::iterator_category			iterator_category;

			private:
				pointer														_current;

			public:
				random_access_iterator(void) : _current(NULL) {};
				random_access_iterator(pointer ptr) : _current(ptr) {};
				random_access_iterator(const random_access_iterator& ptr){
					*this = ptr;
				};
				~random_access_iterator(){};

				random_access_iterator<T>	&operator=(const random_access_iterator& ptr)
				{
					if (&ptr != this)
						this->_current = ptr._current;
					return (*this);
				};

				pointer						base(void)const
				{
					return _current;
				};
				
				reference	operator*(void)const
				{
					return (*_current);
				};
				pointer		operator->(void)const
				{
					return (_current);
				};
				random_access_iterator<T>	&operator++(void)
				{
					_current++;
					return (*this);
				};
				random_access_iterator<T>	operator++(int)
				{
					random_access_iterator	tmp = *this;
					_current++;
					return (tmp);
				};
				random_access_iterator<T>	&operator--(void)
				{
					_current--;
					return (*this);
				};
				random_access_iterator<T>	operator--(int)
				{
					random_access_iterator	tmp = *this;
					_current--;
					return (tmp);
				};
				random_access_iterator<T>	operator+(difference_type n) const
				{
					return (random_access_iterator(_current + n));
				};
				random_access_iterator<T>	&operator+=(difference_type n)
				{
					_current += n;
					return (*this);
				};
				random_access_iterator<T>	operator-(difference_type n)
				{
					return (random_access_iterator(_current - n));
				};
				random_access_iterator<T>	&operator-=(difference_type n)
				{
					_current -= n;
					return (*this);
				};
				difference_type			operator-(const random_access_iterator& ptr) const
				{
					return(_current - ptr.base());
				};
				difference_type			operator+(const random_access_iterator& ptr) const
				{
					return(_current + ptr.base());
				};

				reference	operator[](difference_type n)
				{
					return _current[n];
				};

				operator	random_access_iterator<const T>() const
				{
					return (random_access_iterator<const T>(_current));
				};
		};
	template <typename T, typename U>
		bool	operator==(const random_access_iterator<T> &x, const random_access_iterator<U> &y)
		{
			return (x.base() == y.base());
		};
	template <typename T, typename U>
		bool	operator<(const random_access_iterator<T> &x, const random_access_iterator<U> &y)
		{
			return (x.base() < y.base());
		};
	template <typename T, typename U>
		bool	operator!=(const random_access_iterator<T> &x, random_access_iterator<U> &y)
		{
			return !(x.base() == y.base());
		};
	template <typename T, typename U>
		bool	operator>(const random_access_iterator<T> &x, random_access_iterator<U> &y)
		{
			return (y.base() < x.base());
		};
	template <typename T, typename U>
		bool	operator<=(const random_access_iterator<T> &x, random_access_iterator<U> &y)
		{
			return !(y.base() < x.base());
		};
	template <typename T, typename U>
		bool	operator>=(const random_access_iterator<T> &x, const random_access_iterator<U> &y)
		{
			return !(y.base() > x.base());
		};
	template <typename T>
		typename random_access_iterator<T>::difference_type	operator-(const random_access_iterator<T> &x, random_access_iterator<T> &y)
		{
			return (x.base() - y.base());
		};
	template <typename T>
		random_access_iterator<T>	operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>	&x)
		{
			return (random_access_iterator<T>(x.base() + n));
		};
};
#endif
