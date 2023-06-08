#pragma once
#ifndef ARRAYT_ARRAYT_HPP_20230215
#define ARRAYT_ARRAYT_HPP_20230215

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <vector>

class ArrayD {
public:
    explicit ArrayD(const std::ptrdiff_t size = 0);
    ~ArrayD();

    ArrayD(const ArrayD&);
    ArrayD& operator=(const ArrayD&);

    ArrayD(std::initializer_list<double> lst);

    std::ptrdiff_t ssize() const noexcept;

    void resize(const std::ptrdiff_t new_size);

    void insert(const std::ptrdiff_t i, const double value);

    void remove(const std::ptrdiff_t i);

    double& operator[](const std::ptrdiff_t i);
    const double& operator[](const std::ptrdiff_t i) const;

    private:
        ptrdiff_t size_ = 0;
        ptrdiff_t capacity_;
        double* arr;
};

#endif