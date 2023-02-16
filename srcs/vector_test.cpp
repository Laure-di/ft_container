# include "vector.hpp"

	template <class T>
std::ostream&	operator<<(std::ostream& os, ft::vector<T> &vector)
{
	os << "VECTOR -----------" << std::endl;
	os << "size "	<< vector.size() << std::endl;;
	os << "capacity " << vector.capacity() << std::endl;
	os << "content" << std::endl;

	typename ft::vector<T>::iterator	it = vector.begin();
	typename ft::vector<T>::iterator end = vector.end();
	for (; it != end; it++)
		os << *it << " ";
	os << ""<< std::endl;
	return os;
}

void	constructor(void)
{
	std::cout << "-----------------Test of constructor of vector---------------" << std::endl;
	std::cout << "---vector (const allocator_type& alloc = allocator_type())---" << std::endl;
	ft::vector<int>			first_int;
	ft::vector<std::string>	first_str;
	ft::vector<char>		first_char;
	ft::vector<float>		first_float;
	std::cout << first_int << std::endl;
	std::cout << first_str << std::endl;
	std::cout << first_char << std::endl;
	std::cout << first_float << std::endl;

	std::cout << "---vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())---"<< std::endl;
	ft::vector<int>			second_int(4, 100);
	ft::vector<std::string>	second_str(5, "container");
	ft::vector<char>		second_char(6, 'c');
	ft::vector<float>		second_float(5, 3.14);
	std::cout << second_int << std::endl;
	std::cout << second_str << std::endl;
	std::cout << second_char << std::endl;
	std::cout << second_float << std::endl;
	std::cout << "---vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())--" <<std::endl;
	ft::vector<int>			third_int(second_int.begin(), second_int.end());
	ft::vector<std::string>	third_str(second_str.begin(), second_str.end());
	ft::vector<char>		third_char(second_char.begin(), second_char.end());
	ft::vector<float>		third_float(second_float.begin(), second_float.end());
	std::cout << third_int << std::endl;
	std::cout << third_str << std::endl;
	std::cout << third_char << std::endl;
	std::cout << third_float << std::endl;
	std::cout << "---vector (const vector& x)---" <<std::endl;
	ft::vector<int>			fourth_int(third_int);
	ft::vector<std::string>	fourth_str(third_str);
	ft::vector<char>		fourth_char(third_char);
	ft::vector<float>		fourth_float(third_float);
	std::cout << fourth_int << std::endl;
	std::cout << fourth_str << std::endl;
	std::cout << fourth_char << std::endl;
	std::cout << fourth_float << std::endl;
	std::cout << "-------------Test of copy constructor of vector--------------" << std::endl;
	ft::vector<int>		copy;
	copy = second_int;
	std::cout << copy << std::endl;
	ft::vector<int>		test;
	std::cout << test << std::endl;
	test.reserve(6);
}

void	assign(void)
{
	ft::vector<int> vct(7);
	ft::vector<int> vct_two(7);
	ft::vector<int> vct_three;
	ft::vector<int> vct_four;

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
