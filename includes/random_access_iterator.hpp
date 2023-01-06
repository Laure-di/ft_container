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

				random_access_iterator&	operator=(const random_access_iterator& ptr)
				{
					if (&ptr != this)
						this->_current = ptr._current;
					return (*this);
				};

				random_access_iterator	base(void)const
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
				random_access_iterator&	operator++(void)
				{
					_current++;
					return (*this);
				};
				random_access_iterator	operator++(int)
				{
					random_access_iterator	tmp = *this;
					_current++;
					return (tmp);
				};
				random_access_iterator&	operator--(void)
				{
					_current--;
					return (*this);
				};
				random_access_iterator	operator--(int)
				{
					random_access_iterator	tmp = *this;
					_current--;
					return (tmp);
				};
				random_access_iterator	operator+(difference_type n) const
				{
					return (random_access_iterator(_current + n));
				};
				random_access_iterator&	operator+=(difference_type n)
				{
					_current += n;
					return (*this);
				};
				random_access_iterator	operator-(difference_type n)
				{
					return (random_access_iterator(_current - n));
				};
				random_access_iterator& operator-=(difference_type n)
				{
					_current -= n;
					return (*this);
				};
				difference_type			operator-(const random_access_iterator ptr)
				{
					return(random_access_iterator(ptr->_current - _current));
				};
				difference_type			operator+(const random_access_iterator ptr)
				{
					return(random_access_iterator(ptr->_current + _current));
				};

				reference	operator[](difference_type n)
				{
					return *(*this + n);
				};
		}
}
