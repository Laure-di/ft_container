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
			public:


				explicit vector(const allocator_type& alloc = allocator_type()) : _capacity(0), _size(0), _data(NULL), _alloc(alloc){};

				explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{
					_alloc = alloc;
					_size = 0;
					_capacity = 0;
					_data = NULL;
					assign(n, val);

				}

				template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0)
					{
						_alloc = alloc;
						_size = 0;
						_capacity = 0;
						_data = NULL;
						assign(first, last);
					};

				vector(const vector& x)
				{
					_alloc = x.get_allocator();
					_size = x.size();
					_capacity = x.capacity();
					if (_capacity)
						_data = _alloc.allocate(_capacity);
					const_iterator	it = x.begin();
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(_data + i, *it++);
				};

				~vector()
				{
					clear();
					if (_capacity)
						_alloc.deallocate(_data, _capacity);
				}

				vector& operator=(const vector& x)
				{
					if (this != &x)
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
					}
					return (*this);
				};

				iterator begin()
				{
					return (iterator(_data));
				};

				const_iterator begin() const
				{
					return (const_iterator(_data));
				};

				iterator end()
				{
					return (iterator(_data + _size));
				};

				const_iterator end() const
				{
					return (const_iterator(_data + _size));
				};

				reverse_iterator rbegin()
				{
					return reverse_iterator(begin());
				};

				const_reverse_iterator rbegin() const
				{
					return const_reverse_iterator(begin());
				};

				reverse_iterator rend()
				{
					return reverse_iterator(end());
				};

				const_reverse_iterator rend() const
				{
					return const_reverse_iterator(end());
				};

				size_type size() const
				{
					return (_size);
				};

				size_type max_size() const
				{
					return (_alloc.max_size());
				};


				void resize(size_type n, value_type val = value_type())
				{
					if (n <= _capacity)
					{
						if (n > _size)
						{
							for (size_type i = _size; i < n; ++i)
							{
								_alloc.construct(&_data[i], val);
							}
						}
						else if (n < _size)
						{
							for (size_type i = n; i < _size; ++i)
							{
								_alloc.destroy(&_data[i]);
							}
						}
						_size = n;
					}
					else
					{
						size_t new_capacity = computeNewCapacity(n);
						pointer new_data = _alloc.allocate(new_capacity);
						for (size_type i = 0; i < n; ++i)
						{
							if (i < _size)
							{
								_alloc.construct(&new_data[i], _data[i]);
							}
							else
							{
								_alloc.construct(&new_data[i], val);
							}
						}
						clear();
						if (_capacity)
							_alloc.deallocate(_data, _capacity);
						_data = new_data;
						_size = n;
						_capacity = new_capacity;
					}
				}

				iterator insert(iterator position, const T& val) {
					size_t index = position - begin();
					if (_size == _capacity)
					{
						size_t new_capacity = computeNewCapacity(_size + 1);
						pointer new_data = _alloc.allocate(new_capacity);
						for (size_type i = 0; i < index; ++i)
						{
							_alloc.construct(&new_data[i], _data[i]);
						}
						_alloc.construct(&new_data[index], val);
						for (size_type i = index; i < _size; ++i)
						{
							_alloc.construct(&new_data[i + 1], _data[i]);
						}
						clear();
						if (_capacity)
							_alloc.deallocate(_data, _capacity);
						_data = new_data;
						_capacity = new_capacity;
						++_size;
						return iterator(&_data[index]);
					}
					else
					{
						_alloc.construct(&_data[_size], _data[_size - 1]);
						for (size_type i = _size - 1; i > index; --i)
						{
							_data[i] = _data[i - 1];
						}
						_data[index] = val;
						++_size;
						return iterator(&_data[index]);
					}
				}

				iterator erase(iterator position)
				{
					size_type index = position - begin();
					_alloc.destroy(&_data[index]);
					for (size_type i = index; i < _size - 1; ++i)
					{
						_data[i] = _data[i + 1];
					}
					_size--;
					return (begin() + index);
				}

				size_type capacity() const
				{
					return (_capacity);
				};

				bool empty() const
				{
					if (_size == 0)
						return (true);
					return (false);
				};

				void reserve(size_type n)
				{
					size_type	new_capacity = computeNewCapacity(n);

					if (max_size() < new_capacity)
						throw (std::length_error("vector::reserve"));//TODO check erreur message
					if (capacity() < new_capacity)
					{
						pointer		newData = NULL;
						newData = _alloc.allocate(new_capacity);
						for (size_type i = 0; i < size(); i++)
						{
							_alloc.construct(&newData[i], _data[i]);
							_alloc.destroy(_data + i);
						}
						if (_capacity)
							_alloc.deallocate(_data, capacity());
						_data = newData;
						_capacity = new_capacity;
					}
				};

				reference operator[] (size_type n)
				{
					return (this->_data[n]);
				};

				const_reference operator[] (size_type n) const
				{
					return (this->_data[n]);
				};

				reference at(size_type n)
				{
					std::ostringstream	buffer;

					buffer << "vector::at n (which is " << n << ") >= this->size() (which is " << _size << ")";
					if (_size <= n)
						throw std::out_of_range(buffer.str());
					return _data[n];
				};

				const_reference at(size_type n) const
				{
					std::ostringstream	buffer;

					buffer << "vector::at n (which is " << n << ") >= this->size() (which is " << _size << ")";
					if (_size <= n)
						throw std::out_of_range(buffer.str());
					return _data[n];
				};

				reference front()
				{
					return _data[0];
				};

				const_reference front() const
				{
					return _data[0];
				};

				reference back()
				{
					return _data[_size - 1];
				};

				const_reference back() const
				{
					return _data[_size - 1];
				};

				value_type* data() 
				{
					return (this->_data);
				};

				const value_type* data() const 
				{
					return (this->_data);
				};

				template <class InputIterator>
					void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0)
					{
						clear();
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

				void pop_back()
				{
					if (_size != 0)
					{
						_alloc.destroy(_data + _size);
						_size--;
					}
				};

				template <typename U>
					void insert(iterator position, size_type count, const U &value)
					{
						size_type index = position - begin();

						if (_size + count > _capacity) {
							reserve(computeNewCapacity(_size + count));
						}
						std::copy_backward(begin() + index, end(), end() + count);
						for (size_type i = 0; i < count; ++i) {
							_alloc.construct(&_data[index + i], value);
						}
						_size += count;	
					}

				template <typename U>
					void insert(iterator position, typename ft::enable_if<!ft::is_integral<U>::value, U>::type first, U last)
					{
						size_type n = ft::distance(first, last);
						if (_size + n > _capacity)
						{
							size_type new_capacity = computeNewCapacity(_size + n);
							pointer new_data = _alloc.allocate(new_capacity);
							pointer new_data_end = new_data;
							for (size_type i = 0; i < _size; ++i)
							{
								if (&_data[i] == position.base())
								{
									pointer insert_point = new_data_end;
									for (; first != last; ++first)
									{
										_alloc.construct(insert_point++, *first);
									}
								}
								_alloc.construct(new_data_end++, _data[i]);
							}
							if (_capacity)
								_alloc.deallocate(_data, _capacity);
							clear();
							_data = new_data;
							_size += n;
							_alloc.construct(&new_data[i + n], _data[i]);
						}
						for (size_type i = 0; i < _size; ++i)
						{
							_alloc.destroy(&_data[i]);
						}
						_alloc.deallocate(_data, _capacity);
						_data = new_data;
						_capacity = new_capacity;
					}
				else
				{
					for (size_type i = _size - 1; i >= index; --i)
					{
						_alloc.construct(&_data[i + n], _data[i]);
						_alloc.destroy(&_data[i]);
					}
					for (size_type i = 0; i < n; ++i)
					{
						_alloc.construct(&_data[index + i], *(first + i));
					}
				}
				_size += n;
		};



iterator erase(iterator first, iterator last)
{
	difference_type index = first - begin();
	difference_type range = last - first;
	for (size_t i = 0; i < (size_t)range; ++i)
	{
		_alloc.destroy(&_data[index + i]);
	}
	for (size_t i = index + range; i < _size; ++i)
	{
		_data[i - range] = _data[i];
	}
	_size -= range;
	return (iterator(&_data[index]));
};


void swap (vector& x)
{
	std::swap(_capacity, x._capacity);
	std::swap(_size, x._size);
	std::swap(_data, x._data);
}

void clear()
{
	while (_size)
		_alloc.destroy(_data + --_size);
};

allocator_type get_allocator() const
{
	return (_alloc);
};

protected:

size_t		computeNewCapacity(size_t size)
{
	if (max_size() < size)
		throw (std::length_error("vector::capacity"));
	size_t	new_capacity = capacity();
	while (new_capacity < size)
	{
		if (new_capacity == 0)
			new_capacity = 1;
		else if (new_capacity * 2 < max_size())
			new_capacity *= 2;
		else
			return max_size();

	}
	return new_capacity;
}

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
