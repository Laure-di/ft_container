# include "vector.hpp"

void	constructor(void)
{
	std::cout << "-----------------Test of constructor of vector---------------" << std::endl;
	ft::vector<int>			first_int;
	ft::vector<std::string>	first_str;
	ft::vector<char>		first_char;
	ft::vector<float>		first_float;
	ft::vector<int>			second_int(4, 100);
	ft::vector<std::string>	second_str(5, "container");
	ft::vector<char>		second_char(6, 'c');
	ft::vector<float>		second_float(5, 3.14);
	ft::vector<int>			third_int(second_int.begin(), second_int.end());
	ft::vector<std::string>	third_str(second_str.begin(), second_str.end());
	ft::vector<char>		third_char(second_char.begin(), second_char.end());
	ft::vector<float>		third_float(second_float.begin(), second_float.end());
	ft::vector<int>			fourth_int(third_int);
	ft::vector<std::string>	fourth_str(third_str);
	ft::vector<char>		fourth_char(third_char);
	ft::vector<float>		fourth_float(third_float);
	std::cout << "-------------Test of copy constructor of vector--------------" << std::endl;
	ft::vector<int>		copy;
	copy = first_int;
	ft::vector<int>		test;
	test.reserve(6);
}

void	assign(void)
{
	ft::vector<int> vct(7);
	//ft::vector<int> vct_two(7);
	ft::vector<int> vct_three;
	//ft::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	/*for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;*/

	vct_three.assign(vct.begin(), vct.end());
	std::cout << "OK" << std::endl;
//	vct.assign(vct_two.begin(), vct_two.end());
	std::cout << "OK" << std::endl;
//	vct_two.assign(2, 42);
	std::cout << "OK" << std::endl;
//	vct_four.assign(4, 21);
	std::cout << "OK" << std::endl;

//	vct_four.assign(6, 84);

	std::cout << vct.data() << " address of vct" << std::endl;
//	std::cout << vct_two.data() << " address of vct_two" << std::endl;
	std::cout << vct_three.data() << " address of vct_three" << std::endl;
//	std::cout << vct_four.data() << " address of vct_four" << std::endl;
	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
//	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

}
