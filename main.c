# include <stdio.h>
# include <stdlib.h>
int main( )
{
         FILE *fp,*fw,*fc ;
         char data[10] ;
         int len;
         int j =0;
         int k = 0;
         int key;
         int sml;
         int lrg;

         int bubble_values[2] = {0};
         int insertion_values[2] = {0};
         int counting_values[2] = {0};
         int merge_values[2] = {0};
         int quick_values[2] = {0};
         int i = -1;
         fp = fopen("C:\\Users\\DELL\\Desktop\\etc\\third semester umd\\ENTS689A\\proj1\\in01.txt","r");
         fw = fopen("C:\\Users\\DELL\\Desktop\\etc\\third semester umd\\ENTS689A\\proj1\\out01.txt","w");
         fc = fopen("C:\\Users\\DELL\\Desktop\\etc\\third semester umd\\ENTS689A\\proj1\\out02.txt","w");

         if ( fp == NULL )
         {
                 printf( "Could not open input file" ) ;
                 return 1;
         }
         if ( fc == NULL )
         {
                 printf( "Could not open evaluation output file" ) ;
                 return 1;
         }
         if ( fw == NULL )
         {
                 printf( "Could not open sorted_data output file" ) ;
                 return 1;
         }
         fscanf(fp,"%d %d %d",&len,&sml,&lrg);
         int *arr0 = malloc(len * sizeof(int));
         int *arr1 = malloc(len * sizeof(int));
         int *arr2 = malloc(len * sizeof(int));
         int arr3[len];
         int arr4[len];
         int arr5[len];
         int *arr3_otp = malloc(len * sizeof(int));

         while( fgets( data, 10, fp ) != NULL )
         {
         if (i>=0)
          {
            arr0[i] = atoi(data);
            arr1[i] = atoi(data);
            arr2[i] = atoi(data);
            arr3[i] = atoi(data);
            arr4[i] = atoi(data);
            arr5[i] = atoi(data);
          }
           i = i + 1;
         }

        int p = 0;
        int q = len - 1;

        mrgSort(arr4,p,q,merge_values);
       QuickSort(arr5,p,q,quick_values);
         bubble_sort(arr0,len,bubble_values);
         insertion_sort(arr2,len,insertion_values);
        counting_sort(arr3,arr3_otp,lrg,sml,len,counting_values);

    for (k=0;k<len;k++)
        {
           fprintf(fw,"%d %d %d %d %d\n",arr0[k],arr2[k],arr3_otp[k],arr4[k],arr5[k]);
           //fprintf(fw,"%d \n",arr2[k]);
        }

        fprintf(fc,"Bubble sort: %d comparisons, %d copies.\n",bubble_values[0],bubble_values[1]);
        fprintf(fc,"Insertion sort: %d comparisons, %d copies.\n",insertion_values[0],insertion_values[1]);
        fprintf(fc,"Counting sort: %d comparisons, %d copies.\n",counting_values[0],counting_values[1]);
        fprintf(fc,"Merge sort: %d comparisons, %d copies.\n",merge_values[0],merge_values[1]);
        fprintf(fc,"Quick sort: %d comparisons, %d copies.",quick_values[0],quick_values[1]);

        free(arr0);
        free(arr1);
        free(arr0);
        free(arr4);
        free(arr3_otp);
        fclose(fp);
        free(arr5);
        fclose(fw);
         return 0;
}
void insertion_sort(int *arr2,int len,int insertion_values[])
        {int k,j,key,cnt;
        static int cmp = 0;
            for (k = 1;k<len;k++)
         {   insertion_values[1]++;
             key = arr2[k];
             j = k -1;
             if (j>= 0)
             {
                 insertion_values[0] = insertion_values[0] + k;
             }
             while(j>= 0 && key < arr2[j])
             {
                 insertion_values[1]++;
                 arr2[j+1] = arr2[j];
                 j--;

             }
             insertion_values[1]++;
             arr2[j+1] = key;

        }
        }
