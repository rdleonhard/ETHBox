/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <Preferences.h>
#include <stddef.h>
#include "utils_crypto.h"

extern Preferences prefs;

void storage_manager_setup();
void storage_manager_saveCounter(uint32_t counter);
uint32_t storage_manager_loadCounter();
void storage_manager_savePrivateKey(const uint8_t *key, size_t len, const char *pin = nullptr);
bool storage_manager_loadPrivateKey(uint8_t *key, size_t len, const char *pin = nullptr);
void storage_manager_loop();

#endif // STORAGE_MANAGER_H
