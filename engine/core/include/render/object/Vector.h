#pragma once

#include <initializer_list>
#include <cmath>

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

		float Length() const noexcept;
		float LengthSqr() const noexcept;

		Vector() noexcept = default;
		~Vector() noexcept = default;
	private:
		T mData[Cnt];
	};

	template<typename T /*= float*/, int Cnt /*= 3*/>
	float rendering::Vector<T, Cnt>::LengthSqr() const noexcept
	{
		T sqr = 0;
		for (int i = 0; i < Cnt; ++i)
			sqr += mData[i] * mData[i];
		return sqr;
	}

	template<typename T /*= float*/, int Cnt /*= 3*/>
	float rendering::Vector<T, Cnt>::Length() const noexcept
	{
		return std::sqrt(LengthSqr());
	}

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


	using Vector2f = Vector<float, 2>;
	using Vector3f = Vector<float, 3>;
	using Vector4f = Vector<float, 4>;

	using Vector2Int = Vector<int, 2>;
	using Vector3Int = Vector<int, 3>;
	using Vector4Int = Vector<int, 4>;
}