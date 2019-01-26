void swap_bytes_2(unsigned short * value) 
{
	value = (value>>8) | (value<<8);
}

void swap_bytes_4(unsigned int * value) 
{
	value  = (value>>24) | ( (value<<8) & 0x00ff0000 ) |  ((value>>8) & 0x0000ff00) | (x<<24 );
}	


