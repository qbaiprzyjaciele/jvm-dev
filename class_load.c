/**
 * @author Jakub Smorąg
 */

#include "stdio.h"
#include "stdlib.h"
#include "constant_field_list.h"
#include "endian_conversions.h"

typedef struct CONSTANT_Class_info 
{
	char tag;
	unsigned short name_index;
} CONSTANT_Class_info;

typedef struct CONSTANT_Fieldref_info
{
	char tag;
	unsigned short class_index;
	unsigned short name_and_type_index;
} CONSTANT_Fieldref_info;

typedef struct CONSTANT_Methodref_info
{
    char tag;
    unsigned short class_index;
    unsigned short name_and_type_index;
} CONSTANT_Methodref_info;

typedef struct CONSTANT_InterfaceMethodref_info
{
    char tag;
    unsigned short class_index;
    unsigned short name_and_type_index;
} CONSTANT_InterfaceMethodref_info;


typedef struct CONSTANT_Integer_info
{
	char tag;
	int bytes;
} CONSTANT_Integer_info;

typedef struct CONSTANT_Float_info
{
	char tag;
	int bytes;
} CONSTANT_Float_info;

typedef struct CONSTANT_Long_info
{
	char tag;
	int high_bytes;
	int low_bytes;
} CONSTANT_Long_info;

typedef struct CONSTANT_Double_info
{
    char tag;
    int high_bytes;
    int low_bytes;
} CONSTANT_Double_info;

typedef struct CONSTANT_NameAndType_info
{
	char tag;
	unsigned short name_index;
	unsigned short descriptor_index;
} CONSTANT_NameAndType_info;

typedef struct CONSTANT_Utf8_info 
{
	char tag;
	unsigned short length;
	char *bytes;
} CONSTANT_Utf8_info;

typedef struct CONSTANT_MethodHandle_info 
{
	char tag;
	char reference_kind;
	unsigned short reference_index;
} CONSTANT_MethodHandle_info;

typedef struct CONSTANT_MethodType_info
{
	char tag;
	unsigned short descriptor_index;
} CONSTANT_MethodType_info;

typedef struct CONSTANT_InvokeDynamic_info
{
	char tag;
	unsigned short bootstrap_method_attr_index;
	unsigned short name_and_type_index;
} CONSTANT_InvokeDynamic_info;

typedef struct attribute_info
{
	unsigned short attribute_name_index;
	unsigned int attribute_length;
	char * info;
} attribute_info;

typedef struct field_info
{
	unsigned short access_flags;
	unsigned short name_index;
	unsigned short descriptor_index;
	unsigned short attributes_count;
	attribute_info * attributes;
} field_info;

typedef struct simple_struct 
{
	char field;
	int * ptr;
} simple_struct;

int big_endian_int(char * bytes) 
{
	//TODO
	char temp;
	temp = bytes[3];
	bytes[0] = bytes[3];
	bytes[3] = temp;
	temp = bytes[1];
	bytes[1] = bytes[2];
	bytes[2] = temp;
	int *int_value = (int*)bytes;
	return *int_value;
}	

unsigned short big_endian_unsigned_short(char * bytes)
{
	//TODO
	return 1;
}


int main()
{
	void * constant_pool = (void*)malloc(4);
	char bytes[4] = {'a','b','a','a'};
	FILE * classFile;
	char cafebabe[4];
	unsigned int *cafebabe_int  = 0;
	unsigned short minor_version;
	unsigned short major_version;
	unsigned short constant_pool_count;
	
	constant_pool = bytes;
	CONSTANT_MethodHandle_info * info = (CONSTANT_MethodHandle_info*)constant_pool;
	printf("info->tag=%c\n",info->tag);
	printf("info->reference_kind=%c\n",info->reference_kind);
	printf("info->reference_index=%d\n",info->reference_index);
	int cp_size = 10;
	printf("::creating_list...\n");
	printf("sizeof(cfl)=%d\n",(int)sizeof(constant_field_list));
	void * pointer = 0;
	printf("poiner: %d\n", (int)sizeof(pointer));
	char one_byte = 0;
	printf("sizeof(one_byte)=%d\n", (int)sizeof(one_byte));
	constant_field_list * cp_array = (constant_field_list*) malloc((sizeof(constant_field_list))*cp_size);
	simple_struct * ss = (simple_struct*)malloc((sizeof(simple_struct)));
	ss->field = 'q';
	int val = 123;
	ss->ptr = &val;

	cp_array[0].tag = 'a';
	cp_array[0].data = (void*)ss;
	
	classFile = fopen("Example2.class","rb");
	fread(cafebabe,sizeof(char)*4,1,classFile);
	fread(&minor_version,sizeof(unsigned short),1,classFile);
	fread(&major_version,sizeof(unsigned short),1,classFile);
	
	printf("cafebabe[0] = %d",(int)cafebabe[0]);
	printf("cafebabe[1] = %d",(int)cafebabe[1]);
	printf("cafebabe[2] = %d",(int)cafebabe[2]);
	printf("cafebabe[3] = %d",(int)cafebabe[3]);
	cafebabe_int =  (unsigned int*)cafebabe;
	printf("cafebabe_int bigendian = %d\n", *cafebabe_int);
	swap_bytes_4(cafebabe_int);	
	printf("cafebabe_int swapped = %d\n", *cafebabe_int);
	cafebabe = (char*)cafebabe_int;
	printf("cafebabe[0] = %d\n", (int)cafebabe[0]);
	printf("cafebabe[1] = %d\n", (int)cafebabe[1]);
	printf("cafebabe[2] = %d\n", (int)cafebabe[2]);
	printf("cafebabe[3] = %d\n", (int)cafebabe[3]);

	if(((unsigned short)cafebabe[0]) == 0xfe)
	{
		printf("cafebabe[0] == 0xfe\n");
	}

	if((unsigned short)cafebabe[0] == 0xca)
	{
		printf("cafebabe[0] == 0xca\n");
	}		

	printf("minor_version = %d, major_version = %d", minor_version, major_version);
	if(major_version == 0x33)
	{
		printf("major_version == 0x0033\n");
	}
	printf("::list created\n");

	free(cp_array);
	fclose(classFile);
	return 0;
}











