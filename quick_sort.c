void quick_sort(int* array, int low, int high)
{
    if(low >= high) // sort ended
        return;
    int i= low;
    int j= high;
    int key = array[low];

    while(low < high)
    {
        while(array[high]>=key && low<high)
        {
            high--;
        }
        if(key > array[high])
        {
            array[low] = array[high];
            low++;
        }
        while(array[low]<=key && low<high)
        {
            low++;
        }
        if(key < array[low])
        {
            array[high] = array[low];
            high--;
        }
    }
    array[low] = key;
    quick_sort(array, i, low-1);
    quick_sort(array, low+1, j);
}