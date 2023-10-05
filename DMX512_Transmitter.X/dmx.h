void DMX_Initialize(void);
void DMX_sync(void);
void DMX_send_byte(uint8_t data);
void DMX_send_bytes(uint8_t *data, uint8_t len);
void DMX_transsmision(uint8_t start_code, uint8_t *data, uint8_t data_len);