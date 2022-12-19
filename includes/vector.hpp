#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	template<class T, class Allocator = std::allocator<T>>
		class vector{

			public:
				typedef		T											value_type;
				typedef		Alloc										allocator_type;
				typedef		allocator_type::reference					reference;
				typedef		allocator_type::const_reference				const_reference;
				typedef		allocator_type::pointer						pointer;
				typedef		allocator_type::const_pointer				const_pointer;
				typedef		/*MISSING SOMTEHING*/						iterator;
				typedef		/*MISSING SOMETHING*/						const_iterator;
				typedef		ft::reverse_iterator<iterator>				reverse_iterator;
				typedef		ft::reverse_iterator<const_iterator>		const_reverse_iterator;
				typedef		std::ptrdiff_t								difference_type;
				typedef		allocator_type::size_type					size_type;

			private:
				size_type		_capacity;
				size_type		_size;
				pointer			_data;
				allocator_type	_alloc;


				/*
				** @Brief : Constructs an empty container, with no elements.
				*/
				explicit vector (const allocator_type& alloc = allocator_type()) : _capacity(0), _size(0), _data(NULL), _alloc(alloc){};

				/*
				** @Brief : Constructs a container with n elements. Each element is a copy of val.
				 */
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{
					_data = _alloc.allocate(n);
					_size = n;
					int	i = 0;
					while (i < n)
						_alloc.construct(_data[i++], val);

				};//TODO need assign method to do this constructor;

				/*
				** @Brief : Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
				 */
				template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){}; //TODO need assign method to do this constructor;

				/*
				** @Brief : Constructs a container with a copy of each of the elements in x, in the same order.
				 */
				vector (const vector& x)
				{
					*this = x; //TODO need assign method
				};

				/*
				** @Brief : Copies all the elements from x into the container.
				*/
				vector& operator=(const vector& x); //TODO need assign method to do this constructor;
				/*
				** @Brief : Returns an iterator pointing to the first element in the vector.
				*/
				 iterator begin();

				 /*
				** @Brief : Returns an const iterator pointing to the first element in the vector.
				*/
				 const_iterator begin() const;

				/*
				** @Brief : Returns an iterator pointing to the last element in the vector.
				*/
				 iterator end();

				/*
				** @Brief : Returns an const iterator pointing to the last element in the vector.
				*/
				 const_iterator end() const;
		
				 /*
				** @Brief : rbegin points to the element right before the one that would be pointed to by member end. Returns a reverse random access iterator.
				*/
				 reverse_iterator rbegin();

				/*
				** @Brief : rbegin points to the element right before the one that would be pointed to by member end. Returns a reverse random access iterator.
				*/
				 const_reverse_iterator rbegin() const;

				 /*
				** @Brief : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
				*/
				reverse_iterator rend();

				 /*
				** @Brief : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
				*/
				const_reverse_iterator rend() const;

				const_iterator cbegin() const noexcept;

				const_iterator cend() const noexcept;

				const_reverse_iterator crbegin() const noexcept;

				const_reverse_iterator crend() const noexcept;

				/*
				** @Brief : Returns the number of elements in the vector.
				*/
				size_type size() const
				{
					return (_size);
				};

				/*
				** @Brief : Returns the maximum number of elements that the vector can hold.
				*/
				size_type max_size() const
				{
					return (_alloc.max_size());
				};

				void resize (size_type n, value_type val = value_type());
				size_type capacity() const;

				/*
				** @Brief : Returns whether the vector is empty (i.e. whether its size is 0)
				*/
				bool empty() const
				{
					if (_size == 0)
						return (true);
					return (false);
				};

				void reserve (size_type n);
				void shrink_to_fit();

				/*
				** @Brief : Returns a reference to the element at position n in the vector container.
				*/
				reference operator[] (size_type n)
				{
					return (this->_data[n]);
				};

				/*
				** @Brief : Returns a const reference to the element at position n in the vector container.
				*/
				const_reference operator[] (size_type n) const
				{
					return (this->_data[n]);
				};


				reference at(size_type n);
				const_reference at(size_type n) const;

				/*
				** @Brief : Returns a reference to the first element in the vector.
				*/
				reference front()
				{
					return (*this->_data);
				};

				/*
				** @Brief : Returns a const_reference to the first element in the vector.
				*/
				const_reference front() const
				{
					return (*this->_data);
				};

				/*
				** @Brief : Returns a reference to the last element in the vector.
				*/
				reference back();

				/*
				** @Brief : Returns a const_reference to the last element in the vector.
				*/
				const_reference back() const;

				/*
				** @Brief : 
				*/
				value_type* data() noexcept
				{
					return (this->_data);
				};

				/*
				** @Brief : 
				*/
				const value_type* data() const noexcept
				{
					return (this->_data);
				};

				value_type* data() noexcept;const value_type* data() const noexcept;

				void assign (size_type n, const value_type& val);

				void push_back (const value_type& val);

				void pop_back();

				iterator insert (iterator position, const value_type& val);

				void insert (iterator position, size_type n, const value_type& val);

				template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);

				iterator erase (iterator position);

				iterator erase (iterator first, iterator last);

				void swap (vector& x);

				void clear();

				template <class... Args>iterator emplace (const_iterator position, Args&&... args);

				template <class... Args>  void emplace_back (Args&&... args);

				/*
				** @Brief : Returns a copy of the allocator object associated with the vector.
				*/
				allocator_type get_allocator() const;
				{
					return (_alloc);
				}

		}

	template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


}

#endif
