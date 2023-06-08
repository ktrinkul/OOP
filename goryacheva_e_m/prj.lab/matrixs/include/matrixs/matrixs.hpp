#pragma once
#ifndef MATRIXS_MATRIXS_HPP_20230215
#define MATRIXS_MATRIXS_HPP_20230215

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <vector>

class MatrixS {
public:
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;

public:
    explicit MatrixS(const SizeType& size = { 0, 0 });
    MatrixS(const std::ptrdiff_t m, const std::ptrdiff_t n);
    ~MatrixS();

    MatrixS(const MatrixS& other);
    MatrixS& operator=(const MatrixS& other);

    /**
     * \brief ���������� ������� ������� ��� ��������� {i, j}
     * \param[in] elem ������� ��������
     * \return ������� �������
     * \throw std::out_of_range ���� i ��� ��������� [0, m) ��� j ��� ��������� [0, n)
     */
    int& at(const SizeType& elem);
    const int& at(const SizeType& elem) const;
    int& at(const std::ptrdiff_t i, const std::ptrdiff_t j);
    const int& at(const std::ptrdiff_t i, const std::ptrdiff_t j) const;

    /**
     * \brief ��������� ������� �������
     * \param[in] new_size ����� ������ ������� {new_m, new_n}
     * \throw std::invalid_argument ���� new_m <= 0 ��� new_n <= 0
     */
    void resize(const SizeType& new_size);
    void resize(const std::ptrdiff_t i, const std::ptrdiff_t j);

    /**
     * \return ������� ������ ������� {m, n}
     */
    const SizeType& ssize() const noexcept;

    /**
     * \return ���������� ����� � ������� (m)
     */
    std::ptrdiff_t nRows() const noexcept;

    /**
     * \return ���������� �������� � ������� (n)
     */
    std::ptrdiff_t nCols() const noexcept;
};

#endif