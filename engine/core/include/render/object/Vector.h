#pragma once

#include <initializer_list>

namespace rendering
{
	template<typename T = float, int Cnt = 3>
	class Vector
	{
	public:
		Vector(std::initializer_list<T>&& args) noexcept;
		Vector(const Vector<T, Cnt>& other) noexcept;
		Vector<T, Cnt>& operator=(const Vector<T, Cnt>& other) noexcept;
		Vector(Vector<T, Cnt>&& other) noexcept;
		T& operator[] (int i) noexcept;

		Vector() noexcept = default;
		~Vector() noexcept = default;
	private:
		T mData[Cnt];
	};
	template<typename T, int Cnt>
	inline Vector<T, Cnt>::Vector(std::initializer_list<T>&& args) noexcept
	{
		int idx = 0;
		for (int arg : args)
		{
			if (idx < Cnt)
				mData[idx] = arg;
			else
				break;
		}
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>::Vector(const Vector<T, Cnt>& other) noexcept
	{
		for (int i = 0; i < Cnt; ++i)
		{
			mData[i] = other.mData[i];
		}
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>& Vector<T, Cnt>::operator=(const Vector<T, Cnt>& other) noexcept
	{
		for (int i = 0; i < Cnt; ++i)
		{
			mData[i] = other.mData[i];
		}
		return *this;
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>::Vector(Vector<T, Cnt>&& other) noexcept
	{
		mData = std::move(other.mData);
	}
	template<typename T, int Cnt>
	inline T& Vector<T, Cnt>::operator[](int i) noexcept
	{
		return mData[i];
	}
}