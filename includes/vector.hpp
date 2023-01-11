#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
		class vector{

			public:
				typedef				T												value_type;
				typedef				Allocator										allocator_type;
				typedef	typename	allocator_type::reference						reference;
				typedef	typename	allocator_type::const_reference					const_reference;
				typedef	typename	allocator_type::pointer							pointer;
				typedef	typename	allocator_type::const_pointer					const_pointer;
				typedef				std::random_access_iterator_tag					iterator; //TODO changer std to ft
				typedef				std::random_access_iterator_tag<const>			const_iterator; //TODO changer std to ft
				typedef				std::reverse_iterator<iterator>					reverse_iterator; //TODO changer std to ft
				typedef				std::reverse_iterator<const_iterator>			const_reverse_iterator; //TODO changer std to ft
				typedef				std::ptrdiff_t									difference_type;
				typedef				typename allocator_type::size_type				size_type;

			private:
				size_type		_capacity;
				size_type		_size;
				pointer			_data;
				allocator_type	_alloc;
			public:
				/*
				 ** @Brief : constructor
				 */
				vector():_capacity(0), _size(0), _data(NULL), _alloc(allocator_type()){};

				/*
				 ** @Brief : Constructs an empty container, with no elements.
				 */
				explicit vector (const allocator_type& alloc = allocator_type()) : _capacity(0), _size(0), _data(NULL), _alloc(alloc){};

				/*
				 ** @Brief : Constructs a container with n elements. Each element is a copy of val.
				 */
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{
					_alloc = alloc;
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
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); /*TODO need assign method to do this constructor;*/

				/*
				 ** @Brief : Constructs a container with a copy of each of the elements in x, in the same order.
				 */
				vector(const vector& x)
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
				iterator begin()
				{
					return (iterator(_data));
				};

				/*
				 ** @Brief : Returns an const iterator pointing to the first element in the vector.
				 */
				const_iterator begin() const
				{
					return (const_iterator(_data));
				};

				/*
				 ** @Brief : Returns an iterator pointing to the last element in the vector.
				 */
				iterator end()
				{
					return (iterator(_data + _size));
				};

				/*
				 ** @Brief : Returns an const iterator pointing to the last element in the vector.
				 */
				const_iterator end() const
				{
					return (const_iterator(_data + _size));
				};

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

				const_iterator cbegin() const
				{
					return (const_iterator(_data));
				};

				const_iterator cend() const
				{
					return (const_iterator(_data + _size));
				};

				const_reverse_iterator crbegin() const ;

				const_reverse_iterator crend() const ;

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

				/*
				 ** @Brief : Resizes the container so that it contains n elements.
				 */
				void resize (size_type n, value_type val = value_type())
				{
					if (n < _size)
						//remove & destroy content beyond n
					else if (_size < n && n < _capacity)
						//content is expended
					else if (_capacity < n)
				};

				/*
				 ** @Brief : Returns the size of the storage space currently allocated for the vector, expressed in terms of elements
				 */
				size_type capacity() const
				{
					return (_capacity);
				};

				/*
				 ** @Brief : Returns whether the vector is empty (i.e. whether its size is 0)
				 */
				bool empty() const
				{
					if (_size == 0)
						return (true);
					return (false);
				};

				/*
				 ** @Brief : Requests that the vector capacity be at least enough to contain n elements.
				 */
				void reserve(size_type n)
				{
					size_type	newCapacity = capacity();
					while (n <= newCapacity)
					{
						if (newCapacity == 0)
							newCapacity = 1;
						else
							newCapacity *= 2;
					}
					if (max_size() < newCapacity)
						throw (std::length_error("vector::reserve"));//TODO check erreur message
					if (capacity() < newCapacity)
					{
						pointer		newData = NULL;
						newData = _alloc.allocate(newCapacity);
						if (!empty())
						{
							for (size_type i = 0; i < size(); i++)
								_alloc.construct(&newData[i], _data[i]);
							_alloc.deallocate(_data, capacity());
						}
						_data = newData;
						_capacity = newCapacity;
					}
				};

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

				/*
				** @Brief : Returns a reference to the element at position n in the vector.
				*/
				reference at(size_type n)
				{
					if (_size <= n)
						throw std::out_of_range("vector::out_of_range");
					_data[n];
				};

				/*
				** @Brief : Returns a const reference to the element at position n in the vector.
				*/
				const_reference at(size_type n) const
				{
					if (_size <= n)
						throw std::out_of_range("vector::out_of_range");
					_data[n];
				};

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
				reference back()
				{
					return (*this->_data[_size - 1]);
				};

				/*
				 ** @Brief : Returns a const_reference to the last element in the vector.
				 */
				const_reference back() const
				{
					return (*this->_data[_size - 1]);
				};

				/*
				 ** @Brief : 
				 */
				value_type* data() 
				{
					return (this->_data);
				};

				/*
				 ** @Brief : 
				 */
				const value_type* data() const 
				{
					return (this->_data);
				};

				void assign (size_type n, const value_type& val)
				{
					if (capacity() < n)
						reserve(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_data[i], val);
					_size = n;
				}

				void push_back (const value_type& val);

				/*
				** @Brief : Removes the last element in the vector, effectively reducing the container size by one
				*/
				void pop_back()
				{
					if (_size != 0)
					{
						_alloc.destroy(_data + _size);
						_size--;
					}
				};

				iterator insert(iterator position, const value_type& val);

				void insert (iterator position, size_type n, const value_type& val);

				template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);

				/*
				** @Brief : Removes the element at pos
				*/
				iterator erase (iterator position)
				{
					return (erase(position, position + 1));
				};

				/*
				** @Brief : Removes the elements in the range [first, last)
				*/
				iterator erase (iterator first, iterator last)
				{
					iterator	it = first;
					int			length_to_delete = std::distance(first, last);
					//equivalent to copy TODO checker si utilisation de copy n'est pas mieux
					for (; last != end(); ++last; ++first)
						*first = *last;
					while (length_to_delete)
					{
						_alloc.destroy(_data + _size);
						length_to_delete--;
						_size--;
					}
					return (it);
				};

				void swap (vector& x);

				/*
				** @Brief: Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
				*/
				void clear()
				{
					while (_size)
					{
						_alloc.destroy(_data + _size);
						_size--;
					}
				};

				/*
				 ** @Brief : Returns a copy of the allocator object associated with the vector.
				 */
				allocator_type get_allocator() const
				{
					return (_alloc);
				};

		};

	template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


};

#endif
