#include "penumbra_bip44.h"

//#include "shared_context.h"

#include "os.h"
#include "cx.h"

// note: spend_key_bytes is now 64 bytes
void compute_spend_key_bytes(unsigned int account_group_index, uint8_t *spend_key_bytes) {
  unsigned int bip32_path[3];
  unsigned char chain[32];

  // bip32_path[0] = 44' because we use BIP/SLIP44, [1] = 6532' = 0x1984
  // these must match those found in Makefile
  bip32_path[0] = 44 | 0x80000000;
  bip32_path[1] = 6532 | 0x80000000;
  bip32_path[2] = account_group_index | 0x80000000;

/*
  os_perso_derive_node_bip32(CX_CURVE_256K1, bip32_path,
                             sizeof(bip32_path) / sizeof(bip32_path[0]),
                             spend_key_bytes, chain);
*/

  os_derive_bip32_no_throw(CX_CURVE_256K1, bip32_path,
                             sizeof(bip32_path) / sizeof(bip32_path[0]),
                             spend_key_bytes, chain);

  return;
}