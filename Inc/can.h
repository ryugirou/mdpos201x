#ifndef _CAN_H
#define _CAN_H

#ifdef __cplusplus
 extern "C" {
#endif

enum can_bitrate {
    CAN_BITRATE_10K,
    CAN_BITRATE_20K,
    CAN_BITRATE_50K,
    CAN_BITRATE_100K,
    CAN_BITRATE_125K,
    CAN_BITRATE_250K,
    CAN_BITRATE_500K,
    CAN_BITRATE_750K,
    CAN_BITRATE_1000K,
};

enum can_bus_state {
    OFF_BUS,
    ON_BUS
};

static const unsigned int CAN_MTU = 8;

void can_init(void);
void can_enable(void);
void can_disable(void);
void can_set_bitrate(enum can_bitrate bitrate);
void can_set_silent(uint8_t silent);
uint32_t can_tx(CAN_TxHeaderTypeDef *tx_header, uint8_t (&buf)[CAN_MTU]);
//uint32_t can_tx(CAN_TxHeaderTypeDef *tx_header,uint8_t aData[]);
uint32_t can_rx(CAN_RxHeaderTypeDef *rx_header, uint8_t (&buf)[CAN_MTU]);
uint8_t is_can_msg_pending(uint8_t fifo);
void can_set_filter(uint32_t id, uint32_t mask);

#ifdef __cplusplus
 }
#endif

#endif // _CAN_H
