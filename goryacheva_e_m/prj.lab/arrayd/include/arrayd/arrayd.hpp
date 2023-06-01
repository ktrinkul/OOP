#pragma once
#ifndef RATIONAL_ARRAYD_HPP_20230215
#define RATIONAL_RARRAYD_HPP_20230215

#include <iosfwd>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <numeric>

class ArrayD {
public:
    explicit ArrayD(const std::ptrdiff_t size = 0); 
    ~ArrayD() = default;
    ArrayD(const ArrayD&);
    ArrayD& operator=(const ArrayD&);

private:
    ptrdiff_t size = 0;
    ptrdiff_t capacity;
};

std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) noexcept;
std::istream& operator>>(std::istream& istrm, ArrayD& rhs) noexcept;


double& ArrayD operator[](const std::ptrdiff_t i);
const double& ArrayD operator[](const std::ptrdiff_t i) const;

std::ptrdiff_t ssize() const noexcept;

void resize(const std::ptrdiff_t new_size);

void insert(const std::ptrdiff_t i, const double value);

void remove(const std::ptrdiff_t i);

#endif