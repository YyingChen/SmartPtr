#pragma once
template<class T>
class ScopedPtr
{
public:
	ScopedPtr(T*ptr)
		:_ptr(ptr)
	{}
	
	~ScopedPtr()
	{
		if (_ptr)
		{
			printf("~ScopedPtr:%p\n",_ptr);
			delete _ptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	ScopedPtr(ScopedPtr<T> &sp);
	ScopedPtr<T>& operator=(const ScopedPtr<T> &sp);
private:
	T* _ptr;
};

void TestScopedPtr()
{
	ScopedPtr<int> p1(new int(2));
	ScopedPtr<int> p2(p1);
	ScopedPtr<int> p3=p2;

}