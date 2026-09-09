#include "can_driver.h"
#include <stm32l4xx.h>  

uint32_t rx_id;
bool rx_ext;
bool rx_rtr;
uint8_t rx_fmi, rx_len;
uint8_t rx_data[8];
 
void led_init(void);
void led_blink(void);
void CAN1_RX0_IRQHandler(void);
void CAN1_RX1_IRQHandler(void);

//vession 1 :
int main(void)
{
    led_init();
    can_gpio_init(CAN1, CAN_GPIO_PB8_PB9);
    can_init(CAN1,
             false, false, false, false, false, false,
             1, 13, 2, 1,
             true,   // LOOPBACK
             false); // SILENT
		//vession 1 :
    can_filter_init(
        CAN1,                               // CAN controller selection
        0,                                  // Filter bank number
        true,                               // 32-bit filter scale
        false,                              // Mask mode
        (0x00000120 << 3) | (1 << 2),       // Filter ID (R1)
        (0x1FFFFFF0 << 3) | (1 << 2),       // Filter mask (just id = 0x123) (R2)
        1,                                  // Assign filter to FIFO1
        true                                // Enable filter
    );

    uint32_t tx_id = 0x123;
//    uint32_t tx_id = 0x420;
    bool eid = true;
    bool rtr = false;
    uint8_t dlc = 8;
    uint8_t tx_data[8] = {'M','O','H','A','M','M','E','D'};
		can_transmit(CAN1, tx_id, eid, rtr, dlc, tx_data);
		
    while (1)
    {
    }
}


//vession 2 :
//void main(void)
//{
//	  led_init();
//    can_gpio_init(CAN1, CAN_GPIO_PB8_PB9);
//    can_init(CAN1,
//             false, false, false, false, false, false,
//             1, 13, 2, 1,
//             true,   // LOOPBACK
//             false); // SILENT
//				
//		//vession 2 :
//    can_filter_init(
//        CAN1,                                    // CAN controller selection
//        0,                                       // Filter bank number
//        false,                                   // 16-bit filter scale
//        false,                                   // Mask mode
//        ((0x7F0<<5) << 16)|(0x120 << 5),         // Filter Mask1 ID1 acepete 0x12x (R1)
//        ((0x70F<<5) << 16)|(0x333 << 5),         // Filter Mask2 ID2 acepete 0x333 (R2)
//        0,                                       // Assign filter to FIFO0
//        true                                     // Enable filter
//    );

//    uint32_t tx_id = 0x123;
////    uint32_t tx_id = 0x333;
////    uint32_t tx_id = 0x420;
//    bool eid = false;
//    bool rtr = false;
//    uint8_t dlc = 8;
//    uint8_t tx_data[8] = {'M','O','H','A','M','M','E','D'};
//		can_transmit(CAN1, tx_id, eid, rtr, dlc, tx_data);
//		
//    while (1)
//    {
//    }
//}



void led_init(void)
{
	RCC-> AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOCEN;       
	
	GPIOA->MODER &= ~(GPIO_MODER_MODE5);	    
	GPIOA->MODER |= (GPIO_MODER_MODE5_0);                             
	
  GPIOC->MODER &= ~(GPIO_MODER_MODE13);	                            

}

void led_blink(void)
{
	for(uint8_t i =0U; i < 10; i++)
	  {
			GPIOA -> ODR ^= GPIO_ODR_OD5;
			
			for(uint32_t j =0U; j < 16000000; j++)
			{
			}
		}
}

void CAN1_RX0_IRQHandler(void)
{
	can_receive(CAN1, 0, true, &rx_id, &rx_ext, &rx_rtr, &rx_fmi, &rx_len, rx_data);
	led_blink();
}

void CAN1_RX1_IRQHandler(void)
{
	can_receive(CAN1, 1, true, &rx_id, &rx_ext, &rx_rtr, &rx_fmi, &rx_len, rx_data);
	led_blink();
}
