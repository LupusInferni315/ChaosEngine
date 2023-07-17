#include "ChaosEngine.h"
#include <limits>
#include <math.h>

using namespace System;
using namespace System::Diagnostics::Contracts;
using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Threading;

namespace Aurora
{
	void ThrowMinMaxException(String^ minValue, String^ maxValue, bool inclusive)
	{
		String^ comparisonOperator = inclusive ? "greater than" : "greater than or equal to";
		String^ message = String::Format("'{0}' cannot be {1} '{2}'.", minValue, comparisonOperator, maxValue);
		throw gcnew ArgumentException(message);
	}

	void ThrowBufferException(String^ bufferName)
	{
		String^ message = String::Format("'{0}' cannot be null or contain less than one element.", bufferName);
		throw gcnew ArgumentNullException(message);
	}

	void ThrowTooLowException(String^ paramName, String^ count)
  {
    String^ message = String::Format("'{0}' cannot be less than {1}.", paramName, count);
		throw gcnew ArgumentOutOfRangeException(paramName, message);
	}

	void ThrowTooLowExceptionZero(String^ paramName) { ThrowTooLowException(paramName, "zero"); }
	void ThrowTooLowExceptionOne(String^ paramName) { ThrowTooLowException(paramName, "one"); }

	void ThrowDivideByZeroException()
	{
		throw gcnew DivideByZeroException("Attempting to divide by zero.");
	}

	String^ ChaosEngine::Seed::get()
	{
		return _seed;
	}

	void ChaosEngine::Seed::set(String^ value)
	{
		Reseed(value);
	}

	ChaosEngine^ ChaosEngine::Shared::get()
	{
		if (s_Shared == nullptr)
			s_Shared = gcnew ChaosEngine();
		return s_Shared;
	}

	void ChaosEngine::Shared::set(ChaosEngine^ engine)
	{
		if (engine == nullptr)
			engine = gcnew ChaosEngine();

		s_Shared = engine;
	}

	ChaosEngine::ChaosEngine()
	{
		Reseed(nullptr);
	}

	ChaosEngine::ChaosEngine(String^ seed)
	{
		Reseed(seed);
	}

	ChaosEngine::ChaosEngine(int seed)
	{
		Reseed(seed);
	}

	void ChaosEngine::Reset()
	{
		Reseed(_seed);
	}

	void ChaosEngine::Reseed()
	{
		Reseed(nullptr);
	}

	void ChaosEngine::Reseed(String^ seed)
	{
		String^ stored;
		int state = ParseSeed(seed, stored);
		Reseed(state, stored);
	}

	void ChaosEngine::Reseed(int seed)
	{
		Reseed(seed, seed.ToString());
	}

	bool ChaosEngine::NextBoolean()
	{
		return NextInteger(0, 2) == 1;
	}

