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

void quick_sort2(int** array, int low, int high, int index)
{
    if(low >= high) // sort ended
        return;
    int i= low;
    int j= high;
    int key = array[low][index];
    int key2 = array[low][!index];

    while(low < high)
    {
        while(array[high][index]>=key && low<high)
        {
            high--;
        }
        if(key > array[high][index])
        {
            array[low][index] = array[high][index];
            array[low][!index] = array[high][!index];
            low++;
        }
        while(array[low][index]<=key && low<high)
        {
            low++;
        }
        if(key < array[low][index])
        {
            array[high][index] = array[low][index];
            array[high][!index] = array[low][!index];
            high--;
        }
    }
    array[low][index] = key;
    array[low][!index] = key2;
    quick_sort2(array, i, low-1, index);
    quick_sort2(array, low+1, j, index);
}