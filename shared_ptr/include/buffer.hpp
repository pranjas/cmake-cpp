#ifndef BUFFER_HPP
#define BUFFER_HPP
#include <memory>

template <typename T>
class Buffer {
	private:
		std::unique_ptr<T[]> buffer;
		size_t _size;
	public:
		Buffer(int size = 0);
		void resize(int size);
		T& operator[] (int index);
		size_t size() const;
		T* get();
		~Buffer();
};
#endif //BUFFER_HPP
