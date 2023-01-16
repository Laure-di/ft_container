void	main_vector(void)
{
	std::cout << "-----------------Test of constructor of vector---------------" << std::endl
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
	ft::vector<std::string>	fourth_str(third_strg);
	ft::vector<char>		fourth_char(third_char);
	ft::vector<float>		fourth_float(third_float)
}
