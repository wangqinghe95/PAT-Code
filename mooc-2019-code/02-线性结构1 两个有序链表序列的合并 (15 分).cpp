// https://www.cnblogs.com/wanghao-boke/p/11674697.html

List Merge( List L1, List L2 )
{
    List tmp1 = L1->Next;
    List tmp2 = L2->Next;
    List L3 = (List)malloc( sizeof(struct Node) );
    List p = L3;

    while( tmp1 && tmp2 )
    {
        if( tmp1->Data > tmp2->Data )
        {
            p->Next = tmp2;
            tmp2 = tmp2->Next;
        }
        else
        {
            p->Next = tmp1;
            tmp1 = tmp1->Next;
        }
        p = p->Next;
    }

    if(tmp1)
    {
        p->Next = tmp1;
    }
    if(tmp2)
    {
        p->Next = tmp2;
    }

    L1->Next = NULL;
    L2->Next = NULL;
    return L3;
}
