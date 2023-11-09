// https://www.cnblogs.com/wanghao-boke/p/11681448.html

BinTree Insert ( BinTree BST, ElementType X )
{
    if ( !BST )
    {
        BST = (BinTree)malloc( sizeof(struct TNode) );
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else if (BST->Data > X)
    {
        BST->Left = Insert( BST->Left, X );
    }
    else if (BST->Data < X)
    {
        BST->Right = Insert( BST->Right, X );
    }
    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    BinTree p;

    if ( !BST )
    {
        printf("Not Found\n");
        return BST;
    }

    if ( BST->Data > X)
    {
        BST->Left = Delete( BST->Left, X);
    }
    else if ( BST->Data < X)
    {
        BST->Right = Delete( BST->Right, X);
    }
    else
    {
        if ( BST->Right && BST->Left )
        {
            p = FindMax( BST->Left );
            BST->Data = p->Data;
            BST->Left = Delete( BST->Left, BST->Data );
        }
        else
        {
            p = BST;
            if ( !BST->Left )
            {
                BST = BST->Right;
            }
            else if ( !BST->Right)
            {
                BST = BST->Left;
            }
            free(p);
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    if ( !BST )
    {
        return NULL;
    }

    if ( BST->Data > X )
    {
        return Find( BST->Left, X );
    }
    else if ( BST->Data < X )
    {
        return Find( BST->Right, X );
    }
    else
    {
        return BST;
    }
}
Position FindMin( BinTree BST )
{
    if ( BST )
    {
        while ( BST->Left )
        {
            BST = BST->Left;
        }
    }
    return BST;
}
Position FindMax( BinTree BST )
{
    if ( BST )
    {
        while ( BST->Right )
        {
            BST = BST->Right;
        }
    }
    return BST;
}
