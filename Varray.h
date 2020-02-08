#if !defined(__VARRAY__)
#define __VARRAY__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef unsigned int uint;

//this template defines a variable array
template <class T> class Varray
{

protected:
	T *_array;		//array
	uint _bufsize;	//buffer size available
	uint _size;		//size of array

public:
	//standart constructor if bufsize = 0 no memmory is allocated.
	Varray(uint size=1)
	{
		_size = _bufsize = size;
		_array	= (T *)calloc(_bufsize,sizeof(T));
	}

	//indirect construction from dynamic array
	Varray(T *array,uint size)
	{
		_bufsize = _size = size;
		_array = array;
	}

	//indirect construction from constant array
	Varray(const T *array,uint size)
	{
		_bufsize = _size = size;
		if (size)
		{
			_array = (T *)calloc(_bufsize,sizeof(T));
			_array = memcpy(_array,array,_bufsize*sizeof(T));
		}
	}

	//copy constructor
	Varray(const Varray< class T > &parray)	
	{
		_bufsize = parray._bufsize;
		_size=parray._size;
		_array = (T *)calloc(_size,sizeof(T));
		_array = memcpy(_array,parray._array,_bufsize*sizeof(T));
	}

	//destructor
	~Varray()	
	{
		if (_bufsize) 
			free(_array);
	}

	//set values from a constant array
	void Set(const T *array,uint size)
	{
		resize(size);
		memcpy(_array,array,size*sizeof(T));
	}
	//adds a new element at the end of array
	//returns the position of the new element
	uint Add(const T &p)
	{
		_size++;//increase size

		if (_bufsize)//if array allocated
		{
			if (_size>_bufsize)//if new size exceeds buffer size
			{
				_bufsize<<=1;	//buffer is doubled
				_array = (T *)realloc(_array,_bufsize*sizeof(T));
			}
		}
		else//array not yet allocated
		{
			_bufsize=_size;//init to unit
			_array = (T *)calloc(_bufsize,sizeof(T));
		}
		_array[_size-1] = p;//add element at the end
		return _size-1;
	}

	//inserts element at position pos or
	//if pos out of range in the end
	//returns position it was inserted
	uint Ins(const T &p,uint pos)
	{
		if (pos<_size)//pos within range
		{
			_size++;
			if ((_size)>_bufsize)//if new size exceeds buffer size
			{
				_bufsize<<=1;	//buffer is doubled
				_array = (T *)realloc(_array,_bufsize*sizeof(T));
			}
			memmove(_array+pos,_array+pos+1,sizeof(T)*(_size-pos-1));//shift right
			_array[pos] = p;
			return _size;
		}
		else//add in the end
			return Add(p);
	}

	//appends parray at the end of this array
	//returns the new size
	uint Append(const Varray< class T > &parray)
	{
		while(_bufsize<(_size+parray._size)) _bufsize<<=1;
		_array = (T *)realloc(_array,_bufsize*sizeof(T));
		memcpy(_array+size,parray._array,sizeof(T)*parray._size);
		_size = _size+parray._size;
		return _size;
	}

	//delete element in position
	//returns the deleted element
	T Del(uint pos)
	{
		T ret;//returned value

		if (pos<_size)//pos within range
		{
			_size--;//decrease size
			ret = _array[pos];//get victim
			if (pos<_size)//element not last
				memmove(_array+pos,_array+pos+1,sizeof(T)*(_size-pos));//shift left
			if (_size)//if size>0
			{
				if (_size<_bufsize>>1)//size less than half of buffer size
				{
					_bufsize>>=1;//halve buffer size
					_array = (T *)realloc(_array,_bufsize*sizeof(T));
				}
			}
			else//size reached zero...free all
			{	
				_size=_bufsize=0;
				free(_array);
			}
		}
		return ret;
	}

	//deletes all elements in array,if keepbuffer it does not frees it
	//returns new buffer size
	uint Delall(int keepbuffer = 1)
	{
		_size = 0;
		if (!keepbuffer)
		{
			_bufsize = 0;
			free(_array);
		}
		return _bufsize;
	}

	//resizes array to new size
	//returns new bufsize
	uint resize(uint newsize)
	{
		if (_bufsize)
			_array = (T *)realloc(_array,newsize*sizeof(T));
		else
			_array = (T *)calloc(newsize,sizeof(T));
		_bufsize =_size= newsize;
		return _bufsize;
	}

	//frees unused buffer
	uint compact(void)
	{
		_bufsize = _size;
		if (_bufsize) _array = (T *)realloc(_array,newsize*sizeof(T));
		else if (_array) free(_array);
	}

	//sorts elements according to compfunc.
	void Sort(int (*compfunc)(const void *,const void *))
	{
		qsort(_array,_size,sizeof(T),compfunc);
	}

	//returns array size.
	uint getSize(void) const {return _size;}
	//returns array buffer size
	uint getBufferSize(void) const {return _bufsize;}
	//returns the i element
	T& operator[](int i) const {return _array[i];}
	//returns the array 
	T* operator&() const {return _array;}
};

#endif // #if !defined(__VARRAY__)