	void ChaosEngine::NextBooleans(array<bool>^% buffer)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextBoolean();
		}
	}
	//ThrowTooLowExceptionOne("count");

	IEnumerable<bool>^ ChaosEngine::NextBooleans(int count)
	{
		if (count < 1)
		{
			throw gcnew ArgumentException("'count' cannot be less than one", "count");
		}
		
		Contract::EndContractBlock();

		List<bool>^ list = gcnew List<bool>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextBoolean());
		}

		return list;
	}

	bool ChaosEngine::NextProbability(float percent)
	{
		return percent >= 1 || (percent > 0 && NextFloat() < percent);
	}

	bool ChaosEngine::NextProbability(int percent)
	{
		return percent >= 100 || (percent > 0 && NextInteger(100) < percent);
	}

	void ChaosEngine::NextProbabilities(array<bool>^% buffer, float percent)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextProbability(percent);
		}
	}

	void ChaosEngine::NextProbabilities(array<bool>^% buffer, int percent)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextProbability(percent);
		}
	}

	IEnumerable<bool>^ ChaosEngine::NextProbabilities(int count, float percent)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<bool>^ list = gcnew List<bool>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextProbability(percent));
		}

		return list;
	}

	IEnumerable<bool>^ ChaosEngine::NextProbabilities(int count, int percent)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<bool>^ list = gcnew List<bool>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextProbability(percent));
		}

		return list;
	}

	bool ChaosEngine::NextOdds(int a, int b)
	{
		return NextOdds(static_cast<float>(a), static_cast<float>(b));
	}

	void ChaosEngine::NextOdds(array<bool>^% buffer, int a, int b)
	{
		NextOdds(buffer, static_cast<float>(a), static_cast<float>(b));
	}

	IEnumerable<bool>^ ChaosEngine::NextOdds(int count, int a, int b)
	{
		return NextOdds(count, static_cast<float>(a), static_cast<float>(b));
	}

	bool ChaosEngine::NextOdds(float a, float b)
	{
		if (b == 0)
		{
			ThrowDivideByZeroException();
		}

		Contract::EndContractBlock();

		return NextProbability(a / b);
	}

	void ChaosEngine::NextOdds(array<bool>^% buffer, float a, float b)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextOdds(a, b);
		}
	}

	IEnumerable<bool>^ ChaosEngine::NextOdds(int count, float a, float b)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<bool>^ list = gcnew List<bool>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextOdds(a, b));
		}

		return list;
	}

	unsigned char ChaosEngine::NextByte()
	{
		return static_cast<unsigned char>(NextInteger(0, 256));
	}

	unsigned char ChaosEngine::NextByte(unsigned char minValue, unsigned char maxValue)
	{
		if (minValue > maxValue)
		{
			ThrowMinMaxException("minValue", "maxValue", true);
		}

		Contract::EndContractBlock();

		if (minValue == maxValue)
			return minValue;

		return static_cast<unsigned char>(NextInteger(static_cast<int>(minValue), static_cast<int>(maxValue) + 1));
	}

	unsigned char ChaosEngine::NextByte(unsigned char maxValue)
	{
		return NextByte(0, maxValue);
	}

	void ChaosEngine::NextBytes(array<unsigned char>^% buffer)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextByte();
		}
	}

	void ChaosEngine::NextBytes(array<unsigned char>^% buffer, unsigned char minValue, unsigned char maxValue)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextByte(minValue, maxValue);
		}
	}

	void ChaosEngine::NextBytes(array<unsigned char>^% buffer, unsigned char maxValue)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextByte(maxValue);
		}
	}

	IEnumerable<unsigned char>^ ChaosEngine::NextBytes(int count)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<unsigned char>^ list = gcnew List<unsigned char>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextByte());
		}

		return list;
	}

	IEnumerable<unsigned char>^ ChaosEngine::NextBytes(int count, unsigned char minValue, unsigned char maxValue)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<unsigned char>^ list = gcnew List<unsigned char>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextByte(minValue, maxValue));
		}

		return list;
	}

	IEnumerable<unsigned char>^ ChaosEngine::NextBytes(int count, unsigned char maxValue)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<unsigned char>^ list = gcnew List<unsigned char>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextByte(maxValue));
		}

		return list;
	}

	int ChaosEngine::NextInteger()
	{
		return NextSample();
	}

	int ChaosEngine::NextInteger(int minValue, int maxValue)
	{
		if (minValue >= maxValue)
		{
			ThrowMinMaxException("minValue", "maxValue", false);
		}

		Contract::EndContractBlock();

		if (minValue == maxValue - 1)
			return minValue;

		long range = maxValue - minValue;
		return static_cast<int>(NextRange(false) * range) + minValue;
	}

	int ChaosEngine::NextInteger(int maxValue)
	{
		return NextInteger(0, maxValue);
	}

	void ChaosEngine::NextIntegers(array<int>^% buffer)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextInteger();
		}
	}

	void ChaosEngine::NextIntegers(array<int>^% buffer, int minValue, int maxValue)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextInteger(minValue, maxValue);
		}
	}

	void ChaosEngine::NextIntegers(array<int>^% buffer, int maxValue)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextInteger(maxValue);
		}
	}

	IEnumerable<int>^ ChaosEngine::NextIntegers(int count)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<int>^ list = gcnew List<int>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextInteger());
		}

		return list;
	}

	IEnumerable<int>^ ChaosEngine::NextIntegers(int count, int minValue, int maxValue)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<int>^ list = gcnew List<int>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextInteger(minValue, maxValue));
		}

		return list;
	}

	IEnumerable<int>^ ChaosEngine::NextIntegers(int count, int maxValue)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<int>^ list = gcnew List<int>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextInteger(maxValue));
		}

		return list;
	}

	float ChaosEngine::NextFloat()
	{
		return NextRange(true);
	}

	float ChaosEngine::NextFloat(float minValue, float maxValue)
	{
		if (minValue > maxValue)
		{
			ThrowMinMaxException("minValue", "maxValue", true);
		}

		Contract::EndContractBlock();

		if (minValue == maxValue)
			return minValue;

		double range = maxValue - minValue;
		return static_cast<float>(static_cast<double>(NextFloat() * range)) + minValue;
	}

	float ChaosEngine::NextFloat(float maxValue)
	{
		return NextFloat(0, maxValue);
	}

	void ChaosEngine::NextFloats(array<float>^% buffer)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextFloat();
		}
	}

	void ChaosEngine::NextFloats(array<float>^% buffer, float minValue, float maxValue)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextFloat(minValue, maxValue);
		}
	}

	void ChaosEngine::NextFloats(array<float>^% buffer, float maxValue)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextFloat(maxValue);
		}
	}

	IEnumerable<float>^ ChaosEngine::NextFloats(int count)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<float>^ list = gcnew List<float>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextFloat());
		}

		return list;
	}

	IEnumerable<float>^ ChaosEngine::NextFloats(int count, float minValue, float maxValue)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<float>^ list = gcnew List<float>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextFloat(minValue, maxValue));
		}

		return list;
	}

	IEnumerable<float>^ ChaosEngine::NextFloats(int count, float maxValue)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<float>^ list = gcnew List<float>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextFloat(maxValue));
		}

		return list;
	}

	generic <typename T>
	void ChaosEngine::Shuffle(IList<T>^% list)
	{
		if (list == nullptr || list->Count < 1)
		{
			ThrowBufferException("list");
		}

		Contract::EndContractBlock();

		int n = list->Count;

		while (n > 1)
		{
			n--;
			int k = NextInteger(n + 1);

			T temp = list[n];
			list[n] = list[k];
			list[k] = temp;
		}
	}

	generic <typename T>
	void ChaosEngine::Shuffle(array<T>^% array)
	{
		if (array == nullptr || array->Length < 1)
		{
			ThrowBufferException("array");
		}

		Contract::EndContractBlock();

		int n = array->Length;

		while (n > 1)
		{
			n--;
			int k = NextInteger(n + 1);

			T temp = array[n];
			array[n] = array[k];
			array[k] = temp;
		}
	}

	generic <typename T>
	T ChaosEngine::Choose(IEnumerable<T>^ collection)
	{
		if (collection == nullptr || Enumerable::Count(collection) < 1)
		{
			ThrowBufferException("collection");
		}

		Contract::EndContractBlock();

		Type^ weightedType = IWeighted::typeid;
		Type^ genericType = T::typeid;

		if (weightedType->IsAssignableFrom(genericType))
		{
			List<T>^ newList = gcnew List<T>();

			for each (T t in collection)
			{
				IWeighted^ weightedItem = reinterpret_cast<IWeighted^>(t);

				for (int i = 0; i < weightedItem->Weight; i++)
				{
					newList->Add(t);
				}
			}

			return newList[NextInteger(newList->Count)];
		}

		return Enumerable::ElementAt(collection, NextInteger(Enumerable::Count(collection)));
	}

	generic <typename T>
	void ChaosEngine::Choose(array<T>^% buffer, IEnumerable<T>^ collection)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = Choose(collection);
		}
	}

	generic <typename T>
	IEnumerable<T>^ ChaosEngine::Choose(int count, IEnumerable<T>^ collection)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<T>^ list = gcnew List<T>();

		for (int i = 0; i < count; i++)
		{
			list->Add(Choose(collection));
		}

		return list;
	}

	generic <typename T>
	T ChaosEngine::Choose(IEnumerable<IWeightedObject<T>^>^ collection)
	{
		if (collection == nullptr || Enumerable::Count(collection) < 1)
		{
			ThrowBufferException("collection");
		}

		Contract::EndContractBlock();

		List<T>^ newList = gcnew List<T>();

		for each (IWeightedObject<T> ^ t in collection)
		{

			for (int i = 0; i < t->Weight; i++)
			{
				newList->Add(t->Value);
			}
		}

		return newList[NextInteger(newList->Count)];
	}

	generic <typename T>
	void ChaosEngine::Choose(array<T>^% buffer, IEnumerable<IWeightedObject<T>^>^ collection) {
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = Choose(collection);
		}
	}

	generic <typename T>
	IEnumerable<T>^ ChaosEngine::Choose(int count, IEnumerable<IWeightedObject<T>^>^ collection)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<T>^ list = gcnew List<T>();

		for (int i = 0; i < count; i++)
		{
			list->Add(Choose(collection));
		}

		return list;
	}

	generic <typename T> where T : Enum
		T ChaosEngine::NextEnum()
	{
		return safe_cast<T>(Enum::ToObject(T::typeid, 0));
	}

	generic <typename T> where T : Enum
		void ChaosEngine::NextEnum(array<T>^% buffer)
	{
		if (buffer == nullptr || buffer->Length < 1)
		{
			ThrowBufferException("buffer");
		}

		Contract::EndContractBlock();

		for (int i = 0; i < buffer->Length; i++)
		{
			buffer[i] = NextEnum<T>();
		}
	}

	generic <typename T> where T : Enum
		IEnumerable<T>^ ChaosEngine::NextEnum(int count)
	{
		if (count < 1)
		{
			ThrowTooLowExceptionOne("count");
		}

		Contract::EndContractBlock();

		List<T>^ list = gcnew List<T>();

		for (int i = 0; i < count; i++)
		{
			list->Add(NextEnum<T>());
		}

		return list;
	}

	int ChaosEngine::ParseSeed(String^ seed, String^% storedValue)
	{
		int value;
		if (String::IsNullOrEmpty(seed))
		{
			value = Guid::NewGuid().GetHashCode();
			storedValue = value.ToString();
			return value;
		}
		else if (Int32::TryParse(seed, value))
		{
			storedValue = seed;
		}
		else
		{
			value = seed->GetHashCode();
			storedValue = seed;
		}

		return value;
	}

	void ChaosEngine::Reseed(int seed, String^ stored)
	{
		Monitor::Enter(_stateLock);

		_seed = stored;

		int subtraction = seed == std::numeric_limits<int>::min() ? std::numeric_limits<int>::max() : abs(seed);
		int mj = SEED - subtraction;
		_seedArray[54] = mj;
		int mk = 1;

		for (int i = 0; i < 54; i++)
		{
			int ii = (42 * (i + 1) % 55) - 1;
			_seedArray[ii] = mk;
			mk = mj - mk;

			if (mk < 0)
			{
				mk += std::numeric_limits<int>::max();
			}

			mj = _seedArray[ii];
		}

		for (int k = 1; k < 5; k++)
		{
			for (int i = 0; i < 55; i++)
			{
				_seedArray[i] -= _seedArray[(i + 30) % 55];

				if (_seedArray[i] < 0)
				{
					_seedArray[i] += std::numeric_limits<int>::max();
				}
			}
		}

		_iNext = 0;
		_iNextP = 42;

		Monitor::Exit(_stateLock);
	}

	int ChaosEngine::NextSample()
	{
		Monitor::Enter(_stateLock);

		int retVal = _seedArray[_iNext] - _seedArray[_iNextP];

		if (retVal == std::numeric_limits<int>::max())
		{
			retVal--;
		}

		if (retVal < 0)
		{
			retVal = std::numeric_limits<int>::max();
		}

		_seedArray[_iNext] = retVal;

		if (++_iNext >= 55)
		{
			_iNext = 0;
		}

		if (++_iNextP >= 55)
		{
			_iNextP = 0;
		}


		Monitor::Exit(_stateLock);

		return retVal;
	}

	float ChaosEngine::NextRange(bool inclusive)
	{
		int sample = NextSample();
		int max = std::numeric_limits<int>::max();

		if (inclusive)
			max -= 1;

		return sample * (1.0f / max);
	}
}
