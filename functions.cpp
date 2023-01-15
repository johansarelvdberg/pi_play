#include "functions.h"

#define FLAG_VALUE 123

uint32_t comm_fifo[10];

/*
void multicore_launch_core1_with_stack 	( 	void(*)(void)  	entry,
		uint32_t *  	stack_bottom,
		size_t  	stack_size_bytes 
	) 	
    */
bool cpu_done = false;

inline static void out_core_name() {
    printf("Its all gone well on core %i\n", get_core_num());
}


void call_core_first(){
    auto time_stamp = time_us_32 ();
    multicore_fifo_push_blocking(time_stamp);
    auto time_other = multicore_fifo_pop_blocking();
    out_core_name();
    printf("Start time %i on core first function and other at %i\n",time_stamp, time_other);

    while(cpu_done == false){
        sleep_ms(2);
    }
}

void call_core_second(){
    auto time_stamp = time_us_32 ();
    multicore_fifo_push_blocking(time_stamp);
    auto time_other = multicore_fifo_pop_blocking();
    out_core_name();
    printf("Start time %i on core first function and other at %i\n",time_stamp, time_other);
    cpu_done = true;
}

void init(){
    auto time_stamp = time_us_32 ();

    printf("Time: %i\nMust be flase %d\n", time_stamp, cpu_done);
    multicore_reset_core1();
    multicore_launch_core1 (call_core_second);
    //multicore_launch_core1_with_stack 	( 	call_core_second,		comm_fifo,		10	);
    //sleep_ms(20);
    call_core_first();
    time_stamp = time_us_32 ();
    printf("Done time %i\n", time_stamp);
}