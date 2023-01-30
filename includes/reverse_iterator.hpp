#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
/*
 ** @Brief : source https://cs.brown.edu/people/jwicks/libstdc++/html_user/stl__iterator_8h-source.html
 */
namespace ft {
	template <class Iterator>
		class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
		typename iterator_traits<Iterator>::reference> {
			protected:
				Iterator														_current;
			public:
				typedef Iterator												iterator_type;
				typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
				typedef typename iterator_traits<Iterator>::difference_type	difference_type;
				typedef typename iterator_traits<Iterator>::reference			reference;
				typedef typename iterator_traits<Iterator>::pointer			pointer;

				/*
				 ** @Brief : constuctors & destructor
				 */
				reverse_iterator(): _current(0){};
				explicit reverse_iterator(Iterator x): _current(x){};
				template <class U>
					reverse_iterator(const reverse_iterator<U>& u):_current(u>base()){};

				//TODO check if destructor really needed
				~reverse_iterator(){};

				Iterator base() const
				{
					return _current;
				};
				// explicit
				reference			operator*() const
				{
					iterator_type	tmp = _current;
					tmp--;
					return *tmp;
				};

				pointer			operator->() const
				{
					return &(operator*());
				};

				reverse_iterator&	operator++()
				{
					--_current;
					return *this;
				};

				reverse_iterator operator++(int)
				{
					reverse_iterator	tmp = *this;
					--_current;
					return tmp;
				};

				reverse_iterator& operator--()
				{
					++_current;
					return *this;
				};

				reverse_iterator operator--(int)
				{
					reverse_iterator	tmp = *this;
					++_current;
					return tmp;
				};

				reverse_iterator operator+ (difference_type n) const
				{
					return reverse_iterator(_current - n);
				};

				reverse_iterator& operator+=(difference_type n)
				{
					_current -= n;
					return *this;
				};

				reverse_iterator operator- (difference_type n) const
				{
					return reverse_iterator(_current + n);
				};

				reverse_iterator& operator-=(difference_type n)
				{
					_current += n;
					return *this;
				};

				reference operator[](difference_type n) const
				{
					return *(*this + n);
				};

				operator			reverse_iterator<const Iterator>() const
				{
					return reverse_iterator<const Iterator>(_current);
				}
		};
	template <class Iterator>
		bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return x.base() == y.base();
		};

	template <class Iterator>
		bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return y.base() < x.base();
		};

	template <class Iterator>
		bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return !(x == y);
		};

	template <class Iterator>
		bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return y < x;
		};

	template <class Iterator>
		bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return !(x < y);
		};

	template <class Iterator>
		bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return !(y < x);
		};

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return y.base() - x.base();
		};
	template <class Iterator>
		reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
		{
			return reverse_iterator<Iterator>(x.base() - n);
		};
}

#endif

