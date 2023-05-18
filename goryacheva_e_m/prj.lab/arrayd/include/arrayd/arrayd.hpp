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
    ArrayD() = default;
    //ArrayD(const ArrayD&) = default;
    //ArrayD(const int32_t num) noexcept;
    ~ArrayD() = default;



};
std::istream& operator>>(std::istream& istrm, ArrayD& rhs) noexcept;
std::ostream& operator<<(std::ostream& ostrm, const ArrayD& rhs) noexcept;
#endif



ArrayD(const std::ptrdiff_t ������);
ArrayD(const ArrayD&);
ArrayD& operator= (const ArrayD&);

/**
* \brief ������ � ��������� �� �������
* \param[in] i ������ ������������� ��������
* \return i-��� �������
* \throw std::out_of_range ���� ������ ��� ��������� [0, size)
    */
[[nodiscard]] �������� double& [](const std::ptrdiff_t i);
[[nodiscard]] const  �������& ��������[](const std::ptrdiff_t i) const;

/**
* \return ������� ������ �������
    */
[[nodiscard]] std::ptrdiff_t  ssize() const  ��� ����������;

/**
* \brief ��������� ������� �������
* \param[in] new_size ����� ������ �������
* \throw std::invalid_argument ���� ������� �������� new_size <= 0
    */
void resize(const std::ptrdiff_t new_size);

/**
* \brief ��������� �������. ���� ������� ������������, ������ resize
* \param[in] i ������ ��������, ������� ����� ��������
* \param[in] value ��������, ������� ���� ��������
* \throw std::invalid_argument ���� ������ ��� ��������� [0, size]
    */
void insert(const std::ptrdiff_t i, const double value);

/**
* \brief ������� ������� �� ������� i
remove
void
     */
*\throw std::out_of_range ���� ������ ��� ���������[0, size)* \param[in] i ������ ���������� ��������(const std::ptrdiff_t i);
};