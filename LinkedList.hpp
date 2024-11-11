#ifndef _LINKEDLIST_HPP
#define _LINKEDLIST_HPP

//사용법은 리스트에 담고 싶은 객체에 LinkProperty를 상속받아서 사용하면 됩니다.
template <typename _Type>
class LinkedList;

template <typename _Type>
struct LinkProperty
{
	LinkProperty* pPrv{ nullptr };
	LinkProperty* pNext{ nullptr };
	_Type* pElement{ nullptr };

public:
	LinkProperty() = default;
	virtual ~LinkProperty() = default;

private:
	friend class LinkedList<_Type>;

private:
	void InternalSeparate()
	{
		pPrv = nullptr;
		pNext = nullptr;
	}
};
//링크드 리스트 클래스입니다. 해당 클래스로 링크, 언링크 가능하고, ForEach로 순회작업을 할 수 있습니다.
template <typename _Type>
class LinkedList
{
public:
	void Link(LinkProperty<_Type>* pNewLinkProperty)
	{
		if (!pHead)
		{
			pHead = pNewLinkProperty;
			pTail = pNewLinkProperty;
		}
		else
		{
			pNewLinkProperty->pPrv = pTail;
			pTail->pNext = pNewLinkProperty;
			pTail = pNewLinkProperty;
		}
	}

	void Unlink(LinkProperty<_Type>* pDeleteLinkProperty)
	{
		LinkProperty<_Type>*& LinkageFront = pDeleteLinkProperty->pPrv;
		LinkProperty<_Type>*& LinkageBack = pDeleteLinkProperty->pNext;

		if (LinkageFront)
		{
			LinkageFront->pNext = LinkageBack;
		}
		else
		{
			pHead = LinkageBack;
		}

		if (LinkageBack)
		{
			LinkageBack->pPrv = LinkageFront;
		}
		else
		{
			pTail = LinkageFront;
		}

		pDeleteLinkProperty->InternalSeparate();
	}

	void ClearLink()
	{
		LinkProperty<_Type>* pCurrent = pHead;
		while (pCurrent)
		{
			LinkProperty<_Type>* pNext = pCurrent->pNext;
			pCurrent->InternalSeparate();
			pCurrent = pNext;
		}
		pHead = nullptr;
		pTail = nullptr;
	}

	LinkProperty<_Type>* GetHead()
	{
		return pHead;
	}

	LinkProperty<_Type>* GetTail()
	{
		return pTail;
	}

	LinkProperty<_Type>* GetNext(LinkProperty<_Type>* pCurrent)
	{
		return pCurrent->pNext;
	}

	LinkProperty<_Type>* GetPrv(LinkProperty<_Type>* pCurrent)
	{
		return pCurrent->pPrv;
	}

	_Type* GetElement(LinkProperty<_Type>* pCurrent)
	{
		return pCurrent->pElement;
	}

	template <typename _Func>
	void ForEach(_Func func)
	{
		LinkProperty<_Type>* pCurrent = pHead;
		while (pCurrent)
		{
			func(pCurrent->pElement);
			pCurrent = pCurrent->pNext;
		}
	}

private:
	LinkProperty<_Type>* pHead{};
	LinkProperty<_Type>* pTail{};
};

#endif // !_LINKEDLIST_HPP