namespace ft
{
	template<T>
		class random_access_iterator
		{
			/*
			 ** @Source : https://en.cppreference.com/w/cpp/iterator/iterator_traits
			 */
			public:
				typedef				T							value_type;
				typedef typename	std::ptrdiff_t						difference_type;
				typedef				T*							pointer;
				typedef				T&							reference;
				typedef				std::random_access_iterator_tag		iterator_category;
			private:
				T												_current;
			public:
				random_access_iterator(void) : _current(NULL) {};
				explicit random_access_iterator(pointer* ptr) : _current(ptr) {};
				random_access_iterator(pointer* ptr) : _current(ptr) {};
				random_access_iterator(const reference ptr)
				{
					*this = x;
				};
				random_access_iterator(const random_access_iterator<T>& ptr) : _current(ptr.base()){};
				~random_access_iterator(){};
				random_access_iterator	base()const
				{
					return _current;
				};
				random_access_iterator<T>&	operator=()

		}
}
