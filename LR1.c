#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int z[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &z[i]);
    }
    for(int i = 0; i<n; i++)
    {
        printf("%d", z[i]);
    }
    printf("\n");
    int more = 0;
    do
    {
        for (int i = n-2; i >= 0; i--)
        {
            more = 0;
            if (z[i] < z[i+1])
            {
                more = 1;
                int mnValue = 2147483647;
                int mnIndex = 0;
                for (int j = i+1; j < n; j++)
                {
                    if (z[j] > z[i] && z[j] < mnValue)
                    {
                        mnValue = z[j];
                        mnIndex = j;
                    }
                }
                int temp = z[i];
                z[i] = z[mnIndex];
                z[mnIndex] = temp;
                for(int j = i+1, k = n-1; j < k; j++, k--)
                {
                    temp = z[j];
                    z[j] = z[k];
                    z[k] = temp;
                }
                for(int j = 0; j < n; j++)
                {
                    printf("%d", z[j]);

                }
                printf("\n");
                break;
            }
        }
    }
    while (more);
    return 0;
}
