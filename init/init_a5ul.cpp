/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "init_msm8926.h"
#include "vendor_init.h"

using android::base::GetProperty;

void cdma_properties(char const default_cdma_sub[], char const default_network[])
{
    property_override("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_override("ro.telephony.default_network", default_network);
    property_override("telephony.lteOnCdmaDevice", "1");
    property_override("ro.ril.enable.sdr", "0");
    property_override("ro.ril.enable.gea3", "1");
    property_override("ro.ril.enable.r8fd", "1");
    property_override("ro.ril.enable.a52", "0");
    property_override("ro.ril.enable.a53", "1");
    property_override("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420");
    property_override("ro.ril.fast.dormancy.cdma.rule", "0");
    property_override("ro.ril.pdpnumber.policy.roaming", "3");
    property_override("ro.ril.air.enabled", "0");
    property_override("ro.ril.gsm.to.lte.blind.redir", "0");
    property_override("persist.radio.snapshot_enabled", "1");
    property_override("persist.radio.snapshot_timer", "22");
}

void gsm_properties(char const default_network[])
{
    property_override("ro.telephony.default_network", default_network);
    property_override("ro.ril.hsupa.category", "6");
    property_override("ro.ril.hsxpa", "4");
    property_override("ro.ril.disable.cpc", "1");
    property_override("ro.ril.enable.pre_r8fd", "1");
    property_override("ro.ril.enable.sdr", "1");
    property_override("ro.ril.enable.r8fd", "1");
    property_override("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420,23594,27202,27205");
    property_override("ro.telephony.ril_class", "A5RIL");
}

void vendor_load_properties()
{

    std::string device;
    std::string bootmid = GetProperty("ro.boot.mid", "");
    if (bootmid == "0P9C10000") {
        /* a5tl */
        gsm_properties("9");
        set_ro_build_fingerprint_prop("htc/htccn_chs_cmcc/htc_a5tl:4.4.2/KOT49H/391137.3:user/release-keys");
        property_override("ro.build.description", "2.07.1403.3 CL391137 release-keys");
        set_ro_product_prop("model", "D816t");
        set_ro_product_prop("device", "htc_a5tl");
        property_override("ro.build.product", "htc_a5tl");
        property_override("ro.ril.hsdpa.category", "10");
        property_override("ro.ril.hsxpa", "2");
        property_override("ro.ril.enable.sdr", "0");
        property_override("ro.ril.enable.a53", "1");
        property_override("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420,27202");
        property_override("ro.ril.oem.ecclist", "112,000,08,110,118,119,911,999,120,122");
        property_override("ro.ril.set.mtusize", "1420");
    } else if (bootmid == "0P9C30000") {
        /* a5chl */
        cdma_properties("1","8");
        set_ro_build_fingerprint_prop("htc/sprint_wwe_vm/htc_a5chl:5.0.2/LRX22G/510432.2:user/release-keys");
        property_override("ro.build.description", "2.33.652.2 CL510432 release-keys");
        set_ro_product_prop("model", "710C");
        set_ro_product_prop("device", "htc_a5chl");
        property_override("ro.build.product", "htc_a5chl");
        property_override("gsm.sim.operator.numeric", "000000");
        property_override("gsm.operator.numeric", "000000");
        property_override("gsm.sim.operator.alpha", "Chameleon");
        property_override("gsm.operator.alpha", "Chameleon");
        property_override("ro.cdma.home.operator.numeric", "310120");
        property_override("ro.cdma.home.operator.alpha", "Virgin Mobile"); 
        property_override("ro.home.operator.carrierid", "Sprint"); 
        property_override("ro.ril.oem.ecclist", "911");
        property_override("ro.ril.set.mtusize", "1422");
        property_override("gsm.sim.operator.iso-country", "us");
        property_override("gsm.operator.iso-country", "us");
        property_override("ro.telephony.ril_class", "A5SprRIL");
    } else {
        /* a5ul */
        gsm_properties("9");
        property_override("ro.build.fingerprint", "htc/htc_asia_tw/htc_a5ul:6.0/MRA58K/698282.5:user/release-keys");
        property_override("ro.build.description", "3.12.709.5 CL698282 release-keys");
        set_ro_product_prop("model", "Desire 816");
        set_ro_product_prop("device", "htc_a5ul");
        property_override("ro.build.product", "htc_a5ul");
        property_override("ro.ril.hsdpa.category", "14");
        property_override("ro.ril.air.enabled", "1");
        property_override("ro.ril.enable.a53", "1");
        property_override("persist.radio.jbims", "1");
        property_override("ro.ril.enable.gea3", "1");
        property_override("ro.ril.gsm.to.lte.blind.redir", "1");
    }
      device = GetProperty("ro.product.device", "");
      LOG(ERROR) << "Found bootmid '" << bootmid.c_str() << "' setting build properties for '" << device.c_str() << "' device\n";
}
