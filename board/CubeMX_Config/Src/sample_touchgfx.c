#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "app_touchgfx.h"

void touchgfx_thread_entry(void *parameter)
{
	MX_TouchGFX_Init();
	MX_TouchGFX_Process();
	for(;;)
	{
		rt_thread_mdelay(100);
	}
}
int TouchGFXTask(void)
{
	rt_thread_t tid = NULL;
	tid = rt_thread_create("TouchGFX",
							touchgfx_thread_entry, RT_NULL,
							4096, 20, 20);
	
   if (tid != RT_NULL)
        rt_thread_startup(tid);
   else
        return -1;

    return RT_EOK;
}
INIT_APP_EXPORT(TouchGFXTask);

void bmp_graph(void *parameter)
{
	for(;;)
	{
		rt_thread_mdelay(1000);
	}
}
int bmp_graph_Task(void)
{
	rt_thread_t tid = NULL;
	tid = rt_thread_create("bmp graph",
							touchgfx_thread_entry, RT_NULL,
							4096, 20, 20);
	
   if (tid != RT_NULL)
        rt_thread_startup(tid);
   else
        return -1;

    return RT_EOK;
}
MSH_CMD_EXPORT(bmp_graph_Task, bmp test);
