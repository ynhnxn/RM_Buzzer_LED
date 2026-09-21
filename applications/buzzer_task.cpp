#include "cmsis_os.h"
#include "io/buzzer/buzzer.hpp"

// 前提：TIM4输入时钟为84MHz
sp::Buzzer buzzer(&htim4, TIM_CHANNEL_3, 84e6f);

extern "C" void buzzer_task(void const * argument)
{
  (void)argument;  // 不使用传入参数

  buzzer.set(4000.0f, 0.1f);

  for (int i = 0; i < 3; i++) {
    buzzer.start();
    osDelay(100);

    buzzer.stop();
    osDelay(100);
  }

  while (true) {
    osDelay(1000);
  }
}