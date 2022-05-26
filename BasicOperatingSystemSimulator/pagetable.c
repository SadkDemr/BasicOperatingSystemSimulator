#include <stdio.h>
#include <cstdint>
#include <stdint.h>



int main() {

    int64_t page_table[512] = { 0 };
    page_table[200] = 0x1234;
    page_table[300] = 0x2345 ;
    page_table[511] = 0x8000 ;

    int64_t page_table_size = (sizeof(array)/sizeof(array[0]));
    int64_t page_size_bits 12 // // 2^12 = 4KB;
    int64_t mask_offset ((1<<page_size_bits)-1);



    int64_t log_addr = 0x12C000;

   
    int64_t correctoutput; 

    log_addr = 0x12CFFF;


    correctoutput; 

    log_addr = 0x1FF84A;

    
    correctoutput; 

}