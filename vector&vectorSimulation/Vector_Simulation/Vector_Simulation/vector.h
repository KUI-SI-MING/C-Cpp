#pragma once

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <algorithm>

using namespace std;

namespace kui
{
	template<class T>
	class Vector
	{
	public:
		//vectorde的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* constiterator;

		iterator Begin(){
			return _start;
		}

		constiterator CBegin() const {
			return _start;
		}

		iterator End(){
			return _finish;
		}

		constiterator CEnd() const { 
			return _finish;
		}
		size_t Size() const{
			return _finish - _start;
		}

		size_t Capacity() const{
			return _endofstorage - _start;
		}

		T& operator[](size_t pos){
			assert(pos < Size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const{
			assert(pod < Size());
			return _start[pos];
		}

		//缺省构造
		Vector() :_start(nullptr), _finish(nullptr), _endofstorage(nullptr){}

		Vector(int n, const T& value = T()) :_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				Push_Back(value);
			}
		}

		~Vector(){
			if (_start){
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		//重新声明新的迭代器，[first, last]可以使任意容器的迭代器区间
		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				Push_Back(*first);
				++first;
			}
		}
		//拷贝构造
		Vector(const Vector<T>& v) :_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			Reserve(v.Capacity());

			iterator it = Begin();
			constiterator vit = v.CBegin();
			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}

			_finish = _start + v.Size();
			_endofstorage = _start + v.Capacity();
		}

		//重载=
		Vector<T>& operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}

		void Reserve(size_t n)//无需考虑n小于capacity的情况
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				//if (_start)
					//memcpy(tmp, _start, sizeof(T) * size);会出错

				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
					{
						tmp[i] = _start[i];
					}
				}

				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}

		void Resize(size_t n, const T& val = T())
		{
			//如果n小于当前的size，则缩小size
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}

			//空间不够则增容
			if (n > Capacity())
			{
				Reserve(n);
			}

			//扩大size
			iterator it = _finish;
			 _finish = _start + n;
			while (it != _finish)
			{
				*it = val;//完成初始化
				++it;
			}
		}

		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
		}

		iterator Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);

			//空间不够增容
			if (_finish == _endofstorage)
			{
				size_t size = Size();
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;

				Reserve(newCapacity);
				//若增容则重置pos
				pos = _start + size;
			}

			iterator end = _finish - 1;//finish是备用空间的起始地址
			while (end >= pos)//pos - ... - end 
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;
			return pos;
		}


		void Push_Back(const T& x)
		{
			Insert(End(), x);
		}

		//返回删除数据的下一个数据
		//迭代器失效问题
		iterator Erase(iterator pos)
		{
			//删除
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;
			return pos;
		}

		void Pop_Back()
		{
			Erase(--End());
		}

	private:
		T* _start;//数据块的开始
		T* _finish;//有效数据的尾
		T* _endofstorage;//存储容量的尾
	};
}