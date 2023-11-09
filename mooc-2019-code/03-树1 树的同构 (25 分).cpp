// https://www.cnblogs.com/wanghao-boke/p/11723129.html

#include<cstdio>
const int maxn = 11;
int countsa[maxn];
int countsb[maxn];

int main(){
    int n;
    char a,b,c;
    
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int add = 2;
        scanf("%*c");
        scanf("%c %c %c",&a,&b,&c);
        if(b == '-')
        {
          add--;	
        } 
            if(c == '-')
            {
              add--;
        }
            countsa[a-'A']+=add;
    }
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int add = 2;
        scanf("%*c");
        scanf("%c %c %c",&a,&b,&c);
        if(b == '-')
        {
          add--;	
        } 
        if(c == '-')
        {
        	add--;
		    }
        countsb[a-'A']+=add;
    }
    
    if(n==1)
	  {                 
        printf("No\n");                   
    } 
    else
    {
        int i;                    
        for(i = 0; i < n; i++)
        {  
            if(countsa[i] != countsb[i])
            {    
               printf("No\n");   
               break;            
            }                     
        }                         
        if(i == n)printf("Yes\n");		
    }                        

    return 0;
}
