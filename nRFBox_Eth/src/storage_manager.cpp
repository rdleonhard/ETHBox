/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "storage_manager.h"

Preferences prefs;

void storage_manager_setup() {
    prefs.begin("nrfbox", false);
}

void storage_manager_saveCounter(uint32_t counter) {
    prefs.putUInt("counter", counter);
}

uint32_t storage_manager_loadCounter() {
    return prefs.getUInt("counter", 0);
}

void storage_manager_loop() {
    // nothing for now
}

