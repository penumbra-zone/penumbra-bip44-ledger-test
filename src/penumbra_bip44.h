#ifndef PENUMBRA_BIP44_H
#define PENUMBRA_BIP44_H

#include "stdint.h"


void compute_spend_key_bytes(unsigned int account_group_index, uint8_t *spend_key_bytes);

#endif // PENUMBRA_BIP44_H