/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 04:13:42 by ayel-mou          #+#    #+#             */
/*   Updated: 2025/10/08 04:13:43 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



template <typename T>

Array<T>::Array()
{
    this->arr = NULL;
    this->_size = 0;
}

template <typename T>

Array<T>::Array(unsigned int n)
{
    this->_size = n;
    this->arr = new T[n]();
}

template <typename T>

Array<T>::Array(const Array& other)
    : _size(other._size)
{
    this->arr = new T[_size]; 
    for (unsigned int i = 0; i < _size; ++i)
    {
        this->arr[i] = other.arr[i];
    }
}

template <typename T>

Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other)
        return *this;
    delete [] arr;

    this->_size = other._size;
    this->arr = new T[_size]; 
    for (unsigned int i = 0; i < _size; ++i)
    {
        this->arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>

unsigned int Array<T>::size() const
{
    return this->_size;
}

template <typename T>

T& Array<T>::operator [](unsigned int index)
{
    if (index >= _size)
        throw IndexNotValid();
    return this->arr[index];
}

template <typename T>

const T& Array<T>::operator [](unsigned int index) const
{
    if (index >= _size)
        throw IndexNotValid();
    return this->arr[index];
}

template <typename T>

Array<T>::~Array()
{
    delete [] arr;
}