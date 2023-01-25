namespace ft
{
	template<T>
		class random_access_iterator
		{
			/*
			 ** @Source : https://en.cppreference.com/w/cpp/iterator/iterator_traits
			 */
			public:
				typedef				T									value_type;
				typedef typename	std::ptrdiff_t						difference_type;
				typedef				T*									pointer;
				typedef				T&									reference;
				typedef				std::random_access_iterator_tag		iterator_category;
			private:
				T														_current;
			public:
				random_access_iterator(void) : _current(NULL) {};
				explicit random_access_iterator(pointer* ptr) : _current(ptr) {};
				random_access_iterator(pointer* ptr) : _current(ptr) {};
				random_access_iterator(const reference ptr)
				{
					*this = x;
				};
				random_access_iterator(const random_access_iterator& ptr) : _current(ptr.base()){};
				~random_access_iterator(){};

				random_access_iterator<T>	&operator=(const random_access_iterator& ptr)
				{
					if (&ptr != this)
						this->_current = ptr._current;
					return (*this);
				};

				random_access_iterator<T>	base(void)const
				{
					return _current;
				};
				random_access_iterator<T> base(void)
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
				random_access_iteratori<T>	&operator-=(difference_type n)
				{
					_current -= n;
					return (*this);
				};
				difference_type			operator-(const random_access_iterator ptr)
				{
					return(random_access_iterator(_current - ptr->base()));
				};
				difference_type			operator+(const random_access_iterator ptr)
				{
					return(random_access_iterator(_current + ptr->base()));
				};

				reference	operator[](difference_type n)
				{
					return *(*this + n);
				};

				operator	random_access_iterator<const T> const
				{
					return (random_access_iterator<const T>(_current);
				}
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
			return !(x == y);
		};
	template <typename T, typename U>
		bool	operator>(const random_access_iterator<T> &x, random_access_iterator<T> &y)
		{
			return (y < x);
		};
	template <typename T, typename U>
		bool	operator<=(const random_access_iterator<T> &x, random_access_iterator<U> &y)
		{
			return !(y < x);
		};
	template <typename T, typename U>
		bool	operator>=(const random_access_iterator<T> &x, const random_access_iterator<U> &y)
		{
			return !(y > x);
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
