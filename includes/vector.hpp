#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	template<class T, class Allocator = std::allocator<T>>
		class vector{
			public://QUID public?
				typedef		T											value_type;
				typedef		Alloc										allocator_type;
				typedef		allocator_type::reference					reference;
				typedef		allocator_type::const_reference				const_reference;
				typedef		allocator_type::pointer						pointer;
				typedef		allocator_type::const_pointer				const_pointer;
				typedef		/*MISSING SOMTEHING*/						iterator;
				typedef		/*MISSING SOMETHING*/						const_iterator;
				typedef		/*MISSING SOMETHING*/						reverse_iterator;
				typedef		/*MISSING SOMETHING*/						const_reverse_iterator;
				typedef		iterator_traits<iterator>::difference_type	difference_type;
				typedef		allocator_type::size_type					size_type;
		}
}

#endif
