/* ABHAY GUPTA (agupta15) */

#include<stdio.h>
#include<stdlib.h>

typedef struct bloom1 
{

	char  bit_array1[250000];
	char  bit_array2[250000];
	char  bit_array3[250000];
	char  bit_array4[250000];
	char  bit_array5[250000];
	char  bit_array6[250000];
	char  bit_array7[250000];
	char  bit_array8[250000];

}bf_t;

bf_t *create_bf()
{
	bf_t *temp1=(bloom1 *)malloc(sizeof(bloom1));
	for (int i=0;i<250000;i++)
	{
		temp1->bit_array1[i]=0;
		temp1->bit_array2[i]=0;
		temp1->bit_array3[i]=0;
		temp1->bit_array4[i]=0;
		temp1->bit_array5[i]=0;
		temp1->bit_array6[i]=0;
		temp1->bit_array7[i]=0;
		temp1->bit_array8[i]=0;
	}
	return temp1;
}

void setBit(char *c, int n)
{
	*(c+(n/8)) |= 1<< (n%8);
}


int checkBit(char *c, int  n)
{
        return *(c+(n/8))& (1<<(n%8));
}

unsigned long  cal_string_to_int(char *p)
{

	int h=0;
	unsigned long hash = 0;
        int c;

        while (c = *p++)
            hash = c + (hash << 6) + (hash << 11) - hash;

        return hash;

}

void padding_string(char p[])
{

	int flag=0;
	for (int i=0;i<8;i++)
	{

		if (p[i]=='\0')
		flag=1;
		
		if (flag==1)
		p[i]='0';

	}

}

void insert_bf(bf_t *b,char *s)
{

	long  h,h1,h2,h3,h4,h5,h6,h7,h8;
	
	h=cal_string_to_int(s);
	h1=abs(((503*h+99991)%2000003)%2000000);
	setBit(b->bit_array1,h1);
	h2=abs(((9*h+100003)%3000017)%2000000);
	setBit(b->bit_array2,h2);
	h3=abs(((1021*h+2040007)%2050007)%2000000);
	setBit(b->bit_array3,h3);
	h4=abs(((153*h+149993)%4000037)%2000000);
	setBit(b->bit_array4,h4);
	h5=abs(((741*h+89989)%2000083)%2000000);
	setBit(b->bit_array5,h5);
	h6=abs(((547*h+90001)%2000093)%2000000);
	setBit(b->bit_array6,h6);
	h7=abs(((2117*h+70001)%2000107)%2000000);
	setBit(b->bit_array7,h7);
	h8=abs(((563*h+69997)%2000113)%2000000);
	setBit(b->bit_array8,h8);

}

int is_element(bf_t *b,char *p)
{	long h,h1,h2,h3,h4,h5,h6,h7,h8;

	h=cal_string_to_int(p);

	if (h==423  || h==449)
	printf(" %s ",p);
	h1=abs(((503*h+99991)%2000003)%2000000);

	h2=abs(((9*h+100003)%3000017)%2000000);

	h3=abs(((1021*h+2040007)%2050007)%2000000);

	h4=abs(((153*h+149993)%4000037)%2000000);

	h5=abs(((741*h+89989)%2000083)%2000000);

	h6=abs(((547*h+90001)%2000093)%2000000);

	h7=abs(((2117*h+70001)%2000107)%2000000);

	h8=abs(((563*h+69997)%2000113)%2000000);

	if ((checkBit(b->bit_array1,h1) != 0) && (checkBit(b->bit_array2,h2)!=0) && (checkBit(b->bit_array3,h3)!=0) && (checkBit(b->bit_array4,h4)!=0 )&& (checkBit(b->bit_array5,h5)!=0)&&  (checkBit(b->bit_array6,h6)!=0) &&  (checkBit(b->bit_array7,h7) !=0) &&  (checkBit(b->bit_array8,h8)!=0))
		return 1;
	else
		return 0;
}



void sample_string_A(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = 'b';
   s[5] = (char)(1 + ((i*(i-3)) %217));
   s[6] = (char)(1 + ((17*i+129)%233 ));
   s[7] = '\0';
}
void sample_string_B(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = (char)(1 + ((i*(i-3)) %217));
   s[5] = (char)(1 + ((17*i+129)%233 ));
   s[6] = '\0';
}
void sample_string_C(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = 'a';
   s[3] = (char)(1 + ((i*(i-3)) %217));
   s[4] = (char)(1 + ((17*i+129)%233 ));
   s[5] = '\0';
}
void sample_string_D(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'b';
   s[4] = 'b';
   s[5] = (char)(1 + ((i*(i-3)) %217));
   s[6] = (char)(1 + ((17*i+129)%233 ));
   s[7] = '\0';
}
void sample_string_E(char *s, long i)
{  s[0] = (char)(1 + (i%254));
   s[1] = (char)(1 + ((i/254)%254));
   s[2] = (char)(1 + (((i/254)/254)%254));
   s[3] = 'a';
   s[4] = (char)(2 + ((i*(i-3)) %217));
   s[5] = (char)(1 + ((17*i+129)%233 ));
   s[6] = '\0';
}



int main()
{  long i,j; 
   bf_t * bloom;
   bloom = create_bf();
   printf("Created Filter\n");
   for( i=0 ; i<1450000; i++ )
   {  char s[8];
      sample_string_A(s,i);
      insert_bf( bloom, s );
   }
   for( i= 0; i<  500000; i++ )
   {  char s[7];
      sample_string_B(s,i);
      insert_bf( bloom, s );
   }
   for( i= 0; i< 50000; i++ )
   {  char s[6];
      sample_string_C(s,i);
      insert_bf( bloom, s );
   }
   printf("inserted 2,000,000 strings of length 8,7,6.\n");
   for( i= 0; i< 1450000; i++ )
   {  char s[8];
      sample_string_A(s,i);
      if( is_element( bloom, s ) != 1 )
	{  printf("found negative error (1), %d \n",i); exit(0); }
   }
   for( i= 0; i< 500000; i++ )
   {  char s[7];
      sample_string_B(s,i);
      if( is_element( bloom, s ) != 1 )
	{  printf("found negative error (2)\n"); exit(0); }
   }
   for( i= 0; i< 50000; i++ )
   {  char s[6];
      sample_string_C(s,i);
      if( is_element( bloom, s ) != 1 )
	{  printf("found negative error (3)\n"); exit(0); }
   }
   j = 0;
   for( i= 0; i< 500000; i++ )
   {  char s[8];
      sample_string_D(s,i);
      if( is_element( bloom, s ) != 0 )
	j+=1; 
   }
   for( i= 0; i< 500000; i++ )
   {  char s[7];
      sample_string_E(s,i);
      if( is_element( bloom, s ) != 0 )
	j+=1;
   }
   printf("Found %d positive errors out of 1,000,000 tests.\n",j);
   printf("Positive error rate %f\%.\n", (float)j/1000000.0);

} 


