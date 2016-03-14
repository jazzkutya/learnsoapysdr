/* 
 * stuff
 */

#include <stdio.h>
#include <SoapySDR/Version.h>
#include <SoapySDR/Modules.h>
#include <SoapySDR/Device.h>

int main(int argc, char *argv[]) {
    size_t ndevs=0;
    //SoapySDRKwargs *devs=SoapySDRDevice_enumerateStrArgs("",&ndevs);
    SoapySDRKwargs filter;
    filter.size=0;
    SoapySDRKwargs *devs=SoapySDRDevice_enumerate(&filter,&ndevs);
    // pfh... segfault in SoapySDRDevice_enumerateStrArgs and SoapySDRDevice_enumerate too
    /*
    printf("SoapySDR enumerated %zu devices\n",ndevs);
    for (size_t t=0;t<ndevs;t++) {
        SoapySDRKwargs dev=devs[t];
        printf("device %zu (",t);
        for (size_t k=0;k<dev.size;k++) {
            char *key=dev.keys[t];
            char *val=dev.vals[t];
            printf("%s=%s",key,val);
            if (k!=dev.size) printf(", ");
        }
        printf(")\n");
    }
    */
}
