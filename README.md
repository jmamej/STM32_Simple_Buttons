# Simple button debounce library

### Use - __BUTTON_X_GPIO_Port__, __BUTTON_X_Pin__ - button port/ pin naming convention.

- *btn_init()* function allocates 2d array for buttons that will hold their consecutive states.

- *check_button_states()* should be executed every 1 ms, with timer or in main loop in order to fill buttons array with data.

- __Buttons_config.h__ contains configuration settings.

### Config

- __NUM_OF_BUTTONS	4__    //number of used buttons (1-8)

- __IDLE_HIGH__      //comment if release state is LOW

- __ON_RELEASE__      //button press will be counted at button release

- __NUM_OF_READS	12__    //ammount of consecutive button state reads that determine debounced button state

- __BTN_ON_ACK		10__    //how many ON states to accept button press (keep lower than NUM_OF_READS)

- __BTN_OFF_ACK		10__    //how many OFF states to allow another button press (keep lower than NUM_OF_READS)

### Resolve button press

![btn_event_num()](https://github.com/user-attachments/assets/855f383e-76b2-4f74-8dcc-4aee68748c73)

*returned value by btn_event_num() - button BUTTON_3_Pin was pressed*

*btn_event_num()* returns bit set for corresponding index of button that was pressed. __BUTTON_0_Pin__ press will return 0x01 - 0'th bit set. Resolve button press and clear 0'th bit with *btn_clear_event(0)*.

Multiple button presses at once are acceptable. When buttons with index 1, 3 and 6 were pressed, *btn_event_num()* will return 0x4A or 0b0100 1010

code below does not contain information how to use *check_button_states()*. Use 1 ms timer interrupt or check in main every 1 ms.

```
btn_init();

while(1)
{
  if(btn_event_num())
  {
    for(int i = 0; i < UNM_OF_BUTTONS; i++)
    {
      if(btn_event_num() >> i && 1)
      {
        //resolve button press with index i
        btn_clear_event(i);  //clear event for index i
      }
    }
  }
}
```
