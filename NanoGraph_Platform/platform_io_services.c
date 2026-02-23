/* ----------------------------------------------------------------------
 * Project:      NanoGraph
 * Title:        platform_computer_io_services.c
 * Description:  abstraction layer to BSP and streams from the application
 *
 * $Date:        15 February 2023
 * $Revision:    V0.0.1
 * -------------------------------------------------------------------- */
/*
 * Copyright (C) 2010-2023 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
* 
 */

#include <stdint.h>
#include "../NanoGraph_Store/nanograph_store_common_const.h"
#include "../NanoGraph_Store/nanograph_store_common_types.h"
#include "../NanoGraph_Interpreter/nanograph_const.h"
#include "top_manifest.h"


#ifdef __cplusplus
 extern "C" {
#endif

/*-----------------------------------------------------------------------
    entry point to the interpreter for data exchanges between the graph and 
    its outside world
*/
extern void NanoGraph_io_ack (uint8_t HW_io_idx, void *data, uint32_t size);



/*-----------------------------------------------------------------------
    no processing node 
 */
void NanoGraph_null_task (int32_t c, nanograph_handle_t i, void *d, uint32_t *s)  {}



/*-----------------------------------------------------------------------
    "HW" IO function : this is what the platform is capable-of  for data 
        exchanges with a graph. There can be 64K HW-IO interface defined
        in the platform manifest. Each HW-IO is assigned to one interpreter 
        instance (see "IDX_TO_NANOGRAPH_HWIO_CONTROL").
        
    Once compiled the graph defines up to 64 IO streams (provision margin up to 2K)
        Each stream can be multichannel of the same data domain.
    
    Here we define 10 IO Streams : 
 */
extern void data_sink      (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 0   SINK   */
extern void data_in_1      (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 1   io_data_in_1.txt   */
extern void analog_in_0    (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 2   io_analog_in_0.txt */
extern void motion_in_0    (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 3   io_motion_in_0.txt */
extern void audio_in_0     (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 4   io_audio_in_0.txt  */
extern void sensor_2d_in_0 (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 5   io_2d_in_0.txt  */
extern void line_out_0     (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 6   io_line_out_0.txt  */
extern void gpio_out_0     (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 7   io_gpio_out_0.txt  */
extern void gpio_out_1     (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 8   io_gpio_out_1.txt  */
extern void data_out_0     (uint32_t command, nanograph_xdmbuffer_t* data);        /*  IO_AL_idx = 9   io_data_out_0.txt  */



/*  IO_AL_idx =  2 analog_in_0 */
#define size_analog_0 16 /* Bytes */
static int16_t buffer_analog_0[size_analog_0 / sizeof(int16_t)];
/*  IO_AL_idx =  3 motion_in_0 */

/*  IO_AL_idx =  4 audio_in_0  buffer declared in the application */
#define size_audio_in_0 640 

/*  IO_AL_idx =  5 sensor_2d_in_0 */

/*  IO_AL_idx =  6 line_out_0 */
#define size_line_out_0 320
static int16_t buffer_line_out_0[size_line_out_0 / sizeof(int16_t)];

/*  IO_AL_idx =  7  gpio_out_0 */
#define size_gpio_out_0 4                      
static uint32_t buffer_gpio_out_0[size_gpio_out_0];

/*  IO_AL_idx =  8  gpio_out_1  UI/LED  */
#define size_gpio_out_1 4
static int32_t buffer_gpio_out_1[size_gpio_out_1 / sizeof(int32_t)];

/*  IO_AL_idx =  9  data_out_0  debug traces  */
#define size_data_out_0 4                      
static uint32_t buffer_data_out_0[size_data_out_0];    



/*  IO_AL_idx = 0   */
void data_sink(uint32_t command, nanograph_xdmbuffer_t* data)
{   
}

/*  IO_AL_idx = 1   */
void data_in_1(uint32_t command, nanograph_xdmbuffer_t* data)
{   switch (command)
    {   case NANOGRAPH_RESET:
        case NANOGRAPH_SET_PARAMETER:
        case NANOGRAPH_SET_BUFFER:
        case NANOGRAPH_RUN:
        case NANOGRAPH_STOP:
        case NANOGRAPH_READ_PARAMETER:
        default:break;
    }
}


/*  IO_AL_idx = 2       1 io_ra8e1_analog_0.txt 2    size_sensor_0 16 */
void analog_in_0(uint32_t command, nanograph_xdmbuffer_t* data)
{   switch (command)
    {
    case NANOGRAPH_RESET:
        //nanograph_format_io_setting = *(uint32_t *)(data->address);
        break;
    case NANOGRAPH_SET_PARAMETER:  /* presets reloaded */
        break;
    case NANOGRAPH_SET_BUFFER:     /* if memory allocation is made in the graph */
        break;
    case NANOGRAPH_RUN:            /* data moves */
        NanoGraph_io_ack(IO_PLATFORM_SENSOR_0, buffer_analog_0, size_analog_0);
        break;
    case NANOGRAPH_STOP:           /* stop data moves */
        break;
    case NANOGRAPH_READ_PARAMETER: /* setting done ? device is ready ? calibrated ? */
        break;
    default:
        break;
    }
}



/*  IO_AL_idx = 3   */
void motion_in_0(uint32_t command, nanograph_xdmbuffer_t* data)
{   switch (command)
    {   case NANOGRAPH_RESET:
        case NANOGRAPH_SET_PARAMETER:
        case NANOGRAPH_SET_BUFFER:
        case NANOGRAPH_RUN:
        case NANOGRAPH_STOP:
        case NANOGRAPH_READ_PARAMETER:
        default:break;
    }
}


/*  IO_AL_idx = 4       1 io_ra8e1_audio_in_0.txt      4    two microphones    320  */
void audio_in_0(uint32_t command, nanograph_xdmbuffer_t* data)
{
    switch (command)
    {   case NANOGRAPH_RESET:
        case NANOGRAPH_SET_PARAMETER:
        case NANOGRAPH_SET_BUFFER:
        case NANOGRAPH_RUN:
        case NANOGRAPH_STOP:
        case NANOGRAPH_READ_PARAMETER:
        default:break;
    }
}


/*  IO_AL_idx = 5   */
void sensor_2d_in_0(uint32_t command, nanograph_xdmbuffer_t* data)
{
    switch (command)
    {   case NANOGRAPH_RESET:
        case NANOGRAPH_SET_PARAMETER:
        case NANOGRAPH_SET_BUFFER:
        case NANOGRAPH_RUN:
        case NANOGRAPH_STOP:
        case NANOGRAPH_READ_PARAMETER:
        default:break;
    }
}




/*  IO_AL_idx = 6      1 io_ra8e1_line_out_0.txt      6    audio out stereo   160  */
void line_out_0 (uint32_t command, nanograph_xdmbuffer_t *data)
{
    switch (command)
    {
    case NANOGRAPH_RESET:
        //stream_format_io_setting = *(uint32_t *)(data->address);
        break;        
    case NANOGRAPH_SET_PARAMETER:  /* presets reloaded */
        break;
    case NANOGRAPH_SET_BUFFER:     /* if memory allocation is made in the graph */
        break;
    case NANOGRAPH_RUN:            /* data moves */
        NanoGraph_io_ack(IO_PLATFORM_LINE_OUT_0, buffer_line_out_0, size_line_out_0);
        break;
    case NANOGRAPH_STOP:           /* stop data moves */
        break;
    case NANOGRAPH_READ_PARAMETER: /* setting done ? device is ready ? calibrated ? */
        break;
    default:
        break;      
    }
}


/*  IO_AL_idx = 7   */
void gpio_out_0(uint32_t command, nanograph_xdmbuffer_t* data)
{
    switch (command)
    {
    case NANOGRAPH_RESET:
    case NANOGRAPH_SET_PARAMETER:
    case NANOGRAPH_SET_BUFFER:
    case NANOGRAPH_RUN:
    case NANOGRAPH_STOP:
    case NANOGRAPH_READ_PARAMETER:
    default:break;
    }
}


/*  IO_AL_idx = 8  UI/LED  */
void gpio_out_1(uint32_t command, nanograph_xdmbuffer_t* data)
{
    switch (command)
    {
    case NANOGRAPH_RESET:
        break;
    case NANOGRAPH_SET_PARAMETER:
        //stream_format_io_setting = *(uint32_t *)(data->address);          
        break;
    case NANOGRAPH_SET_BUFFER:
    {
        nanograph_xdmbuffer_t* pt_pt;
        pt_pt = (nanograph_xdmbuffer_t*)data;
        pt_pt->address = (intptr_t)buffer_gpio_out_1;
        pt_pt->size = size_gpio_out_1;
    }
    break;
    case NANOGRAPH_RUN:
    {	extern void hal_set_led0_low(void);
    	extern void hal_set_led0_high(void);

    	nanograph_xdmbuffer_t* pt_pt = (nanograph_xdmbuffer_t*)data;

        /* "io_platform_stream_in_0," frame_size option in samples + FORMAT-0 in the example graph */
        NanoGraph_io_ack(IO_PLATFORM_GPIO_OUT_1, (void *)(pt_pt->address), pt_pt->size);
        break;
    }
    case NANOGRAPH_STOP:
        break;
    case NANOGRAPH_READ_PARAMETER: /* setting done ? device is ready ? calibrated ? */
        break;
    default:
        break;
    }
}


/*  IO_AL_idx = 9       1 io_ra8e1_data_out_0.txt         9    debug trace        1024  */
void data_out_0(uint32_t command, nanograph_xdmbuffer_t* data)
{
    switch (command)
    {
    case NANOGRAPH_RESET:
        //stream_format_io_setting = *(uint32_t *)(data->address);          
        break;
    case NANOGRAPH_SET_PARAMETER:
        break;
    case NANOGRAPH_SET_BUFFER:
    {
        nanograph_xdmbuffer_t* pt_pt;
        pt_pt = (nanograph_xdmbuffer_t*)data;
        pt_pt->address = (intptr_t)buffer_data_out_0;
        pt_pt->size = size_data_out_0;
    }
    break;
    case NANOGRAPH_RUN:
        /* "io_platform_stream_in_0," frame_size option in samples + FORMAT-0 in the example graph */
        NanoGraph_io_ack(IO_PLATFORM_DATA_OUT_0, (uint8_t*)data, size_data_out_0);
        break;
    case NANOGRAPH_STOP:
        break;
    case NANOGRAPH_READ_PARAMETER: /* setting done ? device is ready ? calibrated ? */
        break;
    default:
        break;
    }
}




#endif
/*
 * -----------------------------------------------------------------------
 */