void bubble_sort(int *arr0,int len,int bubble_values[])
{   int k,i;
    for(k = 0;k<len;k++)
         {
             for(i=len-1;i>= k + 1;i--)
             {   bubble_values[0]++;
                 if (arr0[i]<arr0[i-1])
                 {   bubble_values[1] = bubble_values[1] + 3;
                     swap(&arr0[i],&arr0[i-1]);
                 }
             }
         }
}
void counting_sort(int arr3[],int *arr3_otp,int lrg,int sml,int len,int counting_values[])
    {   int k;
        int c_cnt = lrg - sml + 1;
        int *c_arr = malloc(c_cnt * sizeof(int));
        for (k =0;k<c_cnt;k++)
        {
            c_arr[k] = 0;
        }
        for (k = 0;k<len;k++)
        {
            c_arr[arr3[k]-sml]++;
        }
        for (k = 1;k<c_cnt;k++)
        {   counting_values[1]++;
            c_arr[k] = c_arr[k-1] + c_arr[k];
        }
        for (k = len-1;k>=0;k--)
            {
                counting_values[1]++;
                arr3_otp[c_arr[arr3[k] -sml]-1] = arr3[k];
                c_arr[arr3[k]-sml] = c_arr[arr3[k]-sml] - 1;
            }
       free(c_arr);
       }
void mrg(int arr4[], int l, int m, int r,int merge_values[])
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        {merge_values[1]++;
        L[i] = arr4[l + i];}
    for (j = 0; j < n2; j++)
    {merge_values[1]++;
        R[j] = arr4[m + 1+ j];}

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {   merge_values[0]++;
        if (L[i] <= R[j])
        {   merge_values[1]++;
            arr4[k] = L[i];
            i++;
        }
        else
        {   merge_values[1]++;
            arr4[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {   merge_values[1]++;
        arr4[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {   merge_values[1]++;
        arr4[k] = R[j];
        j++;
        k++;
    }
}

void mrgSort(int arr4[], int l, int r,int merge_values[])
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mrgSort(arr4, l, m,merge_values);
        mrgSort(arr4, m+1, r,merge_values);

        mrg(arr4, l, m, r,merge_values);
    }
}

int median(int arr5[], int p, int r,int quick_values[])
{
    int m = (p+r)/2;
    if (arr5[p] > arr5[m])
    {
        swap(&arr5[p],&arr5[m]);
        quick_values[1] = quick_values[1] + 3;
    }
    if (arr5[p] > arr5[r])
    {
        swap(&arr5[p],&arr5[m]);
        quick_values[1] = quick_values[1] + 3;
    }
    if (arr5[m] > arr5[r])
    {
        swap(&arr5[m],&arr5[r]);
        quick_values[1] = quick_values[1] + 3;
    }
    swap(&arr5[m],&arr5[r]);
    quick_values[1] = quick_values[1] + 3;
    return r;
}
void QuickSort (int arr5[],int low,int high,int quick_values[])
{int split;
    if (low<high)
    {
     split = partition(arr5,low,high,quick_values);
     QuickSort(arr5,low,split-1,quick_values);
     QuickSort(arr5,split+1,high,quick_values);
    }
}
int partition(int arr5[],int l,int h,int quick_values[])
{
    int piv;
    piv = arr5[median(arr5,l,h,quick_values)];
    int i = l -1;
    int j,temp;
    for(j=l;j <=h-1;j++)
    {   quick_values[0]++;
        if (arr5[j]<=piv)
        {
            i++;
            int temp;
            quick_values[1] = quick_values[1] + 3;
            swap(&arr5[i],&arr5[j]);
        }

    }
            quick_values[1] = quick_values[1] + 3;
            swap(&arr5[i+1],&arr5[h]);
    return i+1;
}
void swap(int *pa, int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
