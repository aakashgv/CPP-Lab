#include<stdio.h>
#include<stdlib.h>
struct array
{
    int n;
    int m;
    int *a;
};
void printarray(struct array *arr)
{
    for(int i=0;i<arr->m;i++)
        printf("%d",arr->a[i]);
    return;
}
struct array* shrinksize(struct array *arr)
{
    arr->n /=2;
    return arr;
}
struct array* resizearray(struct array *arr)
{
    arr->n *=2;   
    return arr;
}
struct array* Add(struct array *arr, int a, int b)
{
    
    if(b>arr->n)
    {
        return arr;
    }   
    if(arr->m >= 0.75*(arr->n))
    {
        resizearray(arr);
    }
    for(int i=b;i<arr->m;i++)
    {
        arr->a[b+1]=arr->a[b];
    }
    arr->a[b] = a;
    arr->m++;
    printarray(arr);
    printf("\n");
    return arr;
}
struct array* Delete(struct array *arr, int c, int d)
{
    if(d>arr->n)
    {
        return arr;
    }   
    if(arr->m <= 0.25*(arr->n))
    {
        shrinksize(arr);
    }
    for(int i=d;i<arr->m;i++)
    {
        arr->a[i]=arr->a[i+1];
    }
    arr->m--;
    printarray(arr);
    printf("\n");
    return arr;
}

int main()
{
    struct array *arr = malloc(sizeof(struct array)); 
    arr->n=2;
    arr->m=0;
    arr->a = malloc(arr->n*(sizeof(int)));
    int a = 0, b = 0, c=0, d=0;
    char f[]="";
    while(1){
    printf("INSERT or DELETE\n");
    gets(&f);
    if(f=="I")
    {
    	printf("Insertion");
        printf("Element and Index:");
        scanf("%d %d",&a,&b);
        if(a==-1&&b==-1)
            break;
        Add(arr,a,b);
     }
     else if(f=="D")
     {
     	printf("Deletion");
        printf("Element and Index:\n");
            scanf("%d %d",&a,&b);
            if(a==-1&&b==-1)
                break;
            Delete(arr,a,b);
     }
     }
     printf("Final Array;");
     printarray(arr);
     printf("\n");
     return 0;
}
