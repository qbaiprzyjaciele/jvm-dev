#include "stdio.h"
#include "stdlib.h"
#include "constant_field_list.h"

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


int main()
{
	void * constant_pool = (void*)malloc(4);
	char bytes[4] = {'a','b','a','a'};
	constant_pool = bytes;
	CONSTANT_MethodHandle_info * info = (CONSTANT_MethodHandle_info*)constant_pool;
	printf("info->tag=%c\n",info->tag);
	printf("info->reference_kind=%c\n",info->reference_kind);
	printf("info->reference_index=%d\n",info->reference_index);
	return 0;
}		









