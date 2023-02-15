#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <memory>
# include <algorithm>
# include <sstream>
# include "iterator_traits.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "random_access_iterator.hpp"
# include "enable_if.hpp"
# include "utils.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
		class vector {

			public:
				typedef				T												value_type;
				typedef				Allocator										allocator_type;
				typedef	typename	allocator_type::reference						reference;
				typedef	typename	allocator_type::const_reference					const_reference;
				typedef	typename	allocator_type::pointer							pointer;
				typedef	typename	allocator_type::const_pointer					const_pointer;
				typedef				random_access_iterator<T>						iterator;
				typedef				random_access_iterator<const T>					const_iterator;
				typedef				ft::reverse_iterator<iterator>					reverse_iterator;
				typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
				typedef				typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
				typedef				typename allocator_type::size_type				size_type;

			private:
				size_type		_capacity;
				size_type		_size;
				pointer			_data;
				allocator_type	_alloc;
				//	protected:
				//		size_t	
			public:

				/*
				 ** @Brief : Constructs an empty container, with no elements.
				 */
				explicit vector(const allocator_type& alloc = allocator_type()) : _capacity(0), _size(0), _data(NULL), _alloc(alloc){};

				/*
				 ** @Brief : Constructs a container with n elements. Each element is a copy of val.
				 */
				explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{
					_alloc = alloc;
					_data = _alloc.allocate(n);
					_size = n;
					size_t	i = 0;
					while (i < n)
						_alloc.construct(&_data[i++], val);

				};//TODO need assign method to do this constructor;

				/*
				 ** @Brief : Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
				 */
				template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0)
					{
						_alloc = alloc;
						difference_type n= ft::distance(first, last); //TODO reimplement distance
						_size = n;
						_capacity = _size;
						_data = _alloc.allocate(_size);
						for (size_t i = 0; i < _size; i++)
						{
							_alloc.construct(_data + i, *first);
							first++;
						}

					};
				/*
				 ** @Brief : Constructs a container with a copy of each of the elements in x, in the same order.
				 */
				vector(const vector& x)
				{
					_alloc = x.get_allocator();
					_size = x.size();
					_capacity = _size;
					if (_capacity)
						_data = _alloc.allocate(_capacity);
					const_iterator	it = x.begin();
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(_data + i, *it++);
				};

				~vector()
				{
					/*for (size_t i = 0;i < _size; i++)
					  _alloc.destroy(_data + i);
					  _size = 0;*/
					clear();
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
				}

				/*
				 ** @Brief : Copies all the elements from x into the container.
				 */
				vector& operator=(const vector& x)
				{
						clear();
						if (_capacity)
							_alloc.deallocate(_data, _capacity);
						_size = x.size();
						_alloc = x.get_allocator();//TODO look for clarification not sure about that
												   //The container preserves its current allocator, which is used to allocate storage in case of reallocation.
						_capacity = _size;
						if (_capacity)
							_data = _alloc.allocate(_capacity);
						const_iterator	it = x.begin();
						for (size_t i = 0; i < _size; i++)
							_alloc.construct(_data + i, *it++);
					return (*this);
				};

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
					return reverse_iterator(begin());
				};

				/*
				 ** @Brief : rbegin points to the element right before the one that would be pointed to by member end. Returns a reverse random access iterator.
				 */
				const_reverse_iterator rbegin() const
				{
					return const_reverse_iterator(begin());
				};

				/*
				 ** @Brief : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
				 */
				reverse_iterator rend()
				{
					return reverse_iterator(end());
				};

				/*
				 ** @Brief : Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
				 */
				const_reverse_iterator rend() const
				{
					return const_reverse_iterator(end());
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
					while (newCapacity < n)
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
						for (size_type i = 0; i < size(); i++)
						{
							_alloc.construct(&newData[i], _data[i]);
							_alloc.destroy(_data + i);
						}
						if (_capacity)
							_alloc.deallocate(_data, capacity());
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
					return _data[n];
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
					return _data[n];
				};

				/*
				 ** @Brief : Returns a reference to the first element in the vector.
				 */
				reference front()
				{
					return _data[0];
				};

				/*
				 ** @Brief : Returns a const_reference to the first element in the vector.
				 */
				const_reference front() const
				{
					return _data[0];
				};

				/*
				 ** @Brief : Returns a reference to the last element in the vector.
				 */
				reference back()
				{
					return _data[_size - 1];
				};

				/*
				 ** @Brief : Returns a const_reference to the last element in the vector.
				 */
				const_reference back() const
				{
					return _data[_size - 1];
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
					void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0)
					{
						size_t	distance = ft::distance(first, last);
						clear();
						if (capacity() < distance)
							reserve(distance);
						while (first != last)
						{
							push_back(*first);
							first++;
						}
					};

				void assign (size_type n, const value_type& val)
				{
					clear();
					if (capacity() < n)
						reserve(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&_data[i], val);
					_size = n;
				}

				void push_back (const value_type& val)
				{
					if (_size + 1 > _capacity)
						reserve(_size + 1);
					_alloc.construct(&_data[_size], val);
					_size += 1;
				};

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

				void insert(iterator position, size_type n, const value_type& val)
				{
					difference_type			index_pos = position - begin();

					if (n == 0)
						return ;
					if (_capacity < _size + n)
						reserve(_size + n);
					else
						_size += n;
					size_t	i = _size - 1;
					for (int y = index_pos + n; index_pos < y; y--, i++)
						_alloc.construct(&_data[i], _data[y]);
					for (; (size_t)index_pos < (size_t)index_pos + n; index_pos++) //TODO check syntaxe
						_alloc.construct(&_data[index_pos], val);

				};

				template <class InputIterator>
					void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
					{
						if (first == last)
							return ;
						/*if (first == end())
						  {
						  while (first++ != last)
						  push_back(*first);
						  }*/
						//	else
						//	{
						//difference_type	index_pos = position - begin();
						size_t			length_insert = ft::distance(begin(), position);
						//size_t			previous_size = _size;
						if (_size + length_insert <= _capacity)
							reserve(_size + length_insert);
						else
							_size += length_insert;
						for (size_t i = 0; i < length_insert; i++, first++)
							insert(position + i, 1, *first);
						//	}


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
					int			length_to_delete = ft::distance(first, last);
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
						_alloc.destroy(_data + --_size);
				};

				/*
				 ** @Brief : Returns a copy of the allocator object associated with the vector.
				 */
				allocator_type get_allocator() const
				{
					return (_alloc);
				};

		};

	template <class T, class Alloc, class T2, class Alloc2>
		bool operator==(const vector<T,Alloc>& lhs, const vector<T2,Alloc2>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		};

	template <class T, class Alloc, class T2, class Alloc2>
		bool operator!=(const vector<T,Alloc>& lhs, const vector<T2,Alloc2>& rhs)
		{
			return (!(lhs == rhs));
		};

	template <class T, class Alloc, class T2, class Alloc2>
		bool operator<(const vector<T,Alloc>& lhs, const vector<T2,Alloc2>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		};

	template <class T, class Alloc, class T2, class Alloc2>
		bool operator<=(const vector<T,Alloc>& lhs, const vector<T2,Alloc2>& rhs)
		{
			return (lhs == rhs || lhs < rhs);
		};

	template <class T, class Alloc, class T2, class Alloc2>
		bool operator>(const vector<T,Alloc>& lhs, const vector<T2,Alloc2>& rhs)
		{
			return (!(lhs <= rhs));
		};

	template <class T, class Alloc, class T2, class Alloc2>
		bool operator>=(const vector<T,Alloc>& lhs, const vector<T2,Alloc2>& rhs)
		{
			return !(lhs < rhs);
		};

	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		};
};

#endif
