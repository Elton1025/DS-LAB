#include<stdio.h>

int main() {
    while(1)
    {
        int n;
        printf("\nEnter\n1.Length\n2.Concatenation\n3.Comparison\n4.Insert Substring\n5.Delete SubString\n6.Exit\n");
        printf("Enter Your choice:");
        scanf("%d",&n);
        switch(n) {
            case 1: {
                char a[50];
                printf("Enter a String to find its length:");
                scanf("%s",a);
                int m=lent(a);
                printf("%d",m);
                break;
            }
            case 2: {
                char b[50],c[50];
                printf("\nEnter two strings for concatenation:");
                scanf("%s",b);
                scanf("%s",c);
                concat(b,c);
                break;
            }
            case 3: {
                char d[50],e[50];
                printf("\nEnter two stings for comparison:");
                scanf("%s",d);
                scanf("%s",e);
                if(comp(d,e)) {
                    printf("String are Equal");
                }
                else {
                    printf("Strings are not equal");
                }
                break;
            }
            case 4: {
                char f[50],g[50];
                int k;
                printf("\nEnter two string for insertion:");
                scanf("%s",f);
                scanf("%s",g);
                printf("\nEnter the position where the string needs to be inserted:");
                scanf("%d",&k);
                inssub(f,g,k);
                break;
            }
            case 5: {
                char h[50],i[50];
                int t;
                printf("Enter two strings:");
                scanf("%s",h);
                scanf("%s",i);
                delsub(h,i);
                printf("%s",h);
                break;
            }
            case 6: {
                return 0;
            }
        }
    }
}

int lent(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;
}

void concat(char a[],char b[]) {

    for(int i=lent(a),j=0;b[j]!='\0';i++,j++){

        a[i]=b[j];
    }
    printf("%s",a);

}

int comp(char a[],char b[]) {

    int c=1;
    for(int i=0;i<lent(a);i++) {
        if(lent(a)!=lent(b)) {
            return 0;
        }
        if(a[i]!=b[i]) {
            c=0;
        }
    }
    return c;

}

void inssub(char a[],char b[],int k) {
    char c[50];
    for(int i=k-1,j=0;j<lent(a);i++,j++) {
        c[j]=a[i];
        a[i]=b[j];
    }

    for(int p=k+lent(b)-1,q=0;q<lent(c);p++,q++) {
        a[p]=c[q];
    }
    printf("%s",a);
}
int findSubstr(char s[100], char sub[100])
{
    int i = 0, sublen = 0;
    int cnt = 0;
    int ind = -1;

    while (s[i] != '\0')
    {
        if (s[i] == sub[0])
        {
            ind = i;
            int j = 0;
            while (sub[j] != '\0')
            {
                if (sub[j] != s[i])
                {
                    ind = -1;
                    break;
                }
                j++;
                i++;
            }
        }

        i++;
    }

    return ind;
}

void delsub(char a[],char b[]) {

    int i=findSubstr(a,b);
    if (i == -1)
        return;

    int sublen = lent(b);
    int j;
    for (j = i; a[i + sublen] != '\0'; j++, i++)
    {
        a[j] = a[i + sublen];
    }
    a[i] = '\0';

}
