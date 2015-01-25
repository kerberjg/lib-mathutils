#ifndef PALLOC_HPP
#define PALLOC_HPP

#include "../common.h"

enum PoolExceptions {
	IllegalArgument = 10,
	PoolOverflow = 20,
	PotentialOverflow = 25
};

template<class T>
class AllocPool
{
	private:
		T* pool;
		u32 last, max;

		virtual T newObj();

	public:
		AllocPool(u32 size): last(0), max(size) {
			pool = new T[size];
		}
		virtual ~AllocPool() {
			delete pool;
		}

		void free(T obj) {
			if(last < max)
				if(obj != nullptr)
					pool[last++] = obj;
				else
					throw IllegalArgument;
			else
				throw PoolOverflow;
		}

		void free(T obj[], u32 length, u32 offset) {
			if(length > max-last)
				throw PotentialOverflow;
			for(int i=offset; i<length; i++)
				if(obj[i] != nullptr)
					pool[last++] = obj[i];
				else
					throw IllegalArgument;
		}

		T get() {
			if(last > 0)
				return pool[--last];
			else
				return newObj();
		}

		u32 count() {
			return last;
		}

		u32 size() {
			return max;
		}

		void clear() {
			for(int i=0; i<last; i++)
				delete pool[i];
			last = 0;
		};
};

#endif
