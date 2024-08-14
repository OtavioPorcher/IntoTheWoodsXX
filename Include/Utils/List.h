#pragma once

#include <iostream>
#include <stdlib.h>

namespace Utils
{

	template <class TYPE>
	class List
	{
	public:

		template<class ETYPE>
		class Element
		{
		private:
			ETYPE* pData;
			Element<ETYPE>* pNext;
			Element<ETYPE>* pPrev;
			const unsigned int id;
		public:
			Element(ETYPE* dI = NULL, const unsigned int i = -1) : pData(dI), pNext(NULL), pPrev(NULL), id(i)  {	}
			~Element()
			{
				if (pData)
					delete pData;
				pData = NULL;
			}

			ETYPE* getData() { return pData; }
			Element<ETYPE>* getNext(){ return pNext; }
			Element<ETYPE>* getPrev(){ return pPrev; }

			void setData(ETYPE* d) { pData = d; }
			void setNext(Element<ETYPE>* n) { pNext = n; }
			void setPrev(Element<ETYPE>* p) { pPrev = p; }
		};
		template<class ITYPE>
		class Iterator
		{
		private:
			Element<ITYPE>* pE;

		public:
			Iterator(Element<ITYPE>* pe = NULL) : pE(pe) {	}
			~Iterator() {	}
			Iterator& operator++()
			{
				pE = pE->getNext();
				return *this;
			}
			Iterator& operator+=(int num)
			{
				int i;
				for (i = 0; i < num; i++)
					pE = pE->getNext();
				return *this;
			}
			Iterator& operator--()
			{
				pE = pE->getPrev();
				return *this;
			}
			Iterator& operator-=(int num)
			{
				int i;
				for (i = 0; i < num; i++)
					pE = pE->getPrev();
				return *this;
			}
			bool operator==(Element<ITYPE>* pE2)const { return pE == pE2; }
			bool operator!=(Element<ITYPE>* pE2)const { return !(pE == pE2); }
			void operator= (Element<ITYPE>* pE2) { pE = pE2; }
			ITYPE* operator*() { return pE->getData; }
			Element<ITYPE>* getElement() { return pE; }
		};
	
		private:
			Element<TYPE>* pFirst;
			Element<TYPE>* pLast;
			unsigned int size;

			void insert(TYPE* dI, const bool optionIndex) /* InsertFront: optionIndex == 1 | InsertBack: optionIndex == 0 */
			{
				if (!dI)
				{
					std::cout << "ERROR: Unable to insert a NULL pointer to the List" << std::endl;
					return;
				}
				Element<TYPE>* aux = new Element<TYPE>(dI, size);
				if (!aux)
				{
					std::cout << "ERROR: Unable to allocate memory" << std::endl;
					return;
				}
				size++;
				if (optionIndex) // InsertFront
				{

					if (pFirst)
					{
						aux->setNext(pFirst);
						pFirst->setPrev(aux);
					}
					else
						pLast = aux;
					pFirst = aux;

					return;
				}
				if (!optionIndex)
				{
					if (pFirst)
					{
						aux->setPrev(pLast);
						pLast->setNext(aux);
					}
					else
						pFirst = aux;
					pLast = aux;

					return;
				}
			}

		public:
			List() : pFirst(NULL), pLast(NULL), size(0) {		}
			~List()
			{
				if (empty())
					return;
				Element<TYPE>* pAux = NULL;
				int size_aux = size;
				while(pFirst!=NULL)
				{
					pAux = pFirst;
					remove(0);
				}
				pFirst = NULL;
				pLast = NULL;
			}

			void insertFront(TYPE* dI) { insert(dI, true); }
			void insertBack(TYPE* dI) { insert(dI, false); }
			
			Element<TYPE>* runThrough(int index)
			{
				if (index < 0 || index > size)
				{
					std::cout << "ERROR: List Segmentation Fault" << std::endl;
					exit(1);
				}
				Element<TYPE>* pAux = pFirst;
				if (!pAux)
				{
					std::cout << "ERROR: NULL Pointer List Index";
					exit(1);
				}
				for (int i = 0; i < index; i++)
				{
					pAux = pAux->getNext();
				}
				return pAux;
			}
			TYPE* operator[](int index)
			{
				return *runThrough(index);
			}

			void remove(unsigned int index)
			{
				if (index >= size)
				{
					std::cout << "ERROR: Segmentation fault" << std::endl;
						return;
				}
				Element<TYPE>* pAux = runThrough(index);
				Element<TYPE>* pPrevAux = pAux->getPrev();

				if (!pAux)
				{
					std::cout << "ERROR: Can't remove a NULL element" << std::endl;
						return;
				}
				if (pAux == pLast)
					pLast = pPrevAux;
				if(pAux == pFirst)
					pFirst = pAux->getNext();
				pPrevAux->setNext(pAux->getNext());

				pAux = NULL;
				pPrevAux = NULL;
				size--;
			}

				const bool empty()const { return(size == 0 ? true : false); }
				const unsigned int getSize()const { return size; }


			};
		}
	