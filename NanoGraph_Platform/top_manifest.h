/* ----------------------------------------------------------------------
 * top_manifest.h
 * -------------------------------------------------------------------- */

#define PLATFORM_ARCH_32BIT
//#define PLATFORM_ARCH_64BIT

/* the graph comes from the platform (internal), otherwise from the application  */
#define GRAPH_FROM_PLATFORM             

/* selection of integer processing with float_t and double_t */
#define STREAM_FLOAT_ALLOWED            

#define CACHE_LINE_BYTE_LENGTH 0        /* 0 for Cortex-M armv6/v7/v8-m */
//#define CACHE_LINE_BYTE_LENGTH 32       /* 32Bytes (CM7/CM55) */
//#define CACHE_LINE_BYTE_LENGTH 64       /* 64bytes for Cortex-A armv8/v9 */

/* 
    Number of interpreter instances reading the graph 
    
    Each processor using an RTOS can define up to 3 theads with different levels of priorities 
    The device can have several processors (PLATFORM_PROCESSOR = 1..7)
       each processor can have one architecture among seven (PLATFORM_ARCHITECTURE=1..7)
       the code used for this architecture is defined in the manifest
       it allows to dedicate the execution of a computing node to a specific instance.
*/
#define NANOGRAPH_NB_INSTANCE 1         
#define PLATFORM_PROCESSOR 1            
#define PLATFORM_ARCHITECTURE 1         

/* used for conditional code to enable memory flush */  
#define MULTIPROCESSING                 

