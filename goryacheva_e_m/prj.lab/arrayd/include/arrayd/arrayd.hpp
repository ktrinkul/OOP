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



ArrayD(const std::ptrdiff_t размер);
ArrayD(const ArrayD&);
ArrayD& operator= (const ArrayD&);

/**
* \brief Доступ к элементам по индексу
* \param[in] i индекс возвращаемого элемента
* \return i-тый элемент
* \throw std::out_of_range если индекс вне диапазона [0, size)
    */
[[nodiscard]] оператор double& [](const std::ptrdiff_t i);
[[nodiscard]] const  двойной& оператор[](const std::ptrdiff_t i) const;

/**
* \return текущий размер массива
    */
[[nodiscard]] std::ptrdiff_t  ssize() const  нет исключения;

/**
* \brief Изменение размера массива
* \param[in] new_size новый размер массива
* \throw std::invalid_argument если входной параметр new_size <= 0
    */
void resize(const std::ptrdiff_t new_size);

/**
* \brief Вставляет элемент. если размера недостаточно, делает resize
* \param[in] i индекс элемента, который будет добавлен
* \param[in] value значение, которое надо добавить
* \throw std::invalid_argument если индекс вне диапазона [0, size]
    */
void insert(const std::ptrdiff_t i, const double value);

/**
* \brief Удаляет элемент по индексу i
remove
void
     */
*\throw std::out_of_range если индекс вне диапазона[0, size)* \param[in] i индекс удаляемого элемента(const std::ptrdiff_t i);
};