#include "buffer.hpp"
#include <iostream>

template <typename T>
Buffer<T>::Buffer(int size)
{
	buffer = std::unique_ptr<T[]>(new T[size]);
	_size = size;
}

template <typename T>
void Buffer<T>::resize(int size)
{
	if (size < 0)
		return;

	auto prev_buffer = std::move(buffer);
	buffer = std::unique_ptr<T[]>(new T[size]);
	
	int to_copy = size < _size ? size : _size;
	for (auto i = 0; i < to_copy; i += 1) {
		buffer[i] = std::move(prev_buffer[i]);
	}
	_size = size;
}

template <typename T>
T& Buffer<T>::operator[] (int index) {
	if (index < 0 || index >= _size) {
		return buffer[0];
	}
	return buffer[index];
}

template <typename T>
size_t Buffer<T>::size() const {
	return _size;
}

template <typename T>
T* Buffer<T>::get() {
	return buffer.get();
}

template <typename T>
Buffer<T>::~Buffer() {
	std::cout<<"Removing buffer \n";
}
