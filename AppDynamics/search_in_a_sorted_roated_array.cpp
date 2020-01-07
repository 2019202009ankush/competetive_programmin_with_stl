/* Searching in sorted in roated array
  Written By:Ankush Mitra
 Date:6.1.20 Iime=23.11*/
 int search(int arr[], int l, int h, int key)
{
	         if(l>h) return -1;
          int mid=(l+h)/2;
          if(arr[mid]==key) return mid;
          else
          {
                  if(arr[l]<=arr[mid])
                   {
                     if(arr[l]<=key&&key<=arr[mid])
                       return search(arr,l,mid-1,key);
                     else
                       return search(arr,mid+1,h,key);
                   }
                   else
                   {
                     if(arr[mid]<=key&&key<=arr[h])
                       return search(arr,mid+1,h,key);
                     else
                       return search(arr,l,mid-1,key);
                   }
            }
}
