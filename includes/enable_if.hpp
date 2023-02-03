#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP


/*
 ** @Brief : source https://code.woboq.org/libreoffice/include/c++/4.8.2/type_traits.html
 */

namespace ft
{
	template<bool B, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T>
		{
			typedef T type;
		};

	template<class T, T v>
		struct integral_constant {
			static const T							value = v;
			typedef T								value_type;
			typedef integral_constant<T, v>	type; // using injected-class-name
		};

	typedef	integral_constant<bool, false>	false_type;
	typedef integral_constant<bool, true>	true_type;

	template<typename>
		struct is_integral_helper : public false_type
	{
	};

	template<>
		struct is_integral_helper<bool> : public true_type
		{};

	template<>
		struct is_integral_helper<char> : public true_type
		{};

	template<>
		struct is_integral_helper<signed char> : public true_type
		{};

	template<>
		struct is_integral_helper<short int> : public true_type
		{};

	template<>
		struct is_integral_helper<int> : public true_type
		{};

	template<>
		struct is_integral_helper<long int> : public true_type
		{};

	template<>
		struct is_integral_helper<long long int> : public true_type
		{};

	template<>
		struct is_integral_helper<unsigned char> : public true_type
		{};

	template<>
		struct is_integral_helper<unsigned short int> : public true_type
		{};

	template<>
		struct is_integral_helper<unsigned int> : public true_type
		{};

	template<>
		struct is_integral_helper<unsigned long int> : public true_type
		{};

	template<>
		struct is_integral_helper<unsigned long long int> : public true_type
		{};

	template<typename T>
		struct is_integral : public is_integral_helper<T>
	{};
}

#endif
