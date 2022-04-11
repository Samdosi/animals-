/*
 09-06-2021
 Alphabet Animals
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxstring 21
//function protype
void freeptr(char **string, int n);

int main()
{
    //n is number of names
    int n=0;
    // bigptr is the array of pointers
    char** bigptr;
    char temp[maxstring], animalname[maxstring];
    scanf("%s", animalname);
    scanf("%d", &n);
    bigptr=malloc(n*sizeof(char*));
    // loading up the bigptr with animals name
    for(int i = 0; i < n; i++) {
            bigptr[i] = malloc((21) * sizeof(char));
            scanf("%s",temp);
            strcpy(bigptr[i], temp);
       }
 
    int length, found=0, i;
    char c;
    char firstlist[21], find[21];
    int* arr;
    //finding the length of the first animal
    length=strlen(animalname);
    // putting the first character of first animal to C
    c=animalname[length-1];
  
    arr = calloc(26, sizeof(int));
    // counting the fist character of animal's name and save them to arr
    for(i=0; i<n; i++)
    {
        arr[bigptr[i][0]-'a']++ ;
    }
    // not finding a match
    if(arr[c-'a']==0)
    {
        printf("?");
    }
    else
    {
        //finding a match
        for(i=0; i<n; i++)
        {
            length=strlen(bigptr[i]);
            if(bigptr[i][0]==c)
            {
                arr[bigptr[i][0]-'a']--;
                if(found==0)
                {
                    strcpy(firstlist, bigptr[i]);
                    found=1;
                }
                strcpy(find, bigptr[i]);
                if(arr[bigptr[i][length-1]-'a']==0)
                {
                    //match found
                    printf("%s!", find);
                    return 0;
                }
                
                arr[bigptr[i][0]-'a']++;
            }
        }
        // match found but not a winner 
        printf("%s", firstlist);
        
    }
    
    
    //free the memory
    freeptr(bigptr, n);
    
    
    
    return 0;
}


void freeptr(char **string, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        free(string[i]);
    }
    free(string);
}

