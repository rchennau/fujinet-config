/**
 * #FUJINET Configuration
 *
 * State Machine
 */

#include <stdbool.h>
#include "state.h"
#include "set_wifi.h"
#include "connect_wifi.h"
#include "diskulator_hosts.h"
#include "diskulator_select.h"
#include "diskulator_slot.h"
#include "diskulator_info.h"
#include "adapter_config.h"

/**
 * Set next state
 */
void state_next(Context* context, State next_state)
{
  context->state = next_state;
}

/**
 * State machine. (Never exits.)
 */
void state(Context *context)
{
  while(true)
    {
      switch(context->state)
	{
	case SET_WIFI:
	  context->state = set_wifi(context);
	  break;
	case CONNECT_WIFI:
	  context->state = connect_wifi(context);
	  break;
	case DISKULATOR_HOSTS:
	  context->state = diskulator_hosts(context);
	  break;
	case DISKULATOR_SELECT:
	  context->state = diskulator_select(context);
	  break;
	case DISKULATOR_SLOT:
	  context->state = diskulator_slot(context);
	  break;
	case DISKULATOR_INFO:
	  context->state = diskulator_info(context);
	  break;
	case ADAPTER_CONFIG:
	  context->state = adapter_config(context);
	  break;
	}
    }
}
