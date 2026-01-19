#include<stdio.h>

int main()
{
    int i, n, a[5], s, flag = 0;

    printf("Enter number of elements :\n");
    scanf("%d", &n);

    printf("Enter elements in the array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Elements in the array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("Enter element to search:\n");
    scanf("%d", &s);

    for(i = 0; i < n; i++)
    {
        if(s == a[i])
        {
            printf("The element is at position %d", i + 1);
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Element is not found");
    }

    return 0;
}
