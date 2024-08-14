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
			Element(ETYPE* dI = NULL, const unsigned int i) : pData(dI), pNext(NULL), pPrev(NULL), id(i) : {	}
			~Element()
			{
				if (pData)
					delete pData;
				pData = NULL;
			}

			ETYPE* getData() { return pData; }
			Element<ETYPE>* getNext{ return pNext; }
			Element<ETYPE>* getPrev{ return pPrev; }

			void setData(ETYPE* d) { pData = e; }
			void setNext(Element<ETYPE>* n) { pNext = n; }
			void setPrev(Element<ETYPE>* p) { pPrev = p; }
		};
		template<class ITYPE>
		class Iterator
		{
		private:
			Element<ITYPE>* pE

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
			ITYPE* operator*() { return pE->getData }
			Element<ITYPE>* getElement() { return pE }
		};
		template <class LTYPE>
		class List
		{
		private:
			Element<LTYPE>* pFirst;
			Element<LTYPE>* pLast;
			unsigned int size;

			void insert(LTYPE* dI, const bool optionIndex) /* InsertFront: optionIndex == 1 | InsertBack: optionIndex == 0 */
			{
				if !(dI)
				{
					std::cout << "ERROR: Unable to insert a NULL pointer to the List" << std::endl;
					return;
				}
				Element<LTYPE>* aux = new Element<LTYPE>(dI, size);
				if !(aux)
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
				if !(optionIndex)
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
				this->clear();
				pFirst = NULL;
				pLast = NULL;
			}

			void insertFront(LTYPE* dI) { insert(dI, true); }
			void insertBack(LTYPE* dI) { insert(dI, false); }

			LTYPE* operator[](int i)
			{
				if (idx < 0 || idx > size)
				{
					std::cout << "ERROR: List Segmentation Fault" << std::endl;
					exit(1);
				}
				Element<T>* pAux = pFirst;
				if (!pAux)
				{
					std::cout << "ERROR: NULL Pointer List Index";
					exit(1);
				}
				for (int i = 0; i < idx; i++)
				{
					pAux = pAux->next;
				}
				return pAux->data;
			}

			void remove(int index)
			{
				if (index >= size)
				{
					cout << "ERROR: Segmentation fault"
						return;
				}
				Element<LTYPE>* pAux = operator[](index);
				Element<LTYPE>* pPrevAux = pAux->getPrev();

				if (!pAux)
				{
					cout << "ERROR: Can't remove a NULL element"
						return;
				}
				if (pAux == pLast)
					pLast = pPrevAux;
				pPrevAux->getNext(pAux->getNext());

				pAux = NULL;
				pPrevAux = NULL;
				size--;
			}

				const bool empty()const { return(size == 0 ? true : false); }
				const unsigned int()const { return size; }


			};
		};
	}