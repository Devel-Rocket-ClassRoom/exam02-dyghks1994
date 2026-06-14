#pragma once

template <typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		static T Instance;
		return Instance;
	}

private:
	Singleton() = default;
	virtual ~Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;
};
