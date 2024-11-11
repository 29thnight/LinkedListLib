#ifndef _LINKEDLIST_HPP
#define _LINKEDLIST_HPP

//������ ����Ʈ�� ��� ���� ��ü�� LinkProperty�� ��ӹ޾Ƽ� ����ϸ� �˴ϴ�.
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
//��ũ�� ����Ʈ Ŭ�����Դϴ�. �ش� Ŭ������ ��ũ, ��ũ �����ϰ�, ForEach�� ��ȸ�۾��� �� �� �ֽ��ϴ�.
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