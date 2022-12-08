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
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); //TODO need assign method to do this constructor;
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


		}
}

#endif
