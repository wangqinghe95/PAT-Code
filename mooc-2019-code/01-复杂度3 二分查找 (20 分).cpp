// https://www.cnblogs.com/wanghao-boke/p/11673957.html

Position BinarySearch( List L, ElementType X )
{
    int left = 1;
    int right = L->Last;
    int mid;
    while( left <= right )
    {
        mid = ( right + left ) / 2;
        if( L->Data[mid] > X )
        {
            right = mid - 1;
        }
        else if( L->Data[mid] < X )
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return NotFound;
}
