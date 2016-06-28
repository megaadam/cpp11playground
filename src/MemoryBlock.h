#ifndef MEMORYBLOCK_H_
#define MEMORYBLOCK_H_

#include <iostream>
#include <iomanip>
#include <algorithm>

#ifdef _WIN32
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif
#define FUNC std::setw(64) << __PRETTY_FUNCTION__ << "   | "

class MemoryBlock
{
public:
   // Simple constructor
   explicit MemoryBlock(size_t length): m_size(length), m_pData(new int[length])
   {
      std::cout << FUNC << "Allocate: " << m_size << " bytes" << std::endl;
   }

   // Destructor
   ~MemoryBlock()
   {
	  std::cout << FUNC;

      if (m_pData != nullptr)
      {
         delete[] m_pData;
      }

      std::cout << "Free: " << m_size << " bytes" << std::endl;
   }

   // Copy constructor
   MemoryBlock(const MemoryBlock& other): m_size(other.m_size), m_pData(new int[other.m_size])
   {
	  std::cout << FUNC << "Copy: " << m_size << " bytes" << std::endl;

      std::copy(other.m_pData, other.m_pData + m_size, m_pData);
   }

   // Copy assignment operator
   MemoryBlock& operator=(const MemoryBlock& other)
   {
	  std::cout << FUNC  << "Copy: " << m_size << " bytes" << std::endl;

      if (this != &other)
      {
         // Free the existing resource
         delete[] m_pData;

         m_size = other.m_size;
         m_pData = new int[m_size];
         std::copy(other.m_pData, other.m_pData + m_size, m_pData);
      }
      return *this;
   }

//#define cpp11
#ifdef cpp11
   // NEW: Move constructor
   MemoryBlock(MemoryBlock&& other) noexcept: m_pData(nullptr), m_size(0)
   {
	   std::cout << FUNC  << "NEW: Don't copy: " << other.m_size << " bytes" << std::endl;

	   m_pData = other.m_pData;
	   m_size = other.m_size;

	   other.m_pData = nullptr;
	   other.m_size = 0;
   }

   // NEW: Move assignment operator
   MemoryBlock& operator=(MemoryBlock&& other) noexcept
   {
	   std::cout << FUNC << "Don't copy: " << other.m_size << " bytes" << std::endl;

	   if(this != &other)
	   {
		   // Free the existing resource.
		   delete[] m_pData;

		   // Copy the data pointer and its length from the
		   // source object.
		   m_pData = other.m_pData;
		   m_size = other.m_size;

		   // Release the data pointer from the source object so that
		   // the destructor does not free the memory multiple times.
		   other.m_pData = nullptr;
		   other.m_size = 0;
	   }
	   return *this;
   }
#endif

   // Retrieves the length of the data resource.
   size_t Length() const
   {
      return m_size;
   }

private:
   size_t m_size; // The length of the resource.
   int* m_pData; // The resource.

};

#endif
