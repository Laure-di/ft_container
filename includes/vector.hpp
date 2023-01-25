#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>

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
				typedef				ft::random_access_iterator						iterator; //TODO changer std to ft
				typedef				ft::random_access_iterator<const>				const_iterator; //TODO changer std to ft
				typedef				ft::reverse_iterator<iterator>					reverse_iterator; //TODO changer std to ft
				typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator; //TODO changer std to ft
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
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
				/*
				 ** @Brief : Constructs a container with a copy of each of the elements in x, in the same order.
				 */
				vector(const vector& x): _capacity(x.capacity())
				{
				};

				~vector()
				{
					for (size_t i = 0;i < _size; i++)
						_alloc.destroy(_data + i);
					_size = 0;
					_alloc.deallocate(_data, _capacity);
				}

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
				reverse_iterator rbegin()
				{
					return reverse_iterator(&_data[size]);
				};

				/*
				 ** @Brief : rbegin points to the element right before the one that would be pointed to by member end. Returns a reverse random access iterator.
				 */
				const_reverse_iterator rbegin() const
				{
					return const_reverse_iterator(&_data[size]);
				};

				/*
				 ** @Brief : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
				 */
				reverse_iterator rend()
				{
					return reverse_iterator(_data);
				};

				/*
				 ** @Brief : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
				 */
				const_reverse_iterator rend() const
				{
					return const_reverse_iterator(_data);
				};

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
				void resize (size_type n, value_type val = value_type()) //TODO check capacity??!!
				{
					if (n < _size)
					{
						for (size_type i = n; i < _size; i++)
							_alloc.destroy(&_data[i]);
					}
					else
					{
						for (size_type i = _size; i < n; i++)
							_alloc.construct(&_data[i], val);
					}
					_size = n;
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
					std::ostringstream	buffer;

					buffer << "vector::at n (which is " << n << ") >= this->size() (which is " << _size << ")";
					if (_size <= n)
						throw std::out_of_range(buffer.str());
					_data[n];
				};

				/*
				 ** @Brief : Returns a const reference to the element at position n in the vector.
				 */
				const_reference at(size_type n) const
				{
					std::ostringstream	buffer;

					buffer << "vector::at n (which is " << n << ") >= this->size() (which is " << _size << ")";
					if (_size <= n)
						throw std::out_of_range(buffer.str());//TODO change message
					_data[n];
				};

				/*
				 ** @Brief : Returns a reference to the first element in the vector.
				 */
				reference front()
				{
					return (*this->_data[0]);
				};

				/*
				 ** @Brief : Returns a const_reference to the first element in the vector.
				 */
				const_reference front() const
				{
					return (*this->_data[0]);
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
				 ** @Brief : Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
				 */
				value_type* data() 
				{
					return (this->_data);
				};

				/*
				 ** @Brief : Returns a direct const pointer to the memory array used internally by the vector to store its owned elements.
				 */
				const value_type* data() const 
				{
					return (this->_data);
				};

				template <class InputIterator>
					void assign (InputIterator first, InputIterator last)
					{
						size_t	distance = std::distance(first, last);
						clear();
						if (capacity() < distance)
							reserve(distance);
						for (size_type i = 0; i < n; i++)
						{
							_alloc.construct(_data[i], first);
							first++;
						}
					};

				void assign (size_type n, const value_type& val)
				{
					clear();
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

				iterator insert(iterator position, const value_type& val)
				{
					difference_type	index_pos = position - begin();

					insert(position, 1, val);
					return iterator(&_data[index_pos]);
				};

				void insert (iterator position, size_type n, const value_type& val)
				{
					difference_type			index_pos = position - begin();

					if (n == 0)
						return ;
					if (_capacity < _size + n)
						reserve(_size + n);
					else
						_size += n;
					size_t	i = _size - 1;
					for (int y = index_pos + n; index_pos < y; y--; i++)
						_alloc.construct(_data[i], _data[y]);
					for (; index_pos < index_pos + n; index_pos++)
						_alloc.construct(_data[index_pos], val);

				};

				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last)
					{
						if (first == last)
							return ;
						if (first == end())
						{
							while (first++ != last)
								push_back(*first);
						}
						else
						{
							difference_type	index_pos = position - begin();
							size_t			length_insert = std::distance(first, begin);
							size_t			previous_size - _size;
						/*	if (_size + length_insert <= _capacity)
								reserve(_size + length_insert);
							else
								_size += length_insert;*/
							for (int i = 0; i < length_insert; i++, first++)
								insert(position + i, 1, *first);
						}


					};

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
					for (; last != end(); ++last, ++first)
						*first = *last;
					while (length_to_delete)
					{
						_alloc.destroy(_data + _size);
						length_to_delete--;
						_size--;
					}
					return (it);
				};

				/*
				 ** @Brief : Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
				 */
				void swap (vector& x)
				{
					std::swap(_capacity, x._capacity);
					std::swap(_size, x._size);
					std::swap(_data, x._data);
				}

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

	template <class T, class Alloc>
		bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
		};

	template <class T, class Alloc>
		bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		};

	template <class T, class Alloc>
		bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), lhs.end()));
		};

	template <class T, class Alloc>
		bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs == rhs || lhs < rhs);
		};

	template <class T, class Alloc>
		bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs < rhs)):
		};

	template <class T, class Alloc>
		bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs <= rhs));
		};

	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		};


};

#endif
