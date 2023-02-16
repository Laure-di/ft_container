#ifdef FT
#define NS ft
# include "vector.hpp"
#else
#define NS std
# include <vector>
#endif

	template <class T>
std::ostream&	operator<<(std::ostream& os, NS::vector<T> &vector)
{
	os << "VECTOR -----------" << std::endl;
	os << "size "	<< vector.size() << std::endl;;
//	os << "capacity " << vector.capacity() << std::endl;
	os << "content" << std::endl;

	if (vector.size())
	{
	typename NS::vector<T>::iterator	it = vector.begin();
	typename NS::vector<T>::iterator end = vector.end();
	for (; it != end; it++)
		os << *it << " ";
	}
	os << ""<< std::endl;
	return os;
}

void	constructor(void)
{
#ifdef STD
	std::cout << "std" << std::endl;
#else
	std::cout << "ft" << std::endl;
#endif
	std::cout << "-----------------Test of constructor of vector---------------" << std::endl;
	std::cout << "---vector (const allocator_type& alloc = allocator_type())---" << std::endl;
	NS::vector<int>			first_int;
	NS::vector<std::string>	first_str;
	NS::vector<char>		first_char;
	NS::vector<float>		first_float;
	std::cout << first_int << std::endl;
	std::cout << first_str << std::endl;
	std::cout << first_char << std::endl;
	std::cout << first_float << std::endl;

	std::cout << "---vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())---"<< std::endl;
	NS::vector<int>			second_int(4, 100);
	NS::vector<std::string>	second_str(first_str.max_size() + 1, "container");
	NS::vector<char>		second_char(6, 'c');
	NS::vector<float>		second_float(5, 3.14);
	std::cout << second_int << std::endl;
	std::cout << second_str << std::endl;
	std::cout << second_char << std::endl;
	std::cout << second_float << std::endl;
	std::cout << "---vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())--" <<std::endl;
	NS::vector<int>			third_int(second_int.begin(), second_int.end());
	NS::vector<std::string>	third_str(second_str.begin(), second_str.end());
	NS::vector<char>		third_char(second_char.begin(), second_char.end());
	NS::vector<float>		third_float(second_float.begin(), second_float.end());
	std::cout << third_int << std::endl;
	std::cout << third_str << std::endl;
	std::cout << third_char << std::endl;
	std::cout << third_float << std::endl;
	std::cout << "---vector (const vector& x)---" <<std::endl;
	NS::vector<int>			fourth_int(third_int);
	NS::vector<std::string>	fourth_str(third_str);
	NS::vector<char>		fourth_char(third_char);
	NS::vector<float>		fourth_float(third_float);
	std::cout << fourth_int << std::endl;
	std::cout << fourth_str << std::endl;
	std::cout << fourth_char << std::endl;
	std::cout << fourth_float << std::endl;
	std::cout << "-------------Test of copy constructor of vector--------------" << std::endl;
//	NS::vector<int>		copy;
//	copy = second_int;
//	std::cout << copy << std::endl;
//	NS::vector<int>		test;
//	test.reserve(6);
//	std::cout << test << std::endl;
}

void	assign(void)
{
	NS::vector<int> vct(7);
	NS::vector<int> vct_two(7);
	NS::vector<int> vct_three;
	NS::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	vct_four.assign(6, 84);

	std::cout << vct.data() << " address of vct" << std::endl;
	std::cout << vct_two.data() << " address of vct_two" << std::endl;
	std::cout << vct_three.data() << " address of vct_three" << std::endl;
	std::cout << vct_four.data() << " address of vct_four" << std::endl;
	std::cout << std::endl;


	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	std::cout <<"1 " <<  vct << std::endl;
	std::cout <<"2 " <<  vct_two << std::endl;
	std::cout <<"3 " <<  vct_three << std::endl;
	std::cout <<"4 " <<  vct_four << std::endl;

}
