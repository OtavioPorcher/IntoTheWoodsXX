#pragma once

#include <iostream>
#include <stdlib.h>

namespace List
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

			void setData(ETYPE* dI) { pData = dI; }
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
			const bool operator==(Element<ITYPE>* pE2)const { return pE == pE2; }
			const bool operator==(ITYPE* pD2)const { return pE->getData() == pD2; }

			const bool operator!=(Element<ITYPE>* pE2)const { return !(pE == pE2); }
			const bool operator!=(ITYPE* pD2)const { return !(pE->getData() == pD2); }
			
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

			void clear()
			{
				if (empty())
					return;
				Element<TYPE>* pAux = NULL;

				while (pFirst != NULL)
				{
					pAux = pFirst;
					remove((unsigned int) 0);
				}
			}

			List() : pFirst(NULL), pLast(NULL), size(0) {		}
			~List()
			{
				clear();

				pFirst = NULL;
				pLast = NULL;

			}

			void insertFront(TYPE* dI) { insert(dI, true); }
			void insertBack(TYPE* dI) { insert(dI, false); }
			
			Element<TYPE>* runThrough(int index)
			{
				if (index < 0 || index > (int)size)
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

			int find(TYPE* pE)
			{
				unsigned int i = 0;
				Iterator<TYPE> it = pFirst;

				for (it; it != end(); it.operator++())
				{
					if ((it.getElement())->getData() == pE)
						return i;
					i++;
				}

				return -1;
			}

			void remove(unsigned int index)
			{
				if (index >= size)
				{
					std::cout << "ERROR: Segmentation fault" << std::endl;
						return;
				}
				Element<TYPE>* pAux = runThrough(index);
				//Element<TYPE>* pPrevAux = pAux->getPrev();

				if (!pAux)
				{
					std::cout << "ERROR: Can't remove a NULL element" << std::endl;
						return;
				}

				if (pAux == pLast)
					pLast = pAux->getPrev();
				if ((pAux == pFirst)&&(pAux->getNext()))
					pFirst = pAux->getNext();
				if (pAux != pFirst)
					(pAux->getPrev())->setNext(pAux->getNext());
				else
					pFirst = NULL;

				pAux = NULL;
				size--;
			}
			void remove(TYPE* pT)
			{
				int aux = find(pT);
				if (aux < 0)
					return;
				remove((unsigned int)aux);
			}

				const bool empty()const { return(size == 0 ? true : false); }
				const unsigned int getSize()const { return size; }

				Element<TYPE>* begin() { return pFirst; }
				Element<TYPE>* end()   { return pLast->getNext();  }


			};
		}
	