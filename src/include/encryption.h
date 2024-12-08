#pragma once

#ifdef USE_ENCRYPTION

#include <climits> 

#define stringify_literal(x) # x
#define stringify_expanded(x) stringify_literal(x)

typedef enum : uint8_t {
	ENCRYPTION_STATE_NONE,
  ENCRYPTION_STATE_PROPOSED,
  ENCRYPTION_STATE_FULL,
	ENCRYPTION_STATE_DISABLED
} encryptionState_e;

typedef struct encryption_params_s
{
    uint8_t nonce[8];
    uint8_t key[16];

} encryption_params_t;

bool ICACHE_RAM_ATTR DecryptMsg(uint8_t *input);
void ICACHE_RAM_ATTR EncryptMsg(uint8_t *input, uint8_t *output);

/// in: valid chars are 0-9 + A-F + a-f
/// out_len_max==0: convert until the end of input string, out_len_max>0 only convert this many numbers
/// returns actual out size
int hexStr2Arr(unsigned char* out, const char* in, size_t out_len_max = 0);

#endif
