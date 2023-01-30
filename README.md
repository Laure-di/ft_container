# ft_container

## Iterator


In C++, an iterator is an object that allows you to traverse through a container (e.g. list, vector, map, etc) and access its elements. They provide a standardized way to access elements in containers, regardless of their underlying implementation.

Iterator traits are a set of type traits (type definitions) used to provide information about the properties of an iterator. They provide a way to access information about an iterator's capabilities, such as whether it is a forward iterator, a random access iterator, or a bidirectional iterator.

For example, you can use iterator traits to determine if an iterator is capable of accessing elements in a container in both directions (bidirectional iterator), or if it can only access elements in one direction (forward iterator). These traits are defined in the C++ Standard Library header <iterator>.

Some common iterator traits include:

iterator_category: Specifies the type of iterator (e.g. std::forward_iterator_tag, std::bidirectional_iterator_tag, std::random_access_iterator_tag)
value_type: Specifies the type of the elements stored in the container.
difference_type: Specifies the type used to represent the difference between two iterators.
Using iterator traits can help make your code more generic and flexible, allowing it to work with a wider range of containers.

### What's iterator_traits ?

std::iterator_traits is a template class in the C++ Standard Template Library (STL) that allows you to obtain information about an iterator, such as its value type, difference type, and pointer type. It can be used to write generic algorithms that work with a wide range of iterator types, including both built-in and user-defined iterators. The class provides a uniform way of accessing information about an iterator, regardless of the underlying container or data structure.

### sources
https://www.simplilearn.com/tutorials/cpp-tutorial/iterators-in-cpp

