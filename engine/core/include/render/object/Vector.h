#pragma once

#include <initializer_list>
#include <cmath>
#include "include/utils/Defines.h"

namespace rendering
{
	template<typename T = float, int Cnt = 3>
	class Vector
	{
	public:
		Vector(std::initializer_list<T>&& args) noexcept;
		Vector(const Vector<T, Cnt>& other) noexcept;
		~Vector() noexcept;
		Vector<T, Cnt>& operator=(const Vector<T, Cnt>& other) noexcept;
		Vector<T, Cnt>& operator=(const Vector<T, Cnt>&& other) noexcept;
		Vector(Vector<T, Cnt>&& other) noexcept;
		T& operator[] (int i) noexcept;

		float Length() const noexcept;
		float LengthSqr() const noexcept;
		float Distance(const Vector<T, Cnt>& other) const noexcept;
		float Distance(const Vector<T, Cnt>&& other) const noexcept;
		Vector<T, Cnt> Normalize() const noexcept;
		void Normalized() noexcept;

		float Dot(const Vector<T, Cnt>& other) const noexcept;
		float Dot(const Vector<T, Cnt>&& other) const noexcept;

		Vector() noexcept = default;
	protected:
		T* mData = nullptr;
	};

	template<typename T>
	class Vector<T, 3> : public Vector<T, 3>
	{
	public:
		float Cross(const Vector<T, 3>) const noexcept;
	};

	template<typename T /*= float*/, int Cnt /*= 3*/>
	void rendering::Vector<T, Cnt>::Normalized() noexcept
	{
		float length = this->Length();
		for (int i = 0; i < Cnt; ++i)
		{
			mData[i] /= length;
		}
	}

	template<typename T /*= float*/, int Cnt /*= 3*/>
	float rendering::Vector<T, Cnt>::LengthSqr() const noexcept
	{
		T sqr = 0;
		for (int i = 0; i < Cnt; ++i)
			sqr += mData[i] * mData[i];
		return sqr;
	}

	template<typename T, int Cnt>
	inline float Vector<T, Cnt>::Distance(const Vector<T, Cnt>& other) const noexcept
	{
		float rst = 0;
		for (int i = 0; i < Cnt; ++i)
		{
			rst += std::pow(other.mData[i] - mData[i], 2);
		}
		return std::sqrt(rst);
	}

	template<typename T, int Cnt>
	inline float Vector<T, Cnt>::Distance(const Vector<T, Cnt>&& other) const noexcept
	{
		float rst = 0;
		for (int i = 0; i < Cnt; ++i)
		{
			rst += std::pow(other.mData[i] - mData[i], 2);
		}
		return std::sqrt(rst);
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt> Vector<T, Cnt>::Normalize() const noexcept
	{
		auto cpy = *this;
		float length = this->Length();
		for (int i = 0; i < Cnt; ++i)
		{
			cpy.mData[i] /= length;
		}
		return cpy;
	}

	template<typename T /*= float*/, int Cnt /*= 3*/>
	float rendering::Vector<T, Cnt>::Length() const noexcept
	{
		return std::sqrt(LengthSqr());
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>::Vector(std::initializer_list<T>&& args) noexcept
	{
		mData = new T[Cnt];

		int idx = 0;
		for (int arg : args)
		{
			if (idx < Cnt)
				mData[idx++] = arg;
			else
				break;
		}
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>::Vector(const Vector<T, Cnt>& other) noexcept
	{
		mData = new T[Cnt];

		for (int i = 0; i < Cnt; ++i)
		{
			mData[i] = other.mData[i];
		}
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>::~Vector() noexcept
	{
		SafeDeleteArray(mData);
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>& Vector<T, Cnt>::operator=(const Vector<T, Cnt>& other) noexcept
	{
		if (this == &other)
			return *this;
		if (mData == null)
			mData = new T[Cnt];
		for (int i = 0; i < Cnt; ++i)
		{
			mData[i] = other.mData[i];
		}
		return *this;
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>& Vector<T, Cnt>::operator=(const Vector<T, Cnt>&& other) noexcept
	{
		if (this == &other)
			return *this;
		if (mData == null)
			mData = new T[Cnt];
		for (int i = 0; i < Cnt; ++i)
		{
			mData[i] = other.mData[i];
		}
		return *this;
	}

	template<typename T, int Cnt>
	inline Vector<T, Cnt>::Vector(Vector<T, Cnt>&& other) noexcept
		: mData(other.mData)
	{
		other.mData = nullptr;
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