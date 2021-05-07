/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "platform.h"

#ifdef USE_CMS

#include "cms/cms.h"
#include "cms/cms_types.h"
#include "cms/cms_menu_flow.h"

#include "config/feature.h"

#include "fc/config.h"


static long cmsx_Flow_onEnter(void) {
    return 0;
}

static long cmsx_Flow_onExit(const OSD_Entry *self) {
    UNUSED(self);
    return 0;
}

static OSD_Entry cmsx_menuFlowEntries[] = {
    { "-- FLOW SETUP --", OME_Label, NULL, NULL, 0},
    
    { "SAVE&EXIT",   OME_OSD_Exit, cmsMenuExit,   (void *)CMS_EXIT_SAVE, 0},
    { "BACK", OME_Back, NULL, NULL, 0 },
    { NULL, OME_END, NULL, NULL, 0 }
};

CMS_Menu cmsx_menuFlow = {
#ifdef CMS_MENU_DEBUG
    .GUARD_text = "MENUFLOW",
    .GUARD_type = OME_MENU,
#endif
    .onEnter = cmsx_Flow_onEnter,
    .onExit = cmsx_Flow_onExit,
    .entries = cmsx_menuFlowEntries
};

#endif
