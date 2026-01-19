#include<stdio.h>

int main()
{
    int a[10], n, i, s;
    int low;
    int  high;
    int mid;
    int  flag = 0;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    printf("Enter elements in the array  :\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search:\n");
    scanf("%d", &s);

    low = 0;
    high = n - 1;   

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == s)
        {
            printf("Element found at position %d", mid + 1);
            flag = 1;
            break;
        }
        else if(s < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(flag == 0)
    {
        printf("Element not found");
    }

    return 0;
}
