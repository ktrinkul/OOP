#pragma once
#ifndef ARRAYT_ARRAYT_HPP_20230520
#define ARRAYT_ARRAYT_HPP_20230520
#include <iostream>
#include <iosfwd>
#include <algorithm>

template<typename T>
class ArrayT {
public:

	ArrayT(const ArrayT& a);
	explicit ArrayT(const ptrdiff_t size = 0);
	ArrayT& operator=(const ArrayT& a);

	~ArrayT();

	T& operator[](const ptrdiff_t i);
	const T& operator[](const ptrdiff_t i) const;

	ptrdiff_t ssize() const noexcept;

	void resize(const ptrdiff_t size);

	void insert(const ptrdiff_t i, const T value);

	void remove(const ptrdiff_t i);

private:
	ptrdiff_t size_ = 0;
	ptrdiff_t capacity_ = 0;
	T* data_ = nullptr;
};

template<typename T>
inline ArrayT<T>::ArrayT(const ArrayT& a) {
	size_ = a.size_;
	capacity_ = a.capacity_;
	data_ = nullptr;
	if (size_ != 0) {
		data_ = new T[capacity_];
		for (ptrdiff_t i = 0; i < size_ && i < capacity_; ++i) {
			data_[i] = a.data_[i];
		}
	}
	else data_ = nullptr;
}

template<typename T>
inline ArrayT<T>::ArrayT(const ptrdiff_t size) {
	if (size < 0) {
		throw std::invalid_argument("Size can't be less than 0");
	}
	else {
		size_ = size;
		capacity_ = size;
		if (size_ != 0) {
			data_ = new T[capacity_];
			for (ptrdiff_t i = 0; i < size_; ++i) data_[i] = T();
		}
		else data_ = nullptr;
	}
}

template<typename T>
inline ArrayT<T>& ArrayT<T>::operator=(const ArrayT& a) {
	if (data_ != a.data_) {
		size_ = a.size_;
		capacity_ = a.capacity_;
		delete[] data_;
		data_ = nullptr;
		if (size_ != 0) {
			data_ = new T[capacity_];
			for (ptrdiff_t i = 0; i < size_ && i < capacity_; ++i) {
				data_[i] = a.data_[i];
			}
		}
		else data_ = nullptr;
	}
	return *this;
}

template<typename T>
inline ArrayT<T>::~ArrayT() {
	if (data_) {
		delete[] data_;
		data_ = nullptr;
	}
}

template<typename T>
inline T& ArrayT<T>::operator[](const ptrdiff_t i) {
	if (i >= size_ || i < 0) throw std::out_of_range("Index out of range");
	else return data_[i];
}

template<typename T>
inline const T& ArrayT<T>::operator[](const ptrdiff_t i) const
{
	if (i >= size_ || i < 0) throw std::out_of_range("Index out of range");
	else return data_[i];
}

template<typename T>
inline ptrdiff_t ArrayT<T>::ssize() const noexcept
{
	return size_;
}

template<typename T>
inline void ArrayT<T>::resize(const ptrdiff_t size)
{
	if (size <= 0) {
		throw std::invalid_argument("New size can't be less than 0");
	}
	else {
		if (size > capacity_) {
			ptrdiff_t new_size = size;
			ptrdiff_t new_capacity = std::max(new_size, size_ * 2);
			T* new_dater = new T[new_capacity];
			for (ptrdiff_t i = 0; i < size_ && i < new_capacity; ++i) {
				new_dater[i] = data_[i];
			}
			delete[] data_;
			data_ = new_dater;
			capacity_ = new_capacity;
		}
		for (ptrdiff_t i = size_; i < size && i < capacity_; ++i) {
			data_[i] = T();
		}
		size_ = size;
	}
}

template<typename T>
inline void ArrayT<T>::insert(const ptrdiff_t i, const T value)
{
	if (i > size_ || i < 0) throw std::out_of_range("invalid_argument");
	else
	{
		resize(size_ + 1);
		data_[size_ - 1] = value;
		for (ptrdiff_t j = size_ - 1; j > i; --j)
		{
			std::swap(data_[j], data_[j - 1]);
		}
	}
}

template<typename T>
inline void ArrayT<T>::remove(const ptrdiff_t i) {
	if (i >= size_ || i < 0) throw std::out_of_range("Index out of range");
	else {
		for (ptrdiff_t j = i; j < size_ - 1; ++j)
		{
			std::swap(data_[j], data_[j + 1]);
		}
		--size_;
	}
}

#endif