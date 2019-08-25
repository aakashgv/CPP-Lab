#include<stdio.h>
#include<stdlib.h>
struct array
{
    int n;
    int m;
    int *val;
};
void printarray(struct array *arr)
{
    for(int i=0;i<arr->m;i++)
        printf("%d",arr->val[i]);
    return;
}
struct array* shrinkarray(struct array *arr)
{
    arr->n=arr->n/2;
    return arr;
}
struct array* resizearray(struct array *arr)
{
    arr->n *=2;   
    return arr;
}
struct array* Add(struct array *arr, int val, int ind)
{
    
    if(ind>arr->n)
    {
        return arr;
    }   
    if(arr->m >= 0.75*(arr->n))
    {
        resizearray(arr);
    }
    for(int i=ind;i<arr->m;i++)
    {
        arr->val[ind+1]=arr->val[ind];
    }
    arr->val[ind] = val;
    arr->m++;
    printf("Array after your input is : ");
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
        shrinkarray(arr);
    }
    for(int i=d;i<arr->m;i++)
    {
        arr->val[i]=arr->val[i+1];
    }
    arr->m--;
    printf("Array after your input is : ");
    printarray(arr);
    printf("\n");
    return arr;
}

int main()
{
    struct array *arr = malloc(sizeof(struct array)); 
    arr->n=2;
    arr->m=0;
    arr->val = malloc(arr->n*(sizeof(int)));
    int val = 0, ind = 0, c=0, d=0;
    int f=0;
    printf("Press -1 -1 to exit\n");
    while(1){
    printf("Press 1 if you want to add and 2 to delete \n");
    scanf("%d",&f);
    if(f==1)
    {
        printf("Enter the elements to be added and the respective index.\n");
        scanf("%d %d",&val,&ind);
        if(val==-1&&ind==-1)
            break;
        Add(arr,val,ind);
     }
     else if(f==2)
     {
        printf("Enter the elements to be deleted and the respective index.\n");
            scanf("%d %d",&val,&ind);
            if(val==-1&&ind==-1)
                break;
            Delete(arr,val,ind);
     }
     }
     printf("Final Array after all the operations is : ");
     printarray(arr);
     printf("\n");
     return 0;
}
