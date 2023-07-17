#pragma once

#include "IWeightedObject.h"

namespace Aurora
{
	/// <summary>
	/// Represents a chaos engine for generating random numbers and performing random operations.
	/// </summary>
	[System::Serializable]
	public ref class ChaosEngine sealed
	{
	public:
		/// <summary>
		/// Gets or sets the seed used by the chaos engine.
		/// </summary>
		property System::String^ Seed { System::String^ get(); void set(System::String^ value); }

		/// <summary>
		/// Gets or sets the shared instance of the chaos engine.
		/// </summary>
		static property ChaosEngine^ Shared { ChaosEngine^ get(); void set(ChaosEngine^ engine); }

		/// <summary>
		/// Initializes a new instance of the ChaosEngine class with the default seed.
		/// </summary>
		ChaosEngine();

		/// <summary>
		/// Initializes a new instance of the ChaosEngine class with the specified seed as a string.
		/// </summary>
		/// <param name="seed">The seed value as a string.</param>
		ChaosEngine(System::String^ seed);

		/// <summary>
		/// Initializes a new instance of the ChaosEngine class with the specified seed as an integer.
		/// </summary>
		/// <param name="seed">The seed value as an integer.</param>
		ChaosEngine(int seed);

		/// <summary>
		/// Resets the chaos engine to its initial state.
		/// </summary>
		void Reset();

		/// <summary>
		/// Reseeds the chaos engine with a new random seed.
		/// </summary>
		void Reseed();

		/// <summary>
		/// Reseeds the chaos engine with the specified seed as a string.
		/// </summary>
		/// <param name="seed">The seed value as a string.</param>
		void Reseed(System::String^ seed);

		/// <summary>
		/// Reseeds the chaos engine with the specified seed as an integer.
		/// </summary>
		/// <param name="seed">The seed value as an integer.</param>
		void Reseed(int seed);

		/// <summary>
		/// Generates the next random boolean value.
		/// </summary>
		/// <returns>A random boolean value.</returns>
		bool NextBoolean();

		/// <summary>
		/// Generates the next random boolean values and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random boolean values.</param>
		void NextBooleans(array<bool>^% buffer);

		/// <summary>
		/// Generates the specified number of random boolean values.
		/// </summary>
		/// <param name="count">The number of random boolean values to generate.</param>
		/// <returns>An enumerable collection of random boolean values.</returns>
		System::Collections::Generic::IEnumerable<bool>^ NextBooleans(int count);

		/// <summary>
		/// Generates a random boolean value based on the specified probability in percentage.
		/// </summary>
		/// <param name="percent">The probability value in percentage (0-100).</param>
		/// <returns>A random boolean value based on the specified probability.</returns>
		bool NextProbability(float percent);

		/// <summary>
		/// Generates a random boolean value based on the specified probability in percentage.
		/// </summary>
		/// <param name="percent">The probability value in percentage (0-100).</param>
		/// <returns>A random boolean value based on the specified probability.</returns>
		bool NextProbability(int percent);

		/// <summary>
		/// Generates the next random boolean values based on the specified probability in percentage and stores them in the buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random boolean values.</param>
		/// <param name="percent">The probability value in percentage (0-100).</param>
		void NextProbabilities(array<bool>^% buffer, float percent);

		/// <summary>
		/// Generates the next random boolean values based on the specified probability in percentage and stores them in the buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random boolean values.</param>
		/// <param name="percent">The probability value in percentage (0-100).</param>
		void NextProbabilities(array<bool>^% buffer, int percent);

		/// <summary>
		/// Generates the specified number of random boolean values based on the specified probability in percentage.
		/// </summary>
		/// <param name="count">The number of random boolean values to generate.</param>
		/// <param name="percent">The probability value in percentage (0-100).</param>
		/// <returns>An enumerable collection of random boolean values based on the specified probability.</returns>
		System::Collections::Generic::IEnumerable<bool>^ NextProbabilities(int count, float percent);

		/// <summary>
		/// Generates the specified number of random boolean values based on the specified probability in percentage.
		/// </summary>
		/// <param name="count">The number of random boolean values to generate.</param>
		/// <param name="percent">The probability value in percentage (0-100).</param>
		/// <returns>An enumerable collection of random boolean values based on the specified probability.</returns>
		System::Collections::Generic::IEnumerable<bool>^ NextProbabilities(int count, int percent);

		/// <summary>
		/// Generates a random boolean value based on the specified odds.
		/// </summary>
		/// <param name="a">The numerator of the odds.</param>
		/// <param name="b">The denominator of the odds.</param>
		/// <returns>A random boolean value based on the specified odds.</returns>
		bool NextOdds(int a, int b);

		/// <summary>
		/// Generates the next random boolean values based on the specified odds and stores them in the buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random boolean values.</param>
		/// <param name="a">The numerator of the odds.</param>
		/// <param name="b">The denominator of the odds.</param>
		void NextOdds(array<bool>^% buffer, int a, int b);

		/// <summary>
		/// Generates the specified number of random boolean values based on the specified odds.
		/// </summary>
		/// <param name="count">The number of random boolean values to generate.</param>
		/// <param name="a">The numerator of the odds.</param>
		/// <param name="b">The denominator of the odds.</param>
		/// <returns>An enumerable collection of random boolean values based on the specified odds.</returns>
		System::Collections::Generic::IEnumerable<bool>^ NextOdds(int count, int a, int b);

		/// <summary>
		/// Generates a random boolean value based on the specified odds.
		/// </summary>
		/// <param name="a">The numerator of the odds.</param>
		/// <param name="b">The denominator of the odds.</param>
		/// <returns>A random boolean value based on the specified odds.</returns>
		bool NextOdds(float a, float b);

		/// <summary>
		/// Generates the next random boolean values based on the specified odds and stores them in the buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random boolean values.</param>
		/// <param name="a">The numerator of the odds.</param>
		/// <param name="b">The denominator of the odds.</param>
		void NextOdds(array<bool>^% buffer, float a, float b);

		/// <summary>
		/// Generates the specified number of random boolean values based on the specified odds.
		/// </summary>
		/// <param name="count">The number of random boolean values to generate.</param>
		/// <param name="a">The numerator of the odds.</param>
		/// <param name="b">The denominator of the odds.</param>
		/// <returns>An enumerable collection of random boolean values based on the specified odds.</returns>
		System::Collections::Generic::IEnumerable<bool>^ NextOdds(int count, float a, float b);

		/// <summary>
		/// Generates the next random byte value.
		/// </summary>
		/// <returns>A random byte value.</returns>
		unsigned char NextByte();

		/// <summary>
		/// Generates the next random byte value within the specified range.
		/// </summary>
		/// <param name="minValue">The minimum value of the random byte (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random byte (inclusive).</param>
		/// <returns>A random byte value within the specified range.</returns>
		unsigned char NextByte(unsigned char minValue, unsigned char maxValue);

		/// <summary>
		/// Generates the next random byte value within the specified range.
		/// </summary>
		/// <param name="maxValue">The maximum value of the random byte (inclusive).</param>
		/// <returns>A random byte value within the specified range.</returns>
		unsigned char NextByte(unsigned char maxValue);

		/// <summary>
		/// Generates the next random byte values and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random byte values.</param>
		void NextBytes(array<unsigned char>^% buffer);

		/// <summary>
		/// Generates the next random byte values within the specified range and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random byte values.</param>
		/// <param name="minValue">The minimum value of the random byte (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random byte (inclusive).</param>
		void NextBytes(array<unsigned char>^% buffer, unsigned char minValue, unsigned char maxValue);

		/// <summary>
		/// Generates the next random byte values within the specified range and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random byte values.</param>
		/// <param name="maxValue">The maximum value of the random byte (inclusive).</param>
		void NextBytes(array<unsigned char>^% buffer, unsigned char maxValue);

		/// <summary>
		/// Generates the specified number of random byte values.
		/// </summary>
		/// <param name="count">The number of random byte values to generate.</param>
		/// <returns>An enumerable collection of random byte values.</returns>
		System::Collections::Generic::IEnumerable<unsigned char>^ NextBytes(int count);

		/// <summary>
		/// Generates the specified number of random byte values within the specified range.
		/// </summary>
		/// <param name="count">The number of random byte values to generate.</param>
		/// <param name="minValue">The minimum value of the random byte (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random byte (inclusive).</param>
		/// <returns>An enumerable collection of random byte values within the specified range.</returns>
		System::Collections::Generic::IEnumerable<unsigned char>^ NextBytes(int count, unsigned char minValue, unsigned char maxValue);

		/// <summary>
		/// Generates the specified number of random byte values within the specified range.
		/// </summary>
		/// <param name="count">The number of random byte values to generate.</param>
		/// <param name="maxValue">The maximum value of the random byte (inclusive).</param>
		/// <returns>An enumerable collection of random byte values within the specified range.</returns>
		System::Collections::Generic::IEnumerable<unsigned char>^ NextBytes(int count, unsigned char maxValue);

		/// <summary>
		/// Generates the next random integer value.
		/// </summary>
		/// <returns>A random integer value.</returns>
		int NextInteger();

		/// <summary>
		/// Generates the next random integer value within the specified range.
		/// </summary>
		/// <param name="minValue">The minimum value of the random integer (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random integer (exclusive).</param>
		/// <returns>A random integer value within the specified range.</returns>
		int NextInteger(int minValue, int maxValue);

		/// <summary>
		/// Generates the next random integer value within the specified range.
		/// </summary>
		/// <param name="maxValue">The maximum value of the random integer (exclusive).</param>
		/// <returns>A random integer value within the specified range.</returns>
		int NextInteger(int maxValue);

		/// <summary>
		/// Generates the next random integer values and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random integer values.</param>
		void NextIntegers(array<int>^% buffer);

		/// <summary>
		/// Generates the next random integer values within the specified range and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random integer values.</param>
		/// <param name="minValue">The minimum value of the random integer (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random integer (exclusive).</param>
		void NextIntegers(array<int>^% buffer, int minValue, int maxValue);

		/// <summary>
		/// Generates the next random integer values within the specified range and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random integer values.</param>
		/// <param name="maxValue">The maximum value of the random integer (exclusive).</param>
		void NextIntegers(array<int>^% buffer, int maxValue);

		/// <summary>
		/// Generates the specified number of random integer values.
		/// </summary>
		/// <param name="count">The number of random integer values to generate.</param>
		/// <returns>An enumerable collection of random integer values.</returns>
		System::Collections::Generic::IEnumerable<int>^ NextIntegers(int count);

		/// <summary>
		/// Generates the specified number of random integer values within the specified range.
		/// </summary>
		/// <param name="count">The number of random integer values to generate.</param>
		/// <param name="minValue">The minimum value of the random integer (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random integer (exclusive).</param>
		/// <returns>An enumerable collection of random integer values within the specified range.</returns>
		System::Collections::Generic::IEnumerable<int>^ NextIntegers(int count, int minValue, int maxValue);

		/// <summary>
		/// Generates the specified number of random integer values within the specified range.
		/// </summary>
		/// <param name="count">The number of random integer values to generate.</param>
		/// <param name="maxValue">The maximum value of the random integer (exclusive).</param>
		/// <returns>An enumerable collection of random integer values within the specified range.</returns>
		System::Collections::Generic::IEnumerable<int>^ NextIntegers(int count, int maxValue);

		/// <summary>
		/// Generates the next random float value between 0.0 (inclusive) and 1.0 (exclusive).
		/// </summary>
		/// <returns>A random float value.</returns>
		float NextFloat();

		/// <summary>
		/// Generates the next random float value within the specified range.
		/// </summary>
		/// <param name="minValue">The minimum value of the random float (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random float (exclusive).</param>
		/// <returns>A random float value within the specified range.</returns>
		float NextFloat(float minValue, float maxValue);

		/// <summary>
		/// Generates the next random float value within the specified range.
		/// </summary>
		/// <param name="maxValue">The maximum value of the random float (exclusive).</param>
		/// <returns>A random float value within the specified range.</returns>
		float NextFloat(float maxValue);

		/// <summary>
		/// Generates the next random float values and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random float values.</param>
		void NextFloats(array<float>^% buffer);

		/// <summary>
		/// Generates the next random float values within the specified range and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random float values.</param>
		/// <param name="minValue">The minimum value of the random float (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random float (exclusive).</param>
		void NextFloats(array<float>^% buffer, float minValue, float maxValue);

		/// <summary>
		/// Generates the next random float values within the specified range and stores them in the specified buffer.
		/// </summary>
		/// <param name="buffer">The buffer to store the random float values.</param>
		/// <param name="maxValue">The maximum value of the random float (exclusive).</param>
		void NextFloats(array<float>^% buffer, float maxValue);

		/// <summary>
		/// Generates the specified number of random float values.
		/// </summary>
		/// <param name="count">The number of random float values to generate.</param>
		/// <returns>An enumerable collection of random float values.</returns>
		System::Collections::Generic::IEnumerable<float>^ NextFloats(int count);

		/// <summary>
		/// Generates the specified number of random float values within the specified range.
		/// </summary>
		/// <param name="count">The number of random float values to generate.</param>
		/// <param name="minValue">The minimum value of the random float (inclusive).</param>
		/// <param name="maxValue">The maximum value of the random float (exclusive).</param>
		/// <returns>An enumerable collection of random float values within the specified range.</returns>
		System::Collections::Generic::IEnumerable<float>^ NextFloats(int count, float minValue, float maxValue);

		/// <summary>
		/// Generates the specified number of random float values within the specified range.
		/// </summary>
		/// <param name="count">The number of random float values to generate.</param>
		/// <param name="maxValue">The maximum value of the random float (exclusive).</param>
		/// <returns>An enumerable collection of random float values within the specified range.</returns>
		System::Collections::Generic::IEnumerable<float>^ NextFloats(int count, float maxValue);

		/// <summary>
		/// Shuffles the elements in the specified list.
		/// </summary>
		/// <typeparam name="T">The type of elements in the list.</typeparam>
		/// <param name="list">The list to be shuffled.</param>
		generic <typename T>
		void Shuffle(System::Collections::Generic::IList<T>^% list);

		/// <summary>
		/// Shuffles the elements in the specified array.
		/// </summary>
		/// <typeparam name="T">The type of elements in the array.</typeparam>
		/// <param name="array">The array to be shuffled.</param>
		generic <typename T>
		void Shuffle(array<T>^% array);

		/// <summary>
		/// Chooses a random element from the specified collection.
		/// If 'T' implements IWeighted, the 'Weights' of the elements will be used when selecting a value.
		/// </summary>
		/// <typeparam name="T">The type of elements in the collection.</typeparam>
		/// <param name="collection">The collection to choose from.</param>
		/// <returns>A randomly chosen element from the collection.</returns>
		generic <typename T>
		T Choose(System::Collections::Generic::IEnumerable<T>^ collection);

		/// <summary>
		/// Chooses random elements from the specified collection and stores them in the buffer.
		/// If 'T' implements IWeighted, the 'Weights' of the elements will be used when selecting values.
		/// </summary>
		/// <typeparam name="T">The type of elements in the collection.</typeparam>
		/// <param name="buffer">The buffer to store the randomly chosen elements.</param>
		/// <param name="collection">The collection to choose from.</param>
		generic <typename T>
		void Choose(array<T>^% buffer, System::Collections::Generic::IEnumerable<T>^ collection);

		/// <summary>
		/// Chooses a specified number of random elements from the specified collection.
		/// If 'T' implements IWeighted, the 'Weights' of the elements will be used when selecting values.
		/// </summary>
		/// <typeparam name="T">The type of elements in the collection.</typeparam>
		/// <param name="count">The number of elements to choose.</param>
		/// <param name="collection">The collection to choose from.</param>
		/// <returns>An enumerable collection of randomly chosen elements from the collection.</returns>
		generic <typename T>
		System::Collections::Generic::IEnumerable<T>^ Choose(int count, System::Collections::Generic::IEnumerable<T>^ collection);

		/// <summary>
		/// Chooses a random element from the specified weighted collection.
		/// </summary>
		/// <typeparam name="T">The type of elements in the weighted collection.</typeparam>
		/// <param name="collection">The weighted collection to choose from.</param>
		/// <returns>A randomly chosen element from the weighted collection.</returns>
		generic <typename T>
		T Choose(System::Collections::Generic::IEnumerable<IWeightedObject<T>^>^ collection);

		/// <summary>
		/// Chooses random elements from the specified weighted collection and stores them in the buffer.
		/// </summary>
		/// <typeparam name="T">The type of elements in the weighted collection.</typeparam>
		/// <param name="buffer">The buffer to store the randomly chosen elements.</param>
		/// <param name="collection">The weighted collection to choose from.</param>
		generic <typename T>
		void Choose(array<T>^% buffer, System::Collections::Generic::IEnumerable<IWeightedObject<T>^>^ collection);

		/// <summary>
		/// Chooses a specified number of random elements from the specified weighted collection.
		/// </summary>
		/// <typeparam name="T">The type of elements in the weighted collection.</typeparam>
		/// <param name="count">The number of elements to choose.</param>
		/// <param name="collection">The weighted collection to choose from.</param>
		/// <returns>An enumerable collection of randomly chosen elements from the weighted collection.</returns>
		generic <typename T>
		System::Collections::Generic::IEnumerable<T>^ Choose(int count, System::Collections::Generic::IEnumerable<IWeightedObject<T>^>^ collection);

		/// <summary>
		/// Generates the next random enum value of the specified type.
		/// If a value in the enum has the 'Weighted' attribute that weight will be used when selecting a value.
		/// If it does not have the attribute the weight is treated as 1.
		/// </summary>
		/// <typeparam name="T">The type of the enum.</typeparam>
		/// <returns>A random enum value of the specified type.</returns>
		generic <typename T> where T : System::Enum
			T NextEnum();

		/// <summary>
		/// Generates the next random enum value of the specified type and stores it in the buffer.
		/// If a value in the enum has the 'Weighted' attribute that weight will be used when selecting values.
		/// If it does not have the attribute the weight is treated as 1.
		/// </summary>
		/// <typeparam name="T">The type of the enum.</typeparam>
		/// <param name="buffer">The buffer to store the random enum value.</param>
		/// <returns>The randomly generated enum value of the specified type.</returns>
		generic <typename T> where T : System::Enum
			void NextEnum(array<T>^% buffer);

		/// <summary>
		/// Generates the specified number of random enum values of the specified type.
		/// If a value in the enum has the 'Weighted' attribute that weight will be used when selecting values.
		/// If it does not have the attribute the weight is treated as 1.
		/// </summary>
		/// <typeparam name="T">The type of the enum.</typeparam>
		/// <param name="count">The number of random enum values to generate.</param>
		/// <returns>An enumerable collection of random enum values of the specified type.</returns>
		generic <typename T> where T : System::Enum
			System::Collections::Generic::IEnumerable<T>^ NextEnum(int count);

	private:
		/// <summary>
		/// The internal seed value.
		/// There is nothing 'default' about it, this value is one of the 'variables' that separates the ChaosEngine from other Instantiable Randomness Generators, that use the same algorithm
		/// </summary>
		static const int SEED = 0xBADDAD;

		/// <summary>
		/// The seed used by the chaos engine.
		/// </summary>
		System::String^ _seed;

		/// <summary>
		/// The index of the next random number.
		/// </summary>
		int _iNext;

		/// <summary>
		/// The index of the next random number for probability calculation.
		/// </summary>
		int _iNextP;

		/// <summary>
		/// The array to store the seed values.
		/// </summary>
		array<int>^ _seedArray = gcnew array<int>(55);

		/// <summary>
		/// Object used for locking the state during concurrent access.
		/// </summary>
		System::Object^ _stateLock = gcnew System::Object();

		/// <summary>
		/// The shared instance of the chaos engine.
		/// </summary>
		static ChaosEngine^ s_Shared;

		/// <summary>
		/// Parses the seed value and retrieves the stored value.
		/// </summary>
		/// <param name="seed">The seed value.</param>
		/// <param name="storedValue">The stored value extracted from the seed.</param>
		/// <returns>The parsed seed value.</returns>
		static int ParseSeed(System::String^ seed, [System::Runtime::InteropServices::Out] System::String^% storedValue);

		/// <summary>
		/// Reseeds the chaos engine with the specified seed as an integer and stored value.
		/// </summary>
		/// <param name="seed">The seed value as an integer.</param>
		/// <param name="stored">The stored value extracted from the seed.</param>
		void Reseed(int seed, System::String^ stored);

		/// <summary>
		/// Generates the next random sample.
		/// </summary>
		/// <returns>A random sample.</returns>
		int NextSample();

		/// <summary>
		/// Generates the next random float value within the range [0, 1) or [0, 1].
		/// </summary>
		/// <param name="inclusive">Specifies whether the maximum value is inclusive.</param>
		/// <returns>A random float value within the specified range.</returns>
		float NextRange(bool inclusive);
	};
}
