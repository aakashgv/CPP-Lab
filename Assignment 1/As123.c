/*Aakash Gopal Vachhani 2017UCP1001
Implementing Unbounded Array, which doubles its size if it reaches 0.75 times its capacity and halves its size when it reaches 0.25 times its capacity */
#include<stdio.h>
#include<stdlib.h>
struct array
{
    int Cap;
    int CuS;
    int *val;
};
void display(struct array *arr)
{
    for(int i=0;i<arr->CuS;i++)
        printf("%d",arr->val[i]);
    return;
}
struct array* shrinksize(struct array *arr)
{
    arr->Cap=arr->Cap/2;
    return arr;
}
struct array* doublearray(struct array *arr)
{
    arr->Cap=arr->Cap*2;   
    return arr;
}
struct array* Add(struct array *arr, int val, int ind)
{
    
    if(ind>arr->Cap)
    {
        return arr;
    }   
    if(arr->CuS >= 0.75*(arr->Cap))
    {
 
        doublearray(arr);
        printf("Doubled \n");
        printf("Capacity: %d \n",arr->Cap);
    }
    for(int i=ind;i<arr->CuS;i++)
    {
        arr->val[ind+1]=arr->val[ind];
    }
    arr->val[ind] = val;
    arr->CuS++;
    printf("Array:");
    display(arr);
    printf("\n");
    return arr;
}
struct array* Delete(struct array *arr, int c, int d)
{
    if(d>arr->Cap)
    {
        return arr;
    }   
    if(arr->CuS <= 0.25*(arr->Cap))
    {
        shrinksize(arr);
        printf("Halved \n");
        printf("Current Size: %d \n",arr->CuS);
        printf("Capacity: %d \n",arr->Cap);
    }
    for(int i=d;i<arr->CuS;i++)
    {
        arr->val[i]=arr->val[i+1];
    }
    arr->CuS--;
    display(arr);
    printf("\n");
    return arr;
}

int main()
{
    struct array *arr = malloc(sizeof(struct array)); 
    arr->Cap=2;
    arr->CuS=0;
    arr->val = malloc(arr->Cap*(sizeof(int)));
    int val = 0, ind = 0, c=0, d=0;
    int f=0;
    
    while(1){
    printf("1. Add 2. Delete");
    printf("\n");
    scanf("%d",&f);
    if(f==1)
    {
        
        printf("Element and Index: ");
        scanf("%d %d",&val,&ind);
        if(val==-1&&ind==-1)
            break;
        Add(arr,val,ind);
        printf("Current Size: %d \n",arr->CuS);
        printf("Capacity: %d \n",arr->Cap);
        printf("\n");

     }
     else if(f==2)
     {
     	
        	printf("Current Size: %d \n",arr->CuS);
            printf("Capacity: %d \n",arr->Cap);
        	printf("Element and Index: ");
            scanf("%d %d",&val,&ind);
            if(val==-1&&ind==-1)
            break;
            Delete(arr,val,ind);
            
            printf("\n");
        	
     }
     }
     
     display(arr);
     return 0;
}
