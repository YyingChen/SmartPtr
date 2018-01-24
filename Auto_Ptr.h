#pragma once
template<class T>
class AutoPtr
{
public:
	AutoPtr(T*ptr)
		:_ptr(ptr)
	{}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr=NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this!=ap)
		{
			if(_ptr)
			{
				delete _ptr;

				_ptr=ap._ptr;
				ap._ptr=NULL;
			}
		}
		return *this;
	}
	~AutoPtr()
	{
		if (_ptr)
		{
			printf("~AutoPtr:%p\n",_ptr);
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
      T* _ptr;
};
struct AA{
	int _a1;
	int _a2;
};
void TestAutoPtr()
{
	AutoPtr<int> p1(new int(2));
	AutoPtr<int> p2(p1);
    AutoPtr<int> p3=p2;

}